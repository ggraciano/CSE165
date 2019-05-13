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

	// Menu
	menu.push_back(new Rect(-0.5,  0.2, 1.0, 0.2));
	menu.push_back(new Rect(-0.5, -0.2, 1.0, 0.2));
	menu.push_back(new Rect(-0.5, -0.6, 1.0, 0.2));

	// Player
	player = new TexRect("cannon-small.png", 0.0, -0.9, 0.1, 0.1);

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
	rateY = 0.01;

	leftRange = -1.00;
	rightRange = 0.90;
	topRange = 1.95;
	bottomRange = -1.85;

	moveLeft = false;
	moveRight = true;

	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

	state = MENU;
	score = 0;

	setRate(1);
	start();

}

void Game::action(){

	if (state != PAUSE) {

		// Hit handle
		for (int i = 0; i < missileVisible.size(); i++) {
			if (missileVisible[i]) {
				missile[i]->setY(missile[i]->getY() + 0.005);
				for (int j = 0; j < enemy.size(); j++) {
					if (enemy[j]->contains(missile[i]->getX(), missile[i]->getY()) && enemyVisible[j]) {
						missileVisible[i] = false;
						enemyVisible[j] = false;
						enemyNum--;
						if (j >= 0 && j <= 10) {
							rateX += 0.000006;
							score += 30;
						} else if (j >= 11 && j <= 32) {
							rateX += 0.000004;
							score += 20;
						} else if (j >= 33 && j <= 54) {
							rateX += 0.000002;
							score += 10;
						}
					} else if (missile[i]->getY() > topRange - 0.10) {
						missileVisible[i] = false;
					}
				}
			}
		}

		// Enemy movement handle
		for (int i = 0; i < enemy.size()/11; i++) {
			for (int j = 0; j < enemy.size(); j++) {
				if (moveRight) {
					enemy[j]->setX(enemy[j]->getX() + rateX);
					if (enemy[rightCol + 11*i]->getX() > rightRange) {
						moveLeft = true;
						moveRight = false;
						for (int k = 0; k < enemy.size(); k++) {
							enemy[k]->setY(enemy[k]->getY() - rateY);
						}
					}
				} else if (moveLeft) {
					enemy[j]->setX(enemy[j]->getX() - rateX);
					if (enemy[leftCol + 11*i]->getX() < leftRange) {
						moveLeft = false;
						moveRight = true;
						for (int k = 0; k < enemy.size(); k++) {
							enemy[k]->setY(enemy[k]->getY() - rateY);
						}
					}
				}
			}
		}

		// Adjust enemy edge
		if (enemyNum > 0) {
			int countRightCol = 0;
			int countLeftCol = 0;
			for (int i = 0; i < enemy.size()/11; i++) {
				if (!enemyVisible[rightCol + 11*i]) {
					countRightCol++;
				}
				if (!enemyVisible[leftCol + 11*i]) {
					countLeftCol++;
				}
			}
			if (countRightCol == enemy.size()/11) {
				rightCol--;
			}
			if (countLeftCol == enemy.size()/11) {
				leftCol++;
			}
		}

		// Check for next level
		if (enemyNum == 0) {
			nextLevel();
		}

		// Check for gameover
		for (int i = 0; i < enemy.size(); i++) {
			if (enemyVisible[i] && enemy[i]->contains(player->getX(), player->getY())) {
				state = GAMEOVER;
			} else if (enemyVisible[i] && enemy[i]->getY() < -0.9) {
				state = GAMEOVER;
			}
		}

	}

}

