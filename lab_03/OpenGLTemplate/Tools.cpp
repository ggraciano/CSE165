#include "Tools.h"
#include <GL/freeglut.h>
#include "SOIL.h"

Tools::Tools() {

	x = -0.5;
	y = 0.5;
	w = 0.5;
	h = 0.5;

	write = false;

	color = NONE;
	tool = none;

	texture_id = 0;
}

Tools::Tools(float x, float y, float w, float h, bool write, Color color, Tool tool) {

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->write = write;

	this->color = color;
	this->tool = tool;

	texture_id = SOIL_load_OGL_texture (
		"mspaint4lyfe.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
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

	float rows = 6.0;
	float cols = 8.0;

	float currRow = 0.0;
	float currCol = 0.0;

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

	glBindTexture(GL_TEXTURE, texture_id);

	if (tool != none) {
		if (tool == eraser) {
			currRow = 3.0;
			currCol = 2.0;
		} else if (tool == pencil) {
			currRow = 1.0;
			currCol = 2.0;
		} else if (tool == brush) {
			currRow = 1.0;
			currCol = 3.0;
		} else if (tool == clear) {
			currRow = 0.0;
			currCol = 0.0;
		}

		glColor3f(1.0, 1.0, 1.0);

		glEnable(GL_TEXTURE_2D);

		glBegin(GL_POLYGON);

		glTexCoord2f(currCol/cols, (currRow + 1)/rows);
		glVertex2f(x, y);
		glTexCoord2f((currCol + 1)/cols, (currRow + 1)/rows);
		glVertex2f(x + w, y);
		glTexCoord2f((currCol + 1)/cols, currRow/rows);
		glVertex2f(x + w, y - h);
		glTexCoord2f(currCol/cols, currRow/rows);
		glVertex2f(x, y - h);

		glEnd();

		glDisable(GL_TEXTURE_2D);

		if (tool == clear) {
			const char *str = "Clear";

			glColor3f(fRED, fGREEN, fBLUE);

			glRasterPos2f(x + 0.045, y - 0.135);

			for (int i = 0; str[i] != '\0'; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
			}
		}
	} else {
		glColor3f(fRED, fGREEN, fBLUE);

		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);

		glEnd();
	}

	return;
}

