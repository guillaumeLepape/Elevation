#include "Level1.h"

#include <memory>

#include "../Plug/Plug.h"
#include "../Message/Message.h"

void Level1::startLevel()
{
    std::unique_ptr<Plug> plug( new Plug("Petite frappe") );

    Message message( "../messages/messageLevel1.json", player_, plug.get() );
    message.writeInConsole();

}