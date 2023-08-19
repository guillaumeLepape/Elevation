#ifndef NAME_DATA_H
#define NAME_DATA_H

#include <set>
#include <string>

namespace data {
std::set<std::string> read_list_name(std::string_view&& nameFolder,
                                     std::string_view&& nameFile);
}

#endif
