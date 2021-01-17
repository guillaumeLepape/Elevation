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
        inline std::string nameLevel = "Introduction : Dur réveil";
        inline int hour = 13;
        inline int minut = 12;

        // Messages data
        inline std::vector<std::vector<std::tuple<std::string, bool, std::string>>> messages = {
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
        inline std::string nameLevel = "Niveau 1 : Beuh";
        inline int hour = 14;
        inline int minut = 35;
    } // namespace Level1

    namespace Level2
    {
        inline std::string nameLevel = "Niveau 2 : Coke";
        inline int hour = 15;
        inline int minut = 10;
    } // namespace Level2

    namespace Level3
    {
        inline std::string nameLevel = "Niveau 3 : Shit";
        inline int hour = 16;
        inline int minut = 4;
    } // namespace Level3

    namespace Level4
    {
        inline std::string nameLevel = "Niveau 4 : Lean";
        inline int hour = 17;
        inline int minut = 15;
    } // namespace Level4

    namespace Level5
    {
        inline std::string nameLevel = "Niveau 5 : Xanax";
        inline int hour = 19;
        inline int minut = 2;
    } // namespace Level5

    namespace Action
    {
        // generic UseWeapon data statement for fist
        inline std::tuple<bool, std::string> statementUseFist(false, "Cognez ! (Poing)");
        // generic UseWeapon data statement for knife
        inline std::tuple<bool, std::string> statementUseKnife(false, "Plantez ! (Couteau)");
        inline std::tuple<bool, std::string> statementUseKnifeFistCombo(false, "Combo avec le couteau !");
        // generic UseWeapon data statement for katana
        inline std::tuple<bool, std::string> statementUseKatana(false, "Découpez ! (Katana)");
        inline std::tuple<bool, std::string> statementUseKatanaFistCombo(false, "Combo avec le katana !");

        // generic UseWeapon data result
        inline std::tuple<bool, std::string> resultUseWeapon(true, "-*-plugName-*- perd -*-damage-*- points de vie.");

        inline std::string titleChooseWeapon = "Choix de l'arme";

        inline std::unique_ptr<std::tuple<bool, std::string>> newStatementUseWeapon(const std::string &nameWeapon)
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

        inline std::tuple<bool, std::string> statementChoosePlug( true, "Attaquer -*-plugName-*-." );
        inline std::tuple<bool, std::string> resultChoosePlug( true, "Vous avez choisi d'attaquer -*-plugName-*-." );

        inline std::tuple<bool, std::string> resultPlugAttack( true, "-*-plugName-*- vous inflige -*-damagePlug-*- points de vie." );

        inline std::tuple<bool, std::string> resultDead( true, "-*-plugName-*- est mort." );

        // data for pseudo action
        inline std::tuple<bool, std::string> statementPseudo( false, "Entrez votre prénom" );
        inline std::tuple<bool, std::string> resultPseudo( true, "Votre prénom est à présent : -*-pseudo-*-." );
    
        // data for negociate action
        inline std::tuple<bool, std::string> statementNegociate( false, "Entrez votre montant" );
        inline std::tuple<bool, std::string> resultNegociate( true, "Vous perdez -*-pricePlayer-*-€." );    
    } // namespace Action

    namespace Menu 
    {
        // title of startGame menu 
        inline std::string titleStartGameMenu = "Menu";

        // data for startGame action
        inline std::tuple<bool, std::string> statementStartGame( false, "Commencer une nouvelle partie" );
        inline std::tuple<bool, std::string> resultStartGame( false, "La partie commence." );

        // data for loadGame action
        inline std::tuple<bool, std::string> statementLoadGame( false, "Charger une partie" );
        inline std::tuple<bool, std::string> resultLoadGame( false, "Vous avez choisi de charger une partie." );
    
        // data for quit action 
        inline std::tuple<bool, std::string> statementQuit( false, "Quitter le jeu" );
        inline std::tuple<bool, std::string> resultQuit( false, "Fin du jeu" );

        // title of loadGame menu
        inline std::string titleLoadGameMenu = "Choix de la partie";

        // data for the choice of the loaded game 
        inline std::tuple<bool, std::string> statementChooseLoadedGame( true, "Charger la partie -*-pseudo-*-." );
        inline std::tuple<bool, std::string> resultChooseLoadedGame( false, "Vous avez chois charger une partie." );

        // title of endOfLevel menu
        inline std::string titleContinueMenu = "Niveau terminé";

        // data for continue action 
        inline std::tuple<bool, std::string> statementContinue( false, "Continuer votre partie" );
    
        // data for save and quit action
        inline std::tuple<bool, std::string> statementSaveAndQuit( false, "Quitter et sauvegarder" );
        inline std::tuple<bool, std::string> resultSaveAndQuit( false, "Partie sauvegardée" );
    
        // data for game Over action
        inline std::tuple<bool, std::string> resultGameOver( false, "Vous etes mort. Game Over." );
    }

    namespace Combo
    {
        inline std::string comboFistMeleeWeaponComboTitle = "Combo Poing-Arme de mếlée";
        inline std::string comboDoubleMeleeTitle = "Combo Double arme de melée";
        inline std::tuple<bool, std::string> statementDontCombo(false, "Ne pas déclencher le combo");
    }

    namespace Question 
    {
        // First question title
        inline std::string titleFirstQuestion = "Les hommes sont-ils allez sur la Lune ?";
        
        // First Answer
        inline std::tuple<bool, std::string> answer1Question1( false, "Oui, bien sur !" );
        inline bool correctOrNotAnswer1Question1 = false;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question1( false, "Bien sur, les américains l'ont fait pour niquer les russes." );
        inline bool correctOrNotAnswer2Question1 = false;

        // Third Answer
        inline std::tuple<bool, std::string> answer3Question1( false, "Non, l'alunissage a eu lieu au Nevada." );
        inline bool correctOrNotAnswer3Question1 = true;


        // Second question title
        inline std::string titleSecondQuestion = "Pourquoi le faux alunissage a été caché ?";
        
        // First Answer
        inline std::tuple<bool, std::string> answer1Question2( false, "Euh ..." );
        inline bool correctOrNotAnswer1Question2 = false;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question2( false, "Pour montrer leurs supériorités, les américains ont préféré mentir car ils n'avaient pas les moyens technologiques d'y aller." );
        inline bool correctOrNotAnswer2Question2 = false;

        // Third Answer 
        inline std::tuple<bool, std::string> answer3Question2( false, "Pour cacher qu'en fait la Terre est plate." );
        inline bool correctOrNotAnswer3Question2 = true;


        // Third question title        
        inline std::string titleThirdQuestion = "Pourquoi vouloir masquer tout ça ?";

        // First Answer
        inline std::tuple<bool, std::string> answer1Question3( false,
            "Pour cacher la grand plan des élites qui consiste à réduire drastiquement la population." );
        inline bool correctOrNotAnswer1Question3 = true;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question3( false,
            "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre constitant à implémenter des puces à la population pour les controler." );
        inline bool correctOrNotAnswer2Question3 = true;

        // Third Answer 
        inline std::tuple<bool, std::string> answer3Question3( false,
            "Pour cacher que toutes gouvernements sont à la solde d'un organisation secrète dirigé par les reptiliens." );
        inline bool correctOrNotAnswer3Question3 = true;

    }
} // namespace data

#endif