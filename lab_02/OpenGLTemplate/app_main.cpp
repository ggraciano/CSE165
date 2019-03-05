#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// Width and height
int width = 640, height = 640;

// Current display
int mainWindow = 0;

int board[3][3];

bool player;

int draw;
int winner;

//-------------------------------------------------------
// A function to initiate the board
//-------------------------------------------------------
void appInitBoard() {

	player = false;

	draw = 0;
	winner = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}

	return;
}

//-------------------------------------------------------
// A function to check if there is a draw
//-------------------------------------------------------
bool drawCheck() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				return false;
			}
		}
	}

	draw = 1;

	return true;
}

//-------------------------------------------------------
// A function to check the win state
//-------------------------------------------------------
bool winCheck() {

	// Check the horizontal win condition
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			if (board[i][0] != 0 && board[i][0] == board[i][j]) {
				if (j == 2) {
					winner = board[i][0];
					return true;
				}
			} else {
				break;
			}
		}
	}

	// Check the vertical win condition
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			if (board[0][i] != 0 && board[0][i] == board[j][i]) {
				if (j == 2) {
					winner = board[0][i];
					return true;
				}
			} else {
				break;
			}
		}
	}

	// Check the diagonal win conditions
	for (int i = 1; i < 3; i++) {
		if (board[0][0] != 0 && board[0][0] == board[i][i]) {
			if (i == 2) {
				winner = board[0][0];
				return true;
			}
		} else {
			break;
		}
	}

	for (int i = 1; i < 3; i++) {
		if (board[2][0] != 0 && board[2][0] == board[2-i][i]) {
			if (i == 2) {
				winner = board[2][0];
				return true;
			}
		} else {
			break;
		}
	}

	return false;
}

//-------------------------------------------------------
// A function that controls the computer
//-------------------------------------------------------
void computerPick() {

	int rowPick;
	int colPick;

	if (!winCheck() && !drawCheck()) {
		do {
			rowPick = rand() % 3;
			colPick = rand() % 3;
		} while (board[rowPick][colPick] != 0);

		board[rowPick][colPick] = 2;
	}

	return;
}

//-------------------------------------------------------
// A function to initiate the window
//-------------------------------------------------------
void appInitWindow(float xOffset, float yOffset) {

// ------------------------- TIC -------------------------

	// ----- T: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.90; i < -0.60; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.80);
	}

	glEnd();

	// ----- T: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.80; i < -0.70; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- I: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.55; i < -0.45; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- C: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.40; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.80);
	}

	glEnd();

	// ----- C: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.40; i < -0.30; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- C: Bottom Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.40; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.70);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- -: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.15; i < 0.05; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.80);
		glVertex2f(xOffset + i, yOffset + 0.70);
	}

	glEnd();

// ------------------------- TAC -------------------------

	// ----- T: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.10; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.80);
	}

	glEnd();

	// ----- T: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.20; i < 0.30; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- A: Left Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.54; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- A: Right Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.56; i < 0.65; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- A: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.65; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.85);
	}

	glEnd();

	// ----- A: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.65; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.80);
		glVertex2f(xOffset + i, yOffset + 0.70);
	}

	glEnd();

	// ----- C: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.70; i < 0.90; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.80);
	}

	glEnd();

	// ----- C: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.70; i < 0.80; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.90);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

	// ----- C: Bottom Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.70; i < 0.90; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.70);
		glVertex2f(xOffset + i, yOffset + 0.60);
	}

	glEnd();

