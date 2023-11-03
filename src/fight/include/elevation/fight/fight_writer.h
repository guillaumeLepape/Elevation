#pragma once

#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"

namespace fight {
namespace start {
void write();
}

namespace separator {
void write();
}

namespace header {
void write(const int nbTurns);
}  // namespace header

namespace game_board {
void write(const entity::Player& player,
           const std::vector<entity::Plug*>& plugs);
}

namespace remove_dead_body {
void write();
}

namespace end {
void write();
}
}  // namespace fight
