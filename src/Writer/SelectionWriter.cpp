/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

// #include <iostream>

#include "Pause.h"
#include "color.h"

SelectionWriter::SelectionWriter
( 
    const std::vector<Action*>& actions,
    const nlohmann::json& jsonObject
) :
    actions_( actions ),
    selectionData_( jsonObject )
{

}

SelectionWriter::SelectionWriter
(
    const std::vector<Action*>& actions,
    const SelectionData& selectionData
) :
    actions_( actions ),
    selectionData_( selectionData )
{

}

SelectionWriter::SelectionWriter
(
    const std::vector<Action*>& actions,
    const std::string& folderFromRoot,
    const std::string& fileName
) :
    actions_( actions ),
    selectionData_( folderFromRoot, fileName )
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