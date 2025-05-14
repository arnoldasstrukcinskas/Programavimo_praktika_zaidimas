cmake_minimum_required(VERSION 3.30)
project(Programavimo_praktika_zaidimas_)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programavimo_praktika_zaidimas_ main.cpp
        Source/Core/Game.cpp
        Source/Core/Game.h
        Source/Systems/MapSystem/Map.cpp
        Source/Systems/MapSystem/Map.h
        Source/Systems/Player/Player.cpp
        Source/Systems/Player/Player.h
        Source/Systems/Actions/Actions.cpp
        Source/Systems/Actions/Actions.h
        Source/Systems/Enemy/Enemy.cpp
        Source/Systems/Enemy/Enemy.h
        Source/Misc/FontManager.cpp
        Source/Misc/FontManager.h
        Source/Core/GUI.cpp
        Source/Core/GUI.h
        Source/Misc/Button.cpp
        Source/Misc/Button.h)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(Programavimo_praktika_zaidimas_ PRIVATE SFML::Graphics SFML::Audio SFML::System SFML::Network SFML::Window)

FetchContent_Declare(
        tinyxml2
        GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
        GIT_TAG        10.0.0
)

FetchContent_MakeAvailable(tinyxml2)

target_link_libraries(Programavimo_praktika_zaidimas_ PRIVATE tinyxml2)