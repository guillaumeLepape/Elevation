#ifndef ACTION_WRITER_H
#define ACTION_WRITER_H

/*!
    * \file ActionWriter.h
*/

#include "ActionData.h"

#include "Player.h"
#include "Plug.h"

class ActionWriter
{
    private:
        ActionData actionData_;

    public:
        ActionWriter( const nlohmann::json& jsonObject );
        ActionWriter( const ActionData& actionData );
        ActionWriter( const std::string& folderFromRoot, const std::string& nameFile );

        const ActionData& actionData() const { return actionData_; }

        void writeStatement( const Player* const player, const Plug* const plug ) const;
        void writeResult( const Player* const player, const Plug* const plug ) const;
};

#endif