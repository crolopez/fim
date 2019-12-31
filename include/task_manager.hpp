#ifndef __TASK_MANAGER_H__
#define __TASK_MANAGER_H__

#include <queue>
#include <mutex>

template <class task_type>
class Task_queue {
private:
    std::mutex mutex;
    std::queue<task_type> tasks;
    unsigned int size;
    unsigned int max_size;
public:
    void push(task_type element);
    task_type pop();
};

class Task_manager {
private:
    Task_queue<int> file_integrity;
    Task_queue<int> directory_scan;
public:
    void add_task(int task);
    int get_task();
};

#endif