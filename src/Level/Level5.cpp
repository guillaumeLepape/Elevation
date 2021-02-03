/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"
#include "TutorialWriter.h"

#include "Fight.h"

#include "ComboFistMeleeWeapon.h"
#include "ComboDoubleMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"

#include "Fist.h"
#include "Knife.h"
#include "Katana.h"
#include "Cutter.h"

#include "RegenerateAllLife.h"
#include "AddWeaponAction.h"

#include "Languages.h"

void Level5::startLevel()
{
    HeaderWriter headerWriter( 
        data::Level5::nameLevel,
        data::Level5::hour,
        data::Level5::minut
    );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 35, new Fist() );

    MessageWriter messageWriter0( data::Level5::message0, player_->name(), guetteur.name() );
    messageWriter0.writeMessage();
    
    MessageWriter messageWriter1( data::Level5::message1, player_->name(), guetteur.name() );
    messageWriter1.writeMessage();

    if ( !options_.noRule_ )
    {
        TutorialWriter tutorialCombatSystem( data::Tutorial::titleCombatSystem, data::Tutorial::statementCombatSystem(player_->maxLifePoints()) );
        tutorialCombatSystem.writeTutorial();
    }

    if ( !options_.noRule_ )
    {   
        TutorialWriter tutorialCombo( data::Tutorial::titleCombo, data::Tutorial::statementCombo );
        tutorialCombo.writeTutorial();
    }

    // Declare combos
    std::unique_ptr<Combo> comboFistMeleeWeapon( new ComboFistMeleeWeapon(player_) ); 
    std::unique_ptr<Combo> comboDoubleMeleeWeapon( new ComboDoubleMeleeWeapon(player_) ); 
    std::unique_ptr<Combo> comboQuadrupleCutter( new ComboQuadrupleCutter(player_) );

    // First fight (introduction to Fist - Melee Weapon combo)
    if ( !options_.noRule_ )
    {
        TutorialWriter tutorialFistMeleeWeapon
        ( 
            data::Tutorial::titleComboFistMeleeWeapon, 
            data::Tutorial::statementComboFistMeleeWeapon
        );
        tutorialFistMeleeWeapon.writeTutorial();
    }

    Fight firstFight( 
        player_,
        { &guetteur },
        { comboFistMeleeWeapon.get() },
        options_.noRule_,
        false
    );
    firstFight.startFight();

    // Second fight (introduction to Double melee Weapon combo )
    Plug garde( "Garde", 50, new Fist() );

    MessageWriter messageWriter2( data::Level5::message2, player_->name(), garde.name() );
    messageWriter2.writeMessage();

    if ( !options_.noRule_ )
    {
        TutorialWriter tutorialDoubleMeleeWeapon
        ( 
            data::Tutorial::titleComboDoubleMeleeWeapon, 
            data::Tutorial::statementComboDoubleMeleeWeapon
        );
        tutorialDoubleMeleeWeapon.writeTutorial();
    }

    Fight secondFight(
        player_,
        { &garde },
        { comboDoubleMeleeWeapon.get() },
        options_.noRule_,
        false
    );
    secondFight.startFight();

    // Third fight (introduction to Healing and weapon recuperation)
    Plug secondGarde( "Un futur cadavre", 30, new Knife() );

    MessageWriter messageWriter3( data::Level5::message3, player_->name(), secondGarde.name() );
    messageWriter3.writeMessage();

    if ( !options_.noRule_ )
    {
        TutorialWriter tutorialNoWeapon
        (
            data::Tutorial::titleNoWeapon,
            data::Tutorial::statementNoWeapon
        );
        tutorialNoWeapon.writeTutorial();
    }

    Fight thirdFight(
        player_,
        { &secondGarde },
        {},
        options_.noRule_,
        false
    );
    thirdFight.startFight();

    MessageWriter messageWriter4( data::Level5::message4, player_->name(), "" );
    messageWriter4.writeMessage();

    RegenerateAllLife regenerateAllLife( player_, "", "" ); 
    regenerateAllLife.triggerAction();

    MessageWriter messageWriter5( data::Level5::message5, player_->name(), "" );
    messageWriter5.writeMessage();

    if ( !options_.noRule_ )
    {
        TutorialWriter tutorialRegeneration
        ( 
            data::Tutorial::titleRegeneration, 
            data::Tutorial::statementRegeneration 
        );
        tutorialRegeneration.writeTutorial();
    }

    // Fourth fight
    Plug sacAPV( "Sac à PV", 100, new Cutter() );
    Plug kamikaze( "Kamikaze", 32, new Katana() );
    Plug soutien( "Soutien", 60, new Knife() );

    MessageWriter messageWriter6( data::Level5::message6, player_->name(), kamikaze.name() );
    messageWriter6.writeMessage();

    Fight fight( 
        player_, 
        { &sacAPV, &kamikaze, &soutien },
        { comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(), comboQuadrupleCutter.get() },
        options_.noRule_
    );
    fight.startFight(); 

    MessageWriter messageWriter7( data::Level5::message7, player_->name(), "" );
    messageWriter7.writeMessage();

    regenerateAllLife.triggerAction();

    Level::endOfLevel();

    std::cout << "\n";
}