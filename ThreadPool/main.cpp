#include <iostream>
#include "threadpool.h"
#include <functional>
#include <random>
#include <chrono>

using namespace std;

int genRand(int min, int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

void add_func(int a, int b)
{
    cout << a << " + " << b << " = " << a + b << endl;
}

int main()
{
    ThreadPool pool(5); // 5 threads

    pool.start();

    for (int i = 0; i < 100; i++)
    {
        int priority = genRand(1, 100);
        pool.addTask(priority, bind(add_func, i, i));
    }

    pool.addTask(0, bind(add_func, 999, 999));

    this_thread::sleep_for(chrono::seconds(5));

    pool.stop();

    this_thread::sleep_for(chrono::seconds(5));

    return 0;
}

