#include "elevation/utils/pause.h"

#include <atomic>
#include <iostream>

namespace elevation::utils {
std::atomic_bool keep_running{true};

void pause() {
  while (keep_running) {
    if (std::cin.get() == 10) {
      keep_running = false;
    }
  }
  keep_running = true;
  return;
}
}  // namespace elevation::utils
