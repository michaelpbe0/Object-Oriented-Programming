#include "RPG.h"
// RPG

RPG::RPG() {
	name = "NPC";
	hits_taken = 0;
	luck = 0.1f;
	exp = 50.0f;
	lvl = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int lvl) {
	this->name = name;
	this->hits_taken = hits_taken;
	this->luck = luck;
	this->exp = exp;
	this->lvl = lvl;
}

// accessors
string RPG::getName() const {
	return name;
}

int RPG::getHitsTaken() const {
	return hits_taken;
}

float RPG::getLuck() const {
	return luck;
}

float RPG::getExp() const {
	return exp;
}

int RPG::getLvl() const {
	return lvl;
}

// mutator
void RPG::setHitsTaken(int newHits) {
	hits_taken = newHits;
}

bool RPG::isAlive() const {
	return getHitsTaken() < MAX_HITS_TAKEN;
}
