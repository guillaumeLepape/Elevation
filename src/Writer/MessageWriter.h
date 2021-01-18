#ifndef MESSAGE_WRITER_H
#define MESSAGE_WRITER_H

/*!
    * \file MessageWriter.h
*/

#include "MessageData.h"

class MessageWriter
{
    private:
        MessageData messageData_;

        void writeName( const int& i ) const;

        void writeOneMessage( const int& i) const;

    public: 
        MessageWriter
        (
            const nlohmann::json& jsonObject
        );
        
        MessageWriter
        (
            const std::vector<std::tuple<std::string, bool, std::string>>& message
        );

        MessageWriter
        ( 
            const MessageData& messageData 
        );

        MessageWriter
        (
            const std::string& folderFromRoot,
            const std::string& fileName
        );

        void writeMessage() const;

        void preTreatment( const Player* const player, const Plug* const plug ) {  }
};

#endif