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

	for (int i = 0; i < layout.size(); i++) {
		layout[i].display();
	}

	glPointSize(5);

	glBegin(GL_POINTS);

	for (int i = 0; i < coord.size(); i++) {
		glColor3f(coord[i].fRED, coord[i].fGREEN, coord[i].fBLUE);
		glVertex2f(coord[i].mx, coord[i].my);
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

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);

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
		for (int i = 0; i < layout.size() - 1; i++) {
			if (layout[i].getTool() == eraser && layout[i].contains(mx, my)) {
				std::cout << "eraser" << std::endl;
				tool = eraser;
				color = WHITE;
			} else if (layout[i].getTool() == pencil && layout[i].contains(mx, my)) {
				std::cout << "pencil" << std::endl;
				tool = pencil;
				color = BLACK;
				currColor();
			} else if (layout[i].getTool() == brush && layout[i].contains(mx, my)) {
				std::cout << "brush" << std::endl;
				tool = brush;
				color = BLACK;
				currColor();
			} else if (layout[i].getTool() == line && layout[i].contains(mx, my)) {
				std::cout << "line" << std::endl;
				tool = line;
				color = BLACK;
				currColor();
			} else if (layout[i].getColor() == BLACK && layout[i].contains(mx, my)) {
				std::cout << "BLACK" << std::endl;
				color = BLACK;
			} else if (layout[i].getColor() == WHITE && layout[i].contains(mx, my)) {
				std::cout << "WHITE" << std::endl;
				color = WHITE;
			} else if (layout[i].getColor() == GRAY && layout[i].contains(mx, my)) {
				std::cout << "GRAY" << std::endl;
				color = GRAY;
			} else if (layout[i].getColor() == LGRAY && layout[i].contains(mx, my)) {
				std::cout << "LGRAY" << std::endl;
				color = LGRAY;
			} else if (layout[i].getColor() == RED && layout[i].contains(mx, my)) {
				std::cout << "RED" << std::endl;
				color = RED;
			} else if (layout[i].getColor() == LRED && layout[i].contains(mx, my)) {
				std::cout << "LRED" << std::endl;
				color = LRED;
			} else if (layout[i].getColor() == YELLOW && layout[i].contains(mx, my)) {
				std::cout << "YELLOW" << std::endl;
				color = YELLOW;
			} else if (layout[i].getColor() == LYELLOW && layout[i].contains(mx, my)) {
				std::cout << "LYELLOW" << std::endl;
				color = LYELLOW;
			} else if (layout[i].getColor() == GREEN && layout[i].contains(mx, my)) {
				std::cout << "GREEN" << std::endl;
				color = GREEN;
			} else if (layout[i].getColor() == LGREEN && layout[i].contains(mx, my)) {
				std::cout << "LGREEN" << std::endl;
				color = LGREEN;
			} else if (layout[i].getColor() == BLUE && layout[i].contains(mx, my)) {
				std::cout << "BLUE" << std::endl;
				color = BLUE;
			} else if (layout[i].getColor() == LBLUE && layout[i].contains(mx, my)) {
				std::cout << "LBLUE" << std::endl;
				color = LBLUE;
			}

			currColor();
		}
	}

	std::cout << "x = " << mx << ", y = " << my << std::endl;

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

	for (int i = 0; i < layout.size(); i++) {
			if (layout[i].getWrite() && layout[i].contains(mx - 0.04, my + 0.04) && tool == eraser) {
				color = WHITE;
				currColor();
				coord.push_back(Position(mx, my, fRED, fGREEN, fBLUE));
				for (float i = 0.005; i <= 0.04; i += 0.005) {
					coord.push_back(Position(mx - i, my, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx - i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx, my + i, fRED, fGREEN, fBLUE));
				}
			} else if (layout[i].getWrite() && layout[i].contains(mx, my) && tool == pencil) {
				coord.push_back(Position(mx, my, fRED, fGREEN, fBLUE));
			} else if (layout[i].getWrite() && layout[i].contains(mx - 0.02, my + 0.02) && tool == brush) {
				coord.push_back(Position(mx, my, fRED, fGREEN, fBLUE));
				for (float i = 0.005; i <= 0.02; i += 0.005) {
					coord.push_back(Position(mx - i, my, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx - i, my + i, fRED, fGREEN, fBLUE));
					coord.push_back(Position(mx, my + i, fRED, fGREEN, fBLUE));
				}
			}
	}

	std::cout << "x = " << mx << ", y = " << my << std::endl;

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
	layout.push_back(Tools(-0.95, 0.95, 0.22, 0.22, false, false, NONE, eraser));
	layout.push_back(Tools(-0.71, 0.95, 0.22, 0.22, false, false, NONE, pencil));

	layout.push_back(Tools(-0.95, 0.71, 0.22, 0.22, false, false, NONE, brush));
	layout.push_back(Tools(-0.71, 0.71, 0.22, 0.22, false, false, NONE, line));

	// Colors
	layout.push_back(Tools(-0.95, 0.47, 0.22, 0.22, false, false, BLACK, none));
	layout.push_back(Tools(-0.71, 0.47, 0.22, 0.22, false, false, WHITE, none));

	layout.push_back(Tools(-0.95, 0.23, 0.22, 0.22, false, false, GRAY, none));
	layout.push_back(Tools(-0.71, 0.23, 0.22, 0.22, false, false, LGRAY, none));

	layout.push_back(Tools(-0.95, -0.01, 0.22, 0.22, false, false, RED, none));
	layout.push_back(Tools(-0.71, -0.01, 0.22, 0.22, false, false, LRED, none));

	layout.push_back(Tools(-0.95, -0.25, 0.22, 0.22, false, false, YELLOW, none));
	layout.push_back(Tools(-0.71, -0.25, 0.22, 0.22, false, false, LYELLOW, none));

	layout.push_back(Tools(-0.95, -0.49, 0.22, 0.22, false, false, GREEN, none));
	layout.push_back(Tools(-0.71, -0.49, 0.22, 0.22, false, false, LGREEN, none));

	layout.push_back(Tools(-0.95, -0.73, 0.22, 0.22, false, false, BLUE, none));
	layout.push_back(Tools(-0.71, -0.73, 0.22, 0.22, false, false, LBLUE, none));

	// Window
	layout.push_back(Tools(-0.44, 0.95, 1.39, 1.90, false, true, WHITE, none));

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

