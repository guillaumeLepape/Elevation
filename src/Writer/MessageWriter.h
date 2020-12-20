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
        MessageData messageData_;

        void writeName( const int& i ) const;

        void writeOneMessage( const int& i) const;

    public: 
        MessageWriter
        (
            const Player* const player,
            const Plug* const plug,
            const nlohmann::json& jsonObject
        );
        
        MessageWriter
        ( 
            const Player* const player, 
            const Plug* const plug, 
            const MessageData& messageData 
        );

        MessageWriter
        (
            const Player* const player, 
            const Plug* const plug,
            const std::string& folderFromRoot,
            const std::string& fileName
        );

        void writeMessage() const;
};

#endif