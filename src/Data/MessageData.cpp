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

MessageData::MessageData( const std::vector<std::tuple<std::string, bool, std::string>>& message ) :
    tokenName_( vectorFromVectorOfTuple1(message) ),
    token_( vectorFromVectorOfTuple2(message) ),
    dialog_( vectorFromVectorOfTuple3(message) )
{

}


void MessageData::readData()
{
    for ( int i = 0; i < jsonObject_["message"].size(); i++ )
    {
        tokenName_.push_back( (std::string) jsonObject_["message"][i][0] );
        token_.push_back( jsonObject_["message"][i][1] );
        dialog_.push_back( (std::string) jsonObject_["message"][i][2] );
    }
}

void MessageData::preTreatment( const Player* player, const Plug* plug )
{
    for ( int i = 0; i < token_.size(); i++ )
    {
        if( token_[i] )
        {        
            dialog_[i] = Token::replace( dialog_[i], player, plug );
        }    
    }

    name_.resize( tokenName_.size() );

    for ( int i = 0; i < tokenName_.size(); i++ )
    {
        if ( tokenName_[i] == "player" )
        {
            name_[i] = player->pseudo();
        }
        else if ( tokenName_[i] == "plug" )
        {
            name_[i] = plug->name();
        }
        else if ( tokenName_[i] == "description" )
        {
            name_[i] = "description";
        }
        else if ( tokenName_[i] == "action" )
        {
            name_[i] = "action";
        }
        else
        {
            assert( false );
        }
    }
}

std::vector<std::string> MessageData::vectorFromVectorOfTuple1
( 
    const std::vector<std::tuple<std::string, bool, std::string>>& message
) const
{
    std::vector<std::string> result;
    for ( auto m = message.cbegin(); m != message.cend(); m++ )
    {
        result.push_back( std::get<0>( *m ) );
    }
    return result;
}

std::vector<bool> MessageData::vectorFromVectorOfTuple2
( 
    const std::vector<std::tuple<std::string, bool, std::string>>& message
) const
{
    std::vector<bool> result;
    for ( auto m = message.cbegin(); m != message.cend(); m++ )
    {
        result.push_back( std::get<1>( *m ) );
    }
    return result;
}

std::vector<std::string> MessageData::vectorFromVectorOfTuple3
( 
    const std::vector<std::tuple<std::string, bool, std::string>>& message
) const
{
    std::vector<std::string> result;
    for ( auto m = message.cbegin(); m != message.cend(); m++ )
    {
        result.push_back( std::get<2>( *m ) );
    }
    return result;
}