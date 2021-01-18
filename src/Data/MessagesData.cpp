/*!
    * \file MessagesData.cpp
*/

#include "MessagesData.h"

MessagesData::MessagesData( const nlohmann::json& jsonObject ) :
    Data( jsonObject_ )
{
    readData();
}

MessagesData::MessagesData( const std::string& folderFromRoot, const std::string& fileName ) :
    Data( folderFromRoot, fileName ),
    folderFromRoot_( folderFromRoot ),
    fileName_( fileName )
{
    readData();
}

MessagesData::MessagesData( const std::vector<std::vector<std::tuple<std::string, bool, std::string>>>& messages ) :
    messages_( convertSTLToMessages(messages) )
{
    
}


void MessagesData::readData()
{
    nbMessage_ = jsonObject_["nbMessage"];

    for ( int i = 0; i < nbMessage_; i++ )
    {
        MessageData messageData( folderFromRoot_, fileName_ + std::to_string(i) ); 

        messages_.push_back( messageData );
    }
}

std::vector<MessageData> MessagesData::convertSTLToMessages
( 
    const std::vector<std::vector<std::tuple<std::string, bool, std::string>>>& messages
) const 
{
    std::vector<MessageData> result;
    for ( auto m = messages.cbegin(); m != messages.cend(); m++ )
    {
        MessageData messageData( *m );
        result.push_back( messageData );
    }
    return result;
}