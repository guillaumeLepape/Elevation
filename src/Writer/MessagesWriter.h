#ifndef MESSAGES_WRITER_H
#define MESSAGES_WRITER_H

/*!
    * \file MessagesWriter.h
*/

#include "../Data/MessagesData.h"
#include "MessageWriter.h"

class MessagesWriter    
{
    private:
        MessagesData messagesData_;
        const Player* const player_;
        const Plug* const plug_;

        int indexMessage_;

    public:
        MessagesWriter
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