#ifndef ACTION_H
#define ACTION_H

/*! 
    * \file Action.h
*/

#include "ActionWriter.h"

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
            const std::string& statement, 
            const std::string& result
        ) :
            actionWriter_( statement, result )
        {
        
        }

        const ActionWriter& actionWriter() const { return actionWriter_; }

        virtual void triggerAction() = 0;

        virtual ~Action() = default;
};

#endif