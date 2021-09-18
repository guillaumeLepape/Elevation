#ifndef DEAD_H
#define DEAD_H

/*!
 * \file Dead.h
 */

#include "NameType.h"

// forward declaration of Plug class
class Plug;

class Dead {
 private:
  // ActionWriter actionWriter_;
  Result result_;
  const Plug& plug_;

 public:
  Dead(const Plug& plug, const Result& result);

  void triggerAction();
};

#endif