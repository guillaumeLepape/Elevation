#ifndef ACTION_H
#define ACTION_H

/*! 
    * \file Action.h
*/

#include "../Writer/ActionWriter.h"
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
            const int& levelNumber, 
            const std::string& nameAction, 
            const bool& inputOrNot
        ) : 
            actionWriter_( levelNumber, nameAction, inputOrNot )
        {

        }

        const ActionWriter& actionWriter() const { return actionWriter_; }

        virtual void triggerAction() const = 0;

        virtual ~Action() {}
};

#endif