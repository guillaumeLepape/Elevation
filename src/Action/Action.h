#ifndef ACTION_H
#define ACTION_H

/*! 
    * \file Action.h
*/

#include "../Message/Message.h"

/*! \class Action
    * \brief Abstract class Action to introduce various actions (herited classes)
*/

class Action
{
    protected:
        std::string statement_;

    public:
        explicit Action
        ( 
            const std::string& statement
        ) : 
            statement_( statement )
        {

        }

        virtual void triggerAction() const = 0;

        const std::string& statement() const { return statement_; }

        virtual ~Action() {}
};

#endif