#ifndef __LINUX_FILE_H__
#define __LINUX_FILE_H__

#include "file.hpp"

class Linux_file: private File {
private:
    unsigned int inode;
    unsigned int device;
};

#endif