//------------------------- TOE -------------------------

	// ----- T: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.40; i < -0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.40);
	}

	glEnd();

	// ----- T: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

	// ----- O: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.05; i < 0.15; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.40);
	}

	glEnd();

	// ----- O: Left Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.05; i < 0.04; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

	// ----- O: Right Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.06; i < 0.15; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

	// ----- O: Bottom Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.05; i < 0.15; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.30);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

	// ----- E: Left Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.20; i < 0.30; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

	// ----- E: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.20; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.50);
		glVertex2f(xOffset + i, yOffset + 0.41);
	}

	glEnd();

	// ----- E: Middle Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.20; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.39);
		glVertex2f(xOffset + i, yOffset + 0.31);
	}

	glEnd();

	// ----- E: Bottom Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = 0.20; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.29);
		glVertex2f(xOffset + i, yOffset + 0.20);
	}

	glEnd();

// ------------------------- Rectangles -------------------------

	// ----- Top -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.60; i < 0.60; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.10);
		glVertex2f(xOffset + i, yOffset - 0.40);
	}

	glEnd();

	// ----- Bottom -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.60; i < 0.60; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.50);
		glVertex2f(xOffset + i, yOffset - 0.80);
	}

	glEnd();

// ------------------------- 1 - Player -------------------------

	// ----- 1: Tail -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex2f(xOffset - 0.55, yOffset - 0.20);
	glVertex2f(xOffset - 0.50, yOffset - 0.15);
	glVertex2f(xOffset - 0.50, yOffset - 0.20);

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex2f(xOffset - 0.55, yOffset - 0.20);
	glVertex2f(xOffset - 0.55, yOffset - 0.25);
	glVertex2f(xOffset - 0.50, yOffset - 0.20);

	glEnd();

	// ----- 1: Middle Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.50; i < -0.45; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- 1: Bottom Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.55; i < -0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.30);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- -: Middle Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.375; i < -0.325; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.20);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- P: Left Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- P: Right Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.245; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- P: Top Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- P: Bottom Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- L: Left Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.15; i < -0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- L: Bottom Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.15; i < -0.05; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.30);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.0475; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.0525; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- A: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.15; i < 0.1975; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.2025; i < 0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Lower Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.15; i < 0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.1750; i < 0.2250; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- E: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.35; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- E: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.2175);
	}

	glEnd();

	// ----- E: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2225);
		glVertex2f(xOffset + i, yOffset - 0.2775);
	}

	glEnd();

	// ----- E: Bottom Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2825);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- R: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.4975; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- R: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.5025; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- R: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- R: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- R: Tail -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2550);
		glVertex2f(xOffset + i, yOffset - 0.30);
	}

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.5025; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2550);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

// ------------------------- 2 - Player -------------------------

	// ----- 2: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.55; i < -0.50; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.55);
		glVertex2f(xOffset + i, yOffset - 0.6250);
	}

	glEnd();

	// ----- 2: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.55; i < -0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.55);
		glVertex2f(xOffset + i, yOffset - 0.60);
	}

	glEnd();

	// ----- 2: Slant Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex2f(xOffset - 0.45, yOffset - 0.60);
	glVertex2f(xOffset - 0.55, yOffset - 0.70);
	glVertex2f(xOffset - 0.4750, yOffset - 0.70);

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex2f(xOffset - 0.45, yOffset - 0.60);
	glVertex2f(xOffset - 0.40, yOffset - 0.6250);
	glVertex2f(xOffset - 0.4750, yOffset - 0.70);

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.45; i < -0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.55);
		glVertex2f(xOffset + i, yOffset - 0.6250);
	}

	glEnd();

	// ----- 2: Bottom Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.55; i < -0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.70);
		glVertex2f(xOffset + i, yOffset - 0.75);
	}

	glEnd();

	yOffset = -0.40;

	// ----- -: Middle Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.375; i < -0.325; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.20);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- P: Left Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- P: Right Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.245; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- P: Top Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- P: Bottom Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.30; i < -0.20; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- L: Left Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.15; i < -0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- L: Bottom Bar -----	
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = -0.15; i < -0.05; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.30);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.0475; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.0525; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- A: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- A: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.00; i < 0.10; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.15; i < 0.1975; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.2025; i < 0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Lower Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.15; i < 0.25; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- Y: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.1750; i < 0.2250; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- E: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.35; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- E: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.2175);
	}

	glEnd();

	// ----- E: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2225);
		glVertex2f(xOffset + i, yOffset - 0.2775);
	}

	glEnd();

	// ----- E: Bottom Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.30; i < 0.40; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2825);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- R: Left Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.4975; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	// ----- R: Right Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.5025; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- R: Top Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.15);
		glVertex2f(xOffset + i, yOffset - 0.1975);
	}

	glEnd();

	// ----- R: Middle Bar -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2025);
		glVertex2f(xOffset + i, yOffset - 0.25);
	}

	glEnd();

	// ----- R: Tail -----
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.45; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2550);
		glVertex2f(xOffset + i, yOffset - 0.30);
	}

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	for (float i = 0.5025; i < 0.55; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.2550);
		glVertex2f(xOffset + i, yOffset - 0.35);
	}

	glEnd();

	yOffset = 0.0;

	return;
}


