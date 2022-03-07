#ifndef FIGHT_WRITER_H
#define FIGHT_WRITER_H

#include "Player.h"
#include "Plug.h"

class FightWriter {
 private:
  const entity::Player& player_;
  const std::vector<entity::Plug*>& plugs_;

  void writeSeparator() const;

 public:
  FightWriter(const entity::Player& player,
              const std::vector<entity::Plug*>& plugs);

  void writeHeader(const int nbTurns) const;
  void writeGameBoard() const;
  void writeRemoveDeadBody();
  void writeEndOfFight() const;
};

#endif