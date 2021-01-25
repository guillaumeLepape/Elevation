/*!
    * \file Level4.cpp
*/

#include "Level4.h"

#include <iostream>

#include "Question.h"

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Plug.h"

#include "Languages.h"

void Level4::startLevel( const Options& options )
{
    Plug plug( "Freeze Corleone", 20 );

    HeaderWriter headerWriter( 
        data::Level4::nameLevel,
        data::Level4::hour,
        data::Level4::minut
    );
    headerWriter.writeHeader();

    auto message = data::Level4::message0( player_->name() );
    MessageWriter messageWriter0( message, player_->name(), plug.name() );
    messageWriter0.writeMessage();

    // first question
    Answer answer0_0( 
        data::Question::answer1Question1, 
        "",
        data::Question::correctOrNotAnswer1Question1
    ); 
    Answer answer1_0
    ( 
        data::Question::answer2Question1,
        "",
        data::Question::correctOrNotAnswer2Question1
    );   
    Answer answer2_0
    (
        data::Question::answer3Question1,
        "",
        data::Question::correctOrNotAnswer3Question1
    );

    MessageWriter messageWriter1( data::Level4::message1, player_->name(), plug.name() );
    MessageWriter messageWriter2( data::Level4::message2, player_->name(), plug.name() );

    while
    ( 
        !Question::question
        ( 
            { &answer0_0, &answer1_0, &answer2_0 }, 
            data::Question::titleFirstQuestion 
        ) 
    )
    {
        messageWriter1.writeMessage();
    }

    messageWriter2.writeMessage();

    // second question
    Answer answer0_1
    ( 
        data::Question::answer1Question2,
        "",
        data::Question::correctOrNotAnswer1Question2
    );
    Answer answer1_1
    ( 
        data::Question::answer2Question2,
        "",
        data::Question::correctOrNotAnswer2Question2
    );
    Answer answer2_1
    ( 
        data::Question::answer3Question2,
        "",
        data::Question::correctOrNotAnswer3Question2
    );

    while
    ( 
        !Question::question
        ( 
            { &answer0_1, &answer1_1, &answer2_1 }, 
            data::Question::titleSecondQuestion 
        ) 
    )
    {
        messageWriter1.writeMessage();
    }

    messageWriter2.writeMessage();

    // third question
    Answer answer0_2
    ( 
        data::Question::answer1Question3,
        "",
        data::Question::correctOrNotAnswer1Question3
    );
    Answer answer1_2
    ( 
        data::Question::answer2Question3,
        "",
        data::Question::correctOrNotAnswer2Question3
    );
    Answer answer2_2
    ( 
        data::Question::answer3Question3,
        "",
        data::Question::correctOrNotAnswer3Question3
    );

    while
    ( 
        !Question::question
        ( 
            { &answer0_2, &answer1_2, &answer2_2 }, 
            data::Question::titleThirdQuestion 
        ) 
    )
    {}

    messageWriter2.writeMessage();

    Level::endOfLevel();

    std::cout << "\n";
}