#include "Paint.h"
#include <vector>
#include <GL/freeglut.h>

Paint::Paint() {
	fRED = 0.0;
	fGREEN = 0.0;
	fBLUE = 0.0;

	tool = none;
	color = NONE;

	// Tools
	layout.push_back(new Tools(-0.95, 0.95, 0.22, 0.22, false, NONE, eraser));
	layout.push_back(new Tools(-0.71, 0.95, 0.22, 0.22, false, NONE, pencil));

	layout.push_back(new Tools(-0.95, 0.71, 0.22, 0.22, false, NONE, brush));
	layout.push_back(new Tools(-0.71, 0.71, 0.22, 0.22, false, NONE, clear));

	// Colors
	layout.push_back(new Tools(-0.95, 0.47, 0.22, 0.22, false, BLACK, none));
	layout.push_back(new Tools(-0.71, 0.47, 0.22, 0.22, false, WHITE, none));

	layout.push_back(new Tools(-0.95, 0.23, 0.22, 0.22, false, GRAY, none));
	layout.push_back(new Tools(-0.71, 0.23, 0.22, 0.22, false, LGRAY, none));

	layout.push_back(new Tools(-0.95, -0.01, 0.22, 0.22, false, RED, none));
	layout.push_back(new Tools(-0.71, -0.01, 0.22, 0.22, false, LRED, none));

	layout.push_back(new Tools(-0.95, -0.25, 0.22, 0.22, false, YELLOW, none));
	layout.push_back(new Tools(-0.71, -0.25, 0.22, 0.22, false, LYELLOW, none));

	layout.push_back(new Tools(-0.95, -0.49, 0.22, 0.22, false, GREEN, none));
	layout.push_back(new Tools(-0.71, -0.49, 0.22, 0.22, false, LGREEN, none));

	layout.push_back(new Tools(-0.95, -0.73, 0.22, 0.22, false, BLUE, none));
	layout.push_back(new Tools(-0.71, -0.73, 0.22, 0.22, false, LBLUE, none));

	// Window
	layout.push_back(new Tools(-0.44, 0.95, 1.39, 1.90, true, WHITE, none));
}

Paint::~Paint() {
	for (std::vector<Position*>::iterator it = coord.begin(); it != coord.end(); ++it) {
		delete (*it);
	}
	coord.clear();

	for (std::vector<Tools*>::iterator it = layout.begin(); it != layout.end(); ++it) {
		delete (*it);
	}
	layout.clear();
}

void Paint::currColor() {
	switch (color) {
		case BLACK:
			fRED = 0.0; fGREEN = 0.0; fBLUE = 0.0;
			break;
		case WHITE:
			fRED = 1.0; fGREEN = 1.0; fBLUE = 1.0;
			break;
		case GRAY:
			fRED = 0.5; fGREEN = 0.5; fBLUE = 0.5;
			break;
		case LGRAY:
			fRED = 0.9; fGREEN = 0.9; fBLUE = 0.9;
			break;
		case RED:
			fRED = 0.8; fGREEN = 0.0; fBLUE = 0.0;
			break;
		case LRED:
			fRED = 1.0; fGREEN = 0.0; fBLUE = 0.0;
			break;
		case YELLOW:
			fRED = 0.8; fGREEN = 0.8; fBLUE = 0.0;
			break;
		case LYELLOW:
			fRED = 1.0; fGREEN = 1.0; fBLUE = 0.0;
			break;
		case GREEN:
			fRED = 0.0; fGREEN = 0.8; fBLUE = 0.0;
			break;
		case LGREEN:
			fRED = 0.0; fGREEN = 1.0; fBLUE = 0.0;
			break;
		case BLUE:
			fRED = 0.0; fGREEN = 0.0; fBLUE = 0.8;
			break;
		case LBLUE:
			fRED = 0.0; fGREEN = 0.0; fBLUE = 1.0;
			break;
		default:
			break;
	}

	return;
}

