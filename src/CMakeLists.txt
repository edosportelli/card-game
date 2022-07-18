add_library(CardGame SHARED card_game.cpp)
target_include_directories(CardGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(CardGameExe main.cpp card_game.cpp)
