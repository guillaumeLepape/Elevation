/*!
    * \file TutorialWriter.cpp
*/

#include "TutorialWriter.h"

#include <iostream>

#include "Pause.h"

#include <cpp-terminal/terminal.h>

TutorialWriter::TutorialWriter
(  
    const std::string& folderFromRoot,
    const std::string& fileName
) :
    tutorialData_( folderFromRoot, fileName )
{

}

void TutorialWriter::writeTutorial() const 
{
    Pause::pause();

    std::cout << "\n " 
        << Term::color( Term::bg::magenta )
        << Term::color( Term::style::bold )
        << tutorialData_.name() 
        << Term::color( Term::bg::reset )
        << Term::color( Term::style::reset );

    std::cout << "\n" 
        << Term::color( Term::fg::black )
        << Term::color( Term::style::bold )
        << "========" 
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    for ( int i = 0; i < tutorialData_.tutorialStatement().size(); i++ )
    {
        Pause::pause();

        std::cout << "\n " 
            << Term::color( Term::fg::magenta )
            << Term::color( Term::style::bold ) 
            << tutorialData_.tutorialStatement()[i] 
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );
    }

    std::cout << "\n";
}