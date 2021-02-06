#include <iostream>
#include <string>

using namespace std;

const unsigned char OFFENSE = 0;
const unsigned char DEFENSE = 1;
const unsigned char SPECIALTEAMS = 2;
const unsigned char TOTAL = 3;

class Team {
private:
	string name;
	float score[3];

public:
	void updateTotal() {
		score[TOTAL] = score[OFFENSE] - score[DEFENSE] + score[SPECIALTEAMS];
	}

	float getScore(unsigned char side){
		return score[side];
	}

	void setScore(unsigned char side, float val){
		score[side] = val;
		updateTotal();
	}

	float calcMargin(Team* enemy){
		return enemy->getScore(TOTAL)-getScore(TOTAL);
	}


	Team(string n, float off, float def, float st){
		name = n;
		score[OFFENSE] = off;
		score[DEFENSE] = def;
		score[SPECIALTEAMS] = st;
		updateTotal();
	}

	Team(string n, float tot){
		name = n;
		score[TOTAL]=tot;
	}

	Team(string n){
		name = n;
	}


};

int main(int argc, char *argv[]){
	Team* t1;
	Team* t2;
	if (argc==9){
		t1 = new Team(argv[1], stof(argv[2]), stof(argv[3]), stof(argv[4]));
		t2 = new Team(argv[5], stof(argv[6]), stof(argv[7]), stof(argv[8]));
		cout<<t1->calcMargin(t2);
	}
	else if(argc==5){
		t1 = new Team(argv[1], stof(argv[2]));
		t2 = new Team(argv[3], stof(argv[4]));
		cout<<t1->calcMargin(t2);
	}
	else if(argc==3){
		t1 = new Team(argv[1]);
		t2 = new Team(argv[2]);
	}

	delete t1;
	delete t2;
	
	return 0;
}