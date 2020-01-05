#ifndef __FIM_H__
#define __FIM_H__

#include "file/linux_file.hpp"
#include "file/windows_file.hpp"
#include "configuration/configuration.hpp"
#include <fim_task_manager.hpp>
#include <thread_pool.hpp>

class FIM_engine {
private:
    // Configuration configuration;
    Thread_pool *thread_pool;
    FIM_task_manager *task_manager;
public:
    FIM_engine();
};

#endif