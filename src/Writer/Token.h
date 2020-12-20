#ifndef REPLACE_TOKEN_H
#define REPLACE_TOKEN_H

/*!
    * \file Token.h
*/

#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp> 

#include "../Player/Player.h"
#include "../Plug/Plug.h"

class Token
{
    public: 
        static std::string replace
        ( 
            const std::string& str, 
            const Player* const player, 
            const Plug* const plug 
        )
        {
            std::vector<std::string> vecResult; 
            boost::split(vecResult, str, boost::is_any_of("-*"), boost::token_compress_on); 
  
            std::string result;

            for (unsigned int i = 0; i < vecResult.size(); i++)
            {
            if ( vecResult[i] == "pseudo" )
            {
                if ( player != nullptr )
                {                
                    result += player->pseudo();
                }
                else
                {
                    assert(false);
                }            
            }
            else if ( vecResult[i] == "plugName" )
            {
                if ( plug != nullptr )
                {
                    result += plug->name();
                }
                else
                {
                    assert(false);
                }
            }
            else if ( vecResult[i] == "pricePlayer" )
            {
                if ( player != nullptr )
                {
                    result += std::to_string( player->price() );
                }
                else
                {
                    assert(false);
                }
            }
            else if ( vecResult[i] == "pricePlug" )
            {
                if ( plug != nullptr )
                {
                    result += std::to_string( plug->price() );
                }
                else
                {
                    assert(false);
                }
            }
            else if ( vecResult[i] == "damage" )
            {
                if ( player != nullptr )
                {
                    result += std::to_string( player->selectedWeapon().damageWeapon() );    
                }
                else
                {
                    assert(false);
                }
            }
            else
            {
                result += vecResult[i];
            }
        } 

        return result;  
    }
};

#endif