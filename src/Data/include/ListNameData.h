#ifndef NAME_DATA_H
#define NAME_DATA_H

#include <set>
#include <string>

namespace data {
std::set<std::string> read_list_name(std::string&& nameFolder,
                                     std::string&& nameFile);
}

#endif