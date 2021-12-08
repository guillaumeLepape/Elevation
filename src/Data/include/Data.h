#ifndef DATA_H
#define DATA_H

/*!
 * \file Data.h
 */

#include <nlohmann/json.hpp>

namespace data {
nlohmann::json read_json_file(std::string&& folderFromRoot,
                              std::string&& fileName);
}

#endif