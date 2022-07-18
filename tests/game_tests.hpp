/**
 *  \file
 *      game_tests.hpp
 *  \brief
 *      Definition of UtPlayer, UtDeck and UtGame classes
 *
 *  \version:
 *
 */
#include "gtest/gtest.h"
#define protected public // This is needed to test Game class which only has private member
#define private public   // In general is not a good practise
#include "card_game.hpp"

namespace tests
{

const int kIdPlayer1 = 0;
const int kIdPlayer2 = 1;
const int kCardValue = 12;

/*
 *
 * \brief  Unit test class for Player
 *
 */
class UtPlayer : public ::testing::Test
{
  public:
    UtPlayer() : player(kIdPlayer2) {}

  protected:
    void SetUp() override{};
    void TearDown() override{};

    Player player;
};

/*
 *
 * \brief  Unit test class for Deck
 *
 */
class UtDeck : public ::testing::Test
{
  public:
    UtDeck() : deck(CARDS_NUMBER) {}

  protected:
    void SetUp() override{};
    void TearDown() override{};

    Deck deck;
};

/*
 *
 * \brief  Unit test class for Game
 *
 */
class UtGame : public ::testing::Test
{
  public:
    UtGame() {}

  protected:
    void SetUp() override{};
    void TearDown() override{};

    Game game;
};

} // namespace tests