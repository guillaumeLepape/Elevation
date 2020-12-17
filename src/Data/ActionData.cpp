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
    token_ = jsonObject_["statement"][0];
    statement_ = jsonObject_["statement"][1];
}