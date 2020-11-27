cmake_minimum_required(VERSION 3.10)

# set the project name
project(Elevation VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(run
    src/main.cpp

    src/Action/Action.cpp
    src/Action/Action.h
    
    src/Action/ChangeAttribute.h

    src/Action/Action.cpp
    src/Action/Action.h

    src/Action/Quit.h
    src/Action/StartGame.h

    src/Level/Level.h

    src/Level/Level1.cpp
    src/Level/Level.h
    src/Level/Level2.cpp
    src/Level/Level2.h

    src/Message/Message.cpp
    src/Message/Message.h

    src/Player/Player.cpp
    src/Player/Player.h

    src/Selection/Selection.cpp
    src/Selection/Selection.h
)

add_subdirectory( libraries/json ) 
add_subdirectory( libraries/AudioFile )

target_link_libraries(run PRIVATE nlohmann_json::nlohmann_json AudioFile)
