/*!
    * \file Level4.cpp
*/

#include "Level4.h"

#include "../Selection/Question.h"

#include "../Writer/HeaderWriter.h"

void Level4::startLevel()
{
    Plug plug( "Freeze Corleone", 20 );

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessageHandler messageHandler( levelNumber_, player_, &plug );
    messageHandler.nextMessage();

    firstQuestion( messageHandler );

    secondQuestion( messageHandler );

    thirdQuestion( messageHandler );

    std::cout << "\n";
}

void Level4::firstQuestion( const MessageHandler& messageHandler )
{
    std::unique_ptr<Answer> answer0( new Answer(levelNumber_, "answer0_0", messageHandler, 1) );
    std::unique_ptr<Answer> answer1( new Answer(levelNumber_, "answer0_1", messageHandler, 1) );
    std::unique_ptr<Answer> answer2( new Answer(levelNumber_, "answer0_2", messageHandler, 2) );

    while( !Question::question( levelNumber_, 0, { answer0.get(), answer1.get(), answer2.get() } ) )
    {}
}

void Level4::secondQuestion( const MessageHandler& messageHandler )
{
    std::unique_ptr<Answer> answer0( new Answer(levelNumber_, "answer1_0", messageHandler, 1) );
    std::unique_ptr<Answer> answer1( new Answer(levelNumber_, "answer1_1", messageHandler, 1) );
    std::unique_ptr<Answer> answer2( new Answer(levelNumber_, "answer1_2", messageHandler, 2) );

    while( !Question::question( levelNumber_, 1, { answer0.get(), answer1.get(), answer2.get() } ) )
    {}
}

void Level4::thirdQuestion( const MessageHandler& messageHandler )
{
    std::unique_ptr<Answer> answer0( new Answer(levelNumber_, "answer2_0", messageHandler, 3) );
    std::unique_ptr<Answer> answer1( new Answer(levelNumber_, "answer2_1", messageHandler, 3) );
    std::unique_ptr<Answer> answer2( new Answer(levelNumber_, "answer2_2", messageHandler, 3) );

    while( !Question::question( levelNumber_, 2, { answer0.get(), answer1.get(), answer2.get() } ) )
    {}
}