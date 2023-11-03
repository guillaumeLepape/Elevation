#include "elevation/entity/results.h"

#include <iomanip>
#include <iostream>

namespace elevation::data {
std::vector<std::tuple<std::string, std::string, int>>
create_load_game_statements() {
  fs::create_directories(RESULTS_PATH);

  std::vector<std::tuple<std::string, std::string, int>> vec;

  for (const auto& dir_entry : fs::directory_iterator{RESULTS_PATH}) {
    if (dir_entry.is_regular_file() and
        dir_entry.path().extension() == ".json") {
      const auto jsonObject = data::read_json_file(dir_entry.path());

      vec.push_back(std::tuple{jsonObject["game_id"],
                               jsonObject["player"]["pseudo"],
                               jsonObject["player"]["nb_level_suceeded"]});
    }
  }

  return vec;
}

void save(const std::string& id, const entity::Player& player) {
  nlohmann::json json{{"game_id", id}, {"player", player.write()}};

  fs::path path = RESULTS_PATH / fmt::format("{}.json", id);

  std::ofstream file{path};
  file.clear();
  file << std::setw(4) << json;
  file.close();
}

nlohmann::json get_saved_data(const std::string& id) {
  return data::read_json_file(RESULTS_PATH / fmt::format("{}.json", id));
}

bool is_new_game(const std::string& id) {
  return not fs::exists(RESULTS_PATH / fmt::format("{}.json", id));
}
}  // namespace elevation::data
