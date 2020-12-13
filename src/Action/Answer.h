#ifndef ANSWER_H
#define ANSWER_H

/*!
    * \file Answer.h
*/

#include "Action.h"

class Answer : public Action
{
    private:
        Player* player_;
        Plug* plug_;
        const Message& message_;
        int indexMessage_;
        bool correctOrNot_;

    public:
        explicit Answer
        ( 
            const std::string& statement,
            Player* player, 
            Plug* plug,
            const Message& message,
            const int& indexMessage,
            const bool& correctOrNot
        ) : 
            Action( statement ),
            player_( player ),
            plug_( plug ),
            message_( message ),
            indexMessage_( indexMessage ),
            correctOrNot_( correctOrNot )
        {

        }

        void triggerAction() const override
        {
            message_.writeInConsole( player_, plug_, indexMessage_ );
        }

        const bool& correctOrNot() const { return correctOrNot_; }
};

#endif