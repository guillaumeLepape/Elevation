#include "Data.h"

#include <fmt/color.h>

#include <fstream>

namespace data {
nlohmann::json read_json_file(std::string_view&& folder,
                              std::string_view&& file_name) {
  auto path =
      fmt::format("{}/{}.json", std::move(folder), std::move(file_name));

  // open json file
  std::ifstream messageFile{path, std::ifstream::binary};

  // check if the file is opened
  assert(messageFile.is_open());

  // read jsonfile
  nlohmann::json jsonObject;
  messageFile >> jsonObject;

  messageFile.close();

  return jsonObject;
}
}  // namespace data
