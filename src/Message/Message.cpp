#include "Message.h"

#include <fstream>
#include <cassert>

#include <nlohmann/json.hpp>

Message::Message( const std::string& fileName, Player* player )
    : fileName_( fileName ), player_(player)
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
        std::cout << "\n ";

        std::string name = (std::string) (*i)[0];

        if ( name == "player" )
        {
            std::cout << player_->pseudo();
        }
        else if ( name == "plug" )
        {
            std::cout << "plug";
        }
        else if ( name == "description" )
        {
            std::cout << "Description";
        }
        else
        {
             assert( false );
        }
        
        std::cout << " : " << ( (std::string) (*i)[1] );
    }

    std::cout << "\n";

    messageFile.close();
}   