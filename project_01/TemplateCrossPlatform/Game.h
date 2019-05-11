#ifndef Game_hpp
#define Game_hpp

#include <vector>

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"

using namespace std;

enum {MENU, PAUSE, START};

class Game: public AppComponent, private Timer{

	TexRect* background;
	TexRect* player;

	vector<Rect*> menu;

	vector<TexRect*> enemy;
	vector<bool> enemyVisible;

	vector<Rect*> missile;
	vector<bool> missileVisible;

	float missileX;
	float missileY;

	int state;

public:

    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    void action();

    ~Game();

};

#endif 
