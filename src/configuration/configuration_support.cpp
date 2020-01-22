#include "configuration/configuration_support.hpp"

cJSON *get_json_from_file(std::string json_path) {
    const char *str_json_path = json_path.c_str();
    FILE *fd = fopen(str_json_path,"rb");

    if (!fd) {
        throw std::string(std::string("Could not load the configuration from ") + json_path);
    }

    // Get file size
    fseek(fd, 0, SEEK_END);
    long size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    if (size > MAX_CONFIG_SIZE) {
        fclose(fd);
        throw std::string(std::string("The configuration file is larger than the allowed size: ") + std::to_string(MAX_CONFIG_SIZE));
    }


    // Alloc memory for the content
    char *file_data = (char *) malloc(size + 1);
    if (!file_data) {
        fclose(fd);
        throw std::string(std::string("Could not alloc memory to read the configuration file."));
    }

    // Read the file content
    fread(file_data, 1, size, fd);
    file_data[size] = '\0';

    fclose(fd);

    // Parse the config
    cJSON *obj = cJSON_Parse(file_data);
    if (!obj) {
        free(file_data);
        throw std::string(std::string("The configuration file is not a JSON object."));
    }

    free(file_data);
    return obj;
}

void configuration_node::operator=(configuration_node cpy) {
    directory = cpy.directory;
    registry = cpy.registry;
    file_content = cpy.file_content;
    reporting = cpy.reporting;
    queues = cpy.queues;
    threads = cpy.threads;
}
