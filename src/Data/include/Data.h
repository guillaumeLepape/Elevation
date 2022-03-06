#ifndef DATA_H
#define DATA_H

#include <nlohmann/json.hpp>

namespace data {
nlohmann::json read_json_file(std::string_view&& folder,
                              std::string_view&& file_name);
}

#endif