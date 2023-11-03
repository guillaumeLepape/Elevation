#pragma once

namespace elevation::utils {
template <class Tuple, class F>
constexpr auto for_each(Tuple&& tuple, F&& f) {
  return []<std::size_t... I>(Tuple&& tuple, F&& f, std::index_sequence<I...>) {
    (f(std::get<I>(tuple)), ...);
    return f;
  }(std::forward<Tuple>(tuple), std::forward<F>(f),
         std::make_index_sequence<
             std::tuple_size<std::remove_reference_t<Tuple>>::value>{});
}
}  // namespace elevation::utils
