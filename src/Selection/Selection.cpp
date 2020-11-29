#include <iostream>
#include <limits>

#include "Selection.h"

Selection::Selection()
{

}

void Selection::select
( 
    const std::string& selectionTitle,
    const std::vector<Action*>& actions 
) const
{
    bool error = true;
    int choice = 0;

    printMenu( selectionTitle, actions );

    while (!(std::cin >> choice) || (choice > actions.size() || choice < 1)) 
    {
        std::cout << "Selection invalide - Entrez un nombre compris entre 1 to " 
            << actions.size()  << " only.\n";

        // reset error flags
        std::cin.clear();

        // throw away garbage input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        printMenu( selectionTitle, actions );
    }

    std::cout<<"\n";

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
    std::cout << "\n " << selectionTitle;

    std::cout << "\n========";
    for ( int i = 0; i < actions.size(); i++ )
    {
        std::cout << "\n " 
            << std::to_string( i + 1 ) 
            << "- " << actions[i]->statement();
    }

    std::cout << "\n Enter selection (between " 
        << 1 << "-" 
        << actions.size() 
        << ") : ";
}