#include "Message.h"

#include <fstream>
#include <cassert>

#include <nlohmann/json.hpp>

#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 
#include <vector>

Message::Message( const std::string& fileName, Player* player, Plug* plug )
    : fileName_( fileName ), player_(player), plug_(plug)
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

    // print level name
    std::cout << "\n " << (std::string) message["nameLevel"];
    std::cout << "\n========";

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
            std::cout << plug_->name();
        }
        else if ( name == "description" )
        {
            std::cout << "Description";
        }
        else
        {
             assert( false );
        }
        
        if ( (*i)[1]["token"] )
        {
            std::cout << " : " << ( replacePlayerPlug( (std::string) (*i)[2] ) );
        }
        else
        {
            std::cout << " : " << ( (std::string) (*i)[2] );
        }
        
    }

    std::cout << "\n";

    messageFile.close();
}   


std::string Message::replacePlayerPlug(const std::string& str)
{
    std::vector<std::string> vecResult; 
    boost::split(vecResult, str, boost::is_any_of("-*"), boost::token_compress_on); 
  
    std::string result;

    for (int i = 0; i < vecResult.size(); i++)
    {
        if ( vecResult[i] == "pseudo" )
        {
            result += player_->pseudo();
        }
        else if ( vecResult[i] == "plugName" )
        {
            result += plug_->name();
        }
        else
        {
            result += vecResult[i];
        }
    } 

    return result;    
}
