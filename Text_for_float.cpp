#include "Text_for_float.h"
#include<stdio.h>
void Text_for_float::set_output_area(int outputX, int outputY, int output_Width, int output_Height)
{
	this->outputX = outputX;
	this->outputY = outputY;
	this->outputWidth = output_Width;
	this->outputHeight = output_Height;
}

void Text_for_float::set_font(int fontWidth, int fontHeight, COLORREF background_color, COLORREF font_color)
{
	this->fontWidth = fontWidth;
	this->fontHeight = fontHeight;
	this->background_color = background_color;
	this->font_color = font_color;
}

void Text_for_float::set_value(float value)
{
	this->value = value;
}

Text_for_float::Text_for_float()
{
}

Text_for_float::Text_for_float(int outputX, int outputY, int output_Width, int output_Height, int fontWidth, int fontHeight, COLORREF background_color, COLORREF font_color, float value)
{
	set_output_area(outputX, outputY, output_Width, output_Height);
	set_font(fontWidth, fontHeight, background_color, font_color);
	set_value(value);
}

void Text_for_float::output()
{
	setfillcolor(background_color);
	solidrectangle(outputX, outputY, outputX + outputWidth, outputY + outputHeight);
	settextstyle(fontHeight, fontWidth, _T("ËÎÌו"));
	char s[10];
	sprintf_s(s, "%.f", value);
	settextcolor(font_color);
	outtextxy(outputX, outputY, s);
}
