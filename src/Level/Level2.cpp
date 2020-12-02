#include "Level2.h"

#include <memory>

#include "../Plug/Plug.h"

void Level2::startLevel()
{
    Plug* plug = new Plug("Jean-Luc Delarue", 80);

    Message message( "../messages/messageLevel2.json" );
    message.writeHeader();

    message.writeInConsole( player_, plug, 0 );

    negociate( message, player_, plug );

    message.writeInConsole( player_, plug, 3 );
    // message.writeInConsole( player_, plug.get() );
    delete plug;

    player_->printState();
}

void Level2::negociate( const Message& message, Player* player, Plug* plug )
{
    bool out = false;
    while ( !out )
    {
        std::string priceStr;
        std::cin >> priceStr;
        int price =  std::stoi( priceStr ); 

        if ( price > plug->price() )
        {
            message.writeInConsole( player, plug, 1 );
        }
        else if ( price <= plug->price() && plug->price() - 30 <= price ) 
        {
            out = true;
            message.writeInConsole( player, plug, 3 );
            player_->increaseMoney( -price );
        }
        else 
        {
            message.writeInConsole( player, plug, 2 );
        }
    }
}