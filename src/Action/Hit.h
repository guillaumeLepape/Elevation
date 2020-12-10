#ifndef HIT_H
#define HIT_H

#include "Action.h"
#include "../color.h"

class Hit : public Action 
{
    private: 
        Player* player_;
        Plug* plug_;

    public:
        Hit( Player* player, Plug* plug ) : 
            Action( "Frappez !" ),
            player_(player),
            plug_(plug)
        {

        }   
        void triggerAction() const override 
        {
            Message message( "../messages/messageHit.json" );
            message.writeInConsole( player_, plug_, 0 );
            // std::cout << "\n " << BOLDYELLOW << plug_->name() << " perd 20 points de vie." << RESET;

            plug_->decreaseLifePoints( 20 );
        }
};

#endif