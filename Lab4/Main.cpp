// lab 3 stuff
#include <iostream>
#include <cstdio>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main() {
//create a game object
	Game newGame;
//create num_players as an int and set it to 10
	int numPlayers = 10;
//call generatePlayers(numPlayers)
	newGame.generatePlayers(numPlayers);

//call gameLoop()
	newGame.gameLoop();

//printFinalResults()
	newGame.printFinalResults();





	return 0;
}
