// lab 3 stuff
#include <iostream>
#include <cstdio>
#include "RPG.h"
using namespace std;

int main() {
	RPG p1 = RPG("Wiz", 0, 0.2f, 60.0f, 1);
	RPG p2 = RPG();

	// use correct printf formats for types
	printf("%s Current Stats\n", p1.getName().c_str());
	printf("Hits Taken: %d\t Luck: %.2f\t EXP: %.2f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLvl());

	return 0;
}