void appLines(float xOffset, float yOffset) {

	// ----- #: Left Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.70; i < 0.70; i += 0.0001) {
		glVertex2f(xOffset - 0.20, yOffset + i);
		glVertex2f(xOffset - 0.30, yOffset + i);
	}

	glEnd();

	// ----- #: Right Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.70; i < 0.70; i += 0.0001) {
		glVertex2f(xOffset + 0.20, yOffset + i);
		glVertex2f(xOffset + 0.30, yOffset + i);
	}

	glEnd();

	// ----- #: Bottom Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.70; i < 0.70; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset - 0.20);
		glVertex2f(xOffset + i, yOffset - 0.30);
	}

	glEnd();

	// ----- #: Top Bar -----
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	for (float i = -0.70; i < 0.70; i += 0.0001) {
		glVertex2f(xOffset + i, yOffset + 0.20);
		glVertex2f(xOffset + i, yOffset + 0.30);
	}

	glEnd();

	return;
}

//-------------------------------------------------------
// A function to play against another opponent
//-------------------------------------------------------
void appTurn() {

	for (int i = 0; i < 3; i++) {
		float yOffset = 0.50 - (i*0.50);

		for (int j = 0; j < 3; j++) {
			float xOffset = -0.50 + (j*0.50);

			if (board[i][j] == 1) {

				// ----- X -----
				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15, yOffset + 0.10);
				glVertex2f(xOffset + -0.10, yOffset + 0.15);
				glVertex2f(xOffset + 0.10, yOffset + -0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.10, yOffset + 0.15);
				glVertex2f(xOffset + 0.10, yOffset + -0.15);
				glVertex2f(xOffset + 0.15, yOffset + -0.10);

				glEnd();

				// ----------------------------------------

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15, yOffset + -0.10);
				glVertex2f(xOffset + -0.10, yOffset + -0.15);
				glVertex2f(xOffset + 0.10, yOffset + 0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.10, yOffset + -0.15);
				glVertex2f(xOffset + 0.10, yOffset + 0.15);
				glVertex2f(xOffset + 0.15, yOffset + 0.10);

				glEnd();
			}

			if (board[i][j] == 2) {

				// ----- O -----
				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15, yOffset + 0.15);
				glVertex2f(xOffset + -0.15 + (0.05*sqrt(2)), yOffset + 0.15);
				glVertex2f(xOffset + -0.15, yOffset + -0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15 + (0.05*sqrt(2)), yOffset + 0.15);
				glVertex2f(xOffset + -0.15, yOffset + -0.15);
				glVertex2f(xOffset + -0.15 + (0.05*sqrt(2)), yOffset + -0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + 0.15 - (0.05*sqrt(2)), yOffset + 0.15);
				glVertex2f(xOffset + 0.15, yOffset + 0.15);
				glVertex2f(xOffset + 0.15 - (0.05*sqrt(2)), yOffset + -0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + 0.15, yOffset + 0.15);
				glVertex2f(xOffset + 0.15 - (0.05*sqrt(2)), yOffset + -0.15);
				glVertex2f(xOffset + 0.15, yOffset + -0.15);

				glEnd();

				// ----------------------------------------

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15, yOffset + 0.15);
				glVertex2f(xOffset + 0.15, yOffset + 0.15);
				glVertex2f(xOffset + -0.15, yOffset + 0.15 - (0.05*sqrt(2)));

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + 0.15, yOffset + 0.15);
				glVertex2f(xOffset + -0.15, yOffset + 0.15 - (0.05*sqrt(2)));
				glVertex2f(xOffset + 0.15, yOffset + 0.15 - (0.05*sqrt(2)));

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + -0.15, yOffset + -0.15 + (0.05*sqrt(2)));
				glVertex2f(xOffset + 0.15, yOffset + -0.15 + (0.05*sqrt(2)));
				glVertex2f(xOffset + -0.15, yOffset + -0.15);

				glEnd();

				glColor3f(1.0, 0.0, 0.0);

				glBegin(GL_POLYGON);

				glVertex2f(xOffset + 0.15, yOffset + -0.15 + (0.05*sqrt(2)));
				glVertex2f(xOffset + -0.15, yOffset + -0.15);
				glVertex2f(xOffset + 0.15, yOffset + -0.15);

				glEnd();
			}
		}
	}

	return;
}

