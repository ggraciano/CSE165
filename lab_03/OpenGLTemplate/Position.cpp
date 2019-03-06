#include "Position.h"

Position::Position() {

	mx = 0.0;
	my = 0.0;

	fRED = 0.0;
	fGREEN = 0.0;
	fBLUE = 0.0;
}

Position::Position(float mx, float my, float fRED, float fGREEN, float fBLUE) {

	this->mx = mx;
	this->my = my;

	this->fRED = fRED;
	this->fGREEN = fGREEN;
	this->fBLUE = fBLUE;
}

void Position::setMx(float mx) {

	this->mx = mx;

	return;
}

float Position::getMx() {

	return this->mx;
}

void Position::setMy(float my) {

	this->my = my;

	return;
}

float Position::getMy() {

	return this->my;
}

void Position::setFRED(float fRED) {

	this->fRED = fRED;

	return;
}

float Position::getFRED() {

	return this->fRED;
}

void Position::setFGREEN(float fGREEN) {

	this->fGREEN = fGREEN;

	return;
}

float Position::getFGREEN() {

	return this->fGREEN;
}

void Position::setFBLUE(float fBLUE) {

	this->fBLUE = fBLUE;

	return;
}

float Position::getFBLUE() {

	return this->fBLUE;
}

