#include <fim_engine_support.hpp>
#include <fim_task_manager.hpp>

inline void process_task(int task);
void directory_analyzer(int directory_task);
void file_analyzer(int file_task);

void tasks_processor(FIM_task_manager *task_manager) {
    while (true) {
        auto task = task_manager->get_task();
        process_task(task);
    }
}

void process_task(int task) {
    switch (task) {
        case 0:
            file_analyzer(task);
            break;
        default:
            directory_analyzer(task);
    }
}

void directory_analyzer(int directory_task) {

}

void file_analyzer(int file_task) {

}