cmake_minimum_required(VERSION 3.12)

# set the project name
project(Elevation VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#
# Set header and source files for Action class and its herited classes (in the folder Action) 
#
set(FOLDER_ACTION src/Action)

include_directories(
    ${FOLDER_ACTION}
)

set(HEADER_ACTION
    ${FOLDER_ACTION}/Action.h
    ${FOLDER_ACTION}/Actions.h

    ${FOLDER_ACTION}/StartGame.h
    ${FOLDER_ACTION}/LoadGame.h
    ${FOLDER_ACTION}/Quit.h
    ${FOLDER_ACTION}/WriteResults.h

    ${FOLDER_ACTION}/GameOver.h
    ${FOLDER_ACTION}/Negociate.h
    ${FOLDER_ACTION}/Pseudo.h
    ${FOLDER_ACTION}/UseWeapon.h
    ${FOLDER_ACTION}/Answer.h
    ${FOLDER_ACTION}/Dead.h
    ${FOLDER_ACTION}/PlugAttack.h
    ${FOLDER_ACTION}/Regeneration.h
    ${FOLDER_ACTION}/RegenerateAllLife.h
    ${FOLDER_ACTION}/AddWeaponAction.h

    ${FOLDER_ACTION}/InformationCombo.h
    ${FOLDER_ACTION}/InformationWeaponInventory.h
)

set(SOURCE_ACTION
    ${FOLDER_ACTION}/Dead.cpp
    ${FOLDER_ACTION}/AddWeaponAction.cpp
    ${FOLDER_ACTION}/StartGame.cpp
    ${FOLDER_ACTION}/Negociate.cpp
    ${FOLDER_ACTION}/LoadGame.cpp
    ${FOLDER_ACTION}/Pseudo.cpp
    ${FOLDER_ACTION}/WriteResults.cpp
    ${FOLDER_ACTION}/Quit.cpp
)

#
# Set header and source files for Data class and its herited classes (in the folder Data) 
#
set(FOLDER_DATA src/Data)

include_directories(
    ${FOLDER_DATA}
)

set(HEADER_DATA
    ${FOLDER_DATA}/Data.h
    ${FOLDER_DATA}/ListNameData.h
    ${FOLDER_DATA}/ResultsData.h
)

set(SOURCE_DATA
    ${FOLDER_DATA}/Data.cpp
    ${FOLDER_DATA}/ListNameData.cpp
    ${FOLDER_DATA}/ResultsData.cpp
)

#
# Set header and source files for Data files (in the folder DataFiles) 
#
set(FOLDER_DATAFILES src/DataFiles)

include_directories(
    ${FOLDER_DATAFILES}
)

set(HEADER_DATAFILES
    ${FOLDER_DATAFILES}/Languages.h
    ${FOLDER_DATAFILES}/FrenchData.h    
)

set(SOURCE_DATAFILES

)

#
# Set header and source files for Entity and its herited classes (Player and Plug)
#

set(FOLDER_ENTITY src/Entity)

include_directories(
    ${FOLDER_ENTITY}
)

set(HEADER_ENTITY
    ${FOLDER_ENTITY}/Entity.h
    ${FOLDER_ENTITY}/Id.h
    ${FOLDER_ENTITY}/Player.h
    ${FOLDER_ENTITY}/Plug.h
    )

set(SOURCE_ENTITY
    ${FOLDER_ENTITY}/Entity.cpp
    ${FOLDER_ENTITY}/Player.cpp
    ${FOLDER_ENTITY}/Plug.cpp
)

#
# Set header and source files for Level class and its herited classes (in the folder Level) 
#
set(FOLDER_LEVEL src/Level)

include_directories(
    ${FOLDER_LEVEL}
)

set(HEADER_LEVEL
    ${FOLDER_LEVEL}/Level.h
    ${FOLDER_LEVEL}/LevelFactory.h
    ${FOLDER_LEVEL}/Introduction.h
    ${FOLDER_LEVEL}/Level1.h
    ${FOLDER_LEVEL}/Level2.h
    ${FOLDER_LEVEL}/Level3.h
    ${FOLDER_LEVEL}/Level4.h
    ${FOLDER_LEVEL}/Level5.h
    ${FOLDER_LEVEL}/Level6.h
    ${FOLDER_LEVEL}/Level7.h
    ${FOLDER_LEVEL}/Level8.h
)

set(SOURCE_LEVEL
    ${FOLDER_LEVEL}/Level.cpp
    ${FOLDER_LEVEL}/Introduction.cpp
    ${FOLDER_LEVEL}/Level1.cpp
    ${FOLDER_LEVEL}/Level2.cpp
    ${FOLDER_LEVEL}/Level3.cpp
    ${FOLDER_LEVEL}/Level4.cpp
    ${FOLDER_LEVEL}/Level5.cpp
    ${FOLDER_LEVEL}/Level6.cpp
    ${FOLDER_LEVEL}/Level7.cpp
    ${FOLDER_LEVEL}/Level8.cpp
)

#
# Set header and source files for Player class (in the folder Player) 
#
set(FOLDER_WEAPON src/Weapon)
set(FOLDER_FIST Fist)
set(FOLDER_MELEE_WEAPON MeleeWeapon)
set(FOLDER_FIRE_ARM FireArm)

include_directories(
    ${FOLDER_WEAPON}
    ${FOLDER_WEAPON}/${FOLDER_FIST}
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}
    ${FOLDER_WEAPON}/${FOLDER_FIRE_ARM}
)

