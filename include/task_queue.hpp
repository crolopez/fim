#ifndef __TASK_QUEUE_H__
#define __TASK_QUEUE_H__

#include <queue>
#include <condition_variable>
#include <mutex>

#define MAX_QUEUE_SIZE 100

template <typename task_type>
class Task_queue {
private:
    std::mutex mutex;
    std::condition_variable c_not_full;
    std::condition_variable c_not_empty;
    std::queue<task_type> tasks;
    unsigned int max_size;
    bool discard_if_full;
public:
    Task_queue(int max_size, bool discard_if_full);
    void push(task_type element);
    task_type pop();
};

#endif