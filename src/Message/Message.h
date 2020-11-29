#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

#include "../Player/Player.h"

// Read message in a txt file and write it the terminal

class Message
{
    private:
        std::string fileName_;
        Player* player_;

    public:
        Message( const std::string& fileName, Player* player );
        void writeInConsole();
};

#endif