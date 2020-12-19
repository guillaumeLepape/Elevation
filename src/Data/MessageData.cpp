/*!
    * \file MessageData.cpp
*/

#include "MessageData.h"

MessageData::MessageData( const int& levelNumber, const int& indexMessage ) :
    Data( levelNumber, "message" + std::to_string(indexMessage) )
{
    readData();
}

MessageData::MessageData
( 
    const std::vector<std::string>& name, 
    const std::vector<bool>& token,  
    const std::vector<std::string>& dialog
) : 
    Data(),
    name_( name ),
    token_( token ),
    dialog_( dialog )
{

}

void MessageData::readData()
{
    for ( int i = 0; i < jsonObject_["message"].size(); i++ )
    {
        name_.push_back( (std::string) jsonObject_["message"][i][0] );
        token_.push_back( jsonObject_["message"][i][1] );
        dialog_.push_back( (std::string) jsonObject_["message"][i][2] );
    }
}
