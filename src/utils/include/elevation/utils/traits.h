#pragma once

#include <tuple>

#include "elevation/data_files/languages.h"
#include "elevation/utils/concept.h"

namespace utils {
template <typename>
struct is_tuple : std::false_type {};

template <typename... T>
struct is_tuple<std::tuple<T...>> : std::true_type {};

template <typename T>
static constexpr bool is_tuple_v = is_tuple<T>::value;

template <typename>
struct is_message_tuple : std::false_type {};

template <typename T, typename U>
  requires std::same_as<T, data::NameSpeaker> and utils::Printable<U>
struct is_message_tuple<std::tuple<T, U>> : std::true_type {};

template <typename T>
static constexpr bool is_message_tuple_v = is_message_tuple<T>::value;

}  // namespace utils
