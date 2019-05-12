#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <cstring>
#include <sstream>

#include "Game.h"

using namespace std;

typedef vector<Rect*>::const_iterator RectCont;
typedef vector<TexRect*>::const_iterator TexCont;

Game::Game(){

	// Player
	player = new TexRect("mushroom.png", 0.0, -0.9, 0.1, 0.1);

	// Top row		0-10
	enemy.push_back(new TexRect("invader3-small.png", -0.80, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png", -0.65, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png", -0.50, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png", -0.35, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png", -0.20, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png", -0.05, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png",  0.10, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png",  0.25, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png",  0.40, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png",  0.55, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("invader3-small.png",  0.70, 1.3, 0.1, 0.1));

	// Middle top row	11-21
	enemy.push_back(new TexRect("invader2-small.png", -0.80, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.65, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.50, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.35, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.20, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.05, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.10, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.25, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.40, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.55, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.70, 1.1, 0.1, 0.1));

	// Middle row		22-32
	enemy.push_back(new TexRect("invader2-small.png", -0.80, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.65, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.50, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.35, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.20, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png", -0.05, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.10, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.25, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.40, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.55, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("invader2-small.png",  0.70, 0.9, 0.1, 0.1));

	// Middle bottom row	33-43
	enemy.push_back(new TexRect("invader1-small.png", -0.80, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.65, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.50, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.35, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.20, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.05, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.10, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.25, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.40, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.55, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.70, 0.7, 0.1, 0.1));

	// Bottom row		44-54
	enemy.push_back(new TexRect("invader1-small.png", -0.80, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.65, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.50, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.35, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.20, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png", -0.05, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.10, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.25, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.40, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.55, 0.5, 0.1, 0.1));
	enemy.push_back(new TexRect("invader1-small.png",  0.70, 0.5, 0.1, 0.1));

	for (TexCont it = enemy.begin(); it != enemy.end(); ++it) {
		enemyVisible.push_back(true);
	}

	missileX = 0.0;
	missileY = 0.0;

	rateX = 0.000025;
	rateY = 0.005;

	moveLeft = false;
	moveRight = true;

	state = START;
	score = 0;

	setRate(1);
	start();
}

void Game::action(){

	if (state != PAUSE) {

		// Hit handle
		for (int i = 0; i < missileVisible.size(); i++) {
			if (missileVisible[i]) {
				missile[i]->setY(missile[i]->getY() + 0.01);
				for (int j = 0; j < enemy.size(); j++) {
					if (enemy[j]->contains(missile[i]->getX(), missile[i]->getY()) && enemyVisible[j]) {
						missileVisible[i] = false;
						enemyVisible[j] = false;
						if (j >= 0 && j <= 10) {
							score += 30;
						} else if (j >= 11 && j <= 32) {
							score += 20;
						} else if (j >= 33 && j <= 54) {
							score += 10;
						}
					}
				}
			}
		}

		// Enemy movement handle
		for (int i = 0; i < enemy.size()/11; i++) {
			for (int j = 0; j < enemy.size(); j++) {
				if (moveRight) {
					enemy[j]->setX(enemy[j]->getX() + rateX);
					if (enemy[10 + 11*i]->getX() > 0.90) {
						moveLeft = true;
						moveRight = false;
						for (int k = 0; k < enemy.size(); k++) {
							enemy[k]->setY(enemy[k]->getY() - rateY);
						}			
					}
				} else if (moveLeft) {
					enemy[j]->setX(enemy[j]->getX() - rateX);
					if (enemy[11*i]->getX() < -1.00) {
						moveLeft = false;
						moveRight = true;
						for (int k = 0; k < enemy.size(); k++) {
							enemy[k]->setY(enemy[k]->getY() - rateY);
						}
					}
				}
			}
		}
	}

}

void Game::draw() const {

	player->draw(0.0);

	for (int i = 0; i < enemy.size(); i++) {
		if (enemyVisible[i]) {
			enemy[i]->draw(0.0);
		}
	}

	for (int i = 0; i < missile.size(); i++) {
		if (missileVisible[i]) {
			missile[i]->draw();
		}
	}

	stringstream ss;
	ss << score;

	string s = ss.str();

	const char* text = s.c_str();

	handleText("SCORE: ", -0.95, 1.90);
	handleText(text, -0.70, 1.90);

}

void Game::handleKeyDown(unsigned char key, float x, float y){

	if (state == START) {
		if (key == 'w' && player->getY() < 1.95) {
			player->setY(player->getY() + 0.05);
			player->redrawScene();
		} else if (key == 'a' && player->getX() > -1.00) {
			player->setX(player->getX() - 0.05);
			player->redrawScene();
		} else if (key == 's' && player->getY() > -1.85) {
			player->setY(player->getY() - 0.05);
			player->redrawScene();
		} else 	if (key == 'd' && player->getX() < 0.90) {
			player->setX(player->getX() + 0.05);
			player->redrawScene();
		}
	}


	if (key == ' ') {
		missileX = player->getX() + 0.05;
		missileY = player->getY() - 0.10;
		missile.push_back(new Rect(missileX, missileY, 0.02, 0.03, 1.0, 1.0, 1.0));
		missileVisible.push_back(true);
	} else if ( key == 'p') {
		state = PAUSE;
	} else if (key == 'r') {
		state = START;
	}

}

void Game::handleText(const char* text, float x, float y) const{

	glColor3f(1.0, 1.0, 1.0);
	float offset = 0;
	for (int i = 0; i < (int)strlen(text); i++) {
		glRasterPos2f(x+offset, y);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
		int w = glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, text[i]);
		offset += ((float)w / 600)*2;
	}

}

Game::~Game(){

	stop();

	delete player;

	for (TexCont it = enemy.begin(); it != enemy.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = missile.begin(); it != missile.end(); ++it) {
		delete (*it);
	}

}