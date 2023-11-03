#pragma once

#include <fmt/color.h>

#include <fstream>
#include <nlohmann/json.hpp>

#include "elevation/utils/concept.h"

namespace elevation::data {
template <utils::Printable T>
nlohmann::json read_json_file(T&& path) {
  // open json file
  std::ifstream messageFile{std::forward<T>(path), std::ifstream::binary};

  // check if the file is opened
  assert(messageFile.is_open());

  // read jsonfile
  nlohmann::json jsonObject;
  messageFile >> jsonObject;

  messageFile.close();

  return jsonObject;
}
}  // namespace elevation::data
