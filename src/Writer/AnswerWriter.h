#ifndef ANSWER_WRITER_H
#define ANSWER_WRITER_H

/*!
    * \file AnswerWriter.h
*/

#include "../Data/AnswerData.h"

class AnswerWriter
{
    private:
        AnswerData answerData_;

    public:
        AnswerWriter( const nlohmann::json& jsonObject );
        AnswerWriter( const AnswerData& answerData );
        AnswerWriter( const std::string& folderFromRoot, const std::string& fileName); 

        const AnswerData& answerData() const { return answerData_; }
};

#endif