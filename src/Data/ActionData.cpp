/*!
    * \file ActionData.cpp
*/

#include "ActionData.h"

ActionData::ActionData( const int& levelNumber, const std::string& nameFile ) :
    Data(levelNumber, nameFile )
{
    readData();
}

void ActionData::readData()
{
    tokenStatement_ = jsonObject_["statement"][0];
    statement_ = jsonObject_["statement"][1];

    tokenResult_ = jsonObject_["result"][0];
    result_ = jsonObject_["result"][1];
}