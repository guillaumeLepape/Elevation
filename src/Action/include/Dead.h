#ifndef DEAD_H
#define DEAD_H

/*!
 * \file Dead.h
 */

#include "ActionWriter.h"
#include "NameType.h"

// forward declaration of Plug class
class Plug;

class Dead {
 private:
  ActionWriter actionWriter_;

  const Plug* const plug_;

 public:
  Dead(const Plug* const plug, const Result& result);

  void triggerAction();
};

#endif