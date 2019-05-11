#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

using namespace std;

typedef vector<Rect*>::const_iterator RectCont;
typedef vector<TexRect*>::const_iterator TexCont;

Game::Game(){

	// Player
	player = new TexRect("mushroom.png", 0.0, -0.7, 0.1, 0.1);

	// Top row
	enemy.push_back(new TexRect("mushroom.png", -0.95, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.65, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.35, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.05, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.25, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.55, 1.3, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.85, 1.3, 0.1, 0.1));

	// Middle top row
	enemy.push_back(new TexRect("mushroom.png", -0.8, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.5, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.2, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.1, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.4, 1.1, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.7, 1.1, 0.1, 0.1));

	// Middle bottom row
	enemy.push_back(new TexRect("mushroom.png", -0.95, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.65, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.35, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.05, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.25, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.55, 0.9, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.85, 0.9, 0.1, 0.1));

	// Bottom row
	enemy.push_back(new TexRect("mushroom.png", -0.8, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.5, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", -0.2, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.1, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.4, 0.7, 0.1, 0.1));
	enemy.push_back(new TexRect("mushroom.png", 0.7, 0.7, 0.1, 0.1));

	for (TexCont it = enemy.begin(); it != enemy.end(); ++it) {
		enemyVisible.push_back(true);
	}

	missileX = 0.0;
	missileY = 0.0;

	state = START;

	setRate(1);
	start();
}

void Game::action(){

	if (state != PAUSE) {
		for (int i = 0; i < missileVisible.size(); i++) {
			if (missileVisible[i]) {
				missile[i]->setY(missile[i]->getY() + 0.01);
				for (int j = 0; j < enemy.size(); j++) {
					if (enemy[j]->contains(missile[i]->getX(), missile[i]->getY()) && enemyVisible[j]) {
						missileVisible[i] = false;
						enemyVisible[j] = false;
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
}

void Game::handleKeyDown(unsigned char key, float x, float y){

	if (state == START) {
		if (key == 'w' && player->getY() < 1.95) {
			player->setY(player->getY() + 0.05);
			player->redrawScene();
		} else if (key == 'a' && player->getX() > -1.0) {
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
		missileY = player->getY() + 0.1;
		missile.push_back(new Rect(missileX, missileY, 0.02, 0.03, 1.0, 1.0, 1.0));
		missileVisible.push_back(true);
	} else if ( key == 'p') {
		state = PAUSE;
	} else if (key == 'r') {
		state = START;
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
