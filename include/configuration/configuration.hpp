#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "configuration_support.hpp"
#include "../external/cjson/cJSON.h"

class Configuration {
private:
    configuration_node current_config;
    configuration_node pending_config;
    std::string local_path;
    void apply_loaded_configuration();
    void load_reporting(cJSON *json_cfg);
    void load_advanced(cJSON *json_cfg);
    void load_directory(cJSON *json_cfg);
    void load_registry(cJSON *json_cfg);
    void load_file_content(cJSON *json_cfg);
public:
    Configuration(std::string config_path);
    void load_local_configuration();
    void load_remote_configuration(); // ~~~~~~~~~~~~~~~ TODO
};

#endif