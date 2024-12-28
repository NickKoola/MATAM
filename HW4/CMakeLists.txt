cmake_minimum_required(VERSION 3.23)
project(ex4_main)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(ex4_main
        Mtmchkin.h
        Players/Player.cpp
        Players/Player.h
        utilities.cpp
        utilities.h Cards/Card.cpp Cards/Card.h Players/Ninja.cpp Players/Ninja.h Players/Healer.cpp Players/Healer.h Players/Warrior.cpp Players/Warrior.h Cards/Treasure.cpp Cards/Treasure.h Cards/Well.cpp Cards/Well.h Cards/Merchant.cpp Cards/Merchant.h tool/main.cpp Cards/BattleCard.cpp Cards/BattleCard.h Cards/Gremlin.cpp Cards/Gremlin.h Cards/Witch.cpp Cards/Witch.h Cards/Dragon.cpp Cards/Dragon.h Cards/Barfight.cpp Cards/Barfight.h Cards/Mana.cpp Cards/Mana.h Mtmchkin.cpp Exception.h test.cpp myMain.cpp)
