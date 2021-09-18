#include "Id.h"

namespace Id {
unsigned int generate() {
  std::random_device rd;
  return rd();
}
}  // namespace Id