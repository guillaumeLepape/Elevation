/*!
    * \file Message.cpp 
*/

#include "Message.h"

#include <fstream>

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

        pause();

        writeName( name, player, plug );

        writeMessage( message, player, plug, i );
        
        // std::cout << "\n";
    }
}   

void Message::writeHeader() const
{
    pause();

    // print level name
    std::cout << "\n " << BOLDREDSIDEBAR << (std::string) jsonObject_["nameLevel"] << RESET;
    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    // print the hour
    std::cout << "\n " << BOLDCYAN << jsonObject_["hour"] << "h" << jsonObject_["minut"] << RESET;
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
        // std::cout << "Description";
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

void Message::pause() const 
{
    std::string myString = "";

    do 
    {
        std::getline(std::cin, myString);
    } 
    while (myString.length() != 0);
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
        else
        {
            result += vecResult[i];
        }
    } 

    return result;    
}
