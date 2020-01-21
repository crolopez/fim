#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <file_support.hpp>

class File {
private:
    std::string perm;
    std::string uid;
    std::string guid;
    std::string user_name;
    std::string group_name;
    file_timestamps dates;
    unsigned int size;
    file_hashes hashes;
};

#endif