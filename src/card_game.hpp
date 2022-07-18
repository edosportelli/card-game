/**
 *  \file
 *      card_game.hpp
 *  \brief
 *      Declaration of Player, Deck and Game classes
 *
 *  \version:
 *
 */
#include <algorithm>
#include <iostream>
#include <random>
#include <stack>
#include <vector>

#define CARDS_NUMBER 52
#define PLAYERS_NUMBER 2

/*
 *
 * \brief  Declaration of Player class
 *
 */
class Player
{
  public:
    Player(const int id);

    void GiveCard(const int card);

    int PickCard();

    bool HasCards() const;

    void AssignPoint();

    int GetScore() const;

    std::string GetName() const;

  private:
    std::stack<int> cards_;
    std::string name_;
    int score_{0};
};

/*
 *
 * \brief  Declaration of Deck class
 *
 */
class Deck
{
  public:
    Deck(const int cards_number);

    void Shuffle();

    bool IsEmpty() const;

    int PickCard();

  private:
    std::vector<int> deck_;
};

/*
 *
 * \brief  Declaration of Game class
 *
 */
class Game
{
  public:
    Game();

    void Setup();

    void Start();

    void PlayRoud();

    void Result() const;

  private:
    std::vector<Player> players_;
    Deck deck_;
};
