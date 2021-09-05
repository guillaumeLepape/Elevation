/*!
 * \file Quit.cpp
 */

#include "Quit.h"

#include <iostream>

Quit::Quit(const Statement& statement, const Result& result)
    : statement_(statement), result_(result) {}

void Quit::triggerAction() {
  Action::writeResult(result_);
  std::cout << "\n";
}