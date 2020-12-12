#ifndef CORRECT_ANSWER_H
#define CORRECT_ANSWER_H

/*!
    * \file CorrectAnswer.h
*/

#include "Action.h"

class CorrectAnswer : public Action
{
    private:
        Player* player_;
        Plug* plug_;
        const Message& message_;
        int indexMessage_;

    public:
        explicit CorrectAnswer
        ( 
            const std::string& statement,
            Player* player, 
            Plug* plug,
            const Message& message,
            const int& indexMessage
        ) : 
            Action( statement ),
            player_( player ),
            plug_( plug ),
            message_( message ),
            indexMessage_( indexMessage )
        {

        }

        void triggerAction() const override
        {
            message_.writeInConsole( player_, plug_, indexMessage_ );
        }
};

#endif