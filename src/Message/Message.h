#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

#include "../Player/Player.h"
#include "../Plug/Plug.h"

// Read message in a txt file and write it the terminal

class Message
{
    private:
        std::string fileName_;
        Player* player_;
        Plug* plug_;

    public:
        Message( const std::string& fileName, Player* player, Plug* plug );
        void writeInConsole( );
};

#endif