#pragma once

#include <fmt/color.h>

#include <filesystem>
#include <fstream>

#include "elevation/data/data.h"
#include "elevation/entity/player.h"

namespace fs = std::filesystem;

namespace data {
std::vector<std::tuple<std::string, std::string, int>>
create_load_game_statements();

void save(const std::string& id, const entity::Player& player);

nlohmann::json get_saved_data(const std::string& id);

bool is_new_game(const std::string& id);

static const auto RESULTS_PATH =
    fs::path{fmt::format("{}/.elevation/results", getenv("HOME"))};
}  // namespace data
