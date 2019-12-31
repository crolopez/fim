#ifndef __MONITORING_H__
#define __MONITORING_H__

#include <string>
#include <vector>
#include <chrono>
#include "monitoring_support.hpp"

class Monitoring {
private:
    std::string ID;
    device_type dtype;
    monitoring_type mtype;
    std::vector<std::string> filter;
    std::chrono::duration<double> date;
    unsigned long long options;
    bool valid_configuration;
};

#endif