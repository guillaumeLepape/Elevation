#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

#include <fmt/color.h>

#include <concepts>
#include <string_view>

#include "concept.h"
#include "pause.h"
#include "utils_writer.h"

namespace header {
template <utils::Printable T, typename U, typename V>
  requires std::unsigned_integral<std::remove_cvref_t<U>> and
           std::unsigned_integral<std::remove_cvref_t<V>>
void write(T&& name_level, U&& hour, V&& minut) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::red) | fmt::emphasis::bold,
             std::forward<T>(name_level));

  utils::writeSeparators();

  fmt::print(fmt::emphasis::bold, "\n {:0>2}h{:0>2}", std::forward<U>(hour),
             std::forward<V>(minut));

  utils::writeSeparators();
}
}  // namespace header

#endif
