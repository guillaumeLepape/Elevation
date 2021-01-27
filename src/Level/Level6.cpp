/*!
    * \file Level6.h
*/

#include "Level6.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Player.h"
#include "Plug.h"

#include "Ninemm.h"
#include "Knife.h"
#include "Hammer.h"

#include "ComboFistMeleeWeapon.h"
#include "ComboDoubleMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"

#include "Fight.h"

#include "Languages.h"

void Level6::startLevel()
{
    HeaderWriter headerWriter( data::Level6::nameLevel, data::Level6::hour, data::Level6::minut );
    headerWriter.writeHeader();

    Plug boss( "Boss", 200, new Knife() );

    std::unique_ptr<Combo> comboFistMeleeWeapon( new ComboFistMeleeWeapon( player_ ) );
    std::unique_ptr<Combo> comboDoubleMeleeWeapon( new ComboDoubleMeleeWeapon(player_) );  
    std::unique_ptr<Combo> comboQuadrupleCutter( new ComboQuadrupleCutter(player_) );

    Fight fight(
        player_,
        { boss },
        { comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(), comboQuadrupleCutter.get() }
    );
    fight.startFight();

    Level::endOfLevel();
    std::cout << "\n";
}