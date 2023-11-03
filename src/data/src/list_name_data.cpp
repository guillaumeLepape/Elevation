#include "elevation/data/list_name_data.h"

#include <fstream>

#include "elevation/data/data.h"

namespace elevation::data {
std::set<std::string> read_list_name(fs::path&& file_path) {
  auto jsonObject = read_json_file(std::move(file_path));
  return std::set<std::string>{std::cbegin(jsonObject), std::cend(jsonObject)};
}
}  // namespace elevation::data
