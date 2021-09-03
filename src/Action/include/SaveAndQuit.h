#ifndef SAVE_AND_QUIT_H
#define SAVE_AND_QUIT_H

/*!
 * \file SaveAndQuit.h
 */

#include <iostream>

#include "ActionWriter.h"
#include "NameType.h"

class SaveAndQuit {
 private:
  const Statement& statement_;

  ActionWriter actionWriter_;

 public:
  SaveAndQuit(const Statement& statement, const Result& result)
      : statement_(statement), actionWriter_(statement.get(), result.get()) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {
    actionWriter_.writeResult();
    std::cout << "\n";
    exit(0);
  }
};
#endif