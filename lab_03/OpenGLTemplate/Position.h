#ifndef POSITION_H
#define POSITION_H

struct Position {
	float mx;
	float my;

	float fRED;
	float fGREEN;
	float fBLUE;

	Position() {
		mx = 0.0;
		my = 0.0;

		fRED = 0.0;
		fGREEN = 0.0;
		fBLUE = 0.0;
	}

	Position(float mx, float my, float fRED, float fGREEN, float fBLUE) {
		this->mx = mx;
		this->my = my;

		this->fRED = fRED;
		this->fGREEN = fGREEN;
		this->fBLUE = fBLUE;
	}
};

#endif /* Position.h */

