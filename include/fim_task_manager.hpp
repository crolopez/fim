#ifndef __TASK_MANAGER_H__
#define __TASK_MANAGER_H__

#include <task_queue.hpp>

class FIM_task_manager {
private:
    Task_queue<int> directory_queue; // ~~~~~~~~ This will be a directory events queue
    Task_queue<int> integrity_queue; // ~~~~~~~~ This will be a file integrity events queue
public:
    FIM_task_manager(int dq_size, int iq_size, bool discard_events);
    void add_task(int task);
    int get_task();
};

#endif