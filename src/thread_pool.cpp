#include <thread_pool.hpp>

template <typename Function, typename... Arguments >
Thread_pool::Thread_pool(int threads, Function && func, Arguments &&... args) {
    if (threads <= 0 || threads > MAX_THREADS_NUMBER) {
        throw std::out_of_range("Invalid threads number.");
    }

    threads_array = new std::vector<std::thread>(threads, std::thread(func, args...));
};
