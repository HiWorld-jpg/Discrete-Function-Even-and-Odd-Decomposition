#include "tools.h"

void initialLayout()
{
	setfillcolor(WHITE);
	solidrectangle(0, 0, 1200, 410);


	int i, j;
	int area;
	setlinecolor(LIGHTGRAY);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 1);
	for (area = 0;area < 3;area++)
	{
		for (i = 0;i < 20;i++)
		{
			line(i * 20 + area * 400, 0, i * 20 + area * 400, 400);
			line(0 + area * 400, i * 20, 400 + area * 400, i * 20);
		}
	}
	initialAxis();
}

void initialAxis()
{
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	setlinecolor(BLUE);
	line(400, 0, 400, 400);
	line(800, 0, 800, 400);
	line(0, 400, 1200, 400);

	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3);
	setlinecolor(BLACK);
	line(0, 200, 400, 200);
	line(200, 0, 200, 400);
	line(0 + 400, 200, 400 + 400, 200);
	line(200 + 400, 0, 200 + 400, 400);
	line(0 + 800, 200, 400 + 800, 200);
	line(200 + 800, 0, 200 + 800, 400);

}

void drawArray(int originX, int originY, float array[], bool lineOrNot)
{
	int i;
	if (originX == 200)
	{
		setfillcolor(BLACK);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
		setlinecolor(BLACK);
	}
	else if (originX == 600)
	{
		setfillcolor(RED);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
		setlinecolor(RED);
	}
	else
	{
		setfillcolor(GREEN);
		setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
		setlinecolor(GREEN);
	}
	for (i = 0;i < 21;i++)
	{
		solidcircle(originX + (i - 10) * 20, originY - array[i] * 20, 5);
	}
	if (lineOrNot == true)
	{
		for (i = 0;i < 20;i++)
		{
			line(originX + (i - 10) * 20, originY - array[i] * 20, originX + (i + 1 - 10) * 20, originY - array[i + 1] * 20);
		}
	}
}

void calEvenArray(float valueArray[], float evenArray[])
{
	int i;
	for (i = 0;i < 21;i++)
	{
		evenArray[i] = (valueArray[i] + valueArray[20 - i]) / 2;
	}
}

void calOddArray(float valueArray[], float oddArray[])
{
	int i;
	for (i = 0;i < 21;i++)
	{
		oddArray[i] = (valueArray[i] - valueArray[20 - i]) / 2;
	}
}
