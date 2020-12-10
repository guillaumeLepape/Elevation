/*!
    * \file Selection.cpp
*/

#include <limits>

#include "Selection.h"
#include "../color.h"

Selection::Selection()
{

}

void Selection::select
( 
    const std::string& selectionTitle,
    const std::vector<Action*>& actions 
) const
{
    int choice = 0;

    printMenu( selectionTitle, actions );

    while (!(std::cin >> choice) || (choice > actions.size() || choice < 1)) 
    {
        if ( actions.size() != 1 )
        {
            std::cout << "Selection invalide - Entrez un nombre compris entre 1 et " 
                << actions.size()  << ".\n";
        }
        else 
        {
            std::cout << "Selection invalide - Entrez un nombre égale à 1";
        }
        // reset error flags
        std::cin.clear();

        // throw away garbage input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        printMenu( selectionTitle, actions );
    }

    std::cout << "\n";

    for ( int i = 0; i < actions.size(); i++ )
    {
        if ( choice == i + 1 )
        {
            actions[i]->triggerAction();
        }
    }
} 

void Selection::printMenu
(
    const std::string& selectionTitle,
    const std::vector<Action*>& actions 
) const
{
    std::cout << "\n " << BOLDGREENSIDEBAR << selectionTitle << RESET;

    std::cout << "\n" << BOLDBLACK << "========" << RESET;
    for ( int i = 0; i < actions.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " << BOLDMAGENTA << actions[i]->statement() << RESET;
    }

    if ( actions.size() != 1 )
    {
        std::cout << "\n " << BOLDYELLOW << "Entrez un chiffre entre " 
            << 1 << "-" 
            << actions.size() << RESET
            << " : ";
    }
    else 
    {
        std::cout << "\n Entrez un chiffre égale à 1 : ";
    }
}