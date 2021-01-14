# include "iGraphics.h"

struct buttonCordinate
{
int x;
int y;
}bCordinate[5];

char button[20][20]={"bs.bmp","bl.bmp","bh.bmp","bc.bmp","bq.bmp"};
char homemenu [20] = "homemenu.bmp";
char start [20] = "insidegame.bmp";
char load [20] = "insideload";
char high [20] = "insidehighscore,bmp";
char credit [20] = "insidecredits.bmp";
char quit [20] = "insidequit.bmp";

/* 
	function iDraw() is called again and again by the system.
	
*/int gameState =-1;
void iDraw()
{
	//place your drawing codes here
	iClear();
	if(gameState == -1)
	  {
	       iShowBMP(0,0,homemenu);
	       for(int i=0;i<5;i++)
	       {
	       iShowBMP2(bCordinate[i].x,bCordinate[i].y,button[i],255);
	       }
	 }

	else if (gameState ==0){
	iShowBMP(0,0,start);
	}

	else if(gameState == 1)
	{
	iShowBMP(0,0,load);
	}

	else if(gameState == 2)
	{
	iShowBMP(0,0,high);
	}

	else if (gameState == 3)
	{
	iShowBMP(0,0,credit);
	}

	else if(gameState==4)
	{
	iShowBMP(0,0,quit);
	}

	else{}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		for(int i = 0; i<5 ; i++)
		{
		  if(mx>=bCordinate[i].x && mx<= bCordinate[i].x+130 && my>=bCordinate[i].y && my<=bCordinate[i].y+65)
		  {
		  gameState = i;
		  }
		}
	

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
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

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}


int main()
{
	//place your own initialization codes here. 

	int sum=75;
	for(int i=4;i>=0;i--)
	{
	bCordinate[i].x=350;
	bCordinate[i].y=sum;
	sum+=100;
	}


	iInitialize(800, 600, "demo");
	iStart();


	return 0;
}

