#include <memory>
#include <iostream>
#include "configuration/configuration.hpp"

Configuration::Configuration(): local_path(LOCAL_CONFIGURATION_PATH) {
    try {
        load_local_configuration();
        apply_loaded_configuration();
    } catch (std::string excp) {
        std::cerr << excp << std::endl; // ~~~ It should be printed or handled by the object creator
        throw;
    }
}

void Configuration::load_local_configuration() {
    const char *str_local_path = local_path.c_str(); // <~~~~~~~~~~~~~~~
    cJSON *json_cfg = cJSON_Parse(str_local_path);

    if (!json_cfg) {
        throw std::string(std::string("Could not load the configuration from ") + std::string(str_local_path));
    }

    try {
        load_reporting(json_cfg);
    } catch (std::string excp) {
        throw;
    }


    cJSON_Delete(json_cfg);
    delete json_cfg;
}

void Configuration::apply_loaded_configuration() {

}

void Configuration::load_reporting(cJSON *json_cfg) {
    cJSON *cfg_node = cJSON_GetObjectItem(json_cfg, "reporting");

    if (!cfg_node) {
        // To avoid memory management. We assume because it's low memory and shouldn't be a common case
        throw std::string("reporting section not found in the loaded configuration.");
    }
}


void Configuration::load_directory(cJSON *json_cfg) {

}

void Configuration::load_registry(cJSON *json_cfg) {

}

void Configuration::load_file_content(cJSON *json_cfg) {

}