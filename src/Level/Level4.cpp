/*!
    * \file Level4.cpp
*/

#include "Level4.h"

#include "Question.h"

#include "HeaderWriter.h"

void Level4::startLevel( const Options& options )
{
    Plug plug( "Freeze Corleone", 20 );

    HeaderWriter headerWriter( 
        data::Level4::nameLevel,
        data::Level4::hour,
        data::Level4::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( data::Level4::messages );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    // first question
    Answer answer0_0( 
        messageHandler, 1, 
        data::Question::answer1Question1, 
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer1Question1
    ); 
    Answer answer1_0
    ( 
        messageHandler, 1, 
        data::Question::answer2Question1,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer2Question1
    );   
    Answer answer2_0
    (
        messageHandler, 2, 
        data::Question::answer3Question1,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer3Question1
    );

    while
    ( 
        !Question::question
        ( 
            { &answer0_0, &answer1_0, &answer2_0 }, 
            data::Question::titleFirstQuestion 
        ) 
    )
    {}

    // second question
    Answer answer0_1
    ( 
        messageHandler, 1, 
        data::Question::answer1Question2,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer1Question2
    );
    Answer answer1_1
    ( 
        messageHandler, 1, 
        data::Question::answer2Question2,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer2Question2
    );
    Answer answer2_1
    ( 
        messageHandler, 2, 
        data::Question::answer3Question2,
        std::tuple<bool, std::string>(),
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
    {}

    // third question
    Answer answer0_2
    ( 
        messageHandler, 3, 
        data::Question::answer1Question3,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer1Question3
    );
    Answer answer1_2
    ( 
        messageHandler, 3, 
        data::Question::answer2Question3,
        std::tuple<bool, std::string>(),
        data::Question::correctOrNotAnswer2Question3
    );
    Answer answer2_2
    ( 
        messageHandler, 3, 
        data::Question::answer3Question3,
        std::tuple<bool, std::string>(),
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

    Level::endOfLevel();

    std::cout << "\n";
}