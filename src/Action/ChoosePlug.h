#ifndef CHOOSE_PLUG
#define CHOOSE_PLUG

/*!
    * \file ChoosePlug.h 
*/

#include "Action.h"

class ChoosePlug : public Action
{
    private:
        Plug* const plug_;
    public:
        ChoosePlug
        ( 
            Plug* const plug,
            const std::string& folderFromRoot,
            const std::string& nameFile 
        ) :
            Action( folderFromRoot, nameFile ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {

        }
};

#endif