#ifndef ID_H
#define ID_H

#include <uuid.h>

namespace utils::id {
auto generate() {
  std::random_device rd;
  auto seed_data = std::array<int, std::mt19937::state_size>{};
  std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
  std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
  std::mt19937 generator(seq);
  uuids::uuid_random_generator gen{generator};

  return uuids::to_string(gen());
}
}  // namespace utils::id

#endif
