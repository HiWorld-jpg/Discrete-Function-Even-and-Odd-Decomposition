#pragma once
#include<graphics.h>
class Button
{
private:
	int x;
	int y;
	int width;
	int height;
	char text[7];
	int index;
public:
	void setPosition(int x, int y);
	void setShape(int width, int height);
	void setIndex(int index);
	Button();
	Button(int x, int y, int width, int height, int index);
	bool checkMouseIn(int mouseX, int mouseY);
	int getIndex();
	void setText(char c1, char c2, char c3, char c4, char c5, char c6);
	void drawText();
	void drawButtonUp();
	void drawButtonDown();
};

