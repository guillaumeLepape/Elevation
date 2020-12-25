#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

/*!
    * \file MessageHandler.h
*/

#include "MessagesData.h"
#include "MessageWriter.h"

class MessageHandler  
{
    private:
        MessagesData messagesData_;

        mutable int indexMessage_;

        void writeMessagePrivate() const;

    public:
        MessageHandler
        ( 
            const nlohmann::json& jsonObject,
            int indexMessage = -1
        );

        MessageHandler
        (
            const MessagesData& messagesData,
            int indexMessage = -1
        );

        MessageHandler
        (
            const std::string& folderFromRoot,
            const std::string& nameFile,
            int indexMessage = -1
        );

        void writeMessage( const int& indexMessage ) const;
        void nextMessage() const;

        void preTreatment( const Player* const player, const Plug* const plug )
        {
            messagesData_.preTreatment( player, plug );
        }

        void preTreatment( const Player* const player, const Plug* const plug, const int& indexMessage )
        {
            messagesData_.preTreatment( player, plug, indexMessage);
        }

        void preTreatmentNextMessage( const Player* const player, const Plug* plug )  
        {
            messagesData_.preTreatment( player, plug, indexMessage_ + 1);
        }
};

#endif