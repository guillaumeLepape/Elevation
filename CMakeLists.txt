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
    src/Action/WrongAnswer.h
    src/Action/CorrectAnswer.h

    src/Level/Level.h

    src/Level/Introduction.cpp
    src/Level/Introduction.h

    src/Level/Level1.cpp
    src/Level/Level.h

    src/Level/Level2.cpp
    src/Level/Level2.h

    src/Level/Level3.cpp
    src/Level/Level3.h

    src/Level/Level4.cpp
    src/Level/Level4.h

    src/Message/Message.cpp
    src/Message/Message.h
    src/Message/Pause.h

    src/Player/Player.cpp
    src/Player/Player.h

    src/Selection/Selection.cpp
    src/Selection/Selection.h

    src/Plug/Plug.cpp
    src/Plug/Plug.h

    src/Weapon/Weapon.h
)

add_subdirectory( libraries/json ) 
set(JSON_BuildTests OFF CACHE INTERNAL "")


target_link_libraries(run PRIVATE nlohmann_json::nlohmann_json)
