#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <thread>
#include <vector>

#define MAX_THREADS_NUMBER 50

class Thread_pool {
private:
    std::vector<std::thread> threads_array;
    int threads;
public:
    template <typename Function, typename ... Arguments>
    Thread_pool(int threads, Function && func, Arguments && ... args);
    void set_threads_number(int threads);
};

#endif