#include "elevation/utils/pause.h"

#include <atomic>

namespace elevation::utils {
std::atomic_bool keep_running{true};

void pause(std::istream& in) {
  while (keep_running) {
    if (in.get() == 10) {
      keep_running = false;
    }
  }
  keep_running = true;
  return;
}
}  // namespace elevation::utils
