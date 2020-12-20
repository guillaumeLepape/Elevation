#ifndef MESSAGES_DATA_H
#define MESSAGES_DATA_H

/*!
    * \file MessagesData.h
*/

#include "MessageData.h"

class MessagesData : public Data
{
    private:
        std::string folderFromRoot_;
        std::string fileName_;

        std::vector<MessageData> messages_;
        int nbMessage_;

    public:
        MessagesData( const nlohmann::json& jsonObject );
        MessagesData( const std::string& folderFromRoot, const std::string& fileName );

        void readData() override;

        const std::vector<MessageData>& messages() const { return messages_; }
};

#endif