#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <queue>
#include <functional>
#include <memory>
#include <mutex>
#include <atomic>
#include <list>
#include <thread>
#include <condition_variable>

using callable = std::function<void (void)>;

class ThreadPool
{
private:
    // impl
    class Task
    {
    private:
        int m_priority;
        callable m_call_me;

    public:
        Task(int priority, callable call_me);
        int getPriority() const;
        void Run();
        bool operator<(const Task& rhs) const;
    };

    struct my_greater
    {
        bool operator()(const Task* x, const Task* y) const
        {
            return !(*x < *y);
        }
    };


private:
    std::size_t m_threadsCount;
    std::atomic<bool> m_started;
    std::atomic<bool> m_needStop;
    std::mutex m_mutex;
    std::mutex m_mutexPrint;
    std::condition_variable m_condVar;

    std::list<std::shared_ptr<std::thread>> m_pool;
    std::priority_queue<Task*,std::vector<Task*>, my_greater> m_tasksQueue;

    int genRand(int min = 1, int max = 100);
    Task* getTask();
    void worker();
    bool empty();

public:
    ThreadPool(int threadCount);
    ~ThreadPool();
    void addTask(int priority, callable call_me);
    void start();
    void stop();
};

#endif // THREADPOOL_H
