#include "iGraphics.h"
#include "myheader.h"
#include "bitmap_loader.h"


int ball_x, ball_y;

int pic_x1=410,pic_y1=410;
int mon_x=397;
int mon_y=15;
int pic3_x=10, pic3_y=15;
int dx1=9,dy1=8;


int image1,image2,image3,image4,pic2_x, pic2_y;
int flag=0;


  bool musicOn = true;
  bool jump = false;
  bool jumpUp=false;
  bool jumpDown = false;
  int herooJump=0;
 
  bool punch=false;
  int j;
  int score=0;
  void writeHighScore(char *c)
{
	FILE *fp=fopen("highscore.txt","a");
	int max=0;
	if(score>=max)
	{
	fprintf(fp,"%s\n", c);
	}
	fclose(fp);
}

/*
function iDraw() is called again and again by the system.
*/struct buttonCordinate
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

	/* iShowImage():
	Here, first 2 parameters are the lower left
	corner position of image you want to put.
	3rd and 4th parameters are the widht and the height
	of the image.
	Last parameter is the id of the image you want to put.
	*/if(gameState == -1)
	  {
	       iShowBMP(0,0,homemenu);
	       for(int i=0;i<5;i++)
	       {
	       iShowBMP2(bCordinate[i].x,bCordinate[i].y,button[i],255);
	       }
		   
	 }

	else if (gameState ==0){
		iShowImage(pic_x, pic_y, 800, 600, image1);
	iShowImage(pic2_x, pic2_y, 800, 600, image2);
	
	/*iShowBMPAlternativeSkipWhite(pic_x1,450,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,450,"coin4.bmp");


	iShowBMPAlternativeSkipWhite(pic_x1,430,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,430,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,410,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,410,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,390,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x1,390,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,370,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x1,370,"coin4.bmp");*/
	iShowImage(mon_x,mon_y,180,240,image3);
	
	iSetColor(0,255,0);
	iFilledRectangle(550,550,20,20);
	iFilledRectangle(570,550,20,20);
	iFilledRectangle(590,550,20,20);
	iFilledRectangle(610,550,20,20);
	iFilledRectangle(630,550,20,20);
	iFilledRectangle(650,550,20,20);
	iSetColor(255,0,0);
	iText(10,553,"SCORE:", GLUT_BITMAP_HELVETICA_18);  

	if (flag==1)
	{ 
	   iSetColor(255,0,0);
	   iFilledRectangle(550,550,20,20);


	}

	
	
	
	
	if(jump){
		if(jumpUp){
	            	iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "herojump.bmp");
		          }

		else
			iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "heroo.bmp");

	       }

	else{
		
	       iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo.bmp");
		   iShowImage(pic_x1, pic_y1, 30, 30, image4);
	    }
	if (flag==1)
	{ 
	   iSetColor(255,0,0);
	   iFilledRectangle(550,550,20,20);


	}

	if(punch){

		if(punch == false){
		iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo.bmp");
		}
		else{
			
	iShowBMPAlternativeSkipWhite(pic3_x+ herooJump, pic3_y, "heroopunch.bmp");
	
	punch = false;
		}
	}
	
	}

	else if(gameState == 1)
	{
	iShowBMP(0,0,load);
	}

	else if(gameState == 2)
	{ 
		char c[15];
		itoa(score,c,10);
		iText(550, 240,"Your Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 240,c, GLUT_BITMAP_TIMES_ROMAN_24);
	    writeHighScore(c);
	  
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
	
	
	
/*	iShowImage(pic_x, pic_y, 800, 600, image1);
	iShowImage(pic2_x, pic2_y, 800, 600, image2);
	
	iShowBMPAlternativeSkipWhite(pic_x1,450,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,450,"coin4.bmp");


	iShowBMPAlternativeSkipWhite(pic_x1,430,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,430,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,410,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x2,410,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,390,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x1,390,"coin4.bmp");

	iShowBMPAlternativeSkipWhite(pic_x1,370,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(pic_x1,370,"coin4.bmp");
	iShowBMPAlternativeSkipWhite(mon_x,mon_y,"zom (1).bmp");
	iShowBMPAlternativeSkipWhite(mon_x,mon_y,"zom (1).bmp");
	iSetColor(0,255,0);
	iFilledRectangle(550,550,20,20);
	iFilledRectangle(570,550,20,20);
	iFilledRectangle(590,550,20,20);
	iFilledRectangle(610,550,20,20);
	iFilledRectangle(630,550,20,20);
	iFilledRectangle(650,550,20,20);
	iSetColor(255,0,0);
	iText(10,553,"SCORE:", GLUT_BITMAP_HELVETICA_18);  

	if (flag==1)
	{ 
	   iSetColor(255,0,0);
	   iFilledRectangle(j,550,20,20);


	}

	
	
	
	
	if(jump){
		if(jumpUp){
	            	iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "herojump.bmp");
		          }

		else
			iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "heroo.bmp");

	       }

	else{
		
	       iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo.bmp");
	    }
	if (flag==1)
	{ 
	   iSetColor(255,0,0);
	   iFilledRectangle(550,550,20,20);


	}

	if(punch){

		if(punch == false){
		iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo.bmp");
		}
		else{
			
	iShowBMPAlternativeSkipWhite(pic3_x+ herooJump, pic3_y, "heroopunch.bmp");
	
	punch = false;
		}
	}
	*/
	
	


	

    
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
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	for(int i = 0; i<5 ; i++)
		{
		  if(mx>=bCordinate[i].x && mx<= bCordinate[i].x+130 && my>=bCordinate[i].y && my<=bCordinate[i].y+65)
		  {
		  gameState = i;
		  }
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
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
	if(key == 's'){
	pic3_x=1200;
	pic3_y=900;

	punch = true;
	
	}
	else{
	
		pic3_x=10;
		pic3_y=15;
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
		if(musicOn)
		{
		musicOn = false;
		PlaySound(0,0,0);
		}
		else
		{
		musicOn = true;
		PlaySound("wavedfile.wav",NULL,SND_LOOP|SND_ASYNC);
		}
	}
	if(key == GLUT_KEY_LEFT)
	{   
		if(pic3_x>0)
		pic3_x= pic3_x-dx1;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(pic3_x+465 < 1000)
		pic3_x=pic3_x+dx1;
	}
	if(key == GLUT_KEY_UP)
	{
		if(!jump){
		           jump= true;
		           jumpUp= true;
		         }	
	}
	
	//place your codes for other keys here
}
void herooJumpp(){

	if(jump)
	{
		if(jumpUp){
		
		herooJump +=5;
		if(herooJump >= 230){

		                     jumpUp = false;
		                    }
                  }


		else{
		herooJump -=5;
		if(herooJump < 0){
		                  jump = false;
		                 }
		    }

     }
	if(mon_x==pic3_x){
	 {
		if(mon_x>=pic3_x||mon_x<=pic3_x)
	
		  flag=1;
	 }
	     flag=1;

}



}

void change(){ 
	for(int i=0;i<=5;i++)
	{
		pic_x-=dx;
	    pic2_x-=dx;
		if(pic2_x<=0)
		{
	        pic2_x=800;
			pic_x=0;
			for(int i=0;i<=5;i++)
	{
		pic_x-=dx;
	    pic2_x-=dx;
	       
       
		
		}

		}

}

}
void coinMove(){
	pic_x1-=dx;
	//pic_x2-=dx;
	if(pic_x1<=0/*&&pic_x2*/)
	{
		pic_x1=800;
		//pic_x2=800;
	}
	
	
}
void monChange()
{
	mon_x=mon_x-5;
	if(mon_x<=0)
	{
		mon_x=800;
	}
	if(mon_x==pic3_x){
	 {
		if(mon_x>=pic3_x||mon_x<=pic3_x)
	
		  flag=1;
	 }
	     flag=1;

}
	
	
}

void scores(){
	
	if(pic3_x==pic_x1)
	 score=score+5;
	
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
	if(musicOn)
		PlaySound("wavedfile.wav",NULL,SND_LOOP|SND_ASYNC);

	iInitialize(800, 600, "Animation with image");
	iSetTimer(1,scores);
	iSetTimer(1,herooJumpp);
	iSetTimer(5, change);
	iSetTimer(20, coinMove);
	iSetTimer(20,monChange);
	
	dx =1;
	pic_x1=400;
	//pic_x2=400;
	
	

	
	

	pic_x = 0;
	pic_y = 0;
	pic2_x = 800;
	pic2_y = 0;
	pic3_x=10;
    pic3_y=10;
 


	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	*/

	image1 = iLoadImage("pic3 (1).jpg");
	image2 = iLoadImage("pic3 (1).jpg");
	image3 = iLoadImage("monster.png");
	image4= iLoadImage("Coin.png");
	

	

   iStart(); // it will start drawing
   return 0;
	
}

