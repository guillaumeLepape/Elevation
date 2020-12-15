/*!
    * \file ActionData.cpp
*/

#include "ActionData.h"

ActionData::ActionData( const int& levelNumber, const std::string& nameFile ) :
    levelNumber_(levelNumber, nameFile )
{

}

void ActionData::readData()
{
    statement_ = jsonObject_["statement"];
}