void Game::draw() const {

	if (state == MENU) {
		handleText("SPACE INVADERS", -0.130, 1.0, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("START", -0.130, 0.075, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);
		handleText("SCORES", -0.155, -0.325, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);
		handleText("CONTROLS", -0.215, -0.725, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);

		for (int i = 0; i < menu.size(); i++) {
			menu[i]->draw();
		}
	} else {
		stringstream ss;
		ss << score;

		string s = ss.str();

		const char* text = s.c_str();

		if (state == START) {

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

			handleText("SCORE: ", leftRange + 0.05, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText(text, leftRange + 0.35, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		} else if (state == PAUSE) {
			handleText("PUASED", -0.16, 0.50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText("PRESS 'r' TO RESUME", -0.42, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		} else if (state == GAMEOVER) {
			handleText("GAMEOVER", -0.23, 0.50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText("PRESS 'n' TO START A NEW GAME", -0.66, -0.20, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		}

		handleText("SCORE: ", leftRange + 0.05, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText(text, leftRange + 0.35, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
	}

}

void Game::handleKeyDown(unsigned char key, float x, float y){

	if (state == START) {
		if (key == 'w' && player->getY() < topRange) {
			player->setY(player->getY() + 0.05);
		} else if (key == 'a' && player->getX() > leftRange) {
			player->setX(player->getX() - 0.05);
		} else if (key == 's' && player->getY() > bottomRange) {
			player->setY(player->getY() - 0.05);
		} else 	if (key == 'd' && player->getX() < rightRange) {
			player->setX(player->getX() + 0.05);
		}
	}


	if (key == ' ' && state == START) {
		int last = missile.size() - 1;
		if (last >= 0 && !missileVisible[last]) {
			missileX = player->getX() + 0.05;
			missileY = player->getY() - 0.10;
			missile.push_back(new Rect(missileX, missileY, 0.02, 0.03, 1.0, 1.0, 1.0));
			missileVisible.push_back(true);
		} else if (last < 0) {
			missileX = player->getX() + 0.05;
			missileY = player->getY() - 0.10;
			missile.push_back(new Rect(missileX, missileY, 0.02, 0.03, 1.0, 1.0, 1.0));
			missileVisible.push_back(true);
		}
	} else if (key == 'p' && state == START) {
		state = PAUSE;
	} else if (key == 'r' && state == PAUSE) {
		state = START;
	} else if (key == 'n' && state == GAMEOVER) {
		newGame();
	}

}

void Game::handleLeftMouseDown(float mx, float my) {

	if (menu[0]->contains(mx, my)) {
		state = START;
	} else if (menu[1]->contains(mx, my * (float)2)) {
		state = SCORES;
	} else if (menu[2]->contains(mx, my * (float)2)) {
		state = CONTROLS;
	}

}

void Game::handleText(const char* text, float x, float y, void* font, float r, float g, float b) const {

	glColor3f(r, g, b);
	float offset = 0;
	for (int i = 0; i < (int)strlen(text); i++) {
		glRasterPos2f(x+offset, y);
		glutBitmapCharacter(font, text[i]);
		int w = glutBitmapWidth(font, text[i]);
		offset += ((float)w / 600)*2;
//cout << offset << endl;
	}

}

void Game::newGame() {

	// Player
	player = new TexRect("cannon-small.png", 0.0, -0.9, 0.1, 0.1);

	for (int i = 0; i < enemy.size()/11; i++) {
		enemy[11*i +  0]->setX(-0.80); enemy[11*i +  0]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  1]->setX(-0.65); enemy[11*i +  1]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  2]->setX(-0.50); enemy[11*i +  2]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  3]->setX(-0.35); enemy[11*i +  3]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  4]->setX(-0.20); enemy[11*i +  4]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  5]->setX(-0.05); enemy[11*i +  5]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  6]->setX( 0.10); enemy[11*i +  6]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  7]->setX( 0.25); enemy[11*i +  7]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  8]->setX( 0.40); enemy[11*i +  8]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  9]->setX( 0.55); enemy[11*i +  9]->setY(1.3 - (float)i * 0.2);
		enemy[11*i + 10]->setX( 0.70); enemy[11*i + 10]->setY(1.3 - (float)i * 0.2);
	}

	for (int i = 0; i < enemyVisible.size(); i++) {
		enemyVisible[i] = true;
	}

	moveLeft = false;
	moveRight = true;

	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

	missileX = 0.0;
	missileY = 0.0;

	rateX = 0.000025;
	rateY = 0.01;

	leftRange = -1.00;
	rightRange = 0.90;
	topRange = 1.95;
	bottomRange = -1.85;

	moveLeft = false;
	moveRight = true;

	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

	state = START;
	score = 0;

}

void Game::nextLevel() {

	for (int i = 0; i < enemy.size()/11; i++) {
		enemy[11*i +  0]->setX(-0.80); enemy[11*i +  0]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  1]->setX(-0.65); enemy[11*i +  1]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  2]->setX(-0.50); enemy[11*i +  2]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  3]->setX(-0.35); enemy[11*i +  3]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  4]->setX(-0.20); enemy[11*i +  4]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  5]->setX(-0.05); enemy[11*i +  5]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  6]->setX( 0.10); enemy[11*i +  6]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  7]->setX( 0.25); enemy[11*i +  7]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  8]->setX( 0.40); enemy[11*i +  8]->setY(1.3 - (float)i * 0.2);
		enemy[11*i +  9]->setX( 0.55); enemy[11*i +  9]->setY(1.3 - (float)i * 0.2);
		enemy[11*i + 10]->setX( 0.70); enemy[11*i + 10]->setY(1.3 - (float)i * 0.2);
	}

	for (int i = 0; i < enemyVisible.size(); i++) {
		enemyVisible[i] = true;
	}

	moveLeft = false;
	moveRight = true;

	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

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

	for (RectCont it = menu.begin(); it != menu.end(); ++it) {
		delete (*it);
	}

}
