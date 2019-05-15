#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"

using namespace std;

enum {MENU, SCORES, CONTROLS, PAUSE, START, GAMEOVER};

class Game: public AppComponent, private Timer{

	TexRect* title;

	TexRect* player;

	vector<Rect*> menu;
	vector<int> fscore;

	vector<TexRect*> enemy;
	vector<bool> enemyVisible;

	vector<Rect*> missile;
	vector<bool> missileVisible;

	vector<Rect*> enemyMissile;
	vector<bool> enemyMissileVisible;

	float missileX;
	float missileY;

	float enemyMissileX;
	float enemyMissileY;

	float rateX;
	float rateY;

	float leftRange;
	float rightRange;
	float topRange;
	float bottomRange;

	bool moveLeft;
	bool moveRight;

	int playerNum;
	int enemyNum;

	int leftCol;
	int rightCol;

	int state;
	int score;

public:

    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);

	void handleLeftMouseDown(float, float);

	void handleText(const char*, float, float, void*, float, float, float) const;

	bool checkColBelow(int);

	void ifScore();
	void ofScore();

	void newGame(int);
	void nextLevel();
    
    void action();

    ~Game();

};

#endif 
