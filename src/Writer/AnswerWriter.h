#ifndef ANSWER_WRITER_H
#define ANSWER_WRITER_H

/*!
    * \file AnswerWriter.h
*/

#include "Writer.h"

class AnswerWriter
{
    private:
        AnswerData answerData_;

    public:
        AnswerWriter( const nlohmann::json& jsonObject );
        AnswerWriter
        ( 
            const std::tuple<bool, std::string>& statement, 
            const std::tuple<bool, std::string>& result, 
            const bool& correctOrNot 
        );
        AnswerWriter( const AnswerData& answerData );
        AnswerWriter( const std::string& folderFromRoot, const std::string& fileName); 

        const AnswerData& answerData() const { return answerData_; }
};

#endif