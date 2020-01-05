#ifndef __WINDOWS_FILE_H__
#define __WINDOWS_FILE_H__

#include "file.hpp"

class Windows_file: public File {
private:
    unsigned int attrs;
};

#endif