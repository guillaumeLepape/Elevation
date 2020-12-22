#ifndef DEAD_H
#define DEAD_H

/*!
    * \file Dead.h
*/

#include "Action.h"

#include "Pause.h"

class Dead : public Action
{
    private:
        const Player* const player_;
        const Plug* const plug_;

    public:
        Dead
        (
            const Player* const player,
            const Plug* const plug,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) :
            Action( folderFromRoot, nameFile ),
            player_( player ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {
            if ( plug_->deadOrNot() )
            {
                actionWriter_.writeResult( player_, plug_ );
            }
        }
};

#endif