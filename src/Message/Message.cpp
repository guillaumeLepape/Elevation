#include "Message.h"

#include <fstream>
#include <cassert>
// #include <chrono>
// #include <thread>

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

    for ( auto i = message["message"].cbegin(); i != message["message"].cend(); i++ )
    {
        // std::chrono::seconds dura(3);
        // std::this_thread::sleep_for( dura );
        std::cout << "\n " << ( (std::string) *i );
    }

    std::cout << "\n";

    messageFile.close();
}   