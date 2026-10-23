#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <set>
#include "RPG.h"

class Game {
public:
    // Constructors
    Game();
    Game(std::vector<RPG*> players, std::set<int> live_players);

    void generatePlayers(int n);
    int selectPlayer();
    void endRound(RPG* winner, RPG* loser, int loserIndex);
    void battleRound();
    void gameLoop();
    void printFinalResults();

    // Destructor
    ~Game();

private:
    std::vector<RPG*> players;
    std::set<int> live_players;
};

#endif // GAME_H