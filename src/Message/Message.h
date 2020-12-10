#ifndef MESSAGE_H
#define MESSAGE_H

/*!
    * \file Message.h
*/ 

#include <iostream>

#include <nlohmann/json.hpp>

#include "../Player/Player.h"
#include "../Plug/Plug.h"

/*!
    * \class Message
    * \brief Write message in console
    * Read message in a json file and write it the terminal
*/

class Message
{
    private:
        // json variable to store message from a json file
        nlohmann::json jsonObject_;

        std::string replacePlayerPlug(const std::string& str, Player* player, Plug* plug) const;

        void writeName( const std::string& name, Player* player, Plug* plug ) const;
        
        void writeMessage
        ( 
            const nlohmann::json& message, 
            Player* player, 
            Plug* plug, 
            const int& i 
        ) const;

    public:
        explicit Message( const std::string& fileName );

        void writeHeader() const;
        void writeInConsole( Player* player, Plug* plug, const int& indexMessage ) const;
};

#endif