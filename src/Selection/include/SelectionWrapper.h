#ifndef SELECTION_WRAPPER
#define SELECTION_WRAPPER

#include <string_view>
#include <tuple>

#include "NameType.h"
#include "Selection.h"

namespace selection {
template <typename T>
concept bool Action = requires(T& action) {
  { action.statement() }
  ->const std::string&;
  { action.trigger() }
  ->void;
};

template <Action... Args>
std::size_t select(const Title& title, Args&... actions) {
  auto result = selection::select(title, {actions.statement()...});

  std::size_t index = 0;
  ((index++ == result ? actions.trigger() : []() {}()), ...);
  return result;
}

template <Action Arg>
std::size_t select(const Title& title, std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result = selection::select(title, statements);
  actions[result].trigger();
  return result;
}
}  // namespace selection

#endif