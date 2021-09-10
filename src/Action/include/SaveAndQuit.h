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
  Statement statement_;
  Result result_;

 public:
  SaveAndQuit(const Statement& statement, const Result& result)
      : statement_(statement), result_(result) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {
    Action::writeResult(result_);
    std::cout << "\n";
    exit(0);
  }
};
#endif