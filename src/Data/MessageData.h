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

        std::vector<std::string> vectorFromVectorOfTuple1
        ( 
            const std::vector<std::tuple<std::string, bool, std::string>>& message
        ) const;

        std::vector<bool> vectorFromVectorOfTuple2
        ( 
            const std::vector<std::tuple<std::string, bool, std::string>>& message
        ) const;

        std::vector<std::string> vectorFromVectorOfTuple3
        ( 
            const std::vector<std::tuple<std::string, bool, std::string>>& message
        ) const;

    public:
        MessageData( const nlohmann::json& jsonObject );
        MessageData( const std::string& folderFromRoot, const std::string& fileName );
        MessageData( const std::vector<std::tuple<std::string, bool, std::string>>& message );

        void readData() override;

        void preTreatment( const Player* const player, const Plug* plug );

        const std::vector<std::string>& tokenName() const { return tokenName_; }
        const std::vector<std::string>& name() const { return name_; }
        const std::vector<bool>& token() const { return token_; }
        const std::vector<std::string>& dialog() const { return dialog_; }
};

#endif