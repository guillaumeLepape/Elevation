/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

#include "Pause.h"

#include <cpp-terminal/terminal.h>

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

    std::cout << "\n "
        << Term::color( Term::fg::black ) 
        << Term::color( Term::bg::green ) 
        << Term::color( Term::style::bold ) 
        << selectionData_.title() 
        << Term::color( Term::fg::reset ) 
        << Term::color( Term::bg::reset ) 
        << Term::color( Term::style::reset );

    std::cout << "\n" 
        << Term::color( Term::fg::black ) 
        << Term::color( Term::style::bold )  
        << "========" 
        << Term::color( Term::fg::reset ) 
        << Term::color( Term::style::reset );

    for ( int i = 0; i < actions_.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " 
            << Term::color( Term::fg::yellow ) 
            << Term::color( Term::style::bold )   
            << actions_[i]->actionWriter().actionData().statement() 
            << Term::color( Term::fg::reset ) 
            << Term::color( Term::style::reset );   
    }

    if ( actions_.size() != 1 )
    {
        std::cout << "\n " 
            << Term::color( Term::fg::black ) 
            << Term::color( Term::bg::yellow ) 
            << Term::color( Term::style::bold ) 
            << "Entrez un chiffre entre " 
            << 1 << "-" 
            << actions_.size() 
            << Term::color( Term::fg::reset ) 
            << Term::color( Term::bg::reset ) 
            << Term::color( Term::style::reset ) 
            << " : ";
    }
    else 
    {
        std::cout << "\n " 
            << Term::color( Term::fg::black ) 
            << Term::color( Term::bg::yellow ) 
            << Term::color( Term::style::bold )  
            << "Entrez un chiffre égale à 1" 
            << Term::color( Term::fg::reset ) 
            << Term::color( Term::bg::reset ) 
            << Term::color( Term::style::reset ) 
            << " : ";
    }
}