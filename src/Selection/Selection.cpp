#include <iostream>

#include "Selection.h"

Selection::Selection()
{

}

void Selection::newSelection
( 
    const std::string& selectionTitle,
    const std::vector<std::string>& selections,
    const std::vector<Action*>& actions 
)
{
    int selection;
    std::cout << "\n " << selectionTitle;

    std::cout << "\n========";
    for ( auto i = selections.cbegin(); i != selections.cend(); i++ )
    {
        std::cout << "\n " << std::to_string(std::distance(selections.cbegin(),i + 1)) << "- " << *i;
    }

    std::cout << "\n Enter selection (between " << 1 << "-" << selections.size() << ") : ";

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