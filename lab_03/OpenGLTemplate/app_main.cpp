#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "Paint.h"

// Store the width and height of the window
int width = 640, height = 640;

Paint *paint;

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

	paint->draw();

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

	paint->handle(b, s, mx, my);

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

	paint->motion(mx, my);

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
			delete paint;
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

	paint = new Paint();

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

