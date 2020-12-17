#ifndef MESSAGE_WRITER_H
#define MESSAGE_WRITER_H

/*!
    * \file MessageWriter.h
*/

#include "../Data/MessageData.h"

#include "../Player/Player.h"
#include "../Plug/Plug.h"

class MessageWriter
{
    private:
        const Player* const player_;
        const Plug* const plug_;
        const MessageData& messageData_;

        void writeName( const int& i ) const;

        void writeOneMessage( const int& i) const;

        // std::string replaceToken( const std::string& str ) const;

    public: 
        MessageWriter
        ( 
            const Player* const player, 
            const Plug* const plug, 
            const MessageData& messageData 
        );

        void writeMessage() const;
};

#endif