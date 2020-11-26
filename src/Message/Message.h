#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

// Read message in a txt file and write it the terminal

class Message
{
    private:
        std::string fileName_;

    public:
        Message( const std::string& fileName );
        void writeInConsole();
};

#endif