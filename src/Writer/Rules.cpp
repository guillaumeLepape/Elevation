/*!
    * \file Rules.cpp
*/

#include "Rules.h"

#include "color.h"
#include "Pause.h"

void Rules::displayRules()
{
    system("clear"); 

    std::cout << "\n " << GREENSIDEBAR << BOLDBLACK << "Interface" << RESET;

    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    std::cout << "\n Une fois que vous avez lu un message, appuyez sur entrée pour passer au suivant.";

    Pause::pause();

    std::cout << "\n Si un champ doit être rempli pour continuer le jeu, cela sera indiqué par la couleur " 
                << YELLOWSIDEBAR << BOLDBLACK << "noir encadré jaune" << RESET << ".";

    Pause::pause();

    std::cout << "\n Le pseudo du joueur est affiché en " 
                << BOLDGREEN << "vert" 
                << RESET << ".";

    Pause::pause();

    std::cout << "\n Le nom du dealer est affiché en " 
                << BOLDRED << "rouge" 
                << RESET << ".";

    Pause::pause();

    std::cout << "\n Les dialogues sont affichés en " 
                << BOLDBLUE << "bleu" 
                << RESET << ".";

    Pause::pause();

    std::cout << "\n Les descriptions sont affichées en " 
                << BOLDMAGENTA << "magenta" 
                << RESET << ".";

    Pause::pause();

    std::cout << "\n Les effets résultant des actions du joueur sont affichés en " 
                << BOLDYELLOW << "jaune" 
                << RESET << ".";

    std::cout << "\n";
}