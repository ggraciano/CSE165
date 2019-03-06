#include <iostream>
#include <cmath>
#include <vector>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Tools.h"
#include "Position.h"

// Store the width and height of the window
int width = 640, height = 640;

float fRED = 0.0;
float fGREEN = 0.0;
float fBLUE = 0.0;

Tool tool = none;
Color color = NONE;

std::vector<Position> coord;
std::vector<Tools> layout;

void currColor() {

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

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {

	// Set background color to black
	glClearColor(0.2, 0.4, 0.6, 1.0);

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end(); ++it) {
		it->display();
	}

	glPointSize(5);

	glBegin(GL_POINTS);

	for (std::vector<Position>::iterator it = coord.begin(); it != coord.end(); ++it) {
		glColor3f(it->getFRED(), it->getFGREEN(), it->getFBLUE());
		glVertex2f(it->getMx(), it->getMy());
	}

	glEnd();

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();

	return;
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {

	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));

	return;
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s    - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {

	// Window size has changed
	width = w;
	height = h;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, width, height);

	// Now we use glOrtho to set up our viewing frustum
	glOrtho(0, width, 0, height, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	return;
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s    - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {

	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	if (b == 0 && s == 0) {
	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end() - 1; ++it) {
			if (it->getTool() == eraser && it->contains(mx, my)) {
				tool = eraser;
				color = WHITE;
				currColor();
			} else if (it->getTool() == pencil && it->contains(mx, my)) {
				tool = pencil;
				color = BLACK;
				currColor();
			} else if (it->getTool() == brush && it->contains(mx, my)) {
				tool = brush;
				color = BLACK;
				currColor();
			} else if (it->getTool() == blank && it->contains(mx, my)) {
				tool = blank;
				color = BLACK;
				currColor();
			} else if (it->getColor() == BLACK && it->contains(mx, my)) {
				color = BLACK;
			} else if (it->getColor() == WHITE && it->contains(mx, my)) {
				color = WHITE;
			} else if (it->getColor() == GRAY && it->contains(mx, my)) {
				color = GRAY;
			} else if (it->getColor() == LGRAY && it->contains(mx, my)) {
				color = LGRAY;
			} else if (it->getColor() == RED && it->contains(mx, my)) {
				color = RED;
			} else if (it->getColor() == LRED && it->contains(mx, my)) {
				color = LRED;
			} else if (it->getColor() == YELLOW && it->contains(mx, my)) {
				color = YELLOW;
			} else if (it->getColor() == LYELLOW && it->contains(mx, my)) {
				color = LYELLOW;
			} else if (it->getColor() == GREEN && it->contains(mx, my)) {
				color = GREEN;
			} else if (it->getColor() == LGREEN && it->contains(mx, my)) {
				color = LGREEN;
			} else if (it->getColor() == BLUE && it->contains(mx, my)) {
				color = BLUE;
			} else if (it->getColor() == LBLUE && it->contains(mx, my)) {
				color = LBLUE;
			}

			currColor();
		}
	}

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();

	return;
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {

	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	for (std::vector<Tools>::iterator it = layout.begin(); it != layout.end(); ++it) {
			if (it->getWrite() && it->contains(mx + 0.025, my + 0.025) && it->contains(mx - 0.025, my - 0.025) && tool == eraser) {
				color = WHITE;
				currColor();
				for (float i = 0.001; i <= 0.02; i += 0.001) {
					coord.push_back(Position(mx - i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx + i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx - i, my - i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx + i, my - i, fRED, fGREEN, fBLUE));
				}
			} else if (it->getWrite() && it->contains(mx, my) && tool == pencil) {
				coord.push_back(Position(mx, my, fRED, fGREEN, fBLUE));
			} else if (it->getWrite() && it->contains(mx + 0.015, my + 0.015) && it->contains(mx - 0.015, my - 0.015) && tool == brush) {
				for (float i = 0.001; i <= 0.01; i += 0.001) {
					coord.push_back(Position(mx - i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx + i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx - i, my - i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx + i, my - i, fRED, fGREEN, fBLUE));
				}
			}
	}

	// Again, we redraw the scene
	glutPostRedisplay();

	return;
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments:
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	
	switch (key) {
		case 27:
			exit(0);
			break;
		default:
			break;
	}

	// After all the state changes, redraw the scene
	glutPostRedisplay();

	return;
}

void idle() {

	return;
}


int main(int argc, char** argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	// Tools
	layout.push_back(Tools(-0.95, 0.95, 0.22, 0.22, false, NONE, eraser));
	layout.push_back(Tools(-0.71, 0.95, 0.22, 0.22, false, NONE, pencil));

	layout.push_back(Tools(-0.95, 0.71, 0.22, 0.22, false, NONE, brush));
	layout.push_back(Tools(-0.71, 0.71, 0.22, 0.22, false, NONE, blank));

	// Colors
	layout.push_back(Tools(-0.95, 0.47, 0.22, 0.22, false, BLACK, none));
	layout.push_back(Tools(-0.71, 0.47, 0.22, 0.22, false, WHITE, none));

	layout.push_back(Tools(-0.95, 0.23, 0.22, 0.22, false, GRAY, none));
	layout.push_back(Tools(-0.71, 0.23, 0.22, 0.22, false, LGRAY, none));

	layout.push_back(Tools(-0.95, -0.01, 0.22, 0.22, false, RED, none));
	layout.push_back(Tools(-0.71, -0.01, 0.22, 0.22, false, LRED, none));

	layout.push_back(Tools(-0.95, -0.25, 0.22, 0.22, false, YELLOW, none));
	layout.push_back(Tools(-0.71, -0.25, 0.22, 0.22, false, LYELLOW, none));

	layout.push_back(Tools(-0.95, -0.49, 0.22, 0.22, false, GREEN, none));
	layout.push_back(Tools(-0.71, -0.49, 0.22, 0.22, false, LGREEN, none));

	layout.push_back(Tools(-0.95, -0.73, 0.22, 0.22, false, BLUE, none));
	layout.push_back(Tools(-0.71, -0.73, 0.22, 0.22, false, LBLUE, none));

	// Window
	layout.push_back(Tools(-0.44, 0.95, 1.39, 1.90, true, WHITE, none));

	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);

	glutIdleFunc(idle);

	// Start the main loop
	glutMainLoop();

	return 0;
}

