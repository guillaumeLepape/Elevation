#ifndef NAME_DATA_H
#define NAME_DATA_H

#include <filesystem>
#include <set>
#include <string>

namespace fs = std::filesystem;

namespace data {
std::set<std::string> read_list_name(fs::path&& file_path);
}

#endif
