/*!
    * \file Negociate.cpp
*/

#include "Negociate.h"

#include <iostream>

#include "MessageWriter.h"

#include "Player.h"
#include "Plug.h"

#include "Languages.h"

Negociate::Negociate
(
    Player* const player, 
    Plug* const plug, 
    const std::string& statement,
    const std::string& result
) :
    Action( statement, result ),  
    player_(player), 
    plug_(plug) 
{

}

void Negociate::triggerAction() 
{
    bool out = false;

    MessageWriter messageWriter1
    ( 
        data::Level2::message1, 
        player_->pseudo(),
        plug_->name() 
    );
    messageWriter1.writeMessage();

    while ( !out )
    {
        std::string priceStr;

        actionWriter_.writeStatement();
        std::cin >> priceStr;
        int price = std::stoi( priceStr ); 
        player_->setPrice( price );

        if ( price > plug_->price() )
        {
            MessageWriter messageWriter2
            ( 
                data::Level2::message2,
                player_->pseudo(),
                plug_->name()
            );
            messageWriter2.writeMessage();
        }
        else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
        {
            out = true;
            MessageWriter messageWriter4
            ( 
                data::Level2::message4,
                player_->pseudo(),
                plug_->name()
            );
            messageWriter4.writeMessage();

            player_->increaseMoney( -price );

            actionWriter_.updateResult( data::Action::resultNegociate( price ) );
            actionWriter_.writeResult();
        }
        else 
        {
            MessageWriter messageWriter3
            ( 
                data::Level2::message3,
                player_->pseudo(),
                plug_->name()
            );
            messageWriter3.writeMessage();
        } 
    }
            
    MessageWriter messageWriter5
    (
        data::Level2::message5,
        player_->pseudo(),
        plug_->name()
    );
    messageWriter5.writeMessage();
}