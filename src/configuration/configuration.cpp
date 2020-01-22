#include <memory>
#include <iostream>
#include <string.h>
#include "configuration/configuration.hpp"
#include "configuration/configuration_support.hpp"

Configuration::Configuration(std::string config_path): local_path(config_path) {
    load_local_configuration();
    apply_loaded_configuration();
}

void Configuration::load_local_configuration() {
    cJSON *json_cfg = get_json_from_file(local_path);

    load_reporting(json_cfg);
    load_advanced(json_cfg);

    pending_config.valid = true;
    cJSON_Delete(json_cfg);
}

void Configuration::apply_loaded_configuration() {
    if (!pending_config.valid ) {
        throw std::string("There are not pending configuration to be loaded.");
    }

    current_config = pending_config;
    current_config.valid = true;
    pending_config.valid = false;
}

void Configuration::load_reporting(cJSON *json_cfg) {
    cJSON *cfg_section = cJSON_GetObjectItem(json_cfg, "reporting");

    if (!cfg_section || !cfg_section->child) {
        // To avoid memory management. We assume because it's low memory and shouldn't be a common case
        throw std::string("reporting section not found in the loaded configuration.");
    }

    // Load address
    cJSON *cfg_node = cJSON_GetObjectItem(cfg_section, "address");
    if (!cfg_node || cfg_node->type != cJSON_String) {
        throw std::string("reporting section does not have a valid address.");
    }
    pending_config.reporting.address = std::string(cfg_node->valuestring);

    // Load protocol
    cfg_node = cJSON_GetObjectItem(cfg_section, "protocol");
    if (!cfg_node || cfg_node->type != cJSON_String) {
        throw std::string("reporting section does not have a valid protocol.");
    }
    pending_config.reporting.protocol = !strcmp(cfg_node->valuestring, "tcp") ? 'T' : 'U';

    // Load port
    cfg_node = cJSON_GetObjectItem(cfg_section, "port");
    if (!cfg_node || cfg_node->type != cJSON_Number) {
        throw std::string("reporting section does not have a valid port.");
    }
    pending_config.reporting.port = cfg_node->valueint;

    // Load max_eps
    cfg_node = cJSON_GetObjectItem(cfg_section, "max_eps");
    if (!cfg_node || cfg_node->type != cJSON_Number) {
        throw std::string("reporting section does not have a valid max_eps.");
    }
    pending_config.reporting.max_eps = cfg_node->valueint;
}


void Configuration::load_advanced(cJSON *json_cfg) {
    cJSON *cfg_section = cJSON_GetObjectItem(json_cfg, "advanced");

    if (!cfg_section || !cfg_section->child) {
        // To avoid memory management. We assume because it's low memory and shouldn't be a common case
        throw std::string("advanced section not found in the loaded configuration.");
    }

    // Load queues
    cJSON *cfg_queues = cJSON_GetObjectItem(cfg_section, "queue");
    if (!cfg_queues || !cfg_queues->child) {
        throw std::string("queue section not found in the loaded configuration.");
    }

    // Load directory queue size
    cJSON *cfg_node = cJSON_GetObjectItem(cfg_queues, "directory");
    if (!cfg_node || cfg_node->type != cJSON_Number) {
        throw std::string("queue section does not have a valid directory queue size.");
    }
    pending_config.queues.directories = cfg_node->valueint;

    // Load file queue size
    cfg_node = cJSON_GetObjectItem(cfg_queues, "file");
    if (!cfg_node || cfg_node->type != cJSON_Number) {
        throw std::string("queue section does not have a valid file queue size.");
    }
    pending_config.queues.files = cfg_node->valueint;

    // Load threads number
    cfg_node = cJSON_GetObjectItem(cfg_section, "threads");
    if (!cfg_node || cfg_node->type != cJSON_Number) {
        throw std::string("advanced section does not have a valid thread number.");
    }
    pending_config.threads= cfg_node->valueint;

}


void Configuration::load_directory(cJSON *json_cfg) {

}

void Configuration::load_registry(cJSON *json_cfg) {

}

void Configuration::load_file_content(cJSON *json_cfg) {

}