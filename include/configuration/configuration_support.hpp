#ifndef __CONFIGURATION_SUPPORT_H__
#define __CONFIGURATION_SUPPORT_H__

#include <string>

struct file_timestamps {
    std::string creation_date;
    std::string modification_date;
    std::string last_access;
};

struct file_hashes {
    std::string md5;
    std::string sha1;
    std::string sha256;
    std::string sha512;
};

#endif