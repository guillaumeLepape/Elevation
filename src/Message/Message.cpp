#include "Message.h"

#include <fstream>
#include <cassert>

#include <nlohmann/json.hpp>

Message::Message( const std::string& fileName )
    : fileName_( fileName )
{
    writeInConsole();
}

void Message::writeInConsole()
{
    std::ifstream messageFile( fileName_, std::ifstream::binary );

    // check if the file is opened
    assert( messageFile.is_open() );

    // create json variable to store message from a json file
    nlohmann::json message;

    messageFile >> message;

    // print the hour
    std::cout << "\n " << message["hour"] << "h" << message["minut"];
    std::cout << "\n========";

    for ( int i = 0; i < message["message"].size(); i++ )
    {
        // casting not to print the quotes at the begin and end of message
        std::cout << "\n " << ( (std::string) message["message"][i] );
    }

    std::cout << "\n";

    messageFile.close();
}   