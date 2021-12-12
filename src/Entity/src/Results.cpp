/*!
 * \file Results.cpp
 */

#include "Results.h"

#include <iomanip>

namespace data {

Results::Results(entity::Player&& player)
    : data{[&player]() {
        std::vector<entity::Player> result;
        result.push_back(std::forward<decltype(player)>(player));
        return result;
      }()} {}

Results read_results(std::string&& nameFolder, std::string&& nameFile) {
  auto jsonObject =
      data::read_json_file(std::forward<decltype(nameFolder)>(nameFolder),
                           std::forward<decltype(nameFile)>(nameFile));

  Results results;

  std::transform(std::cbegin(jsonObject), std::cend(jsonObject),
                 std::back_inserter(results.data),
                 [](const auto& result) { return entity::Player{result}; });

  return results;
}

void add(Results& results, entity::Player&& player) {
  auto is_same_player = [&player](const auto& p) {
    return p.id() == player.id();
  };
  results.data.erase(std::remove_if(std::begin(results.data),
                                    std::end(results.data), is_same_player),
                     std::cend(results.data));
  results.data.push_back(std::move(player));
}

void write(const Results& results, std::string&& nameFolder,
           std::string&& nameFile) {
  std::string path = std::forward<decltype(nameFolder)>(nameFolder) + "/" +
                     std::forward<decltype(nameFile)>(nameFile) + ".json";

  // open json file
  std::ofstream jsonFile(path);

  // check if the file is opened
  assert(jsonFile.is_open());

  nlohmann::json jsonObjectOutput;

  std::for_each(std::cbegin(results.data), std::cend(results.data),
                [&jsonObjectOutput](const auto& res) {
                  nlohmann::json jsonPlayer = res.write();
                  jsonObjectOutput.push_back(jsonPlayer);
                });

  // read jsonfile
  jsonFile << std::setw(4) << jsonObjectOutput;

  jsonFile.close();
}
}  // namespace data