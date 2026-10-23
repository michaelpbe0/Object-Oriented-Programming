#include "Game.h"
#include <string>
#include <vector>
#include <set>
using namespace std;


	//constructors
	Game::Game() 
	{
	}
	Game::Game(vector<RPG*> players, set<int> live_players) {
		this->players = players;
		this->live_players = live_players;
	}

	void Game::generatePlayers(int n) {
		for (int i = 0; i < n; i++) {
			players.push_back(new RPG());
			string name = "NPC_" + to_string(i);
			players[i]->setName(name);
			live_players.insert(i);
		}
	}
	int Game::selectPlayer() {
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distrobution<> dis(0, live_players.size() - 1);
		int randomIndex = dis(gen);
		set<int>::iterator it = live_players.begin();
		advance(it, randomIndex);
		return *it;
	}
	void Game::endRound(RPG* winner, RPG* loser, int loserIndex) {
		winner->setHitsTaken(0);
		winner->updateExpLvl();
		//remove the loser from the live_players set
		live_players.erase(loserIndex);
		cout << loser->getName() << " has been eliminated from the game by " << winner->getName() << "!" << endl;
	}
	void Game::battleRound() {
		int player1Index = selectPlayer();
		int player2Index = selectPlayer();
		while (player1Index == player2Index) {
			player2Index = selectPlayer();
		}
		RPG* player1 = players[player1Index];
		RPG* player2 = players[player2Index];
		cout << "Battle between " << player1->getName() << " and " << player2->getName() << "!" << endl;
		while (player1->isAlive() && player2->isAlive()) {
			player1->attack(*player2);
			if (!player2->isAlive()) {
				endRound(player1, player2, player2Index);
				break;
			}
			player2->attack(*player1);
			if (!player1->isAlive()) {
				endRound(player2, player1, player1Index);
				break;
			}
		}
	}
	void Game::gameLoop() {
		int i = 0;
		if (live_players.size() >= 2) {
			
			cout << "Round " << i << "\n" << endl;
			battleRound();
		}
		else
		{
			cout << "End Game" << endl;
			return;
		}
	}
	void Game::printFinalResults() {
		for (int i = 0; i < live_players.size();i++) {
			live_players(i).printStats();
			cout << "\n\n";

		}
	}

	//destructor
	Game::~Game() {

	}