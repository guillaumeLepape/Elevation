#include "results.h"

#include <fmt/color.h>

#include <filesystem>
#include <iomanip>
#include <iostream>

namespace fs = std::filesystem;

namespace data {
std::vector<std::tuple<std::string, std::string, int>>
create_load_game_statements() {
  const fs::path results_path{"results"};

  std::vector<std::tuple<std::string, std::string, int>> vec;

  for (const auto& dir_entry : fs::directory_iterator{results_path}) {
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

  std::string path = fmt::format("{}/{}.json", "results", id);

  std::ofstream file{path};
  file.clear();
  file << std::setw(4) << json;
  file.close();
}

nlohmann::json get_saved_data(const std::string& id) {
  return data::read_json_file(fmt::format("results/{}.json", id));
}

bool is_new_game(const std::string& id) {
  return not fs::exists(fmt::format("results/{}.json", id));
}
}  // namespace data
