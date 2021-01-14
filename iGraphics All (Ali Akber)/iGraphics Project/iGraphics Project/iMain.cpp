#include "iGraphics.h"
#include "bitmap_loader.h"

int x = 300, y = 300, r = 20;
int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0;
int counter =0;
/*
 function iDraw() is called again and again by the system.

 */
void drawRoadLines(int offset)
{
	int len = 10;
	int width = 5;
	int gap = 10;
	int midx = 0, midy = win_l / 2;
	for (int i = 0; i < win_b / (len + gap); i++)
		iFilledRectangle((i * (len + gap) + offset) % win_b, midy, len, width);
}
int k = 0;

void drawBGDflag()
{
	iSetColor(0, counter%256, 0);
	iFilledRectangle(100, 100, 100, 60);
	iSetColor(255,0,0);
	iFilledCircle(150,130,20);
	counter++;
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	/*
	iSetColor(255,255,255);
	iPoint(100,100);
	iLine(100,100,200,300);
	iRectangle(100,200,40,50);
	iFilledRectangle(100,200,40,50);
	//iFilledCircle(200,200,30,100);
	double X[] = {100,102,110,107};
	double Y[] = {100,110,219,206};
	int N = 4;
	iFilledPolygon(X,Y,N);
	iText(200,200,"iGraphics",GLUT_BITMAP_HELVETICA_18);
	*/

	iSetColor(0,140,0);
	iFilledRectangle(100,100,100,60);
	iSetColor(255,0,0);
	iFilledCircle(145,130,20,100);
	/*iSetColor(255,255,255);
	iFilledRectangle(0,0,1000,400);
	iSetColor(0,0,0);
	iPoint(100,100);
	iLine(100,100,200,300);
	iFilledRectangle(150,150,20,30);
	iCircle(230,100,70,100);
	double X[] = {100,102,110,107};
	double Y[] = {100,110,109,106};
	int N = 4;
	iFilledPolygon(X,Y,N);
	iText(200,200,"iGraphics",GLUT_BITMAP_HELVETICA_18);
	
	iSetColor(0,128,0);
	iFilledRectangle(100,100,100,60);
	iSetColor(255,0,0);
	iFilledCircle(145,130,20,100);
	*/
	/*iSetColor(0,255,0);
	iFilledRectangle(100,100,200,120);
	iSetColor(255,0,0);
	iFilledCircle(190,160,30,100);
	
	iText(100,80,"The Flag of Bangladesh",GLUT_BITMAP_HELVETICA_18);
	*/
	//drawBGDflag();
	//iDelayMS(200);
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'a' && speed < 5)
		speed += 1;
	else if (key == 's' && speed > 0)
		speed -= 1;
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.


	iInitialize(1000, 400, "Demo");

	iStart(); // it will start drawing

	return 0;
}

