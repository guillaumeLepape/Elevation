/*!
    * \file Level4.cpp
*/

#include "Level4.h"

#include "Question.h"

#include "HeaderWriter.h"

void Level4::startLevel( const Options& options )
{
    std::string folder = "data/Level4";

    Plug plug( "Freeze Corleone", 20 );

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    // first question
    std::unique_ptr<Answer> answer0_0( new Answer( messageHandler, 1, folder, "answer0_0" ) );
    std::unique_ptr<Answer> answer1_0( new Answer( messageHandler, 1, folder, "answer0_1" ) );
    std::unique_ptr<Answer> answer2_0( new Answer( messageHandler, 2, folder, "answer0_2" ) );

    while( !Question::question( { answer0_0.get(), answer1_0.get(), answer2_0.get() }, folder, "selection0" ) )
    {}

    // second question
    std::unique_ptr<Answer> answer0_1( new Answer( messageHandler, 1, folder, "answer1_0" ) );
    std::unique_ptr<Answer> answer1_1( new Answer( messageHandler, 1, folder, "answer1_1" ) );
    std::unique_ptr<Answer> answer2_1( new Answer( messageHandler, 2, folder, "answer1_2" ) );

    while( !Question::question( { answer0_1.get(), answer1_1.get(), answer2_1.get() }, folder, "selection1" ) )
    {}

    // third question
    std::unique_ptr<Answer> answer0_2( new Answer( messageHandler, 3, folder, "answer2_0" ) );
    std::unique_ptr<Answer> answer1_2( new Answer( messageHandler, 3, folder, "answer2_1" ) );
    std::unique_ptr<Answer> answer2_2( new Answer( messageHandler, 3, folder, "answer2_2" ) );

    while( !Question::question( { answer0_2.get(), answer1_2.get(), answer2_2.get() }, folder, "selection2" ) )
    {}

    std::cout << "\n";
}