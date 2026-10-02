//lab 3 stuff
#include <iostream>
#include "RPG.h"
using namespace std;

int main(){
	RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
	RPG p2 = RPG();

	printf("%s Current Stats\n", p1.getName().c_str());
	printf("Hits Taken: %i\t Luck: %i\t", p1.getHitsTaken().c_str(), p1.getLuck();
}
