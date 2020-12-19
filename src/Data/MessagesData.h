#ifndef MESSAGES_DATA_H
#define MESSAGES_DATA_H

/*!
    * \file MessagesData.h
*/

#include "MessageData.h"

class MessagesData : public Data
{
    private:
        std::vector<MessageData> messages_;
        int nbMessage_;

    public:
        MessagesData( const int& levelNumber );
        MessagesData( const std::vector<MessageData>& messages );
        void readData() override;
        const std::vector<MessageData>& messages() const { return messages_; }
};

#endif