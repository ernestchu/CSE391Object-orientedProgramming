//
//  mytar.cpp
//  hw2
//
//  Created by Ernest Chu on 2020/10/23.
//

#include <fstream>
#include <cstring>
#include <iomanip>
#include "lib/tar.h"
#include "lib/utils.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./mytar [filename]\n";
        exit(EXIT_FAILURE);
    }
    Tar tar;
    tar.read_file(argv);
    tar.list_files();
    return 0;
}
