//RPG.h
#ifndef RPG_H
#define RPG_H
#include <string>

using namespace std;
const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG {
	public:
		//constructors
		RPG();
		RPG(string name, int hits_taken, float luck, float exp, int lvl);
	
		//mutators
		bool isAlive() const;
		void setHitsTaken(int newhits);
		void setName(string newname);
		void updateExpLvl();
		void attack(RPG& target);
		void printStats();
	
		//accessors 
		string getName() const;
		int getHitsTaken() const;
		float getLuck() const;
		float getExp() const;
		int getLvl() const;

		~RPG();
	private:
		string name;
		int hits_taken;
		float luck;
		float exp;
		int lvl;






};
#endif
