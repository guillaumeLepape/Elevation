#ifndef RESULTS_H
#define RESULTS_H

#include <fstream>

#include "Data.h"
#include "Player.h"

namespace data {
std::vector<std::tuple<unsigned, std::string, int>>
create_load_game_statements();
void save(const unsigned id, const entity::Player& player);
nlohmann::json get_saved_data(unsigned id);
bool is_new_game(unsigned id);
}  // namespace data

#endif