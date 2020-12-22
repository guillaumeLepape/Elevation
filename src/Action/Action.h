#ifndef ACTION_H
#define ACTION_H

/*! 
    * \file Action.h
*/

#include "ActionWriter.h"
#include <iostream>

/*! \class Action
    * \brief Abstract class Action to introduce various actions (herited classes)
*/

class Action
{
    protected:
        ActionWriter actionWriter_;

    public:
        explicit Action
        ( 
            const std::string& folderFromRoot,
            const std::string& nameFile 
        ) : 
            actionWriter_( folderFromRoot, nameFile )
        {

        }

        const ActionWriter& actionWriter() const { return actionWriter_; }

        virtual void triggerAction() = 0;

        virtual ~Action() {}
};

#endif