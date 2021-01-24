/*!
    * \file Quit.cpp
*/

#include "Quit.h"

#include <iostream>

Quit::Quit
( 
    const std::string& statement, 
    const std::string& result
) : 
    Action( statement, result )
{

}

void Quit::triggerAction()  
{ 
    actionWriter_.writeResult();
    std::cout << "\n";
    exit(0);
}