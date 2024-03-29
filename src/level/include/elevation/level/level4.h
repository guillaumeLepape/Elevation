#pragma once

#include "elevation/action/answer.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/selection/question.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::level4 {
void start(entity::Player& player) {
  entity::Plug plug{"Freeze Corleone", 20};

  header::write(data::level4::nameLevel, data::level4::hour,
                data::level4::minut);

  auto message = data::level4::message0(player.pseudo());
  message::write(message, player.pseudo(), plug.name());

  // first question
  action::Answer answer0_0{data::question::answer1Question1,
                           data::question::correctOrNotAnswer1Question1};
  action::Answer answer1_0{data::question::answer2Question1,
                           data::question::correctOrNotAnswer2Question1};
  action::Answer answer2_0{data::question::answer3Question1,
                           data::question::correctOrNotAnswer3Question1};

  message::write(data::level4::message2, player.pseudo(), plug.name());

  while (not selection::question(
      data::question::titleFirstQuestion,
      std::vector{answer0_0.statement(), answer1_0.statement(),
                  answer2_0.statement()},
      std::vector{answer0_0.correctOrNot(), answer1_0.correctOrNot(),
                  answer2_0.correctOrNot()})) {
    message::write(data::level4::message1, player.pseudo(), plug.name());
  }

  message::write(data::level4::message2, player.pseudo(), plug.name());

  // second question
  action::Answer answer0_1{data::question::answer1Question2,
                           data::question::correctOrNotAnswer1Question2};
  action::Answer answer1_1{data::question::answer2Question2,
                           data::question::correctOrNotAnswer2Question2};
  action::Answer answer2_1{data::question::answer3Question2,
                           data::question::correctOrNotAnswer3Question2};

  while (not selection::question(
      data::question::titleSecondQuestion,
      std::vector{answer0_1.statement(), answer1_1.statement(),
                  answer2_1.statement()},
      std::vector{answer0_1.correctOrNot(), answer1_1.correctOrNot(),
                  answer2_1.correctOrNot()})) {
    message::write(data::level4::message1, player.pseudo(), plug.name());
  }

  message::write(data::level4::message2, player.pseudo(), plug.name());

  // third question
  action::Answer answer0_2{data::question::answer1Question3,
                           data::question::correctOrNotAnswer1Question3};
  action::Answer answer1_2{data::question::answer2Question3,
                           data::question::correctOrNotAnswer2Question3};
  action::Answer answer2_2{data::question::answer3Question3,
                           data::question::correctOrNotAnswer3Question3};

  while (not selection::question(
      data::question::titleThirdQuestion,
      std::vector{answer0_2.statement(), answer1_2.statement(),
                  answer2_2.statement()},
      std::vector{answer0_2.correctOrNot(), answer1_2.correctOrNot(),
                  answer2_2.correctOrNot()})) {
    message::write(data::level4::message1, player.pseudo(), plug.name());
  }

  message::write(data::level4::message2, player.pseudo(), plug.name());
}
}  // namespace elevation::level4
