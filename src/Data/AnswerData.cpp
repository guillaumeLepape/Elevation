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

AnswerData::AnswerData
( 
    const std::tuple<bool, std::string>& statement, 
    const std::tuple<bool, std::string>& result, 
    const bool& correctOrNot 
) :
    ActionData( statement, result ),
    correctOrNot_( correctOrNot )
{

}


void AnswerData::readData()
{
    correctOrNot_ = jsonObject_["correctOrNot"];
}