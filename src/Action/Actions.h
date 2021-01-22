#ifndef ACTIONS_H
#define ACTIONS_H

/*!
    * \file Actions.h
*/

#include "Action.h"

class Actions : public Action
{
    private:
        std::vector<Action*> actions_;
    public:
        Actions( const std::vector<Action*>& actions ) :
            actions_( actions )
        {

        }

        void triggerAction() override
        {
            for ( auto a = actions_.cbegin(); a != actions_.cend(); a++ )
            {
                (*a)->triggerAction();
            }
        }
};

#endif