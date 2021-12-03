add_subdirectory(Action)
add_subdirectory(Beginning)
add_subdirectory(Data)
add_subdirectory(DataFiles)
add_subdirectory(Entity)
add_subdirectory(Fight)
add_subdirectory(Level)
add_subdirectory(Selection)
add_subdirectory(Utils)
add_subdirectory(Weapon)
add_subdirectory(Writer)

add_executable(main main.cpp)

target_link_libraries(
    main
    PUBLIC beginning
)
