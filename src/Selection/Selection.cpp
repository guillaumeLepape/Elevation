/*!
    * \file Selection.cpp
*/

#include <limits>

#include "Selection.h"

int Selection::select
( 
    const std::vector<Action*>& actions,
    const std::string& folderFromRoot,
    const std::string& nameFile
)
{
    std::vector<const ActionWriter*> actionWriter( 
        vectorOfActionsToVectorOfActionWriter( actions )
    );
    SelectionWriter selectionWriter( actionWriter, folderFromRoot, nameFile );
    int result = select( actions, selectionWriter );
    return result;
}

int Selection::select
(
    const std::vector<Action*>& actions,
    const std::string& title
)
{
    std::vector<const ActionWriter*> actionWriter( 
        vectorOfActionsToVectorOfActionWriter( actions )
    );
    SelectionWriter selectionWriter( actionWriter, title );
    int result = select( actions, selectionWriter );
    return result;
}

int Selection::select
(
    const std::vector<Action*>& actions,
    const SelectionWriter& selectionWriter
)
{
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

std::vector<const ActionWriter*> 
    Selection::vectorOfActionsToVectorOfActionWriter( const std::vector<Action*>& actions )
{
    std::vector<const ActionWriter*> actionWriter;
    for ( auto a = actions.cbegin(); a != actions.cend(); a++ )
    {
        actionWriter.push_back( &((*a)->actionWriter()) );
    }
    return actionWriter;
}