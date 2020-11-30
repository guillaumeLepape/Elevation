#include "Level2.h"

#include <memory>

#include "../Message/Message.h"
#include "../Plug/Plug.h"

void Level2::startLevel()
{
    std::unique_ptr<Plug> plug( new Plug("Jean-Luc Delarue") );

    Message( "../messages/messageLevel2.json", player_, plug.get() );

}