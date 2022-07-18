enable_testing()

add_executable(GameTests game_tests.cpp)
target_link_libraries(GameTests gtest pthread CardGame)
