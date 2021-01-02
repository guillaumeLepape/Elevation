cmake_minimum_required(VERSION 3.10)

# set the project name
project(Elevation VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
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

    ${FOLDER_ACTION}/StartGame.h
    ${FOLDER_ACTION}/LoadGame.h
    ${FOLDER_ACTION}/Quit.h

    ${FOLDER_ACTION}/GameOver.h
    ${FOLDER_ACTION}/Negociate.h
    ${FOLDER_ACTION}/Pseudo.h
    ${FOLDER_ACTION}/UseWeapon.h
    ${FOLDER_ACTION}/Answer.h
    ${FOLDER_ACTION}/Dead.h
)

set(SOURCE_ACTION

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
    ${FOLDER_DATA}/HeaderData.h
    ${FOLDER_DATA}/MessagesData.h
    ${FOLDER_DATA}/MessageData.h
    ${FOLDER_DATA}/ListNameData.h
    ${FOLDER_DATA}/QuestionData.h
    ${FOLDER_DATA}/ActionData.h
    ${FOLDER_DATA}/AnswerData.h
    ${FOLDER_DATA}/SelectionData.h
    ${FOLDER_DATA}/ResultsData.h
    ${FOLDER_DATA}/TutorialData.h
)

set(SOURCE_DATA
    ${FOLDER_DATA}/Data.cpp
    ${FOLDER_DATA}/HeaderData.cpp
    ${FOLDER_DATA}/MessagesData.cpp
    ${FOLDER_DATA}/MessageData.cpp
    ${FOLDER_DATA}/ListNameData.cpp
    ${FOLDER_DATA}/QuestionData.cpp
    ${FOLDER_DATA}/ActionData.cpp
    ${FOLDER_DATA}/AnswerData.cpp
    ${FOLDER_DATA}/SelectionData.cpp
    ${FOLDER_DATA}/ResultsData.cpp
    ${FOLDER_DATA}/TutorialData.cpp
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
)

set(SOURCE_LEVEL
    ${FOLDER_LEVEL}/Introduction.cpp
    ${FOLDER_LEVEL}/Level1.cpp
    ${FOLDER_LEVEL}/Level2.cpp
    ${FOLDER_LEVEL}/Level3.cpp
    ${FOLDER_LEVEL}/Level4.cpp
    ${FOLDER_LEVEL}/Level5.cpp
)

#
# Set header and source files for Player class (in the folder Player) 
#
set(FOLDER_PLAYER src/Player)

include_directories(
    ${FOLDER_PLAYER}
)

set(HEADER_PLAYER
    ${FOLDER_PLAYER}/Id.h
    ${FOLDER_PLAYER}/Player.h
    ${FOLDER_PLAYER}/Weapon.h
)

set(SOURCE_PLAYER
    ${FOLDER_PLAYER}/Player.cpp
)

#
# Set header and source files for Plug class (in the folder Plug) 
#
set(FOLDER_PLUG src/Plug)

include_directories(
    ${FOLDER_PLUG}
)

set(HEADER_PLUG
    ${FOLDER_PLUG}/Plug.h
)

set(SOURCE_PLUG
    ${FOLDER_PLUG}/Plug.cpp
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
    ${FOLDER_SELECTION}/ComboFistWeapon.h
)

set(SOURCE_SELECTION
    ${FOLDER_SELECTION}/Fight.cpp
    ${FOLDER_SELECTION}/Selection.cpp
    ${FOLDER_SELECTION}/Question.cpp
    ${FOLDER_SELECTION}/ComboFistWeapon.cpp
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
    ${FOLDER_WRITER}/Pause.h
    ${FOLDER_WRITER}/Rules.h
    ${FOLDER_WRITER}/HeaderWriter.h
    ${FOLDER_WRITER}/MessageWriter.h
    ${FOLDER_WRITER}/MessageHandler.h
    ${FOLDER_WRITER}/ActionWriter.h
    ${FOLDER_WRITER}/SelectionWriter.h
    ${FOLDER_WRITER}/Token.h
    ${FOLDER_WRITER}/AnswerWriter.h
    ${FOLDER_WRITER}/FightWriter.h
    ${FOLDER_WRITER}/TutorialWriter.h
)

set(SOURCE_WRITER
    ${FOLDER_WRITER}/Rules.cpp
    ${FOLDER_WRITER}/HeaderWriter.cpp
    ${FOLDER_WRITER}/MessageWriter.cpp
    ${FOLDER_WRITER}/MessageHandler.cpp
    ${FOLDER_WRITER}/ActionWriter.cpp
    ${FOLDER_WRITER}/SelectionWriter.cpp
    ${FOLDER_WRITER}/AnswerWriter.cpp
    ${FOLDER_WRITER}/FightWriter.cpp
    ${FOLDER_WRITER}/TutorialWriter.cpp
)


add_executable(main
    src/main.cpp
    
    ${HEADER_ACTION}
    ${SOURCE_ACTION}

    ${HEADER_DATA}
    ${SOURCE_DATA}

    ${HEADER_LEVEL}
    ${SOURCE_LEVEL}

    ${HEADER_PLAYER}
    ${SOURCE_PLAYER}

    ${HEADER_PLUG}
    ${SOURCE_PLUG}

    ${HEADER_SELECTION}
    ${SOURCE_SELECTION}

    ${HEADER_WRITER}
    ${SOURCE_WRITER}
)   

add_executable(dataset
    dataset/main.cpp
)

add_subdirectory( libraries/tabulate )

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory( libraries/json ) 

add_subdirectory( libraries/cpp-terminal )

target_link_libraries(
    main 
    PRIVATE nlohmann_json::nlohmann_json 
    PRIVATE tabulate::tabulate
    PRIVATE cpp-terminal
)

target_link_libraries(
    dataset 
    PRIVATE nlohmann_json::nlohmann_json 
)
