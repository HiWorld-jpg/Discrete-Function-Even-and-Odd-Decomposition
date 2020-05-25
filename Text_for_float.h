#pragma once
#include<graphics.h>
class Text_for_float
{
private:
	int outputX;
	int outputY;
	int outputWidth;
	int outputHeight;
	int fontWidth;
	int fontHeight;
	COLORREF background_color;
	COLORREF font_color;
	float value;
public:
	void set_output_area(int outputX, int outputY, int output_Width, int output_Height);
	void set_font(int fontWidth, int fontHeight, COLORREF background_color, COLORREF font_color);
	void set_value(float value);
	Text_for_float();
	Text_for_float(int outputX, int outputY, int output_Width, int output_Height, int fontWidth, int fontHeight, COLORREF background_color, COLORREF font_color, float value);
	void output();
};