//-------------------------------------------------------
// A function to draw the result
//-------------------------------------------------------
void appResult(void *font, const char *str, float xOffset, float yOffset) {

	glColor3f(1.0, 1.0, 1.0);

	glRasterPos2f(xOffset, yOffset);

	for (int i = 0; str[i] != '\0'; i++) {
		glutBitmapCharacter(font, str[i]);
	}

	return;
}

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float xOffset = 0.0;
	float yOffset = 0.0;

	if (draw != 0) {
		appResult(GLUT_BITMAP_HELVETICA_18, "Draw!", xOffset - 0.075, yOffset);
		appResult(GLUT_BITMAP_HELVETICA_12, "Play Again? (y/n)", xOffset - 0.155, yOffset - 0.70);
	} else if (winner != 0) {
		if (winner == 1) {
			appResult(GLUT_BITMAP_HELVETICA_18, "Player 1 Wins!", xOffset - 0.175, yOffset);
		} else {
			appResult(GLUT_BITMAP_HELVETICA_18, "Player 2 Wins!", xOffset - 0.175, yOffset);
		}
		appResult(GLUT_BITMAP_HELVETICA_12, "Play Again? (y/n)", xOffset - 0.155, yOffset - 0.70);
	} else if (mainWindow == 0) {
		appInitWindow(xOffset, yOffset);
		appResult(GLUT_BITMAP_HELVETICA_12, "Press ESC to Cancel", xOffset - 0.1895, yOffset - 0.90);
	} else if (player == false) {
		if (drawCheck() || winCheck()) {
			appResult(GLUT_BITMAP_HELVETICA_12, "Game Over! (click anywhere to continue)", xOffset - 0.36, yOffset - 0.90);
		} else {
			appResult(GLUT_BITMAP_HELVETICA_12, "Player 1's Turn", -0.135, -0.85);
		}
		appLines(xOffset, yOffset);
		appTurn();
	} else {
		if (drawCheck() || winCheck()) {
			appResult(GLUT_BITMAP_HELVETICA_12, "Game Over! (click anywhere to continue)", xOffset - 0.36, yOffset - 0.90);
		} else {
			appResult(GLUT_BITMAP_HELVETICA_12, "Player 2's Turn", -0.135, -0.85);
		}
		appLines(xOffset, yOffset);
		appTurn();
	}

	glFlush();
	glutSwapBuffers();

	return;
}

