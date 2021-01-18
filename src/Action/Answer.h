#ifndef ANSWER_H
#define ANSWER_H

/*!
    * \file Answer.h
*/

#include "Action.h"

class Answer : public Action
{
    private:
        const AnswerWriter answerWriter_;
        const MessageHandler& messageHandler_;
        const int indexMessage_;

    public:
        explicit Answer
        ( 
            const MessageHandler& messageHandler,
            const int& indexMessage,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            answerWriter_( folderFromRoot, nameFile ),
            messageHandler_( messageHandler ),
            indexMessage_( indexMessage )
        {

        }

        explicit Answer
        (
            const MessageHandler& messageHandler,
            const int& indexMessage,
            const std::tuple<bool, std::string>& statement, 
            const std::tuple<bool, std::string>& result, 
            const bool& correctOrNot  
        ) :
            Action( statement, result ),
            answerWriter_( statement, result, correctOrNot ),
            messageHandler_( messageHandler ),
            indexMessage_( indexMessage )
        {

        }

        void triggerAction() override
        {
            messageHandler_.writeMessage( indexMessage_ );
        }

        const bool& correctOrNot() const { return answerWriter_.answerData().correctOrNot(); }
};

#endif