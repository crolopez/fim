#include <iostream>
#include <fim.hpp>
#include <fim_engine_support.hpp>

FIM_engine::FIM_engine(std::string config_path) {

    // Load config
    config = new Configuration(config_path);


    // Create a task manager instance
    // task_manager = new FIM_task_manager(10, 10, false); // <~~~~~~~~~~~~~~ COMPILATION ERROR

    // Create a thread pool instance
    // thread_pool = new Thread_pool(5, tasks_processor, task_manager); // <~~~~~~~~~~~~~~ COMPILATION ERROR
}

FIM_engine::FIM_engine(char *config_path) {
    FIM_engine(std::string(config_path));
}