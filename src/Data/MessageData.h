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
        std::vector<NameSpeaker> tokenName_;
        std::vector<std::string> name_;
        std::vector<std::string> dialog_;

        std::vector<NameSpeaker> vectorFromVectorOfTuple1
        ( 
            const std::vector<std::tuple<NameSpeaker, std::string>>& message
        ) const;

        std::vector<std::string> vectorFromVectorOfTuple2
        ( 
            const std::vector<std::tuple<NameSpeaker, std::string>>& message
        ) const;

    public:
        MessageData( const nlohmann::json& jsonObject );
        MessageData( const std::string& folderFromRoot, const std::string& fileName );
        MessageData
        ( 
            const std::vector<std::tuple<NameSpeaker, std::string>>& message, 
            const std::string& pseudo, 
            const std::string& plugName
        );

        void readData() override;

        void writeName
        ( 
            const std::string& pseudo = std::string(), 
            const std::string& plugName = std::string()
        );

        const std::vector<NameSpeaker>& tokenName() const { return tokenName_; }
        const std::vector<std::string>& name() const { return name_; }
        const std::vector<std::string>& dialog() const { return dialog_; }
};

#endif