/*!
 * \file Quit.cpp
 */

#include "Quit.h"

#include <iostream>

Quit::Quit(const Statement& statement, const Result& result)
    : statement_(statement), actionWriter_(statement_.get(), result.get()) {}

void Quit::triggerAction() {
  actionWriter_.writeResult();
  std::cout << "\n";
}