#ifndef SELECTION_WRAPPER
#define SELECTION_WRAPPER

#include <string_view>
#include <tuple>

namespace SelectionWrapper {
template <typename T>
concept bool Action = requires(T& action) {
  action.statement();
  action.triggerAction();
};

void nothing() {}

template <Action... Args>
void select(const Title& title, Args&... actions) {
  auto result = Select::select(title, {actions.statement()...});

  int index = 0;
  ((index++ == result ? actions.triggerAction() : nothing()), ...);
}
}  // namespace SelectionWrapper

#endif