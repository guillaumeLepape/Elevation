#ifndef SAVE_AND_QUIT_H
#define SAVE_AND_QUIT_H

/*!
 * \file Regeneration.h
 */

#include <iostream>

#include "Action.h"

class SaveAndQuit : public Action {
 public:
  SaveAndQuit(const std::string& statement, const std::string& result)
      : Action(statement, result) {}

  void triggerAction() override {
    actionWriter_.writeResult();
    std::cout << "\n";
    exit(0);
  }
};
#endif