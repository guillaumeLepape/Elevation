/*!
    * \file FightWriter.cpp
*/

#include "FightWriter.h"

// #include <iostream>

#include "Pause.h"
#include "color.h"

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
    std::cout << "\n | ";

    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        std::cout << BOLDRED << e->name() << RESET << " | ";
    }
    std::cout << "\n ";

    int totalNbCaracters = 0;

    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        int n = numberCharactersString(e->name()) + 3 
                - std::to_string( e->lifePoints() ).length();

        if ( n%2 == 0 )
        {
            int q = n/2;
            std::cout << std::string( q, ' ' ) << BOLDYELLOW << e->lifePoints() << RESET << std::string( q, ' ' );
        }
        else
        {
            int q1 = (n+1)/2;
            int q2 = (n-1)/2;
            std::cout << std::string( q1, ' ' ) << BOLDYELLOW << e->lifePoints() << RESET<< std::string( q2, ' ' );
        }

        totalNbCaracters += numberCharactersString(e->name()) + 3;
    }
    totalNbCaracters += 1;

    std::cout << "\n ";
    std::cout << "\n ";

    int n = totalNbCaracters - numberCharactersString( player_->pseudo() );

    if ( n%2 )
    {
        int q = n/2;
        std::cout << "\n" << std::string(q, ' ') << BOLDGREEN << player_->pseudo() << RESET << std::string(q, ' ');
    }   
    else
    {
        int q1 = (n+1)/2;
        int q2 = (n-1)/2;
        std::cout << "\n" << std::string(q1,' ') << BOLDGREEN << player_->pseudo() << RESET << std::string( q2, ' ' );
    }
    std::cout << "\n";
}


int FightWriter::numberCharactersString( const std::string& str)
{
    int l = 0;
    for ( int i = 0; i < str.length(); i++ )
    {
        char c = str[i];
        if ( c != -61 )
        {
            l++;
        }
    }
    return l;
}
