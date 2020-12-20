/*!
    * \file AnswerData.cpp
*/

#include "AnswerData.h"

AnswerData::AnswerData( const nlohmann::json& jsonObject ) :
    ActionData( jsonObject )
{
    readData();
}

AnswerData::AnswerData( const std::string& folderFromRoot, const std::string& nameFile ) :
    ActionData( folderFromRoot, nameFile )   
{
    readData();
}

void AnswerData::readData()
{
    correctOrNot_ = jsonObject_["correctOrNot"];
}