/**
 *  \file
 *      game_tests.cpp
 *  \brief
 *      Unit test for Player, Deck and Game classes
 *
 *  \version:
 *
 */
#include "game_tests.hpp"

namespace tests
{

/*
 *
 * \brief  Unit tests for Player class
 *
 */
TEST_F(UtPlayer, WhenGiveCardIsCalled_ThenPickCardReturnsTheSame)
{
    int card = kCardValue;

    player.GiveCard(kCardValue);

    int expected_card = player.PickCard();

    EXPECT_EQ(expected_card, card);
}

TEST_F(UtPlayer, WhenNoCardsAreGiven_ThenHasCardsReturnsFalse)
{
    EXPECT_FALSE(player.HasCards());
}

TEST_F(UtPlayer, WhenSomeCardsAreGiven_ThenHasCardsReturnsTrue)
{
    player.GiveCard(kCardValue);

    EXPECT_TRUE(player.HasCards());
}

TEST_F(UtPlayer, WhenAssignPointIsCalled_ThenGetScoreResultIsIncreasedByOne)
{
    const int first_score = player.GetScore();

    player.AssignPoint();

    const int second_score = player.GetScore();

    EXPECT_EQ(1, second_score - first_score);
}

TEST_F(UtPlayer, WhenThePlayerIdIsOne_ThenGetNameReturnsPlayerTwo)
{
    std::string expected_name{"Player 2"};

    std::string name = player.GetName();

    EXPECT_EQ(expected_name, name);
}

/*
 *
 * \brief  Unit tests for Deck class
 *
 */
TEST_F(UtDeck, WhenNoCardsArePicked_ThenIsEmptyReturnsFalse)
{
    EXPECT_FALSE(deck.IsEmpty());
}

TEST_F(UtDeck, WhenPickCardIsCalledCardNumberTimes_ThenIsEmptyReturnsTrue)
{
    for (size_t i = 0; i < CARDS_NUMBER; i++)
    {
        deck.PickCard();
    }

    EXPECT_TRUE(deck.IsEmpty());
}

/*
 *
 * \brief  Unit tests for Game class
 *
 */
TEST_F(UtGame, WhenSetupIsCalled_ThenDeckIsEmptyAndPlayersHaveCards)
{
    game.Setup();

    EXPECT_TRUE(game.deck_.IsEmpty());
    EXPECT_TRUE(game.players_[kIdPlayer1].HasCards());
    EXPECT_TRUE(game.players_[kIdPlayer2].HasCards());
}

TEST_F(UtGame, WhenSetupIsNotCalled_ThenDeckIsNotEmptyAndPlayersHaveNoCards)
{
    EXPECT_FALSE(game.deck_.IsEmpty());
    EXPECT_FALSE(game.players_[kIdPlayer1].HasCards());
    EXPECT_FALSE(game.players_[kIdPlayer2].HasCards());
}

TEST_F(UtGame, WhenPlayerHasHigherCard_ThenAssignPointGoesToThatPlayer)
{
    game.Setup();

    auto stack1 = game.players_[kIdPlayer1].cards_;
    auto stack2 = game.players_[kIdPlayer2].cards_;

    if (stack1.top() > stack2.top())
    {
        game.PlayRoud();
        EXPECT_TRUE(game.players_[kIdPlayer1].GetScore() > game.players_[kIdPlayer2].GetScore());
    }
    else
    {
        game.PlayRoud();
        EXPECT_TRUE(game.players_[kIdPlayer1].GetScore() < game.players_[kIdPlayer2].GetScore());
    }
}

TEST_F(UtGame, WhenStartIsCalled_ThenGetScoreReturnsCorrectValues)
{
    game.Setup();
    int score1{0}, score2{0};

    auto stack1 = game.players_[kIdPlayer1].cards_;
    auto stack2 = game.players_[kIdPlayer2].cards_;

    while (stack1.size() > 0)
    {
        if (stack1.top() > stack2.top())
        {
            score1++;
        }
        else
        {
            score2++;
        }

        stack1.pop();
        stack2.pop();
    }

    game.Start();
    game.Result();

    if (score1 > score2)
    {
        EXPECT_TRUE(game.players_[kIdPlayer1].GetScore() > game.players_[kIdPlayer2].GetScore());
    }
    else if (score1 < score2)
    {
        EXPECT_TRUE(game.players_[kIdPlayer1].GetScore() < game.players_[kIdPlayer2].GetScore());
    }
    else
    {
        EXPECT_EQ(game.players_[kIdPlayer1].GetScore(), game.players_[kIdPlayer2].GetScore());
    }
}

} // namespace tests

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
