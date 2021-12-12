#include "Id.h"

namespace utils::id {
unsigned int generate() {
  std::random_device rd;
  return rd();
}
}  // namespace utils::id