#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <thread>
#include <vector>

class Thread_pool {
private:
    std::vector<std::thread> threads;
    int n_threads;
public:
    void set_threads_number(int threads);
};

#endif