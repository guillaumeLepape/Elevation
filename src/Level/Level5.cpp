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
#include "Katana.h"
#include "Cutter.h"

void Level5::startLevel( const Options& options )
{
    HeaderWriter headerWriter( 
        data::Level5::nameLevel,
        data::Level5::hour,
        data::Level5::minut
    );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 0, 15, Fist() );

    MessageHandler messageHandler( data::Level5::messages );
    messageHandler.preTreatment( player_, &guetteur );
    messageHandler.nextMessage();
    messageHandler.nextMessage();

    if ( !options.noRule_ )
    {
        TutorialWriter tutorial0( data::Tutorial::title1, data::Tutorial::statement1 );
        tutorial0.writeTutorial();
    }

    if ( !options.noRule_ )
    {   
        TutorialWriter tutorial1( data::Tutorial::title2, data::Tutorial::statement2 );
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

    Katana katana;
    Knife knife;
    Cutter cutter;
    Plug sacAPV( "Sac à PV", 0, 100, cutter );
    Plug kamikaze( "Kamikaze", 0, 32, katana );
    Plug soutien( "Soutien", 0, 60, knife );

    std::vector<Plug> enemies;
    enemies.push_back( sacAPV );
    enemies.push_back( kamikaze );
    enemies.push_back( soutien );

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