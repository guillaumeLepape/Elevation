#ifndef OUTRO_H
#define OUTRO_H

#include "Player.h"

class Outro {
 private:
  entity::Player& player_;

 public:
  Outro(entity::Player& player) : player_{player} {}

  Outro(const Outro&) = delete;
  Outro(Outro&&) = default;

  Outro& operator=(const Outro&) = delete;
  Outro& operator=(Outro&&) = default;

  ~Outro() = default;

  void start();
};

#endif