#ifndef DATA_H
#define DATA_H

#include <fmt/color.h>

#include <fstream>
#include <nlohmann/json.hpp>

#include "concept.h"

namespace data {
template <utils::Printable T> nlohmann::json read_json_file(T&& path) {
  // open json file
  std::ifstream messageFile{std::move(path), std::ifstream::binary};

  // check if the file is opened
  assert(messageFile.is_open());

  // read jsonfile
  nlohmann::json jsonObject;
  messageFile >> jsonObject;

  messageFile.close();

  return jsonObject;
}

template <utils::Printable T, utils::Printable U>
nlohmann::json read_json_file(T&& folder, U&& file_name) {
  auto path = fmt::format("{}/{}.json", std::forward<T>(folder),
                          std::forward<U>(file_name));

  return read_json_file(path);
}
}  // namespace data

#endif