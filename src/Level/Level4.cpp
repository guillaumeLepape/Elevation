/*!
    * \file Level4.cpp
*/

#include "Level4.h"

#include "../Selection/Question.h"

#include "../Writer/HeaderWriter.h"

void Level4::startLevel()
{
    std::string folder = "data/Level4";

    Plug plug( "Freeze Corleone", 20 );

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( player_, &plug, folder, "message" );
    messageHandler.nextMessage();

    firstQuestion( messageHandler );

    secondQuestion( messageHandler );

    thirdQuestion( messageHandler );

    std::cout << "\n";
}

void Level4::firstQuestion( const MessageHandler& messageHandler )
{
    std::string folder = "data/Level4";

    std::unique_ptr<Answer> answer0( new Answer( messageHandler, 1, folder, "answer0_0" ) );
    std::unique_ptr<Answer> answer1( new Answer( messageHandler, 1, folder, "answer0_1" ) );
    std::unique_ptr<Answer> answer2( new Answer( messageHandler, 2, folder, "answer0_2" ) );

    while( !Question::question( { answer0.get(), answer1.get(), answer2.get() }, folder, "selection0" ) )
    {}
}

void Level4::secondQuestion( const MessageHandler& messageHandler )
{
    std::string folder = "data/Level4";

    std::unique_ptr<Answer> answer0( new Answer( messageHandler, 1, folder, "answer1_0" ) );
    std::unique_ptr<Answer> answer1( new Answer( messageHandler, 1, folder, "answer1_1" ) );
    std::unique_ptr<Answer> answer2( new Answer( messageHandler, 2, folder, "answer1_2" ) );

    while( !Question::question( { answer0.get(), answer1.get(), answer2.get() }, folder, "selection1" ) )
    {}
}

void Level4::thirdQuestion( const MessageHandler& messageHandler )
{
    std::string folder = "data/Level4";

    std::unique_ptr<Answer> answer0( new Answer( messageHandler, 3, folder, "answer2_0" ) );
    std::unique_ptr<Answer> answer1( new Answer( messageHandler, 3, folder, "answer2_1" ) );
    std::unique_ptr<Answer> answer2( new Answer( messageHandler, 3, folder, "answer2_2" ) );

    while( !Question::question( { answer0.get(), answer1.get(), answer2.get() }, folder, "selection2" ) )
    {}
}