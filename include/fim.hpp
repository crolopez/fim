#ifndef __FIM_H__
#define __FIM_H__

#include "configuration/configuration.hpp"
#include <fim_task_manager.hpp>
#include <thread_pool.hpp>

class FIM_engine {
private:
    // Configuration configuration;
    Thread_pool *thread_pool;
    FIM_task_manager *task_manager;
    Configuration *config;
public:
    FIM_engine();
};

#endif