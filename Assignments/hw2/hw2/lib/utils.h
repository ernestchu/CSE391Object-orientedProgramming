//
//  utils.hpp
//  hw2
//
//  Created by Ernest Chu on 2020/10/23.
//

#ifndef utils_hpp
#define utils_hpp
#include <cstdint>
#include <ctime>
#include <sstream>
#include <string>
namespace uti {
uint64_t octal_decoder(const char* data, const int offset);
char* permission_decoder(const char* data, const char type);
std::string get_date(const uint64_t sec_since);
}
#endif /* utils_hpp */
