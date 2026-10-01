//RPG
class RPG(){
	name = "NPC";
	hits_taken = 0;
	luck = 0.1;
	exp = 50.0;
	lvl = 1;
}
class RPG(string name, int hits_taken, float luck, float exp, int lvl) {
	this->name = name;
	this->hits_taken = hits_taken;
	this->luck = luck;
	this->exp = exp;
	this->lvl = lvl;

	//accessors
	string getName() const {
		return name;
	}
	int getHitsTaken() const {
		return hits_taken;
	}
	float getLuck() const {
		return luck;
	}
	float getExp() const {
		return exp;
	}
	int getLvl() const {
		return lvl;
	}


}