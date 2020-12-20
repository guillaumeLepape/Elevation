/*!
    * \file Selection.cpp
*/

#include <limits>

#include "Selection.h"
#include "../color.h"
#include "../Writer/Pause.h"

#include "../Writer/SelectionWriter.h"

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
            std::cout << BOLDRED << "Selection invalide - Entrez un nombre compris entre 1 et " 
                << actions.size() << " !" <<  RESET << "\n";
        }
        else 
        {
            std::cout << BOLDRED << "Selection invalide - Entrez un nombre égale à 1 !" << RESET << "\n";
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