/*!
    * \file FightWriter.cpp
*/

#include "FightWriter.h"

// #include <iostream>

#include "Pause.h"
#include "color.h"

#include <tabulate/table.hpp>

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

    std::cout << "\n" << BOLDBLUE << "====================" << RESET;
    std::cout << "\n " << BOLDBLACK << GREENSIDEBAR << "Tour " << nbTurns << RESET; 
    std::cout << "\n" << BOLDBLUE << "====================" << RESET;
}

void FightWriter::writeGameBoard() const 
{
    Pause::pause();

    std::cout << "\n" << GREENSIDEBAR << BOLDBLACK << "Plateau de jeu" << RESET;
    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    tabulate::Table fighters;
    std::vector<variant<std::string, const char *, tabulate::Table>> nameFighters;
    std::vector<variant<std::string, const char *, tabulate::Table>> lifePointsFighters;

    // build a vector of name and life points of plugs
    for(int i = 0; i < plugs_.size(); i++ )
    {
        nameFighters.push_back( plugs_[i].name() );
        lifePointsFighters.push_back( 
            std::to_string( plugs_[i].lifePoints() ) + " points de vie" 
        );
    }

    fighters.add_row( nameFighters );
    fighters.add_row( lifePointsFighters );
    fighters.add_row( {"", "", ""} );
    fighters.add_row( { "", player_->pseudo(), ""} );
    fighters.add_row( 
        { "", std::to_string( player_->nbLifePoints() ) + " points de vie", "" } 
    );

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
        .padding_top(1)
        .padding_bottom(1);

    fighters[3].format()
        .padding_top(1)
        .padding_bottom(1)
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::green);

    fighters[4].format()
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::yellow);

    std::cout << "\n" << fighters;

}
