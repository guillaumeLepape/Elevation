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
            const int& levelNumber,
            const std::string& nameAction,
            const MessageHandler& messageHandler,
            const int& indexMessage
        ) : 
            Action( levelNumber, nameAction, false ),
            answerWriter_( levelNumber, nameAction ),
            messageHandler_( messageHandler ),
            indexMessage_( indexMessage )
        {

        }

        void triggerAction() const override
        {
            messageHandler_.setIndexMessage( indexMessage_ );
            messageHandler_.writeMessage();
        }

        const bool& correctOrNot() const { return answerWriter_.answerData().correctOrNot(); }
};

#endif