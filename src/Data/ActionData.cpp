/*!
    * \file ActionData.cpp
*/

#include "ActionData.h"

ActionData::ActionData( const int& levelNumber, const std::string& nameFile ) :
    Data(levelNumber, nameFile )
{
    readData();
}

ActionData::ActionData
( 
    const bool& tokenStatement,  
    const std::string& statement,
    const bool& tokenResult,
    const std::string& result
) :
    tokenStatement_( tokenStatement ),
    statement_( statement ),
    tokenResult_( tokenResult ),
    result_( result )
{

}

void ActionData::readData()
{
    tokenStatement_ = jsonObject_["statement"][0];
    statement_ = jsonObject_["statement"][1];

    tokenResult_ = jsonObject_["result"][0];
    result_ = jsonObject_["result"][1];
}