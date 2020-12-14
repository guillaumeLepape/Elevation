/*!
    * \file MessagesData.h
*/

#include "MessagesData.h"

MessagesData::MessagesData( const int& levelNumber ) :
    Data( levelNumber, "message" )
{
    readData();
}

void MessagesData::readData()
{
    nbMessage_ = jsonObject_["nbMessage"];

    for ( int i = 0; i < nbMessage_; i++ )
    {
        MessageData messageData( levelNumber_, i ); 

        messages_.push_back( messageData );
    }
}