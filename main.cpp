#include<graphics.h>
#include"tools.h"
#include"Button.h"
#include"Text_for_float.h"

int main()
{
	int bkWidth = 1200;
	int bkHeight = 500;
	initgraph(bkWidth, bkHeight);
	setbkcolor(WHITE);
	cleardevice();
	MOUSEMSG msg;
	msg = GetMouseMsg();

	initialLayout();

	Button clearButton = Button(20, 420, 60, 40, 0);
	clearButton.setText('c', 'l', 'e', 'a', 'r', ' ');
	clearButton.drawButtonUp();

	Button calculateButton = Button(100, 420, 60, 40, 1);
	calculateButton.setText(' ', 'c', 'a', 'l', ' ', ' ');
	calculateButton.drawButtonUp();

	bool mouseClickFlag1 = false;
	bool mouseClickFlag2 = false;
	int buttonSleepTime = 60;

	int chooseX, chooseY;
	int chooseXpre=0, chooseYpre=0;

	Text_for_float coorXtext = Text_for_float(200, 420, 30, 20, 10, 20, WHITE, BLACK, 0);
	coorXtext.output();
	Text_for_float coorYtext = Text_for_float(240, 420, 30, 20, 10, 20, WHITE, BLACK, 0);
	coorYtext.output();
	outtextxy(180, 420, '(');
	outtextxy(230, 420, ',');
	outtextxy(270, 420, ')');

	float valueArray[21];
	float evenArray[21];
	float oddArray[21];
	int i;
	for (i = 0;i < 21;i++)
	{
		valueArray[i] = 0;
	}
	while (true)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			if (msg.x > 0 && msg.x < 400 && msg.y>0 && msg.y < 400)
			{
				chooseX = (msg.x+10) / 20;
				chooseY = (msg.y+10) / 20;
				coorXtext.set_value(chooseX-10);
				coorXtext.output();
				coorYtext.set_value(-chooseY+10);
				coorYtext.output();
				setlinecolor(LIGHTGRAY);
				setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 1);
				line(chooseXpre * 20, 0, chooseXpre * 20, 400);
				line(0, chooseYpre * 20, 400, chooseYpre * 20);

				setlinecolor(RED);
				setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 1);
				line(chooseX * 20, 0, chooseX * 20, 400);
				line(0, chooseY * 20, 400, chooseY * 20);
				chooseXpre = chooseX;
				chooseYpre = chooseY;
				if (msg.mkCtrl == true)
				{
					setfillcolor(WHITE);
					solidcircle(chooseX * 20, 200 - valueArray[chooseX] * 20, 5);

					valueArray[chooseX] = 10 - chooseY;
					setfillcolor(BLACK);
					solidcircle(chooseX * 20, chooseY * 20, 5);
					initialAxis();
				}
			}
		}
		
		if (msg.uMsg == WM_LBUTTONDOWN)
			mouseClickFlag1 = true;
		if (msg.uMsg == WM_LBUTTONUP && mouseClickFlag1 == true)
			mouseClickFlag2 = true;
		if (mouseClickFlag1 == true && mouseClickFlag2 == true)
		{
			if (clearButton.checkMouseIn(msg.x, msg.y))
			{
				clearButton.drawButtonDown();
				Sleep(buttonSleepTime);
				clearButton.drawButtonUp();
				initialLayout();
			}
			if (calculateButton.checkMouseIn(msg.x, msg.y))
			{
				calculateButton.drawButtonDown();
				Sleep(buttonSleepTime);
				calculateButton.drawButtonUp();
				initialLayout();
				calEvenArray(valueArray,evenArray);
				calOddArray(valueArray, oddArray);
				drawArray(200, 200, valueArray, true);
				drawArray(600, 200, evenArray, true);
				drawArray(1000, 200, oddArray, true);
			}
			mouseClickFlag1 = false;
			mouseClickFlag2 = false;
		}
		Sleep(5);
	}
	system("pause");
	return 0;
}