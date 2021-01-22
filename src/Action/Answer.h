#ifndef ANSWER_H
#define ANSWER_H

/*!
    * \file Answer.h
*/

#include "Action.h"

#include "AnswerWriter.h"

class Answer : public Action
{
    private:
        const AnswerWriter answerWriter_;

    public:
        explicit Answer
        ( 
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            answerWriter_( folderFromRoot, nameFile )
        {

        }

        explicit Answer
        (
            const std::tuple<bool, std::string>& statement, 
            const std::tuple<bool, std::string>& result, 
            const bool& correctOrNot  
        ) :
            Action( statement, result ),
            answerWriter_( statement, result, correctOrNot )
        {

        }

        void triggerAction() override
        {

        }

        const bool& correctOrNot() const { return answerWriter_.answerData().correctOrNot(); }
};

#endif