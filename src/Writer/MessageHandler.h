#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

/*!
    * \file MessageHandler.h
*/

#include "../Data/MessagesData.h"
#include "MessageWriter.h"

class MessageHandler  
{
    private:
        MessagesData messagesData_;
        const Player* const player_;
        const Plug* const plug_;

        int indexMessage_;

    public:
        MessageHandler
        ( 
            const int& levelNumber_,
            const Player* const player, 
            const Plug* const plug, 
            int indexMessage = -1
        );

        void writeMessage() const;
        void setIndexMessage( const int& indexMessage );
        void nextMessage();
};

#endif