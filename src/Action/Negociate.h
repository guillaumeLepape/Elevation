#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
    * \file Negociate.h
*/

#include "Action.h"

#include <iostream>

#include "../color.h"
#include "../Player/Player.h"
#include "../Plug/Plug.h"

#include "../Writer/Writer.h"

class Negociate : public Action
{
    private: 
        Player* const player_;
        Plug* const plug_;
        MessagesWriter& messagesWriter_;

    public:
        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            MessagesWriter& messagesWriter
        ) :
            Action( 2, "negociate", true ),
            player_(player), 
            plug_(plug), 
            messagesWriter_(messagesWriter)
        {

        }
        void triggerAction() const override 
        {
            bool out = false;

            messagesWriter_.setIndexMessage( 1 );
            messagesWriter_.writeMessage();

            while ( !out )
            {
                std::string priceStr;

                actionWriter_.writeAction( player_, plug_ );
                std::cin >> priceStr;
                int price = std::stoi( priceStr ); 

                if ( price > plug_->price() )
                {
                    messagesWriter_.setIndexMessage( 2 );
                    messagesWriter_.writeMessage();
                }
                else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
                {
                    out = true;
                    messagesWriter_.setIndexMessage( 4 );
                    messagesWriter_.writeMessage();

                    player_->increaseMoney( -price );
                }
                else 
                {
                    messagesWriter_.setIndexMessage( 3 );
                    messagesWriter_.writeMessage();
                }
                
            }
        }
};

#endif