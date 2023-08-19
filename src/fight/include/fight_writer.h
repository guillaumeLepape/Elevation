#ifndef FIGHT_WRITER_H
#define FIGHT_WRITER_H

#include "player.h"
#include "plug.h"

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

#endif
