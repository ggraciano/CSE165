#ifndef TOOLS_H
#define TOOLS_H

enum Color {NONE, BLACK, WHITE, GRAY, LGRAY, RED, LRED, YELLOW, LYELLOW, GREEN, LGREEN, BLUE, LBLUE};

enum Tool {none, eraser, pencil, brush, blank};

class Tools {

private:

	float x;
	float y;
	float w;
	float h;

	bool write;

	Color color;
	Tool tool;

public:

	Tools();

	Tools(float x, float y, float w, float h, bool write, Color color, Tool tool);

	void setWrite(bool write);

	bool getWrite();

	void setColor(Color color);

	Color getColor();

	void setTool(Tool tool);

	Tool getTool();

	bool contains(float mx, float my);

	void display();
};

#endif /* Tools.h */

