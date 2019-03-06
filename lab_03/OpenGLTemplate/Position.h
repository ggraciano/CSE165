#ifndef POSITION_H
#define POSITION_H

class Position {

private:

	float mx;
	float my;

	float fRED;
	float fGREEN;
	float fBLUE;

public:
	Position();

	Position(float mx, float my, float fRED, float fGREEN, float fBLUE);

	void setMx(float mx);

	float getMx();

	void setMy(float my);

	float getMy();

	void setFRED(float fRED);

	float getFRED();

	void setFGREEN(float fGREEN);

	float getFGREEN();

	void setFBLUE(float fBLUE);

	float getFBLUE();
};

#endif /* Position.h */

