/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

#include <iostream>

#include "Pause.h"
#include "../color.h"

SelectionWriter::SelectionWriter
( 
    const int& levelNumber, 
    const int& indexSelection, 
    const std::vector<Action*>& actions
) :
    selectionData_( levelNumber, indexSelection ),
    actions_(actions)
{
    
}

void SelectionWriter::writeSelection()
{
    Pause::pause();

    std::cout << "\n " << GREENSIDEBAR << BOLDBLACK << selectionData_.title() << RESET;

    std::cout << "\n" << BOLDBLACK << "========" << RESET;
    for ( int i = 0; i < actions_.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " << BOLDYELLOW << actions_[i]->actionWriter().actionData().statement() << RESET;
    }

    if ( actions_.size() != 1 )
    {
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK << "Entrez un chiffre entre " 
            << 1 << "-" 
            << actions_.size() << RESET
            << " : ";
    }
    else 
    {
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK << "Entrez un chiffre égale à 1" 
            << RESET << " : ";
    }
}