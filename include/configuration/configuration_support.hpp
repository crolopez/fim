#ifndef __CONFIGURATION_SUPPORT_H__
#define __CONFIGURATION_SUPPORT_H__

#include <string>
#include "../monitoring/directory_monitoring.hpp"
#include "../monitoring/registry_monitoring.hpp"
#include "../monitoring/file_content_monitoring.hpp"
#include "../external/cjson/cJSON.h"

#define MAX_CONFIG_SIZE 104857600 // 100MB

struct reporting_data {
    std::string address;
    char protocol;
    int port;
    int max_eps;
};

struct queue_size {
    int directories;
    int files;
};

struct configuration_node {
    Directory directory;
    Registry registry;
    File_content file_content;
    reporting_data reporting;
    queue_size queues;
    int threads;
    bool valid = false;
    void operator=(configuration_node cpy);
};

cJSON *get_json_from_file(std::string json_path);

#endif