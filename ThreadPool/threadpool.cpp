#include "threadpool.h"

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

bool ThreadPool::Task::operator<(const ThreadPool::Task& rhs) const
{
    return (m_priority < rhs.m_priority);
}

ThreadPool::Task::Task(int priority, callable call_me)
    : m_priority(priority)
    , m_call_me(call_me)
{

}

int ThreadPool::Task::getPriority() const
{
    return m_priority;
}


void ThreadPool::Task::Run()
{
    m_call_me();
}




ThreadPool::ThreadPool(int threadsCount)
    : m_threadsCount(threadsCount)
    , m_started(false)
    , m_needStop(false)
{

}

ThreadPool::~ThreadPool()
{
    Task* task = nullptr;
    while (!empty())
    {
        task = getTask();
        if (task != nullptr)
            delete task;
    }
}

int ThreadPool::genRand(int min, int max)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

ThreadPool::Task* ThreadPool::getTask()
{
    unique_lock<mutex> lock(m_mutex);
    Task* task = m_tasksQueue.top();
    m_tasksQueue.pop();
    return task;
}


bool ThreadPool::empty()
{
    unique_lock<mutex> lock(m_mutex);
    return m_tasksQueue.empty();
}

void ThreadPool::addTask(int priority, callable call_me)
{
    m_tasksQueue.push(new Task(priority, call_me));
    m_condVar.notify_all();
}


void ThreadPool::start()
{
    if (m_started)
        return;

    for (size_t i = 0; i < m_threadsCount; i++)
    {
        shared_ptr<thread> t(new thread(bind(&ThreadPool::worker, this)));
        m_pool.push_back(t);
    }
    m_started = true;
}

void ThreadPool::stop()
{
    m_needStop = true;
    m_condVar.notify_all();

    for (auto& worker : m_pool)
        worker->join();

    m_started = false;
    m_needStop = false;
    m_pool.clear();
}

/**
 * @brief ThreadPool::worker - get next task from queue and run it.
 */
void ThreadPool::worker()
{
    Task* task = nullptr;
    while (m_needStop == false)
    {
        while (empty())
        {
            unique_lock<mutex> lock(m_mutex);
            m_condVar.wait_for(lock, chrono::seconds(60));
            if (m_needStop)
            {
                unique_lock<mutex> lockPrint(m_mutexPrint);
                cout << "Thread #" << this_thread::get_id() << " has finished work" << endl;
                return;
            }
        }

        task = getTask();
        if (task != nullptr)
        {
            {
            unique_lock<mutex> lockPrint(m_mutexPrint);
            cout << "[" << this_thread::get_id() << "] " << "Task priority: " << task->getPriority() << " Task result: ";
            }
            task->Run();
        }

        this_thread::yield();
        this_thread::sleep_for(chrono::milliseconds(genRand()));
    }
}
