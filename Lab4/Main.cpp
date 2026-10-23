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

	printf("%s Current Stats\n", p2.getName().c_str());
	printf("Hits Taken: %d\t Luck: %.2f\t EXP: %.2f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLvl());

	p1.setHitsTaken(3);
	p2.setHitsTaken(2);

	cout << " \nP2 hits taken ";
	cout << p2.getHitsTaken() << endl;

	cout << " \nP1 hits taken ";
	cout << p1.getHitsTaken() << endl;

	cout << "0 is dead, 1 is alive for P1" << endl;
	cout << p1.isAlive() << endl;

	cout << "0 is dead, 1 is alive for P2" << endl;
	cout << p2.isAlive() << endl;




	return 0;
}
