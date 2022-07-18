/**
 *  \file
 *      card_game.cpp
 *  \brief
 *      Implementation of Player, Deck and Game classes
 *
 *  \version:
 *
 */
#include "card_game.hpp"

/*
 *
 * \brief  Implementation of Player methods
 *
 */
Player::Player(const int id)
{
    name_ = "Player " + std::to_string(id + 1);
}

void Player::GiveCard(const int card)
{
    cards_.push(card);
}

int Player::PickCard()
{
    int card = cards_.top();
    cards_.pop();

    return card;
}

bool Player::HasCards() const
{
    return cards_.size() > 0;
}

void Player::AssignPoint()
{
    score_++;
}

int Player::GetScore() const
{
    return score_;
}

std::string Player::GetName() const
{
    return name_;
}

/*
 *
 * \brief  Implementation of Deck methods
 *
 */
Deck::Deck(const int cards_number)
{
    for (size_t i = 0; i < cards_number; i++)
    {
        deck_.push_back(i + 1);
    }
}

void Deck::Shuffle()
{
    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(deck_.begin(), deck_.end(), rng);
}

bool Deck::IsEmpty() const
{
    return deck_.empty();
}

int Deck::PickCard()
{
    int card = deck_.back();
    deck_.pop_back();

    return card;
}

/*
 *
 * \brief  Implementation of Game methods
 *
 */
Game::Game() : deck_(CARDS_NUMBER)
{
    for (size_t id = 0; id < PLAYERS_NUMBER; id++)
    {
        players_.push_back(Player(id));
    }
}

void Game::Setup()
{
    deck_.Shuffle();

    int picked_cards{0};
    while (not deck_.IsEmpty())
    {
        int player_id = picked_cards % PLAYERS_NUMBER;
        int card = deck_.PickCard();

        players_[player_id].GiveCard(card);
        picked_cards++;
    }
}

void Game::Start()
{
    while (players_[0].HasCards())
    {
        PlayRoud();
    }
}

void Game::PlayRoud()
{
    std::vector<int> cards;

    for (size_t i = 0; i < players_.size(); i++)
    {
        cards.push_back(players_[i].PickCard());
        std::cout << "Player " << i + 1 << " picked " << cards.back() << ", ";
    }

    auto winner = std::max_element(cards.begin(), cards.end()) - cards.begin();

    players_[winner].AssignPoint();

    std::cout << players_[winner].GetName() << " won the round!" << std::endl;
}

void Game::Result() const
{
    std::vector<int> scores;

    for (size_t i = 0; i < players_.size(); i++)
    {
        scores.push_back(players_[i].GetScore());
        std::cout << "Player " << i + 1 << " totalize " << scores.back() << " points, ";
    }

    auto winner = std::max_element(scores.begin(), scores.end()) - scores.begin();

    if (players_[winner].GetScore() == CARDS_NUMBER / 4)
    {
        std::cout << "The match is a draw!" << std::endl;
    }
    else
    {
        std::cout << players_[winner].GetName() << " won the game!" << std::endl;
    }
}