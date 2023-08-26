#include "list_name_data.h"

#include <fstream>

#include "data.h"

namespace data {
std::set<std::string> read_list_name(fs::path&& file_path) {
  auto jsonObject = read_json_file(std::move(file_path));
  return std::set<std::string>{std::cbegin(jsonObject), std::cend(jsonObject)};
}
}  // namespace data
