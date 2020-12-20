/*!
    * \file AnswerData.cpp
*/

#include "AnswerData.h"

AnswerData::AnswerData( const int& levelNumber, const std::string& nameFile ) :
    ActionData( levelNumber, nameFile )   
{
    readData();
}

void AnswerData::readData()
{
    correctOrNot_ = jsonObject_["correctOrNot"];
}