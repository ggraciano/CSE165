#include "Tools.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <cmath>

Tools::Tools() {

	x = -0.5;
	y = 0.5;
	w = 0.5;
	h = 0.5;

	curr = false;
	write = false;

	color = NONE;
	tool = none;
}

Tools::Tools(float x, float y, float w, float h, bool curr, bool write, Color color, Tool tool) {

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->curr = curr;
	this->write = write;

	this->color = color;
	this->tool = tool;
}

void Tools::setCurr(bool curr) {

	this->curr = curr;

	return;
}

bool Tools::getCurr() {

	return this->curr;
}

void Tools::setWrite(bool write) {

	this->write = write;

	return;
}

bool Tools::getWrite() {

	return this->write;
}

void Tools::setColor(Color color) {

	this->color = color;

	return;
}

Color Tools::getColor() {

	return this->color;
}

void Tools::setTool(Tool tool) {

	this->tool = tool;

	return;
}

Tool Tools::getTool() {

	return this->tool;
}

bool Tools::contains(float mx, float my) {

	if ((mx > x) && (mx < x + w) && (my < y) && (my > y - h)) {
		return true;
	}

	return false;
}

void Tools::display() {

	float fRED = 0.0;
	float fGREEN = 0.0;
	float fBLUE = 0.0;

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

	glColor3f(fRED, fGREEN, fBLUE);
	
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);

	glEnd();

	return;
}

