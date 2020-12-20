/*!
    * \file QuestionData.cpp
*/

#include "QuestionData.h"

#include <iostream>

QuestionData::QuestionData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )  
{
    readData();
}

QuestionData::QuestionData( const std::string& folderFromRoot, const std::string& fileName ) :
    Data( folderFromRoot, fileName )
{
    readData();
}

void QuestionData::readData()
{
    questionName_ = (std::string) jsonObject_["questionName"];

    for ( int i = 0; i < jsonObject_["answer"].size(); i++ )
    {
        std::tuple<std::string, int, bool> t 
            = std::make_tuple
            (
                (std::string) jsonObject_["answer"][i][0],
                jsonObject_["answer"][i][1],
                jsonObject_["answer"][i][2]
            );

        answer_.push_back(t);
    }    
}
