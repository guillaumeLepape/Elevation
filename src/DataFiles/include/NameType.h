#ifndef NAME_TYPE_H
#define NAME_TYPE_H

#include <string>
#include <tuple>
#include <utility>
#include <vector>

template <typename T, typename Parameter>
class NamedType {
 public:
  constexpr explicit NamedType(T const& value) noexcept : value_(value) {}
  constexpr explicit NamedType(T&& value) noexcept : value_(std::move(value)) {}
  T& get() noexcept { return value_; }
  T const& get() const noexcept { return value_; }

 private:
  T value_;
};

struct HourParameter {};
using Hour = NamedType<unsigned, struct HourParameter>;

struct MinutParameter {};
using Minut = NamedType<unsigned, struct MinutParameter>;

struct StatementParameter {};
using Statement = NamedType<std::string, struct StatementParameter>;

struct ResultParameter {};
using Result = NamedType<std::string, struct ResultParameter>;

struct TitleParameter {};
using Title = NamedType<std::string_view, struct TitleParameter>;

enum class NameSpeaker { player = 0, plug, description, action };
using Message_t = std::vector<std::tuple<NameSpeaker, std::string>>;

#endif