void Paint::motion(float mx, float my) {
	for (std::vector<Tools*>::iterator it = layout.begin(); it != layout.end(); ++it) {
		if ((*it)->getWrite() && (*it)->contains(mx + 0.025, my + 0.025) && (*it)->contains(mx - 0.025, my - 0.025) && tool == eraser) {
			color = WHITE;
			currColor();
			for (float i = 0.001; i <= 0.02; i += 0.001) {
				coord.push_back(new Position(mx - i, my + i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx + i, my + i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx - i, my - i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx + i, my - i, fRED, fGREEN, fBLUE));
			}
		} else if ((*it)->getWrite() && (*it)->contains(mx, my) && tool == pencil) {
			coord.push_back(new Position(mx, my, fRED, fGREEN, fBLUE));
		} else if ((*it)->getWrite() && (*it)->contains(mx + 0.015, my + 0.015) && (*it)->contains(mx - 0.015, my - 0.015) && tool == brush) {
			for (float i = 0.001; i <= 0.01; i += 0.001) {
				coord.push_back(new Position(mx - i, my + i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx + i, my + i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx - i, my - i, fRED, fGREEN, fBLUE));
				coord.push_back(new Position(mx + i, my - i, fRED, fGREEN, fBLUE));
			}
		}
	}

	return;
}

void Paint::handle(int b, int s, float mx, float my) {
	if (b == 0 && s == 0) {
		for (std::vector<Tools*>::iterator it = layout.begin(); it != layout.end() - 1; ++it) {
			if ((*it)->getTool() == eraser && (*it)->contains(mx, my)) {
				tool = eraser;
				color = WHITE;
			} else if ((*it)->getTool() == pencil && (*it)->contains(mx, my)) {
				tool = pencil;
				color = BLACK;
			} else if ((*it)->getTool() == brush && (*it)->contains(mx, my)) {
				tool = brush;
				color = BLACK;
			} else if ((*it)->getTool() == clear && (*it)->contains(mx, my)) {
				for (std::vector<Position*>::iterator it1 = coord.begin(); it1 != coord.end(); ++it1) {
					delete (*it1);
				}
				coord.clear();
			} else if ((*it)->getColor() == BLACK && (*it)->contains(mx, my)) {
				color = BLACK;
			} else if ((*it)->getColor() == WHITE && (*it)->contains(mx, my)) {
				color = WHITE;
			} else if ((*it)->getColor() == GRAY && (*it)->contains(mx, my)) {
				color = GRAY;
			} else if ((*it)->getColor() == LGRAY && (*it)->contains(mx, my)) {
				color = LGRAY;
			} else if ((*it)->getColor() == RED && (*it)->contains(mx, my)) {
				color = RED;
			} else if ((*it)->getColor() == LRED && (*it)->contains(mx, my)) {
				color = LRED;
			} else if ((*it)->getColor() == YELLOW && (*it)->contains(mx, my)) {
				color = YELLOW;
			} else if ((*it)->getColor() == LYELLOW && (*it)->contains(mx, my)) {
				color = LYELLOW;
			} else if ((*it)->getColor() == GREEN && (*it)->contains(mx, my)) {
				color = GREEN;
			} else if ((*it)->getColor() == LGREEN && (*it)->contains(mx, my)) {
				color = LGREEN;
			} else if ((*it)->getColor() == BLUE && (*it)->contains(mx, my)) {
				color = BLUE;
			} else if ((*it)->getColor() == LBLUE && (*it)->contains(mx, my)) {
				color = LBLUE;
			}

			currColor();
		}
	}

	return;
}

void Paint::draw() {
	for (std::vector<Tools*>::iterator it = layout.begin(); it != layout.end(); ++it) {
		(*it)->display();
	}

	glPointSize(5);

	glBegin(GL_POINTS);

	for (std::vector<Position*>::iterator it = coord.begin(); it != coord.end(); ++it) {
		glColor3f((*it)->getFRED(), (*it)->getFGREEN(), (*it)->getFBLUE());
		glVertex2f((*it)->getMx(), (*it)->getMy());
	}

	glEnd();

	return;
}

