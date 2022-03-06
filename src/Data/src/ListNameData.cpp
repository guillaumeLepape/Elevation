#include "ListNameData.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include "Data.h"

namespace data {
std::set<std::string> read_list_name(std::string_view&& nameFolder,
                                     std::string_view&& nameFile) {
  auto jsonObject = read_json_file(std::move(nameFolder), std::move(nameFile));

  std::set<std::string> result;

  std::for_each(std::cbegin(jsonObject), std::cend(jsonObject),
                [&result](const auto& name) {
                  result.insert(static_cast<std::string>(name));
                });
  return result;
}
}  // namespace data