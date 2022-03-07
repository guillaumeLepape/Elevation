#include <iostream>

namespace utils {
namespace detail {
template <class T, class U>
concept SameHelper = std::is_same_v<T, U>;
}

template <class T, class U>
concept same_as = detail::SameHelper<T, U>&& detail::SameHelper<U, T>;

template <typename T>
concept Printable = requires(T t) {
  { std::cout << t }
  ->same_as<std::ostream&>;
};
}  // namespace utils