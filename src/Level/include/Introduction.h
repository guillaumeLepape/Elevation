#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
 * \file Introduction.h
 */

#include "Player.h"

class Introduction {
 private:
  entity::Player& player_;

 public:
  Introduction(entity::Player& player) : player_{player} {}

  Introduction(const Introduction&) = delete;
  Introduction(Introduction&&) = default;

  Introduction& operator=(const Introduction&) = delete;
  Introduction& operator=(Introduction&&) = default;

  ~Introduction() = default;

  void start();
};

#endif