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
            const std::vector<std::tuple<NameSpeaker, std::string>>& message,
            const std::string& pseudo,
            const std::string& plugName
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
};

#endif