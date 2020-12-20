/*!
    * \file MessageData.cpp
*/

#include "MessageData.h"

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
        name_.push_back( (std::string) jsonObject_["message"][i][0] );
        token_.push_back( jsonObject_["message"][i][1] );
        dialog_.push_back( (std::string) jsonObject_["message"][i][2] );
    }
}
