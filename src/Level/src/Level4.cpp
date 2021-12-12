/*!
 * \file Level4.cpp
 */

#include "Level4.h"

#include <iostream>

#include "Answer.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "Question.h"

void Level4::startLevel() {
  entity::Plug plug("Freeze Corleone", 20);

  Header::write(data::Level4::nameLevel, data::Level4::hour,
                data::Level4::minut);

  auto message = data::Level4::message0(player_.pseudo());
  Message::write(message, player_.pseudo(), plug.name());

  // first question
  action::Answer answer0_0(data::Question::answer1Question1,
                           data::Question::correctOrNotAnswer1Question1);
  action::Answer answer1_0(data::Question::answer2Question1,
                           data::Question::correctOrNotAnswer2Question1);
  action::Answer answer2_0(data::Question::answer3Question1,
                           data::Question::correctOrNotAnswer3Question1);

  Message::write(data::Level4::message2, player_.pseudo(), plug.name());

  while (!Question::question(
      data::Question::titleFirstQuestion,
      {answer0_0.statement(), answer1_0.statement(), answer2_0.statement()},
      {answer0_0.correctOrNot(), answer1_0.correctOrNot(),
       answer2_0.correctOrNot()})) {
    Message::write(data::Level4::message1, player_.pseudo(), plug.name());
  }

  Message::write(data::Level4::message2, player_.pseudo(), plug.name());

  // second question
  action::Answer answer0_1(data::Question::answer1Question2,
                           data::Question::correctOrNotAnswer1Question2);
  action::Answer answer1_1(data::Question::answer2Question2,
                           data::Question::correctOrNotAnswer2Question2);
  action::Answer answer2_1(data::Question::answer3Question2,
                           data::Question::correctOrNotAnswer3Question2);

  while (!Question::question(
      data::Question::titleSecondQuestion,
      {answer0_1.statement(), answer1_1.statement(), answer2_1.statement()},
      {answer0_1.correctOrNot(), answer1_1.correctOrNot(),
       answer2_1.correctOrNot()})) {
    Message::write(data::Level4::message1, player_.pseudo(), plug.name());
  }

  Message::write(data::Level4::message2, player_.pseudo(), plug.name());

  // third question
  action::Answer answer0_2(data::Question::answer1Question3,
                           data::Question::correctOrNotAnswer1Question3);
  action::Answer answer1_2(data::Question::answer2Question3,
                           data::Question::correctOrNotAnswer2Question3);
  action::Answer answer2_2(data::Question::answer3Question3,
                           data::Question::correctOrNotAnswer3Question3);

  while (!Question::question(
      data::Question::titleThirdQuestion,
      {answer0_2.statement(), answer1_2.statement(), answer2_2.statement()},
      {answer0_2.correctOrNot(), answer1_2.correctOrNot(),
       answer2_2.correctOrNot()})) {
    Message::write(data::Level4::message1, player_.pseudo(), plug.name());
  }

  Message::write(data::Level4::message2, player_.pseudo(), plug.name());

  Level::endOfLevel();

  std::cout << "\n";
}