#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
    * \file Negociate.h
*/

#include "Action.h"

#include <iostream>

#include "../Plug/Plug.h"

#include "../Writer/MessageHandler.h"

class Negociate : public Action
{
    private: 
        Player* const player_;
        Plug* const plug_;
        MessageHandler& messageHandler_;

    public:
        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            MessageHandler& messageHandler
        ) :
            Action( 2, "negociate", true ),
            player_(player), 
            plug_(plug), 
            messageHandler_(messageHandler)
        {

        }
        void triggerAction() const override 
        {
            bool out = false;

            messageHandler_.setIndexMessage( 1 );
            messageHandler_.writeMessage();

            while ( !out )
            {
                std::string priceStr;

                actionWriter_.writeStatement( player_, plug_ );
                std::cin >> priceStr;
                int price = std::stoi( priceStr ); 
                player_->setPrice( price );

                if ( price > plug_->price() )
                {
                    messageHandler_.setIndexMessage( 2 );
                    messageHandler_.writeMessage();
                }
                else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
                {
                    out = true;
                    messageHandler_.setIndexMessage( 4 );
                    messageHandler_.writeMessage();

                    player_->increaseMoney( -price );
                }
                else 
                {
                    messageHandler_.setIndexMessage( 3 );
                    messageHandler_.writeMessage();
                } 
            }
            actionWriter_.writeResult( player_, plug_ );
            
            messageHandler_.setIndexMessage( 5 );
            messageHandler_.writeMessage();
        }
};

#endif