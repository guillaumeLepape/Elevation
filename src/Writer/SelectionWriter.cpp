/*!
    * \file SelectionWriter.cpp
*/

#include "SelectionWriter.h"

#include "Pause.h"

SelectionWriter::SelectionWriter
(
    const std::vector<Action*>& actions,
    const std::string& title
) :
    actions_( actions ),
    title_( title )
{

}

void SelectionWriter::writeSelection() const
{
    Pause::pause();

    std::cout << "\n "
        << Term::color( Term::fg::black ) 
        << Term::color( Term::bg::green ) 
        << Term::color( Term::style::bold ) 
        << title_ 
        << Term::color( Term::fg::reset ) 
        << Term::color( Term::bg::reset ) 
        << Term::color( Term::style::reset );

    std::cout << "\n" 
        << Term::color( Term::fg::black ) 
        << Term::color( Term::style::bold )  
        << "========" 
        << Term::color( Term::fg::reset ) 
        << Term::color( Term::style::reset );

    for ( long unsigned int i = 0; i < actions_.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " 
            << Term::color( Term::fg::yellow ) 
            << Term::color( Term::style::bold )   
            << actions_[i]->actionWriter().statement() 
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