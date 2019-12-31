#ifndef __MONITORING_SUPPORT_H__
#define __MONITORING_SUPPORT_H__

enum device_type {
    FILE_INTEGRITY,
    REGISTRY_INTEGRITY,
    FILE_CONTENT
};

enum monitoring_type {
    ALLOW_ENTRIES,
    DENY_ENTRIES
};

#endif