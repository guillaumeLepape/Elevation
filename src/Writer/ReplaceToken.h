#ifndef REPLACE_TOKEN_H
#define REPLACE_TOKEN_H

/*!
    * \file ReplaceToken.h
*/

#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp> 

#include "../Player/Player.h"
#include "../Plug/Plug.h"

class ReplaceToken
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
};

#endif