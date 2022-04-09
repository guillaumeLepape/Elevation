#ifndef RESULTS_H
#define RESULTS_H

#include <fstream>

#include "data.h"
#include "player.h"

namespace data {
std::vector<std::tuple<std::string, std::string, int>>
create_load_game_statements();
void save(const std::string& id, const entity::Player& player);
nlohmann::json get_saved_data(const std::string& id);
bool is_new_game(const std::string& id);
}  // namespace data

#endif