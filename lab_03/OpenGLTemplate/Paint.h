#ifndef PAINT_H
#define PAINT_H

#include <vector>
#include "Tools.h"
#include "Position.h"

class Paint {
	private:
		float fRED;
		float fGREEN;
		float fBLUE;

		std::vector<Tools*> layout;
		std::vector<Position*> coord;

		Tool tool;
		Color color;

	public:
		Paint();

		~Paint();

		void currColor();

		void motion(float mx, float my);

		void handle(int b, int s, float mx, float my);

		void draw();
};

#endif /* Paint.h */

