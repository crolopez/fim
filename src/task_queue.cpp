#include <task_queue.hpp>

template <typename task_type>
Task_queue<task_type>::Task_queue(int max_size, bool discard_if_full): max_size(max_size), discard_if_full(discard_if_full) {
    if (max_size <= 0 || max_size > MAX_QUEUE_SIZE) {
        throw std::out_of_range("Invalid queue size.");
    }
}

template <typename task_type>
void Task_queue<task_type>::push(task_type element) {
    std::unique_lock<std::mutex> lock(mutex);

    if (tasks.size() == max_size) {
        if (discard_if_full) {
            return;
        }

        c_not_full.wait(lock);
    }

    tasks.push(element);
    c_not_empty.notify_one();
}

template <typename task_type>
task_type Task_queue<task_type>::pop() {
    std::unique_lock<std::mutex> lock(mutex);

    if (tasks.empty()) {
        c_not_empty.wait(lock);
    }

    task_type element = tasks.pop(element);
    if (!discard_if_full) {
        c_not_full.notify_one();
    }
    return element;
}
