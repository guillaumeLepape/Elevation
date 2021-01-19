#ifndef ACTION_WRITER_H
#define ACTION_WRITER_H

/*!
    * \file ActionWriter.h
*/

#include "ActionData.h"

class ActionWriter
{
    private:
        ActionData actionData_;

    public:
        ActionWriter( const nlohmann::json& jsonObject );
        ActionWriter
        ( 
            const std::tuple<bool, std::string>& statement, 
            const std::tuple<bool, std::string>& result
        );
        ActionWriter( const ActionData& actionData );
        ActionWriter( const std::string& folderFromRoot, const std::string& nameFile );

        const ActionData& actionData() const { return actionData_; }

        void preTreatmentStatement( const Player* const player, const Plug* const plug )
        {
            actionData_.preTreatmentStatement( player, plug );
        }

        void preTreatmentResult( const Player* const player, const Plug* const plug )
        {
            actionData_.preTreatmentResult( player, plug );
        }

        void writeStatement() const;
        void writeResult() const;
};

#endif