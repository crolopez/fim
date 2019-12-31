#ifndef __FIM_H__
#define __FIM_H__

#include "file/linux_file.hpp"
#include "file/windows_file.hpp"
#include "configuration/configuration.hpp"

class FIM_engine {
private:
    Configuration configuration;
    int threads;

    void init_threads_pool();
    void init_queues();
public:
    void init_engine();
};

#endif