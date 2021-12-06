/*!
 * \file ListNameData.cpp
 */

#include "ListNameData.h"

#include <cassert>
#include <fstream>
#include <nlohmann/json.hpp>

namespace data {
std::set<std::string> read_list_name(const std::string& nameFolder,
                                     const std::string& nameFile) {
  std::string path = nameFolder + "/" + nameFile + ".json";

  std::ifstream messageFile(path, std::ifstream::binary);

  assert(messageFile.is_open());

  nlohmann::json jsonObject;
  messageFile >> jsonObject;

  messageFile.close();

  std::set<std::string> result;

  std::for_each(std::cbegin(jsonObject), std::cend(jsonObject),
                [&result](const auto& name) {
                  result.insert(static_cast<std::string>(name));
                });
  return result;
}
}  // namespace data