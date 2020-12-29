/*!
    * \file TutorialWriter.cpp
*/

#include "TutorialWriter.h"

#include <iostream>

#include "Pause.h"
#include "color.h"

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

    std::cout << "\n " << MAGENTASIDEBAR << BOLDWHITE << tutorialData_.name() << RESET;
    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    for ( int i = 0; i < tutorialData_.tutorialStatement().size(); i++ )
    {
        Pause::pause();

        std::cout << "\n " 
            << BOLDMAGENTA << tutorialData_.tutorialStatement()[i] 
            << RESET;
    }

    std::cout << "\n";
}