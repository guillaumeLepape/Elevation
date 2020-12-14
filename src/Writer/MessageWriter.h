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
        const MessageData& messageData_;

        void writeName( Player* player, Plug* plug, const int& i ) const;

        void writeOneMessage( Player* player, Plug* plug, const int& i) const;

        std::string replaceToken( Player* player, Plug* plug, const std::string& str ) const;

    public: 
        MessageWriter( const MessageData& messageData );
        void writeMessage( Player* player, Plug* plug ) const;
};

#endif