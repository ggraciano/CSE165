#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"

using namespace std;

enum {MENU, CONTROLS, GAMEOVER, PAUSE, SCORES, START};

class Game: public AppComponent, private Timer{

	TexRect* player;

	vector<Rect*> menu;

	vector<TexRect*> enemy;
	vector<bool> enemyVisible;

	vector<Rect*> missile;
	vector<bool> missileVisible;

	float missileX;
	float missileY;

	float rateX;
	float rateY;

	float leftRange;
	float rightRange;
	float topRange;
	float bottomRange;

	bool moveLeft;
	bool moveRight;

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

	void newGame();
	void nextLevel();
    
    void action();

    ~Game();

};

#endif 
