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
        std::vector<std::string> tokenName_;
        std::vector<std::string> name_;
        std::vector<bool> token_;
        std::vector<std::string> dialog_;

    public:
        MessageData( const nlohmann::json& jsonObject );
        MessageData( const std::string& folderFromRoot, const std::string& fileName );

        void readData() override;

        void preTreatment( const Player* const player, const Plug* plug );

        const std::vector<std::string>& tokenName() const { return tokenName_; }
        const std::vector<std::string>& name() const { return name_; }
        const std::vector<bool>& token() const { return token_; }
        const std::vector<std::string>& dialog() const { return dialog_; }
};

#endif