#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>

#include "Game.h"

using namespace std;

typedef vector<Rect*>::const_iterator RectCont;
typedef vector<TexRect*>::const_iterator TexCont;

Game::Game(){

	// Title
	title = new TexRect("space-invaders.png", -0.80, 1.7, 1.6, 1.2);

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

	playerNum = 1;
	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

	state = MENU;
	score = 0;

	setRate(1);
	start();

}

void Game::action(){

	if (state == START) {

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
							rateX += 0.000002;
							score += 30;
						} else if (j >= 11 && j <= 32) {
							rateX += 0.000004;
							score += 20;
						} else if (j >= 33 && j <= 54) {
							rateX += 0.000006;
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

		// Enemy shoot handle
		int thirdLast = enemyMissileVisible.size() - 3;
		if (thirdLast < 0 || (thirdLast >= 0 && !enemyMissileVisible[thirdLast])) {
			int r = rand() % 55;
			if (enemyVisible[r]) {
				if (r >= 44 && r <= 54) {
					enemyMissile.push_back(new Rect(enemy[r]->getX() + 0.04,
									enemy[r]->getY() - 0.10,
									0.02, 0.03, 1.0, 0.0, 0.0));
					enemyMissileVisible.push_back(true);
				} else if (checkColBelow(r)) {
					enemyMissile.push_back(new Rect(enemy[r]->getX() + 0.04,
									enemy[r]->getY() - 0.10,
									0.02, 0.03, 1.0, 0.0, 0.0));
					enemyMissileVisible.push_back(true);
				}
			}
		}

		// Enemy hit handle
		for (int i = 0; i < enemyMissile.size(); i++) {
			if (enemyMissileVisible[i]) {
				enemyMissile[i]->setY(enemyMissile[i]->getY() - 0.0005);
				if (player->contains(enemyMissile[i]->getX(), enemyMissile[i]->getY())) {
					enemyMissileVisible[i] = false;
					playerNum--;
					break;
				} else if (enemyMissile[i]->getY() < -topRange + 0.10) {
					enemyMissileVisible[i] = false;
				}
			}
		}

		// Check for next level
		if (enemyNum == 0) {
			nextLevel();
		}

		// Check for gameover
		if (playerNum == 0) {
			state = GAMEOVER;
			ifScore();
		} else {
			for (int i = 0; i < enemy.size(); i++) {
				if (enemyVisible[i] && (enemy[i]->contains(player->getX(), player->getY()) || enemy[i]->getY() < -0.9)) {
					state = GAMEOVER;
					ifScore();
					break;
				}
			}
		}

	}

}

