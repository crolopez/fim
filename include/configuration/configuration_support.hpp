#ifndef __CONFIGURATION_SUPPORT_H__
#define __CONFIGURATION_SUPPORT_H__

#include <string>
#include "../monitoring/directory_monitoring.hpp"
#include "../monitoring/registry_monitoring.hpp"
#include "../monitoring/file_content_monitoring.hpp"

struct reporting_data {
    std::string address;
    char protocol;
    int port;
    int max_eps;
};

struct configuration_node {
    Directory directory;
    Registry registry;
    File_content file_content;
    reporting_data reporting;
};

#endif