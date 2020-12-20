#ifndef ANSWER_H
#define ANSWER_H

/*!
    * \file Answer.h
*/

#include "Action.h"

#include "../Writer/MessageHandler.h"
#include "../Writer/AnswerWriter.h"

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

        void triggerAction() const override
        {
            messageHandler_.writeMessage( indexMessage_ );
        }

        const bool& correctOrNot() const { return answerWriter_.answerData().correctOrNot(); }
};

#endif