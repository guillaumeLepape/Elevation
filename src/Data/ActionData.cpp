/*!
    * \file ActionData.cpp
*/

#include "ActionData.h"

#include "Token.h"

ActionData::ActionData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )
{
    readData();
}

ActionData::ActionData
( 
    const std::string& folderFromRoot,
    const std::string& nameFile
) :
    Data( folderFromRoot, nameFile )
{
    readData();
}

ActionData::ActionData
( 
    const std::tuple<bool, std::string>& statement,
    const std::tuple<bool, std::string>& result
) :
    Data(),
    tokenStatement_( std::get<0>(statement) ), 
    statement_( std::get<1>(statement) ),
    tokenResult_( std::get<0>(result) ),
    result_( std::get<01>(result) )

{

}

void ActionData::readData()
{
    tokenStatement_ = jsonObject_["statement"][0];
    statement_ = jsonObject_["statement"][1];

    tokenResult_ = jsonObject_["result"][0];
    result_ = jsonObject_["result"][1];
}

void ActionData::preTreatmentStatement( const Player* player, const Plug* plug )
{
    if ( tokenStatement_ )
    {
        statement_ = Token::replace( statement_, player, plug );
    }
}

void ActionData::preTreatmentResult( const Player* player, const Plug* plug )  
{
    if( tokenResult_ )
    {
        result_ = Token::replace( result_, player, plug );
    }
}