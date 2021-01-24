/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include "HeaderWriter.h"
#include "MessageWriter.h"
#include "TutorialWriter.h"

#include "Fight.h"

#include "ComboFistMeleeWeapon.h"
#include "ComboDoubleMeleeWeapon.h"

#include "Fist.h"
#include "Knife.h"
#include "Katana.h"
#include "Cutter.h"

#include "RegenerateAllLife.h"

void Level5::startLevel( const Options& options )
{
    HeaderWriter headerWriter( 
        data::Level5::nameLevel,
        data::Level5::hour,
        data::Level5::minut
    );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 0, 35, Fist() );

    MessageWriter messageWriter0( data::Level5::message0, player_->pseudo(), guetteur.name() );
    messageWriter0.writeMessage();
    
    MessageWriter messageWriter1( data::Level5::message1, player_->pseudo(), guetteur.name() );
    messageWriter1.writeMessage();

    if ( !options.noRule_ )
    {
        TutorialWriter tutorialCombatSystem( data::Tutorial::titleCombatSystem, data::Tutorial::statementCombatSystem );
        tutorialCombatSystem.writeTutorial();
    }

    if ( !options.noRule_ )
    {   
        TutorialWriter tutorialCombo( data::Tutorial::titleCombo, data::Tutorial::statementCombo );
        tutorialCombo.writeTutorial();
    }

    // Declare combos
    std::unique_ptr<Combo> comboDoubleMeleeWeapon( new ComboDoubleMeleeWeapon(player_) ); 

    // First fight (introduction to Fist - Melee Weapon combo)
    if ( !options.noRule_ )
    {
        TutorialWriter tutorialFistMeleeWeapon
        ( 
            data::Tutorial::titleComboFistMeleeWeapon, 
            data::Tutorial::statementComboFistMeleeWeapon
        );
        tutorialFistMeleeWeapon.writeTutorial();
    }

    ComboFistMeleeWeapon comboFistMeleeWeapon( player_ ); 

    Fight firstFight( 
        player_,
        { guetteur },
        { &comboFistMeleeWeapon },
        false
    );
    firstFight.startFight();



    // Second fight (introduction to Double melee Weapon combo )
    Plug garde( "Garde", 0, 50, Fist() );

    MessageWriter messageWriter2( data::Level5::message2, player_->pseudo(), garde.name() );
    messageWriter2.writeMessage();

    if ( !options.noRule_ )
    {
        TutorialWriter tutorialDoubleMeleeWeapon
        ( 
            data::Tutorial::titleComboDoubleMeleeWeapon, 
            data::Tutorial::statementComboDoubleMeleeWeapon
        );
        tutorialDoubleMeleeWeapon.writeTutorial();
    }

    Fist fist;
    player_->deleteWeapon( fist );

    Fight secondFight(
        player_,
        { garde },
        { comboDoubleMeleeWeapon.get() },
        false
    );
    secondFight.startFight();

    player_->addWeapon( &fist );

    // Third fight (introduction to Healing and weapon recuperation)
    Plug secondGarde( "Un futur cadavre", 0, 30, Knife() );

    MessageWriter messageWriter3( data::Level5::message3, player_->pseudo(), secondGarde.name() );
    messageWriter3.writeMessage();

    if ( !options.noRule_ )
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
        { secondGarde },
        {},
        false
    );
    thirdFight.startFight();

    MessageWriter messageWriter4( data::Level5::message4, player_->pseudo(), "" );
    messageWriter4.writeMessage();

    RegenerateAllLife regenerateAllLife( player_, "", "" ); 
    regenerateAllLife.triggerAction();

    MessageWriter messageWriter5( data::Level5::message5, player_->pseudo(), "" );
    messageWriter5.writeMessage();

    if ( !options.noRule_ )
    {
        TutorialWriter tutorialRegeneration
        ( 
            data::Tutorial::titleRegeneration, 
            data::Tutorial::statementRegeneration 
        );
        tutorialRegeneration.writeTutorial();
    }

    // Fourth fight
    MessageWriter messageWriter6( data::Level5::message6, player_->pseudo(), "" );

    Katana katana;
    Knife knife;
    Cutter cutter;
    Plug sacAPV( "Sac à PV", 0, 100, cutter );
    Plug kamikaze( "Kamikaze", 0, 32, katana );
    Plug soutien( "Soutien", 0, 60, knife );

    Fight fight( 
        player_, 
        { sacAPV, kamikaze, soutien },
        { &comboFistMeleeWeapon, comboDoubleMeleeWeapon.get() }
    );
    fight.startFight(); 

    MessageWriter messageWriter7( data::Level5::message7, player_->pseudo(), "" );

    Level::endOfLevel();

    std::cout << "\n";
}