set(HEADER_WEAPON
    ${FOLDER_WEAPON}/Weapon.h
    ${FOLDER_WEAPON}/WeaponInventory.h
    ${FOLDER_WEAPON}/WeaponFactory.h
    ${FOLDER_WEAPON}/${FOLDER_FIST}/Fist.h
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}/Cutter.h
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}/Knife.h
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}/Hammer.h
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}/Katana.h
    ${FOLDER_WEAPON}/${FOLDER_MELEE_WEAPON}/WeaponFistCombo.h
    ${FOLDER_WEAPON}/${FOLDER_FIRE_ARM}/FireArm.h
    ${FOLDER_WEAPON}/${FOLDER_FIRE_ARM}/Ninemm.h
    ${FOLDER_WEAPON}/${FOLDER_FIRE_ARM}/AK47.h
)

set(SOURCE_WEAPON
    ${FOLDER_WEAPON}/Weapon.cpp
    ${FOLDER_WEAPON}/WeaponInventory.cpp
)

#
# Set header and source files for Selection class (in the folder Selection) 
#
set(FOLDER_SELECTION src/Selection)

include_directories(
    ${FOLDER_SELECTION}
)

set(HEADER_SELECTION 
    ${FOLDER_SELECTION}/Fight.h
    ${FOLDER_SELECTION}/Selection.h
    ${FOLDER_SELECTION}/Question.h
    ${FOLDER_SELECTION}/Combo.h
    ${FOLDER_SELECTION}/ComboFistMeleeWeapon.h
    ${FOLDER_SELECTION}/ComboDoubleMeleeWeapon.h
    ${FOLDER_SELECTION}/ComboQuadrupleCutter.h
)

set(SOURCE_SELECTION
    ${FOLDER_SELECTION}/Fight.cpp
    ${FOLDER_SELECTION}/Selection.cpp
    ${FOLDER_SELECTION}/Question.cpp
    ${FOLDER_SELECTION}/ComboFistMeleeWeapon.cpp
    ${FOLDER_SELECTION}/ComboDoubleMeleeWeapon.cpp
    ${FOLDER_SELECTION}/ComboQuadrupleCutter.cpp
)

#
# Set header and source files for Writer classes which write the 
# data (from Data herited classes) in terminal 
#
set(FOLDER_WRITER src/Writer)

include_directories(
    ${FOLDER_WRITER}
)

set(HEADER_WRITER
    ${FOLDER_WRITER}/Options.h
    ${FOLDER_WRITER}/Pause.h
    ${FOLDER_WRITER}/Rules.h

    ${FOLDER_WRITER}/HeaderWriter.h
    ${FOLDER_WRITER}/MessageWriter.h
    ${FOLDER_WRITER}/ActionWriter.h
    ${FOLDER_WRITER}/SelectionWriter.h
    ${FOLDER_WRITER}/AnswerWriter.h
    ${FOLDER_WRITER}/FightWriter.h
    ${FOLDER_WRITER}/TutorialWriter.h
    ${FOLDER_WRITER}/WeaponWriter.h
    ${FOLDER_WRITER}/ComboWriter.h
)

set(SOURCE_WRITER
    ${FOLDER_WRITER}/Options.cpp
    ${FOLDER_WRITER}/Rules.cpp
    ${FOLDER_WRITER}/HeaderWriter.cpp
    ${FOLDER_WRITER}/MessageWriter.cpp
    ${FOLDER_WRITER}/ActionWriter.cpp
    ${FOLDER_WRITER}/SelectionWriter.cpp
    ${FOLDER_WRITER}/AnswerWriter.cpp
    ${FOLDER_WRITER}/FightWriter.cpp
    ${FOLDER_WRITER}/TutorialWriter.cpp
    ${FOLDER_WRITER}/WeaponWriter.cpp
    ${FOLDER_WRITER}/ComboWriter.cpp
)

add_compile_options(-Wall -Wextra)

add_executable(main
    src/main.cpp
    
    ${HEADER_ACTION}
    ${SOURCE_ACTION}

    ${HEADER_DATA}
    ${SOURCE_DATA}

    ${HEADER_DATAFILES}
    ${SOURCE_DATAFILES}

    ${HEADER_LEVEL}
    ${SOURCE_LEVEL}

    ${HEADER_ENTITY}
    ${SOURCE_ENTITY}

    ${HEADER_SELECTION}
    ${SOURCE_SELECTION}

    ${HEADER_WRITER}
    ${SOURCE_WRITER}

    ${HEADER_WEAPON}
    ${SOURCE_WEAPON}
)   

add_executable(dataset
    dataset/main.cpp
)

add_subdirectory( libraries/tabulate )

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory( libraries/json ) 

add_subdirectory( libraries/cpp-terminal )

add_subdirectory( libraries/boost-cmake )

target_link_libraries(
    main 
    PRIVATE nlohmann_json::nlohmann_json 
    PRIVATE tabulate::tabulate
    PRIVATE cpp-terminal
    PRIVATE Boost::program_options
)

target_link_libraries(
    dataset 
    PRIVATE nlohmann_json::nlohmann_json 
)