//-------------------------------------------------------
// A function to resize the window
//	w, h- the size of the window
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
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s    - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {

	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	if (mainWindow == 0) {
		if (b == 0 && s == 1 && (mx > -0.60 && mx < 0.60) && (my > -0.40 && my < -0.10)) {
			mainWindow = 1;
			player = false;
		}

		if (b == 0 && s == 1 && (mx > -0.60 && mx < 0.60) && (my > -0.80 && my < -0.50)) {
			mainWindow = 2;
			player = false;
		}
	} else {
		if (!drawCheck() && !winCheck()) {
			if (player == false) {

				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > 0.30 && my < 0.70)) {
					if (board[0][0] != 2 && board[0][0] != 1) {
						board[0][0] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > 0.30 && my < 0.70)) {
					if (board[0][1] != 2 && board[0][1] != 1) {
						board[0][1] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > 0.30 && my < 0.70)) {
					if (board[0][2] != 2 && board[0][2] != 1) {
						board[0][2] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > -0.20 && my < 0.20)) {
					if (board[1][0] != 2 && board[1][0] != 1) {
						board[1][0] = 1;
						player = true;
						}
					}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > -0.20 && my < 0.20)) {
					if (board[1][1] != 2 && board[1][1] != 1) {
						board[1][1] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > -0.20 && my < 0.20)) {
					if (board[1][2] = 2 && board[1][2] != 1) {
						board[1][2] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > -0.70 && my < -0.30)) {
					if (board[2][0] != 2 && board[2][0] != 1) {
						board[2][0] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > -0.70 && my < -0.30)) {
					if (board[2][1] != 2 && board[2][1] != 1) {
						board[2][1] = 1;
						player = true;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > -0.70 && my < -0.30)) {
					if (board[2][2] != 2 && board[2][2] != 1) {
						board[2][2] = 1;
						player = true;
					}
				}
			}

			if (player == true && mainWindow == 1) {
					computerPick();
					player = false;
			} else if (player == true && mainWindow == 2) {
				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > 0.30 && my < 0.70)) {
					if (board[0][0] != 1 && board[0][0] != 2) {
						board[0][0] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > 0.30 && my < 0.70)) {
					if (board[0][1] != 1 && board[0][1] != 2) {
						board[0][1] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > 0.30 && my < 0.70)) {
					if (board[0][2] != 1 && board[0][2] != 2) {
						board[0][2] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > -0.20 && my < 0.20)) {
					if (board[1][0] != 1 && board[1][0] != 2) {
						board[1][0] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > -0.20 && my < 0.20)) {
					if (board[1][1] != 1 && board[1][1] != 2) {
						board[1][1] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > -0.20 && my < 0.20)) {
					if (board[1][2] = 1 && board[1][2] != 2) {
						board[1][2] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.70 && mx < -0.30) && (my > -0.70 && my < -0.30)) {
					if (board[2][0] != 1 && board[2][0] != 2) {
						board[2][0] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > -0.20 && mx < 0.20) && (my > -0.70 && my < -0.30)) {
					if (board[2][1] != 1 && board[2][1] != 2) {
						board[2][1] = 2;
						player = false;
					}
				}

				if (b == 0 && s == 1 && (mx > 0.30 && mx < 0.70) && (my > -0.70 && my < -0.30)) {
					if (board[2][2] != 1 && board[2][2] != 2) {
						board[2][2] = 2;
						player = false;
					}
				}
			}
		}
	}

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
		case 'y':
			if (draw != 0 || winner != 0) {
				appInitBoard();
			}
			break;
		case 'n':
			if (draw != 0 || winner != 0) {
				appInitBoard();
				mainWindow = 0;
			}
			break;
		default:
			break;
	}

	glutPostRedisplay();

	return;
}

void idle() {

	return;
}

int main(int argc, char** argv) {

	appInitBoard();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGl Demo");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	// Set callback to display the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle keyboard events
	glutKeyboardFunc(appKeyboardFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}

