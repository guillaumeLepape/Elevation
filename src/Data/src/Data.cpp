#include "Data.h"

#include <fmt/color.h>

#include <fstream>

namespace data {
nlohmann::json read_json_file(std::string_view&& folder,
                              std::string_view&& file_name) {
  auto path =
      fmt::format("{}/{}.json", std::move(folder), std::move(file_name));

  return read_json_file(std::move(path));
}

nlohmann::json read_json_file(std::string&& path) {
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
}  // namespace data
