#pragma once

#include <fmt/color.h>

#include <range/v3/range/traits.hpp>
#include <string>

#include "elevation/data_files/languages.h"
#include "elevation/utils/concept.h"
#include "elevation/utils/pause.h"
#include "elevation/utils/traits.h"
#include "elevation/utils/tuple.h"

namespace elevation {
struct MessageWriter {
  data::Message_t messages_;
  std::string pseudo_;
  std::string plugName_;

  MessageWriter(const data::Message_t& messages, const std::string& pseudo,
                const std::string& plugName)
      : messages_{messages}, pseudo_{pseudo}, plugName_{plugName} {}
};

namespace message {
template <typename T, typename U, typename V>
  requires utils::is_message_tuple_v<std::remove_cvref_t<T>> and
           utils::Printable<U> and utils::Printable<V>
void write_one_message(T&& message, U&& pseudo, V&& plugName) {
  switch (std::get<0>(std::forward<T>(message))) {
    case data::NameSpeaker::player:
      fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "\n {}",
                 std::forward<U>(pseudo));
      fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(std::forward<T>(message)));
      break;

    case data::NameSpeaker::plug:
      fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "\n        {}",
                 std::forward<V>(plugName));
      fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(std::forward<T>(message)));
      break;

    case data::NameSpeaker::description:
      fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(std::forward<T>(message)));
      break;

    case data::NameSpeaker::action:
      fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(std::forward<T>(message)));
      break;
  }  // namespace message
}

template <typename T, typename U, typename V>
  requires utils::is_message_tuple_v<ranges::range_value_t<T>> and
           utils::Printable<U> and utils::Printable<V>
void write(T&& messages, U&& pseudo, V&& plugName) {
  for (auto&& message : std::forward<T>(messages)) {
    utils::pause();

    write_one_message(message, std::forward<U>(pseudo),
                      std::forward<V>(plugName));
  }
}

template <typename T, typename U, typename V>
  requires utils::is_tuple_v<std::remove_cvref_t<T>> and utils::Printable<U> and
           utils::Printable<V>
void write(T&& messages, U&& pseudo, V&& plugName) {
  utils::for_each(std::forward<T>(messages),
                  [&pseudo, &plugName](auto&& message) {
                    utils::pause();
                    write_one_message(message, std::forward<U>(pseudo),
                                      std::forward<V>(plugName));
                  });
}

void write(const MessageWriter& message);
}  // namespace message
}  // namespace elevation
