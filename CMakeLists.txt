cmake_minimum_required(VERSION 3.26)
project(MarioPJCProject)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.1.1
)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(sfml)
add_executable(MarioPJCProject main.cpp
        Character.cpp
        Character.h
        Mario.cpp
        Mario.h
        Global.cpp
        Global.h
        Map.cpp
        Map.h
        Animation.cpp
        Animation.h)
target_link_libraries(
        MarioPJCProject
        fmt
        sfml-graphics
        sfml-window
        sfml-system
        stdc++fs
)
IF (WIN32)
    add_custom_command(TARGET MarioPJCProject POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:MarioPJCProject> $<TARGET_FILE_DIR:MarioPJCProject>
            COMMAND_EXPAND_LISTS
    )
ENDIF ()