void Game::draw() const {

	(const_cast<Game*>(this))->ofScore();

	if (state == MENU) {

		title->draw(0.0);

		handleText("START",    -0.130,  0.075, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);
		handleText("SCORES",   -0.155, -0.325, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);
		handleText("CONTROLS", -0.215, -0.725, GLUT_BITMAP_TIMES_ROMAN_24, 0.0, 0.0, 0.0);

		for (int i = 0; i < menu.size(); i++) {
			menu[i]->draw();
		}

		handleText("PRESS 'esc' TO EXIT", -0.385, -1.4, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

	} else if (state == SCORES) {

		handleText("SCORES", -0.155, 0.75, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

//		(const_cast<Game*>(this))->ofScore();

		stringstream ss;

		int size = fscore.size();

		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				if (size > 0) {
					ss << fscore[0];
					string s = ss.str();
					const char* text = s.c_str();
					handleText("1 - ", -0.145,  0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
					handleText(text,   -0.015,  0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				} else {
					handleText("1 - 0", -0.145,  0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				}
			} else if (i == 1) {
				if (size > 1) {
					ss << fscore[1];
					string s = ss.str();
					const char* text = s.c_str();
					handleText("2 - ", -0.145, -0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
					handleText(text,   -0.015, -0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				} else {
					handleText("2 - 0", -0.145, -0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				}
			} else if (i == 2) {
				if (size > 2) {
					ss << fscore[2];
					string s = ss.str();
					const char* text = s.c_str();
					handleText("3 - ", -0.145, -0.15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
					handleText(text,   -0.015, -0.15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				} else {
					handleText("3 - 0", -0.145, -0.15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				}
			} else if (i == 3) {
				if (size > 3) {
					ss << fscore[3];
					string s = ss.str();
					const char* text = s.c_str();
					handleText("4 - ", -0.145, -0.25, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
					handleText(text,   -0.015, -0.25, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				} else {
					handleText("4 - 0", -0.145, -0.25, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				}
			} else if (i == 4) {
				if (size > 4) {
					ss << fscore[4];
					string s = ss.str();
					const char* text = s.c_str();
					handleText("5 - ", -0.145, -0.35, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
					handleText(text,   -0.015, -0.35, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				} else {
					handleText("5 - 0", -0.145, -0.35, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
				}
			}
			ss.str(string());
			ss.clear();
		}

		handleText("PRESS 'm' TO RETURN TO MENU", -0.63, -1.4, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

	} else if (state == CONTROLS) {

		handleText("CONTROLS", -0.215, 0.75, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("W - UP",    -0.20,   0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText("A - LEFT",  -0.20,  -0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText("S - DOWN",  -0.20,  -0.15, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText("D - RIGHT", -0.20,  -0.25, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("SPACE - SHOOT", -0.31, -0.45, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("P - PAUSE",  -0.235, -0.65, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText("R - RESUME", -0.235, -0.75, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("PRESS 'm' TO RETURN TO MENU", -0.63, -1.4, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

	} else {

		stringstream ss;
		ss << score;

		string cs = ss.str();

		ss.str(string());
		ss.clear();

		if (fscore.size() == 0) {
			ss << 0;
		} else if (score < fscore[0]) {
			ss << fscore[0];
		} else {
			ss << score;
		}

		string hs = ss.str();

		ss.str(string());
		ss.clear();

		const char* currScore = cs.c_str();
		const char* highScore = hs.c_str();

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

			for (int i = 0; i < enemyMissile.size(); i++) {
				if (enemyMissileVisible[i]) {
					enemyMissile[i]->draw();
				}
			}

		} else if (state == PAUSE) {
			handleText("PUASED", -0.16, 0.50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

			handleText("PRESS 'r' TO RESUME",           -0.42, -0.20, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText("PRESS 'n' TO START A NEW GAME", -0.66, -0.40, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText("PRESS 'm' TO RETURN TO MENU",   -0.63, -0.60, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		} else if (state == GAMEOVER) {
			handleText("GAMEOVER", -0.23, 0.50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

			handleText("PRESS 'n' TO START A NEW GAME", -0.66, -0.20, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
			handleText("PRESS 'm' TO RETURN TO MENU",   -0.63, -0.40, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		}

		handleText("SCORE: ", leftRange + 0.05, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText(currScore, leftRange + 0.35, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

		handleText("HIGHSCORE: ", -0.34, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);
		handleText(highScore,      0.18, topRange - 0.05, GLUT_BITMAP_TIMES_ROMAN_24, 1.0, 1.0, 1.0);

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
		if ((last < 0) || (last >= 0 && !missileVisible[last])) {
			missile.push_back(new Rect(player->getX() + 0.04,
						player->getY() - 0.10,
						0.02, 0.03, 1.0, 1.0, 1.0));
			missileVisible.push_back(true);
		}
	} else if (key == 'p' && state == START) {
		state = PAUSE;
	} else if (key == 'r' && state == PAUSE) {
		state = START;
	} else if (key == 'n' && (state == PAUSE || state == GAMEOVER)) {
		newGame(START);
	} else if (key == 'm' && (state == PAUSE || state == GAMEOVER)) {
		newGame(MENU);
	} else if (key == 'm' && (state == SCORES || state == CONTROLS)) {
		state = MENU;
	}

}

void Game::handleLeftMouseDown(float mx, float my) {

	if (state == MENU) {
		if (menu[0]->contains(mx, my)) {
			state = START;
		} else if (menu[1]->contains(mx, my * (float)2)) {
			state = SCORES;
		} else if (menu[2]->contains(mx, my * (float)2)) {
			state = CONTROLS;
		}
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

bool Game::checkColBelow(int r) {

	if (r >= 0 && r <= 10) {
		for (int i = 1; i < 5; i++) {
			if (enemyVisible[r + 11*i]) {
				return false;
			}
		}
	} else if (r >= 11 && r <= 21) {
		for (int i = 1; i < 4; i++) {
			if (enemyVisible[r + 11*i]) {
				return false;
			}
		}
	} else if (r >= 22 && r <= 32) {
		for (int i = 1; i < 3; i++) {
			if (enemyVisible[r + 11*i]) {
				return false;
			}
		}
	} else if (r >= 33 && r <= 43) {
		for (int i = 1; i < 2; i++) {
			if (enemyVisible[r + 11*i]) {
				return false;
			}
		}
	}

	return true;
}

void Game::ifScore() {

	stringstream ss;
	ss << score;

	string s = ss.str();

	ss.str(string());
	ss.clear();

	fstream fileScore;
	fileScore.open("scores.txt", fstream::out | ios::app);

	if (fileScore.is_open()) {
		fileScore << s << endl;
	}

	fileScore.close();

}

void Game::ofScore() {

	stringstream ss;

	string s;

	int i;

	fstream fileScore;
	fileScore.open("scores.txt", fstream::in);

	fscore.clear();

	if (fileScore.is_open()) {
		while (getline(fileScore, s)) {
			ss << s;
			ss >> i;
			ss.str(string());
			ss.clear();
			fscore.push_back(i);
		}
	}

	sort(fscore.begin(), fscore.end(), greater<int>());

	fileScore.close();

	fileScore.open("scores.txt", fstream::out | fstream::trunc | ios::app);

	if (fileScore.is_open()) {
		for (int i = 0; i < fscore.size(); i++) {
			fileScore << fscore[i] << endl;
		}
	}

	fileScore.close();

}

void Game::newGame(int state) {

	player->setX(0.0); player->setY(-0.9);

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

	for (RectCont it = missile.begin(); it != missile.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = enemyMissile.begin(); it != enemyMissile.end(); ++it) {
		delete (*it);
	}

	missile.clear();
	missileVisible.clear();

	enemyMissile.clear();
	enemyMissileVisible.clear();

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

	playerNum = 1;
	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

	this->state = state;
	score = 0;

}

void Game::nextLevel() {

	player->setX(0.0); player->setY(-0.9);

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

	for (RectCont it = missile.begin(); it != missile.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = enemyMissile.begin(); it != enemyMissile.end(); ++it) {
		delete (*it);
	}

	missile.clear();
	missileVisible.clear();

	enemyMissile.clear();
	enemyMissileVisible.clear();

	moveLeft = false;
	moveRight = true;

	enemyNum = 55;

	leftCol = 0;
	rightCol = 10;

}

Game::~Game(){

	stop();

	delete title;

	delete player;

	for (TexCont it = enemy.begin(); it != enemy.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = missile.begin(); it != missile.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = enemyMissile.begin(); it != enemyMissile.end(); ++it) {
		delete (*it);
	}

	for (RectCont it = menu.begin(); it != menu.end(); ++it) {
		delete (*it);
	}

}
