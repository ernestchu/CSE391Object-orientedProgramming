//
//  tar.hpp
//  hw2
//
//  Created by Ernest Chu on 2020/10/23.
//

#ifndef mytar_hpp
#define mytar_hpp
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "utils.h"

const int INDENT_WIDTH = 8;
const int BLOCK_SIZE = 512;

struct TarHeader {
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];

    /* USTAR Section */
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
};
class Tar {
public:
    void read_file(const char** argv);
    void list_files();
private:
    std::vector<TarHeader> headers;
    int num_files = 0;
};
#endif /* mytar_hpp */
