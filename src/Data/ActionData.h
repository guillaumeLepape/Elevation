#ifndef ACTION_DATA_H
#define ACTION_DATA_H

/*!
    * \file ActionData.h
*/

#include "Data.h"

class ActionData : public Data
{
    private:
        bool tokenStatement_;        
        std::string statement_;

        bool tokenResult_;
        std::string result_;

    public:
        ActionData( const nlohmann::json& jsonObject );
        ActionData( const std::string& folderFromRoot, const std::string& nameFile );

        virtual void readData() override;

        void preTreatmentStatement( const Player* const player, const Plug* const plug );
        void preTreatmentResult( const Player* const player, const Plug* const plug );

        const std::string& statement() const { return statement_; }
        const std::string& result() const { return result_; }
};

#endif