#ifndef SELECTION_WRAPPER
#define SELECTION_WRAPPER

#include <string_view>
#include <tuple>

#include "NameType.h"
#include "Selection.h"

namespace SelectionWrapper {
template <typename T>
concept bool Action = requires(T& action) {
  action.statement();
  action.triggerAction();
};

void nothing();

template <Action... Args>
std::size_t select(const Title& title, Args&... actions) {
  auto result = Selection::select(title, {actions.statement()...});

  std::size_t index = 0;
  ((index++ == result ? actions.triggerAction() : nothing()), ...);
  return result;
}

template <Action Arg>
std::size_t select(const Title& title, std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result = Selection::select(title, statements);
  actions[result].triggerAction();
  return result;
}
}  // namespace SelectionWrapper

#endif