#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "../monitoring/directory_monitoring.hpp"
#include "../monitoring/registry_monitoring.hpp"
#include "../monitoring/file_content_monitoring.hpp"

class Configuration {
private:
    Directory dconfiguration;
    Directory next_dconfiguration;
    Registry rconfiguration;
    Registry next_rconfiguration;
    File_content fconfiguration;
    File_content next_fconfiguration;
public:
    void load_local_configuration();
    void load_remote_configuration();
    void apply_loaded_configuration();
};

#endif