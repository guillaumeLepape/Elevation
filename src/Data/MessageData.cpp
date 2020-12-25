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
