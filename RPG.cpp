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
void RPG::setName(string newname) {
	this->name = newname;

}
void RPG::updateExpLvl() {
	this->exp += 50;
	if (this->exp >= 100) {
		this->lvl += 1;
		this->exp = 0;
		this->luck += 0.1;
	}
}
void RPG::attack(RPG& target) {
	random_device rd;
	mt19937 gen(rd()); 
	uniform_real_distrobution<double> dis(0.0, 1.0);
	float temp = 1 - target.getLuck();
	if (temp < dis(gen)) {
		target.setHitsTaken(target.getHitsTaken() + 1);
	}
	else {
		cout << target.getName() << " dodged the attack!" << endl;
	}
}
void RPG::printStats() {
	cout << "Name: " << getName() << endl;
	cout << "Level: " << getLvl() << endl;
	cout << "Experience: " << getExp() << endl;
	cout << "Hits Taken: " << getHitsTaken() << endl;
	cout << "Luck: " << getLuck() << endl;
}