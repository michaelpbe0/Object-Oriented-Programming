#ifndef Game_H
#define Game_H
#include <string>
#include <vector>
#include <set>
using namespace std;
class Game {
public:
	//constructors
	Game();
	Game(vector<RPG*> players, set<int> live_players);
	
	void generatePlayers(int n);
	int selectPlayer();s
	void endRound(RPG* winner, RPG* loser, int loserIndex);
	void battleRound();
	void gameLoop();
	void printFinalResults();

	//destructor
	~Game();

private:
	vector<RPG*> players;
	set<int> live_players;
#endif Game_H