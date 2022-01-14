#include "Data.h"

#include <fstream>

namespace data {
nlohmann::json read_json_file(std::string&& folderFromRoot,
                              std::string&& fileName) {
  std::string path = std::forward<decltype(folderFromRoot)>(folderFromRoot) +
                     "/" + std::forward<decltype(fileName)>(fileName) + ".json";

  // open json file
  std::ifstream messageFile(path, std::ifstream::binary);

  // check if the file is opened
  assert(messageFile.is_open());

  // read jsonfile
  nlohmann::json jsonObject;
  messageFile >> jsonObject;

  messageFile.close();

  return jsonObject;
}
}  // namespace data
