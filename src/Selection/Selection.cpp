/*!
    * \file Selection.cpp
*/

#include <limits>

#include "Selection.h"
#include "Pause.h"
#include "SelectionWriter.h"

int Selection::select
( 
    const std::vector<Action*>& actions,
    const std::string& folderFromRoot,
    const std::string& nameFile
)
{
    SelectionWriter selectionWriter( actions, folderFromRoot, nameFile );
    selectionWriter.writeSelection();

    int choice = 0;

    while (!(std::cin >> choice) || (choice > actions.size() || choice < 1)) 
    {
        if ( actions.size() != 1 )
        {
            std::cout << Term::color( Term::fg::red )
                << Term::color( Term::style::bold ) 
                << "Selection invalide - Entrez un nombre compris entre 1 et " 
                << actions.size() 
                << " !" 
                << Term::color( Term::fg::reset )
                << Term::color( Term::style::reset )  
                << "\n";
        }
        else 
        {
            std::cout << Term::color( Term::fg::red )
                << Term::color( Term::style::bold )  
                << "Selection invalide - Entrez un nombre égale à 1 !" 
                << Term::color( Term::fg::reset )
                << Term::color( Term::style::reset )   
                << "\n";
        }
        // reset error flags
        std::cin.clear();

        // throw away garbage input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        selectionWriter.writeSelection();    
    }

    for ( int i = 0; i < actions.size(); i++ )
    {
        if ( choice == i + 1 )
        {
            actions[i]->triggerAction();
        }
    }    

    return choice - 1;
}