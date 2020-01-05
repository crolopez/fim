#include <fim.hpp>
#include <fim_engine_support.hpp>

FIM_engine::FIM_engine() {
    // Load config

    // Create a task manager instance
    // task_manager = new FIM_task_manager(10, 10, false); // <~~~~~~~~~~~~~~ COMPILATION ERROR

    // Create a thread pool instance
    // thread_pool = new Thread_pool(5, tasks_processor, task_manager); // <~~~~~~~~~~~~~~ COMPILATION ERROR
}
