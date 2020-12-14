#ifndef MESSAGE_DATA_H
#define MESSAGE_DATA_H

/*!
    * \file MessageData.h
*/

#include "Data.h"

#include <tuple>

class MessageData : public Data
{
    private:
        std::vector<std::string> name_;
        std::vector<bool> token_;
        std::vector<std::string> dialog_;

    public:
        MessageData( const int& levelNumber, const int& indexMessage );

        void readData() override;

        const std::vector<std::string>& name() const { return name_; }
        const std::vector<bool>& token() const { return token_; }
        const std::vector<std::string>& dialog() const { return dialog_; }
};

#endif