/*!
    * \file Level4.cpp
*/

#include "Level4.h"

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
    std::unique_ptr<Answer> answer0_0
    ( 
        new Answer
        ( 
            messageHandler, 
            1,  
            data::Question::answer1Question1,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer1Question1
        ) 
    );
    std::unique_ptr<Answer> answer1_0
    ( 
        new Answer
        (
            messageHandler, 
            1, 
            data::Question::answer2Question1,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer2Question1
        )   
    );
    std::unique_ptr<Answer> answer2_0
    ( 
        new Answer
        (
            messageHandler, 
            2, 
            data::Question::answer3Question1,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer3Question1
        )   
    );

    while
    ( 
        !Question::question
        ( 
            { answer0_0.get(), answer1_0.get(), answer2_0.get() }, 
            data::Question::titleFirstQuestion 
        ) 
    )
    {}

    // second question
    std::unique_ptr<Answer> answer0_1
    ( 
        new Answer
        ( 
            messageHandler, 
            1, 
            data::Question::answer1Question2,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer1Question2
        ) 
    );
    std::unique_ptr<Answer> answer1_1
    ( 
        new Answer
        ( 
            messageHandler, 
            1, 
            data::Question::answer2Question2,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer2Question2
        ) 
    );
    std::unique_ptr<Answer> answer2_1
    ( 
        new Answer
        ( 
            messageHandler, 
            2, 
            data::Question::answer3Question2,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer3Question2
        ) 
    );

    while
    ( 
        !Question::question
        ( 
            { answer0_1.get(), answer1_1.get(), answer2_1.get() }, 
            data::Question::titleSecondQuestion 
        ) 
    )
    {}

    // third question
    std::unique_ptr<Answer> answer0_2
    ( 
        new Answer
        ( 
            messageHandler, 
            3, 
            data::Question::answer1Question3,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer1Question3
        ) 
    );
    std::unique_ptr<Answer> answer1_2
    ( 
        new Answer
        ( 
            messageHandler, 
            3, 
            data::Question::answer2Question3,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer2Question3
        ) 
    );
    std::unique_ptr<Answer> answer2_2
    ( 
        new Answer
        ( 
            messageHandler, 
            3, 
            data::Question::answer3Question3,
            std::tuple<bool, std::string>(),
            data::Question::correctOrNotAnswer3Question3
        )
    );

    while
    ( 
        !Question::question
        ( 
            { answer0_2.get(), answer1_2.get(), answer2_2.get() }, 
            data::Question::titleThirdQuestion 
        ) 
    )
    {}

    Level::endOfLevel();

    std::cout << "\n";
}