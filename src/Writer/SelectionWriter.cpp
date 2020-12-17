/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

#include <iostream>

#include "Pause.h"
#include "../color.h"

SelectionWriter::SelectionWriter( const SelectionData& selectionData ) :
    selectionData_( selectionData )
{

}

void SelectionWriter::writeSelection()
{
    Pause::pause();

    std::cout << "\n " << GREENSIDEBAR << BOLDBLACK << selectionData_.title() << RESET;

    std::cout << "\n" << BOLDBLACK << "========" << RESET;
    for ( int i = 0; i < selectionData_.propositions().size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " << BOLDMAGENTA << selectionData_.propositions()[i] << RESET;
    }

    if ( selectionData_.propositions().size() != 1 )
    {
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK << "Entrez un chiffre entre " 
            << 1 << "-" 
            << selectionData_.propositions().size() << RESET
            << " : ";
    }
    else 
    {
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK << "Entrez un chiffre égale à 1" 
            << RESET << " : ";
    }
}