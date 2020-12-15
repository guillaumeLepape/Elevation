/*!
    * \file Message.cpp 
*/

#include "Message.h"
#include "../Writer/Pause.h"

#include <fstream>
#include <iomanip>

#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 
#include <vector>

#include "../color.h"

Message::Message( const std::string& fileName )
{
    // open json file
    std::ifstream messageFile( fileName, std::ifstream::binary );

    // check if the file is opened
    assert( messageFile.is_open() );

    // read jsonfile 
    messageFile >> jsonObject_;

    messageFile.close();
}

void Message::writeInConsole( Player* player, Plug* plug, const int& indexMessage  ) const
{
    const auto& message = jsonObject_["message"][indexMessage];

    for ( int i = 0; i < message.size(); i++ )
    {
        std::string name = (std::string) message[i][0];

        Pause::pause();

        writeName( name, player, plug );

        writeMessage( message, player, plug, i );
    }
}   

void Message::writeHeader() const
{
    Pause::pause();

    // print level name
    std::cout << "\n " << REDSIDEBAR << BOLDWHITE << (std::string) jsonObject_["nameLevel"] << RESET;
    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    // print the hour
    std::cout << "\n " << BOLDWHITE;
    std::cout << std::setfill('0') << std::setw(2) << (int) jsonObject_["hour"];
    std::cout << "h";
    std::cout << std::setfill('0') << std::setw(2) << (int) jsonObject_["minut"];
    std::cout << RESET;
    std::cout << "\n" <<  BOLDBLACK << "========" << RESET;
}

void Message::writeName( const std::string& name, Player* player, Plug* plug ) const
{
    if ( name == "player" )
    {
        std::cout << "\n        " << BOLDGREEN << player->pseudo() << RESET << BLUE;
    }
    else if ( name == "plug" )
    {
        std::cout << "\n        " << BOLDRED << plug->name() << RESET << BLUE;
    }
    else if ( name == "description" )
    {
        std::cout << BOLDMAGENTA;
    }
    else if ( name == "action" )
    {
        std::cout << BOLDYELLOW;
    }
    else
    {
        assert( false );
    }
}

void Message::writeMessage
( 
    const nlohmann::json& message, 
    Player* player, 
    Plug* plug, 
    const int& i 
) const
{
    if ( message[i][1] )
    {
        std::cout << "\n " << replacePlayerPlug( (std::string) message[i][2], player, plug );
    }
    else
    {
        std::cout << "\n " << ( (std::string) message[i][2] );
    }
    std::cout << RESET;
}


std::string Message::replacePlayerPlug(const std::string& str, Player *player, Plug *plug) const
{
    std::vector<std::string> vecResult; 
    boost::split(vecResult, str, boost::is_any_of("-*"), boost::token_compress_on); 
  
    std::string result;

    for (unsigned int i = 0; i < vecResult.size(); i++)
    {
        if ( vecResult[i] == "pseudo" )
        {
            result += player->pseudo();
        }
        else if ( vecResult[i] == "plugName" )
        {
            result += plug->name();
        }
        else if ( vecResult[i] == "money" )
        {
            result += std::to_string( plug->price() );
        }
        else if ( vecResult[i] == "damage" )
        {
            result += std::to_string( player->selectedWeapon().damageWeapon() );
        }
        else
        {
            result += vecResult[i];
        }
    } 

    return result;    
}
