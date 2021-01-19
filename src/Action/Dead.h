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
        const Plug* const plug_;

    public:
        Dead
        (
            const Plug* const plug,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) :
            Action( folderFromRoot, nameFile ),
            plug_( plug )
        {

        }

        Dead
        (
            const Plug* const plug,
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result
        ) :
            Action( statement, result ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {
            if ( plug_->deadOrNot() )
            {
                actionWriter_.writeResult();
            }
        }
};

#endif