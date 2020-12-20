/*! 
    * \file AnswerWriter.cpp
*/

#include "AnswerWriter.h"

AnswerWriter::AnswerWriter( const nlohmann::json& jsonObject ) :
    answerData_( jsonObject )
{

}

AnswerWriter::AnswerWriter( const AnswerData& answerData ) :
    answerData_( answerData )
{

}

AnswerWriter::AnswerWriter( const std::string& folderFromRoot, const std::string& fileName ) :
    answerData_( folderFromRoot, fileName )
{

}