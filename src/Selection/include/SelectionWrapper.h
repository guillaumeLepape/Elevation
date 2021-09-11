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
void select(const Title& title, Args&... actions) {
  auto result = Select::select(title, {actions.statement()...});

  int index = 0;
  ((index++ == result ? actions.triggerAction() : nothing()), ...);
}

template <Action Arg>
void select(const Title& title, const std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result = Select::select(title, statements);
  actions[result].triggerAction();
}
}  // namespace SelectionWrapper

#endif