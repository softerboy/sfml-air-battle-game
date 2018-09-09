cmake_minimum_required(VERSION 2.8)

# Specify default build type if none provided (before project() command)
if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# For generators with multiple configurations (like VS), only allow Debug and Release
if(CMAKE_CONFIGURATION_TYPES)
        set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Limited configurations" FORCE)
	mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
endif()

# Project name
project(Games)

# Configuration options
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Use static SFML librares")

# General compiler options
if (SFML_STATIC_LIBRARIES)
        add_definitions(-DSFML_STATIC)
endif()

# Specific compiler options - set C++11 flag for g++ and clang
if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

	# Mac OS X: clang uses libc++ standard library
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	endif()
endif()

# Add directory containing FindSFML.cmake to module path
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/;${CMAKE_MODULE_PATH}")

# Find SFML
# Note: SFML_STATIC_LIBRARIES determines which libraries are found by find_package()
find_package(SFML 2 COMPONENTS graphics window system audio)

# If found, include and link; otherwise output error message
if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
else()
        set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
	message("\n-> SFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
	message("-> Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

set(SRCS
    src/MusicPlayer.cpp
    src/SoundPlayer.cpp
    src/Animation.cpp
    src/Main.cpp
    src/Application.cpp
    src/Aircraft.cpp
    src/SceneNode.cpp
    src/Entity.cpp
    src/SpriteNode.cpp
    src/Command.cpp
    src/CommandQueue.cpp
    src/Player.cpp
    src/StateStack.cpp
    src/State.cpp
    src/TitleState.cpp
    src/MenuState.cpp
    src/GameState.cpp
    src/PauseState.cpp
    src/Utility.cpp
    src/SettingsState.cpp
    src/GameOverState.cpp
    src/World.cpp
    src/Component.cpp
    src/Container.cpp
    src/Label.cpp
    src/Button.cpp
    src/DataTables.cpp
    src/TextNode.cpp
    src/Projectile.cpp
    src/Pickup.cpp
    src/ParticleNode.cpp
    src/PostEffect.cpp
    src/BloomEffect.cpp
    src/EmitterNode.cpp)

set(HDRS
    src/MusicPlayer.h
    src/SoundPlayer.h
    src/Application.h
    src/Animation.h
    src/Aircraft.h
    src/ResourceHolder.h
    src/Category.h
    src/SceneNode.h
    src/Entity.h
    src/ResourceIdentifiers.h
    src/StateIdentifiers.h
    src/SpriteNode.h
    src/Command.h
    src/World.h
    src/CommandQueue.h
    src/Player.h
    src/StateStack.h
    src/State.h
    src/TitleState.h
    src/MenuState.h
    src/GameState.h
    src/PauseState.h
    src/SettingsState.h
    src/GameOverState.h
    src/Utility.h
    src/Component.h
    src/Container.h
    src/Label.h
    src/Button.h
    src/DataTables.h
    src/TextNode.h
    src/Projectile.h
    src/Pickup.h
    src/Particle.h
    src/ParticleNode.h
    src/PostEffect.h
    src/BloomEffect.h
    src/EmitterNode.h)

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

# Configuration options
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Use static SFML librares")
