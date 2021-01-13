/*!
    * \file FightWriter.cpp
*/

#include "FightWriter.h"

// #include <iostream>

#include "Pause.h"

#include <tabulate/table.hpp>
#include <cpp-terminal/terminal.h>

FightWriter::FightWriter
( 
    const Player* const player, 
    const std::vector<Plug>& plugs 
) :
    player_( player ),
    plugs_( plugs ),
    numberOfDeadPlug_( 0 )
{
    Pause::pause();
    std::cout << "\n " 
        << Term::color(Term::fg::yellow) 
        << Term::color(Term::style::bold)
        << "Début du combat"
        << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset); 
}

void FightWriter::writeHeader( const int& nbTurns ) const
{
    Pause::pause();

    std::cout << "\n" 
        << Term::color(Term::fg::blue) 
        << Term::color(Term::style::bold) 
        << "===================="
        << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset); 

    std::cout << "\n "
        << Term::color(Term::fg::black)  
        << Term::color(Term::bg::green)
        << Term::color(Term::style::bold)   
        << "Tour " 
        << nbTurns
        << Term::color(Term::fg::reset)
        << Term::color(Term::bg::reset)
        << Term::color(Term::style::reset); 

    std::cout << "\n" 
        << Term::color(Term::fg::blue) 
        << Term::color(Term::style::bold) 
        << "===================="
        << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset); 
}

void FightWriter::writeGameBoard() const 
{
    Pause::pause();

    std::cout << "\n" 
        << Term::color(Term::fg::black)  
        << Term::color(Term::bg::green)
        << Term::color(Term::style::bold)   
        << "Plateau de jeu"
        << Term::color(Term::fg::reset)
        << Term::color(Term::bg::reset)
        << Term::color(Term::style::reset); 

    std::cout << "\n" 
        << Term::color(Term::fg::black)  
        << Term::color(Term::style::bold)   
        << "========"
        << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset); 

    tabulate::Table fighters;
    std::vector<variant<std::string, const char *, tabulate::Table>> nameFighters;
    std::vector<variant<std::string, const char *, tabulate::Table>> lifePointsFighters;
    std::vector<variant<std::string, const char *, tabulate::Table>> damageWeaponFighters;

    // build a vector of name and life points of plugs
    for(int i = 0; i < plugs_.size(); i++ )
    {
        // display plugs only if they are not dead
        if ( !(plugs_[i].deadOrNot()) )
        {
            nameFighters.push_back( plugs_[i].name() );
            lifePointsFighters.push_back( 
                std::to_string( plugs_[i].lifePoints() ) + " points de vie" 
            );
            damageWeaponFighters.push_back(
                std::to_string( plugs_[i].weapon().damageWeapon() ) + " points d'attaque"
            );
        }
    }

    fighters.add_row( nameFighters );
    fighters.add_row( lifePointsFighters );
    fighters.add_row( damageWeaponFighters );

    std::vector<variant<std::string, const char *, tabulate::Table>> 
        emptyLine( nameFighters.size(), "" );
    fighters.add_row( emptyLine );

    std::vector<variant<std::string, const char *, tabulate::Table>> 
        playerLine( nameFighters.size(), "" );
    playerLine[nameFighters.size()/2] = player_->pseudo();
    fighters.add_row( playerLine );

    std::vector<variant<std::string, const char *, tabulate::Table>> 
        lifePlayerPoints( nameFighters.size(), "" );
    lifePlayerPoints[nameFighters.size()/2] 
        = std::to_string( player_->nbLifePoints() ) + " points de vie";
    fighters.add_row( lifePlayerPoints );

    fighters.format()
        .font_style({tabulate::FontStyle::bold})
        .border_top("")
        .border_bottom(" ")
        .border_left(" ")
        .border_right(" ")
        .corner(" ");

    fighters[0].format()
        .padding_top(0)
        .padding_bottom(1)
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::red);

    fighters[1].format()
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::yellow);

    fighters[2].format()
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::magenta);

    fighters[3].format()
        .padding_top(1)
        .padding_bottom(1);

    fighters[4].format()
        .padding_top(1)
        .padding_bottom(1)
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::green);

    fighters[5].format()
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::yellow);

    std::cout << "\n" << fighters;

}


void FightWriter::writeRemoveDeadBody()
{
    const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

    // if the condition is true, it mean that at least one en
    if ( numberOfDeadPlug_ != countNumberOfDeadPlug )
    {
        numberOfDeadPlug_ = countNumberOfDeadPlug;
        
        Pause::pause();
        std::cout << "\n " 
            << Term::color(Term::fg::yellow)  
            << Term::color(Term::style::bold)   
            << "Evacuation des cadavres."
            << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset); 
    }
}

void FightWriter::writeEndOfFight() const 
{
    Pause::pause();
    std::cout << "\n " 
        << Term::color(Term::fg::yellow)  
        << Term::color(Term::style::bold)    
        << "Fin du combat"
        << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset); 
}


const int FightWriter::methodNumberOfDeadPlug() const
{
    int numberOfDead = 0;
    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        if ( e->deadOrNot() )
        {
            numberOfDead++;
        }
    } 
    return numberOfDead;
}
