#include <iostream>

#include "Selection.h"

Selection::Selection()
{

}

void Selection::newSelection
( 
    const std::string& selectionTitle,
    const std::vector<Action*>& actions 
)
{
    int selection;
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

    std::cin >> selection;
    std::cout<<"\n";

    for ( int i = 0; i < actions.size(); i++ )
    {
        if ( selection == i + 1 )
        {
            actions[i]->triggerAction();
        }
    }


} 