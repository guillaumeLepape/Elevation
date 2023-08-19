#include "list_name_data.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <range/v3/iterator.hpp>

#include "data.h"

namespace data {
std::set<std::string> read_list_name(std::string_view&& nameFolder,
                                     std::string_view&& nameFile) {
  auto jsonObject = read_json_file(std::move(nameFolder), std::move(nameFile));
  return std::set<std::string>{ranges::cbegin(jsonObject),
                               ranges::cend(jsonObject)};
}
}  // namespace data