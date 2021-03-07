//
//  tar.cpp
//  hw2
//
//  Created by Ernest Chu on 2020/10/23.
//

#include "tar.h"
//#include <iostream>

void Tar::read_file(const char** argv) {
    std::ifstream is;
    is.open(argv[1]);

    if (!is.good()) {
        std::cout << argv[0]+2 << ": " << argv[1] <<": Cannot open: No such file or directory.\n"
        << argv[0]+2 << ": Error is not recoverable: exiting now.\n";
        exit(EXIT_FAILURE);
    }


    char zero_block[BLOCK_SIZE];
    memset(zero_block, 0, BLOCK_SIZE);
    bool entered_zero_block = false;
    while (is) {
        TarHeader header;
        is.read((char*)&header, BLOCK_SIZE);


        if (!memcmp(&header, zero_block, BLOCK_SIZE)) { /*check if read the ending zero block*/
            if (entered_zero_block) /*break if entered zero block twice*/
                break;
            else {
                entered_zero_block = true;
                continue;
            }
        }
        char ustar[5] = {'u', 's', 't', 'a', 'r'};
        if (memcmp(header.USTAR_id, ustar, 5)) {
            std::cout << argv[0] << ": Damaged tar archive\n" << argv[0] << ": Error exit delayed from previous errors.\n";
            exit(EXIT_FAILURE);
        }

//        header.filesize[11] = header.mtime[11] = '\0';
        headers.push_back(header);
        num_files++;
        uint64_t file_size = uti::octal_decoder(header.filesize, 10);
        uint64_t num_content_blocks = (file_size%BLOCK_SIZE)? file_size/BLOCK_SIZE+1: file_size/BLOCK_SIZE;
        is.seekg(num_content_blocks*BLOCK_SIZE, is.cur); /*set the cursor to the next header*/

//        std::cout
//        << "filename: " << header.filename << std::endl
//        << "filemode: " << header.filemode << std::endl
//        << "userid: " << header.userid << std::endl
//        << "groupid: " << header.groupid << std::endl
//        << "filesize: " << header.filesize << std::endl
//        << "mtime: " << header.mtime << std::endl
//        << "checksum: " << header.checksum << std::endl
//        << "type: " << header.type << std::endl
//        << "lname: " << header.lname << std::endl
//        /* USTAR Section */
//        << "USTAR_id: " << header.USTAR_id << std::endl
//        << "USTAR_ver: " << header.USTAR_ver << std::endl
//        << "username: " << header.username << std::endl
//        << "groupname: " << header.groupname << std::endl
//        << "devmajor: " << header.devmajor << std::endl
//        << "devminor: " << header.devminor << std::endl
//        << "prefix: " << header.prefix << std::endl
//        << "pad: " << header.pad << std::endl << std::endl;
    }
    is.close();
}
void Tar::list_files() {
    for (auto header : headers) {
        if (header.type == 'x') /*skipping extended header*/
            continue;
        std::cout
        << uti::permission_decoder(header.filemode, header.type) << ' '
        << header.username << '/'
        << header.groupname << ' '
        << std::setw(INDENT_WIDTH) << std::setiosflags(std::ios::right) << uti::octal_decoder(header.filesize, 10) << ' '
        << uti::get_date(uti::octal_decoder(header.mtime, 10)) << ' '
        << header.filename;
        if (header.type == '1' || header.type == '2')
            std::cout << " -> " << header.lname;
        std::cout<< std::endl;
    }
}
