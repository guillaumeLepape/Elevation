#include "elevation/utils/id.h"

#include <range/v3/algorithm/generate.hpp>

namespace elevation::utils::id {
std::string generate() {
  std::random_device rd;
  auto seed_data = std::array<int, std::mt19937::state_size>{};
  ranges::generate(seed_data, std::ref(rd));
  std::seed_seq seq(std::cbegin(seed_data), std::cend(seed_data));
  std::mt19937 generator(seq);
  uuids::uuid_random_generator gen{generator};

  return uuids::to_string(gen());
}
}  // namespace elevation::utils::id
