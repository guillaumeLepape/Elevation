#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "../Message/Message.h"
#include "../Player/Player.h"

class Action
{
    protected:
        std::string statement_;
        Player * const player_;

    public:
        explicit Action
        ( 
            const std::string& statement,
            Player * const player = nullptr
        ) : 
            statement_( statement ), player_( player )
        {

        }

        virtual void triggerAction() const = 0;

        const std::string& statement() const { return statement_; }

        virtual ~Action() {}
};

#endif