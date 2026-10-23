#include "Game.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <random>
#include <iterator>

using namespace std;

// Constructors
Game::Game()
{
}

Game::Game(vector<RPG*> players, set<int> live_players)
{
    this->players = players;
    this->live_players = live_players;
}

void Game::generatePlayers(int n)
{
    for (int i = 0; i < n; i++)
    {
        players.push_back(new RPG());

        string name = "NPC_" + to_string(i);
        players[i]->setName(name);

        live_players.insert(i);
    }
}

int Game::selectPlayer()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(
        0,
        static_cast<int>(live_players.size()) - 1
    );

    int randomIndex = dis(gen);

    auto it = live_players.begin();
    advance(it, randomIndex);

    return *it;
}

void Game::endRound(RPG* winner, RPG* loser, int loserIndex)
{
    winner->setHitsTaken(0);
    winner->updateExpLvl();

    live_players.erase(loserIndex);

    cout << loser->getName()
        << " has been eliminated from the game by "
        << winner->getName()
        << "!" << endl;
}

void Game::battleRound()
{
    if (live_players.size() < 2)
    {
        return;
    }

    int player1Index = selectPlayer();
    int player2Index = selectPlayer();

    while (player1Index == player2Index)
    {
        player2Index = selectPlayer();
    }

    RPG* player1 = players[player1Index];
    RPG* player2 = players[player2Index];

    cout << "Battle between "
        << player1->getName()
        << " and "
        << player2->getName()
        << "!"
        << endl;

    while (player1->isAlive() && player2->isAlive())
    {
        player1->attack(*player2);

        if (!player2->isAlive())
        {
            endRound(player1, player2, player2Index);
            break;
        }

        player2->attack(*player1);

        if (!player1->isAlive())
        {
            endRound(player2, player1, player1Index);
            break;
        }
    }
}

void Game::gameLoop()
{
    int round = 1;

    while (live_players.size() > 1)
    {
        cout << "\nRound " << round << endl;
        battleRound();
        round++;
    }

    cout << "\nGame Over!" << endl;

    if (!live_players.empty())
    {
        int winnerIndex = *live_players.begin();

        cout << "Winner: "
            << players[winnerIndex]->getName()
            << endl;
    }
}

void Game::printFinalResults()
{
    cout << "\n===== FINAL RESULTS =====\n" << endl;

    for (int index : live_players)
    {
        players[index]->printStats();
        cout << "\n";
    }
}

// Destructor
Game::~Game()
{
    for (RPG* player : players)
    {
        delete player;
    }

    players.clear();
}