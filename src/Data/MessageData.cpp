/*!
    * \file MessageData.cpp
*/

#include "MessageData.h"

#include "Token.h"

MessageData::MessageData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )
{
    readData();
}

MessageData::MessageData( const std::string& folderFromRoot, const std::string& fileName ) :
    Data( folderFromRoot, fileName )
{
    readData();
}

MessageData::MessageData
( 
    const std::vector<std::tuple<NameSpeaker, std::string>>& message,
    const std::string& pseudo, 
    const std::string& plugName
) :
    tokenName_( vectorFromVectorOfTuple1(message) ),
    dialog_( vectorFromVectorOfTuple2(message) )
{
    writeName( pseudo, plugName );
}


void MessageData::readData()
{
    for ( int i = 0; i < jsonObject_["message"].size(); i++ )
    {
        tokenName_.push_back( jsonObject_["message"][i][0] );
        dialog_.push_back( (std::string) jsonObject_["message"][i][1] );
    }
}

void MessageData::writeName( const std::string& pseudo, const std::string& plugName )
{
    // name_.resize( tokenName_.size() );

    for ( int i = 0; i < tokenName_.size(); i++ )
    {
        if ( tokenName_[i] == NameSpeaker::player )
        {
            name_.push_back( pseudo );
        }
        else if ( tokenName_[i] == NameSpeaker::plug )
        {
            name_.push_back( plugName );
        }
        else if ( tokenName_[i] == NameSpeaker::description )
        {
            name_.push_back( "description" );
        }
        else if ( tokenName_[i] == NameSpeaker::action )
        {
            name_.push_back( "action" );
        }
        else
        {
            assert( false );
        }
    }
}

std::vector<NameSpeaker> MessageData::vectorFromVectorOfTuple1
( 
    const std::vector<std::tuple<NameSpeaker, std::string>>& message
) const
{
    std::vector<NameSpeaker> result;
    for ( auto m = message.cbegin(); m != message.cend(); m++ )
    {
        result.push_back( std::get<0>( *m ) );
    }
    return result;
}

std::vector<std::string> MessageData::vectorFromVectorOfTuple2
( 
    const std::vector<std::tuple<NameSpeaker, std::string>>& message
) const
{
    std::vector<std::string> result;
    for ( auto m = message.cbegin(); m != message.cend(); m++ )
    {
        result.push_back( std::get<1>( *m ) );
    }
    return result;
}