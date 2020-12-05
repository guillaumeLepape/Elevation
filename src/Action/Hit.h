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
            std::cout << "\n " << BOLDYELLOW << plug_->name() << " perd 20 points de vie." << RESET;
            std::cout << "\n";
            plug_->decreaseLifePoints( 20 );
        }
};

#endif