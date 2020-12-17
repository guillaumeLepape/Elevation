#ifndef ACTION_WRITER_H
#define ACTION_WRITER_H

/*!
    * \file ActionWriter.h
*/

#include "../Data/ActionData.h"

#include "../Player/Player.h"
#include "../Plug/Plug.h"

class ActionWriter
{
    private:
        ActionData actionData_;
        bool inputOrNot_;

    public:
        ActionWriter
        ( 
            const int& levelNumber, 
            const std::string& nameFile, 
            const bool& inputOrNot 
        );

        void writeAction( const Player* const player, const Plug* const plug ) const;
};

#endif