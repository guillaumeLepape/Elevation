#pragma once

#include <concepts>
#include <iostream>

namespace elevation::utils {
template <typename T>
concept Printable = requires(T t) {
  { std::cout << t } -> std::same_as<std::ostream&>;
};

template <typename T>
concept Action = requires(T action) {
  { action.statement() } -> Printable;
  { action.trigger() } -> std::same_as<void>;
};
}  // namespace elevation::utils
