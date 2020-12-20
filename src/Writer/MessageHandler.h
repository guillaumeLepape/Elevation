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
        const Player* const player_;
        const Plug* const plug_;

        MessagesData messagesData_;

        mutable int indexMessage_;

    public:
        MessageHandler
        ( 
            const Player* const player, 
            const Plug* const plug, 
            const nlohmann::json& jsonObject,
            int indexMessage = -1
        );

        MessageHandler
        (
            const Player* const player, 
            const Plug* const plug, 
            const MessagesData& messagesData,
            int indexMessage = -1
        );

        MessageHandler
        (
            const Player* const player, 
            const Plug* const plug, 
            const std::string& folderFromRoot,
            const std::string& nameFile,
            int indexMessage = -1
        );

        void writeMessage() const;
        void setIndexMessage( const int& indexMessage ) const;
        void nextMessage() const;
};

#endif