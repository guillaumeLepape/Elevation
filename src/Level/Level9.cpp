/*!
    * \file Level9.cpp
*/

#include "Level9.h"

#include <iostream>

#include "HeaderWriter.h"

#include "Plug.h"
#include "Fight.h"

#include "ComboFistMeleeWeapon.h"
#include "ComboDoubleMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"

#include "RegenerateAllLife.h"

#include "AK47.h"

#include "Languages.h"

void Level9::startLevel() 
{
    HeaderWriter headerWriter( data::Level9::nameLevel, data::Level9::hour, data::Level9::minut );
    headerWriter.writeHeader();

    RegenerateAllLife regenerateAllLife( player_, "", "" );
    regenerateAllLife.triggerAction();

    Plug plug( "Psychopate", 250, new AK47( 100 ) );

    std::unique_ptr<Combo> comboFistMeleeWeapon( new ComboFistMeleeWeapon( player_ ) );
    std::unique_ptr<Combo> comboDoubleMeleeWeapon( new ComboDoubleMeleeWeapon(player_) );  
    std::unique_ptr<Combo> comboQuadrupleCutter( new ComboQuadrupleCutter(player_) );

    Fight fight(
        player_,
        { plug },
        { comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(), comboQuadrupleCutter.get() }
    );
    fight.startFight();

    Level9::endOfLevel();
    std::cout << "\n";
}