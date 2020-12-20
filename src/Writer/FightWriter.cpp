/*!
    * \file FightWriter.cpp
*/

#include "FightWriter.h"

#include <iostream>

#include "Pause.h"
#include "../color.h"

FightWriter::FightWriter
( 
    const Player* const player, 
    const std::vector<Plug>& plugs 
) :
    player_( player ),
    plugs_( plugs )
{

}

void FightWriter::writeHeader( const int& nbTurns ) const
{
    Pause::pause();

    std::cout << "\n" << BOLDBLACK << "========" << RESET;
    std::cout << "\n Tour : " << nbTurns; 
    std::cout << "\n" << BOLDBLACK << "========" << RESET;
}

void FightWriter::writeGameBoard() const 
{
    
}