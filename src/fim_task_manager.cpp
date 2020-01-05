#include <fim_task_manager.hpp>

FIM_task_manager::FIM_task_manager(int dq_size, int iq_size, bool discard_events):
    directory_queue(dq_size, discard_events), integrity_queue(iq_size, discard_events) {};
