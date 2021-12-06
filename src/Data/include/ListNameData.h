#ifndef NAME_DATA_H
#define NAME_DATA_H

/*!
 * \file ListNameData.h
 */

#include <set>
#include <string>

namespace data {
std::set<std::string> read_list_name(const std::string& nameFolder,
                                     const std::string& nameFile);
}

#endif