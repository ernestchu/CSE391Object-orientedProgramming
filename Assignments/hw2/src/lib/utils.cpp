//
//  utils.cpp
//  hw2
//
//  Created by Ernest Chu on 2020/10/23.
//

#include "utils.h"
namespace uti {
uint64_t octal_decoder(const char* data, const int offset) {
    unsigned char *lsb_ptr = (unsigned char*) data + offset; /*move the lsb pointer to the end of data*/
    uint64_t decoded_value = 0;
    uint64_t oct_multiplier = 1;

    unsigned char *null_finder = lsb_ptr;
    while (null_finder >= (unsigned char*)data) {
        if ((*null_finder) == '\0' || (*null_finder) == ' ')
            lsb_ptr = null_finder;
        null_finder--;
    }

    /*updated lsb pointer now is pointing to the lsb of the data*/
    while (lsb_ptr >= (unsigned char*)data) {
        decoded_value += (*(lsb_ptr--) - 48) * oct_multiplier;
        oct_multiplier *= 8;
    }
    return decoded_value;
}

char* permission_decoder(const char* data, const char type) {
    static char permit[11];
    permit[10] = '\0';
    /*
     '0' | - | Normal file
     '1' | h | Hard link
     '2' | l | Symbolic link
     '3' | c | Character special
     '4' | b | Block special
     '5' | d | Directory
     '6' | p | FIFO
     '7' |   | Contiguous file
         | s | Socket link
     */
    switch (type) {
        case '1':
            permit[0] = 'h';
            break;
        case '2':
            permit[0] = 'l';
            break;
        case '3':
            permit[0] = 'c';
            break;
        case '4':
            permit[0] = 'b';
            break;
        case '5':
            permit[0] = 'd';
            break;
        case '6':
            permit[0] = 'p';
            break;

        default:
            permit[0] = '-';
            break;
    }


    for (int i = 3; i <= 5; i++) {
        int num = data[i]-48;
        permit[3*i-8] = (num&4)? 'r': '-'; /*00400*/
        permit[3*i-7] = (num&2)? 'w': '-'; /*00200*/
        permit[3*i-6] = (num&1)? 'x': '-'; /*00100*/
    }
    return permit;
}

std::string get_date(const uint64_t sec_since) {
    tm *ltm = localtime((time_t*)&sec_since);
    std::stringstream year, mon, day, hour, min;
    year << 1900+ltm->tm_year << '-';
    if (1+ltm->tm_mon >= 10)
        mon << 1+ltm->tm_mon << '-';
    else
        mon << '0' << 1+ltm->tm_mon << '-';
    if (ltm->tm_mday >= 10)
        day << ltm->tm_mday;
    else
        day << '0' << ltm->tm_mday;
    if (ltm->tm_hour >= 10)
        hour << ltm->tm_hour << ':';
    else
        hour << '0' << ltm->tm_hour << ':';
    if (ltm->tm_min >= 10)
        min << ltm->tm_min;
    else
        min << '0' << ltm->tm_min;
    std::string str_year, str_mon, str_day, str_hour, str_min;
    year >> str_year;
    mon >> str_mon;
    day >> str_day;
    hour >> str_hour;
    min >> str_min;
    return str_year + str_mon + str_day + " " + str_hour + str_min;
}
}
