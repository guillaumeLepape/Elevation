/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

#include "Pause.h"

SelectionWriter::SelectionWriter
( 
    const std::vector<const ActionWriter*>& actionWriter,
    const nlohmann::json& jsonObject
) :
    actionWriter_( actionWriter ),
    selectionData_( jsonObject )
{

}

SelectionWriter::SelectionWriter
(
    const std::vector<const ActionWriter*>& actionWriter,
    const std::string& title
) :
    actionWriter_( actionWriter ),
    selectionData_( title )
{

}

SelectionWriter::SelectionWriter
(
    const std::vector<const ActionWriter*>& actionWriter,
    const SelectionData& selectionData
) :
    actionWriter_( actionWriter ),
    selectionData_( selectionData )
{

}

SelectionWriter::SelectionWriter
(
    const std::vector<const ActionWriter*>& actionWriter,
    const std::string& folderFromRoot,
    const std::string& fileName
) :
    actionWriter_( actionWriter ),
    selectionData_( folderFromRoot, fileName )
{

}

void SelectionWriter::writeSelection() const
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

    for ( int i = 0; i < actionWriter_.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " 
            << Term::color( Term::fg::yellow ) 
            << Term::color( Term::style::bold )   
            << actionWriter_[i]->actionData().statement() 
            << Term::color( Term::fg::reset ) 
            << Term::color( Term::style::reset );   
    }

    if ( actionWriter_.size() != 1 )
    {
        std::cout << "\n " 
            << Term::color( Term::fg::black ) 
            << Term::color( Term::bg::yellow ) 
            << Term::color( Term::style::bold ) 
            << "Entrez un chiffre entre " 
            << 1 << "-" 
            << actionWriter_.size() 
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