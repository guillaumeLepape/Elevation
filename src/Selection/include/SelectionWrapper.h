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
int select(const Title& title, Args&... actions) {
  auto result = Select::select(title, {actions.statement()...});

  int index = 0;
  ((index++ == result ? actions.triggerAction() : nothing()), ...);
  return result;
}

template <Action Arg>
int select(const Title& title, std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result = Select::select(title, statements);
  actions[result].triggerAction();
  return result;
}
}  // namespace SelectionWrapper

#endif