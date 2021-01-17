/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include "HeaderWriter.h"

#include "TutorialWriter.h"
#include "Fight.h"

#include "ComboFistMeleeWeapon.h"
#include "ComboDoubleMeleeWeapon.h"

#include "Fist.h"
#include "Knife.h"

void Level5::startLevel( const Options& options )
{
    std::string folder = "data/Level5";

    HeaderWriter headerWriter( 
        data::Level5::nameLevel,
        data::Level5::hour,
        data::Level5::minut
    );
    headerWriter.writeHeader();

    // Weapon knife( "Couteau", 30, WeaponType::meleeWeapon );
    Plug guetteur( "Guetteur", 0, 15, Fist() );

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &guetteur );
    messageHandler.nextMessage();
    messageHandler.nextMessage();

    if ( !options.noRule_ )
    {
        TutorialWriter tutorial0( folder, "tutorial0" );
        tutorial0.writeTutorial();
    }

    if ( !options.noRule_ )
    {   
        TutorialWriter tutorial1( folder, "tutorial1" );
        tutorial1.writeTutorial();
    }

    std::vector<Plug> fistFightEnemi;
    fistFightEnemi.push_back( guetteur );

    std::vector<Combo*> combosFirstFight;
    combosFirstFight.push_back( new ComboFistMeleeWeapon( player_ ) );
    combosFirstFight.push_back( new ComboDoubleMeleeWeapon( player_ ) );

    Fight firstFight( 
        player_,
        fistFightEnemi,
        messageHandler,
        combosFirstFight
    );
    firstFight.startFight();

    Knife knife;
    Plug randomDebile( "Random debile", 0, 50, knife );
    Plug randomDebile2( "Random debile 2", 0, 70, knife );
    Plug pasFuteFute( "Pas fute-fute", 0, 100, knife );

    std::vector<Plug> enemies;
    enemies.push_back( randomDebile );
    enemies.push_back( randomDebile2 );
    enemies.push_back( pasFuteFute );

    std::vector<Combo*> combosSecondFight;
    combosSecondFight.push_back( new ComboFistMeleeWeapon( player_ ) );
    combosSecondFight.push_back( new ComboDoubleMeleeWeapon( player_ ) );

    Fight fight( 
        player_, 
        enemies,
        messageHandler,
        combosSecondFight
    );
    fight.startFight(); 

    Level::endOfLevel();

    std::cout << "\n";
}