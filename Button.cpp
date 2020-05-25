#include "Button.h"

void Button::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Button::setShape(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Button::setIndex(int index)
{
	this->index = index;
}

Button::Button()
{
}

Button::Button(int x, int y, int width, int height, int index)
{
	setPosition(x, y);
	setShape(width, height);
	setIndex(index);
}

bool Button::checkMouseIn(int mouseX, int mouseY)
{
	if (mouseX > x&& mouseX<x + width && mouseY>y&& mouseY < y + height)
		return true;
	return false;
}

int Button::getIndex()
{
	return index;
}

void Button::setText(char c1, char c2, char c3, char c4, char c5, char c6)
{
	text[0] = c1;
	text[1] = c2;
	text[2] = c3;
	text[3] = c4;
	text[4] = c5;
	text[5] = c6;
	text[6] = '\0';
	drawText();
}

void Button::drawText()
{
	setfillcolor(getbkcolor());
	solidrectangle(x + 3, y + 3, x + width - 6, y + height - 6);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(height / 5 * 3, width / 6, _T("ËÎÌו"));
	outtextxy(x , y + height / 5, text);
}

void Button::drawButtonUp()
{
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
	setlinecolor(LIGHTGRAY);
	//setlinecolor(WHITE);
	line(x, y, x + width, y);
	line(x, y, x, y + height);
	setlinecolor(BLACK);
	line(x, y + height, x + width, y + height);
	line(x + width, y, x + width, y + height);
}

void Button::drawButtonDown()
{
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
	setlinecolor(BLACK);
	line(x, y, x + width, y);
	line(x, y, x, y + height);
	setlinecolor(LIGHTGRAY);
	//setlinecolor(WHITE);
	line(x, y + height, x + width, y + height);
	line(x + width, y, x + width, y + height);
}
