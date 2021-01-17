#ifndef FRENCH_DATA_H
#define FRENCH_DATA_H

#include <string>
#include <vector>
#include <memory>

namespace data
{
    namespace Introduction
    {
        // Introduction data
        // ***********************************

        // Header data
        static std::string nameLevel = "Introduction : Dur réveil";
        static int hour = 13;
        static int minut = 12;

        // Messages data
        static std::vector<std::vector<std::tuple<std::string, bool, std::string>>> messages = {
            {
                {"description", false, ""},
                {"description", false, ""},
                {"description", false, ""},
                {"description", false, ""},
            },
            {{"player", false, ""}},
            {{"player", false, ""}},
            {{"player", false, ""}},
            {{"player", true, ""}}};
    } // namespace Introduction

    namespace Level1
    {
        // Level 1 data
        // ***********************************

        // Header data
        static std::string nameLevel = "Niveau 1 : Beuh";
        static int hour = 14;
        static int minut = 35;
    } // namespace Level1

    namespace Level2
    {
        static std::string nameLevel = "Niveau 2 : Coke";
        static int hour = 15;
        static int minut = 10;
    } // namespace Level2

    namespace Level3
    {
        static std::string nameLevel = "Niveau 3 : Shit";
        static int hour = 16;
        static int minut = 4;
    } // namespace Level3

    namespace Level4
    {
        static std::string nameLevel = "Niveau 4 : Lean";
        static int hour = 17;
        static int minut = 15;
    } // namespace Level4

    namespace Level5
    {
        static std::string nameLevel = "Niveau 5 : Xanax";
        static int hour = 19;
        static int minut = 2;
    } // namespace Level5

    namespace Action
    {
        // generic UseWeapon data statement for fist
        static std::tuple<bool, std::string> statementUseFist(false, "Cognez ! (Poing)");
        // generic UseWeapon data statement for knife
        static std::tuple<bool, std::string> statementUseKnife(false, "Plantez ! (Couteau)");
        static std::tuple<bool, std::string> statementUseKnifeFistCombo(false, "Combo avec le couteau !");
        // generic UseWeapon data statement for katana
        static std::tuple<bool, std::string> statementUseKatana(false, "Découpez ! (Katana)");
        static std::tuple<bool, std::string> statementUseKatanaFistCombo(false, "Combo avec le katana !");

        // generic UseWeapon data result
        static std::tuple<bool, std::string> resultUseWeapon(true, "-*-plugName-*- perd -*-damage-*- points de vie.");

        static std::unique_ptr<std::tuple<bool, std::string>> newStatementUseWeapon(const std::string &nameWeapon)
        {
            if (nameWeapon == "Poing")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseFist);
            }
            if (nameWeapon == "Couteau")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKnife);
            }
            if (nameWeapon == "Katana")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKatana);
            }
            if (nameWeapon == "CouteauFistCombo")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKnifeFistCombo);
            }
            if (nameWeapon == "KatanaFistCombo")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKatanaFistCombo);
            }
            assert(false);
        }

        static std::tuple<bool, std::string> statementChoosePlug( true, "Attaquer -*-plugName-*-." );
        static std::tuple<bool, std::string> resultChoosePlug( true, "Vous avez choisi d'attaquer -*-plugName-*-." );

        static std::tuple<bool, std::string> resultPlugAttack( true, "-*-plugName-*- vous inflige -*-damagePlug-*- points de vie." );

        static std::tuple<bool, std::string> resultDead( true, "-*-plugName-*- est mort." );

    } // namespace Action

    namespace Menu 
    {
        // title of startGame menu 
        static std::string titleStartGameMenu = "Menu";

        // data for startGame action
        static std::tuple<bool, std::string> statementStartGame( false, "Commencer une nouvelle partie" );
        static std::tuple<bool, std::string> resultStartGame( false, "La partie commence." );

        // data for loadGame action
        static std::tuple<bool, std::string> statementLoadGame( false, "Charger une partie" );
        static std::tuple<bool, std::string> resultLoadGame( false, "Vous avez choisi de charger une partie." );
    
        // data for quit action 
        static std::tuple<bool, std::string> statementQuit( false, "Quitter le jeu" );
        static std::tuple<bool, std::string> resultQuit( false, "Fin du jeu" );

        // title of loadGame menu
        static std::string titleLoadGameMenu = "Choix de la partie";

        // data for the choice of the loaded game 
        static std::tuple<bool, std::string> statementChooseLoadedGame( true, "Charger la partie -*-pseudo-*-." );
        static std::tuple<bool, std::string> resultChooseLoadedGame( false, "Vous avez chois charger une partie." );

        // title of endOfLevel menu
        static std::string titleContinueMenu = "Niveau terminé";

        // data for continue action 
        static std::tuple<bool, std::string> statementContinue( false, "Continuer votre partie" );
    
        // data for save and quit action
        static std::tuple<bool, std::string> statementSaveAndQuit( false, "Quitter et sauvegarder" );
        static std::tuple<bool, std::string> resultSaveAndQuit( false, "Partie sauvegardée" );
    
        // data for game Over action
        static std::tuple<bool, std::string> resultGameOver( false, "Vous etes mort. Game Over." );
    }

    namespace Combo
    {
        static std::string comboFistMeleeWeaponComboTitle = "Combo Poing-Arme de mếlée";
        static std::string comboDoubleMeleeTitle = "Combo Double arme de melée";
        static std::tuple<bool, std::string> statementDontCombo(false, "Ne pas déclencher le combo");
    }

} // namespace data

#endif