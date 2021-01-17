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

        ChoosePlug
        (
            Plug* const plug,
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result
        ) :
            Action( statement, result ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {

        }

        Plug* const plug() const { return plug_; }
};

#endif