#ifndef MESSAGES_DATA_H
#define MESSAGES_DATA_H

/*!
    * \file MessagesData.h
*/

#include "Data.h"
#include "MessageData.h"

class MessagesData : public Data
{
    private:
        int nbMessage_;
        std::vector<MessageData> messages_;

    public:
        MessagesData( const int& levelNumber );
        void readData() override;
        const std::vector<MessageData>& messages() const { return messages_; }
};

#endif