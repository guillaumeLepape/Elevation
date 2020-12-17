cmake_minimum_required(VERSION 3.10)

# set the project name
project(Elevation VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(run
    src/main.cpp

    src/color.h
    
    src/Action/Action.h

    src/Action/GameOver.h
    src/Action/Negociate.h
    src/Action/Pseudo.h
    src/Action/Quit.h
    src/Action/StartGame.h
    src/Action/UseWeapon.h
    src/Action/Answer.h

    src/Level/Level.h
    
    src/Level/LevelFactory.h

    src/Level/Introduction.cpp
    src/Level/Introduction.h

    src/Level/Level1.cpp
    src/Level/Level.h

    src/Level/Level2.cpp
    src/Level/Level2.h

    src/Level/Level3.cpp
    src/Level/Level3.h

    # src/Level/Level4.cpp
    # src/Level/Level4.h

    # src/Level/Level5.cpp
    # src/Level/Level5.h


    src/Data/Data.cpp
    src/Data/Data.h
    src/Data/HeaderData.cpp
    src/Data/HeaderData.h
    src/Data/MessagesData.cpp
    src/Data/MessagesData.h
    src/Data/MessageData.cpp
    src/Data/MessageData.h
    src/Data/QuestionsData.cpp
    src/Data/QuestionsData.h
    src/Data/QuestionData.cpp
    src/Data/QuestionData.h
    src/Data/ActionData.cpp
    src/Data/ActionData.h
    src/Data/SelectionData.cpp
    src/Data/SelectionData.h

    src/Writer/Writer.h
    src/Writer/Pause.h
    src/Writer/Rules.cpp
    src/Writer/Rules.h
    src/Writer/HeaderWriter.cpp
    src/Writer/HeaderWriter.h
    src/Writer/MessageWriter.cpp
    src/Writer/MessageWriter.h
    src/Writer/MessagesWriter.cpp
    src/Writer/MessagesWriter.h
    src/Writer/ActionWriter.cpp
    src/Writer/ActionWriter.h
    src/Writer/SelectionWriter.cpp
    src/Writer/SelectionWriter.h
    src/Writer/ReplaceToken.h

    src/Player/Player.cpp
    src/Player/Player.h

    src/Selection/Selection.cpp
    src/Selection/Selection.h
    # src/Selection/ListAnswers.cpp
    # src/Selection/ListAnswers.h
    # src/Selection/Question.cpp
    # src/Selection/Question.h

    src/Plug/Plug.cpp
    src/Plug/Plug.h

    src/Weapon/Weapon.h
)

add_subdirectory( libraries/json ) 
set(JSON_BuildTests OFF CACHE INTERNAL "")


target_link_libraries(run PRIVATE nlohmann_json::nlohmann_json)
