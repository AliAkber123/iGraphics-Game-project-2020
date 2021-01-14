#include "iGraphics.h"
#include "myheader.h"
#include "bitmap_loader.h"
#include<iostream>

int fage=0;
int ball_x, ball_y;
int fire = 0;
int bullet_x =-(int)1e9;
int bullet_y =138;
int Coinx[5],Coiny[5],movingCoin[5];
bool CollisonM;
int i;

int pic_x1=410,pic_y1=410;
int mon_x;
int mon_y=15;
int pic3_x=10, pic3_y=15;
int dx1=8,dxx=9;
int dy1=8;


int image1,image2,image3,image4,image5,image6,image7,image8,pic2_x, pic2_y,image9,image10;
int flag=0;




bool musicOn = true;
bool jump = false;
bool jumpUp=false;
bool jumpDown = false;
int herooJump=0;

bool punch=false;
int j;
int score=0;
char a[15];
char c[15];
 FILE *fp;
 int highscore;

void initialize(){
	fp=fopen("highscore.txt","r");
   
    fscanf(fp,"%d\n",&highscore);
    fclose(fp);

	//coin initialize
	for(i=0;i<5;i++){
	   Coinx[i]=800+rand()%500;
	   Coiny[i]=rand()%475;
	}
	for(i=0;i<5;i++){
		movingCoin[i]=Coinx[i];
	}
}

//changing coin's value
void update(){
	for(i=0;i<5;i++){
		movingCoin[i]-=5;
 }
}

//checking collison
bool checkCollison(int Coinx,int Coiny){
	if(abs(pic3_x-Coinx)<130 && pic3_y+370>Coiny && pic3_y<Coiny){
	   return true;
	}
	else{
	  return false;
	}

}

 //initialize monster
 void initializeM(){

    mon_x=800+rand()%500;

	 }


 //checking collison of bulet n mons
 bool checkCollisonM(int mon_X,int mon_y1){
    if(bullet_x+1> mon_X && bullet_y+33>mon_y1 ){
	   return true;
	}
	else{
	  return false;
	}
 }



/*void writeHighScore(char *c)
{
    FILE *fp=fopen("highscore.txt","a");
   
   
        fprintf(fp,"%s\n", c);
    
    fclose(fp);
}*/

void writeScore(char *a)
{
    FILE *fp=fopen("score.txt","a");
    
    
        fprintf(fp,"%s\n", a);
    
    fclose(fp);
}



/*
function iDraw() is called again and again by the system.
*/struct buttonCordinate
{
    int x;
    int y;
} bCordinate[6];

char button[20][20]= {"bs.bmp","bl.bmp","bh.bmp","bc.bmp","bi.bmp","bq.bmp"};
char homemenu [20] = "homemenu.bmp";
char start [20] = "insidegame.bmp";
char load [20] = "insideload";
char high [20] = "insidehighscore,bmp";
char credit [20] = "insidecredits.bmp";
char quit [20] = "insidequit.bmp";


/*
	function iDraw() is called again and again by the system.
i
*/ 
int gameState =-1;
int gameOver=0;


void iDraw()
{
    //place your drawing codes here
	printf("gameState=%d\n",gameState);
	printf("gameOver=%d\n",gameOver);

    iClear();

	

    /* iShowImage():
    Here, first 2 parameters are the lower left
    corner position of image you want to put.
    3rd and 4th parameters are the widht and the height
    of the image.
    Last parameter is the id of the image you want to put.

    */
	if(gameOver==1){
		/*if(flag*10>=120)
	   {
		   iClear();
		   iShowImage(0,0,800,600,image5);
	   }*/

		iShowImage(0,0,800,600,image5);
		
		

    }else{
	
	
	if(gameState == -1)
    {   
		
		
        iShowBMP(0,0,homemenu);
        for(int i=0; i<6; i++)
        {
            iShowBMP2(bCordinate[i].x,bCordinate[i].y,button[i],255);
        }

    }
	 

    else if (gameState ==0)
    {   
		//gameOver=0;
		
		fage=1;
		if(fage==1){
		iClear();
        iShowImage(pic_x, pic_y, 800, 600, image1);
        iShowImage(pic2_x, pic2_y, 800, 600, image2);
		iSetColor(0,0,255);
		iText(14,521,"Press HOME to go Menu page",GLUT_BITMAP_HELVETICA_18);

       
        iShowImage(mon_x,mon_y,120,180,image3);

        iSetColor(0,255,0);
        iFilledRectangle(550,550,20,20);
        iFilledRectangle(570,550,20,20);
        iFilledRectangle(590,550,20,20);
        iFilledRectangle(610,550,20,20);
        iFilledRectangle(630,550,20,20);
        iFilledRectangle(650,550,20,20);
        iSetColor(255,0,0);
        iText(10,553,"SCORE:", GLUT_BITMAP_HELVETICA_18);

       
            iSetColor(255,0,0);
            iFilledRectangle(550,550,flag*10,20);
			
		
        itoa(score,a,10);
        iText(100, 550,a, GLUT_BITMAP_TIMES_ROMAN_24);
        

       
		





        if(jump)
        {
            if(jumpUp)
            {
                //iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "herojump.bmp");
				 iShowImage(pic3_x, pic3_y + herooJump,180,240, image6);
            }
			else
          if(pic3_x %2 ==0){
                //iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "heroo.bmp");
				 iShowImage(pic3_x, pic3_y + herooJump,180,240, image7);
				}
				else
                //iShowBMPAlternativeSkipWhite(pic3_x, pic3_y + herooJump, "heroo1.bmp");
			iShowImage(pic3_x, pic3_y + herooJump, 180,240,image8);
        }
        else
        {

           if(pic3_x %2 ==0){
                              // iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo.bmp");
			    iShowImage(pic3_x, pic3_y + herooJump,180,240, image7);

			                }
			else
				//iShowBMPAlternativeSkipWhite(pic3_x, pic3_y, "heroo1.bmp");
				iShowImage(pic3_x, pic3_y + herooJump, 180,240,image8);
            
        }
       

 
		
		/*if(flag*5>=120)
	   {
		   iClear();
		   iShowImage(0,0,800,600,image5);
	   }*/

		//coin collison
		for(i=0;i<5;i++){
	  bool Collison=checkCollison(movingCoin[i],Coiny[i]);
	  bool screenExceed=movingCoin[i]<0;

	  if(Collison == true || screenExceed==true){
	       movingCoin[i]=Coinx[i];
		    
	    }

      //Mon vanish code
	  CollisonM=checkCollisonM(mon_x,mon_y);

	 
	std::cout <<"Collision :" <<CollisonM << std::endl;
	  bool screenExceedM=mon_x<0;
	  if(CollisonM == true || screenExceedM==true){
	     int ran=rand()%600;
		 mon_x=800+ran;
		 bullet_x = -(int)1e9;
	    }
	   iShowImage(mon_x, mon_y, 120, 180, image3);  
	  //}

	  //scoring part
	  if(Collison == true&&gameState==0){
		  score=score+5;
	  }
	  
	   iShowImage(movingCoin[i], Coiny[i], 30, 30, image4);  
	  
	
	}  fage=0;
		}
		
		}

		
	

    else if(gameState == 1)
    {
        fage=0;
		iSetColor(0,0,255);
		iText(14,521,"Press HOME to go Menu page",GLUT_BITMAP_HELVETICA_18);
		FILE *file=fopen("savegame.txt","r");
		fscanf(file,"%d %d %d %d %d %d %d",&pic_x1,&pic_y1,&mon_x,&mon_y,&pic3_x,&pic3_y,&score);
		fclose(file);
		printf("%d %d %d %d %d %d %d\n",pic_x1,pic_y1,mon_x,mon_y,pic3_x,pic3_y,score);
		gameState=0;
    }

    else if(gameState == 2)

    {  
		fage=0;
		iShowImage(0,0,800,600,image9);
		iSetColor(0,0,255);
		iText(290,401,"Press HOME to go Menu page",GLUT_BITMAP_HELVETICA_18);
        itoa(highscore,c,10);
        iText(320, 340,"High Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450, 340,c, GLUT_BITMAP_TIMES_ROMAN_24);    

    }

    else if (gameState == 3)
    { 
		fage=0;
		iSetColor(0,0,255);
		iText(14,521,"Press HOME to go Menu page",GLUT_BITMAP_HELVETICA_18);
        iShowBMP(0,0,credit);
    }

    else if(gameState==5)
    { 
		fage=0;
		iSetColor(0,0,255);
		iText(14,521,"Press HOME to go Menu page",GLUT_BITMAP_HELVETICA_18);
        exit(0);
    }


	else if(gameState == 4)
	{
	iShowImage(0,0,800,600,image10);
	}


    else {}
	if(fire == 1)
	{
		
		
	iShowBMPAlternativeSkipWhite(bullet_x,bullet_y,"bullet.bmp");
	

	}
	}

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
        for(int i = 0; i<6 ; i++)
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

	printf("x=%d\n y=%d",mx,my);
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 's')
    {
        fire = 1;
		bullet_x= pic3_x+193;
		bullet_y = herooJump+138;


    }
    else
    {

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
        if(pic3_x>0){
            pic3_x= pic3_x-dx1;
		pic3_x = pic3_x - dxx;}
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(pic3_x+465 < 1000){
            pic3_x=pic3_x+dx1;
		pic3_x = pic3_x + dxx;}
    }
    if(key == GLUT_KEY_UP)
    {
        if(!jump)
        {
            jump= true;
            jumpUp= true;
        }
		
    }
	if(key == GLUT_KEY_HOME)
	{
		fage=0;
		gameState=-1;
		gameOver=0;
	}
	if(key == GLUT_KEY_INSERT)
	{
		FILE *file=fopen("savegame.txt","w");
		fprintf(file,"%d %d %d %d %d %d %d\n",pic_x1,pic_y1,mon_x,mon_y,pic3_x,pic3_y,score);
		fclose(file);
	}

    //place your codes for other keys here
}
void herooJumpp()
{

    if(jump)
    {
        if(jumpUp)
        {

            herooJump +=6;
            if(herooJump >= 250)
            {

                jumpUp = false;
            }
        }


        else
        {
            herooJump -=6;
            if(herooJump < 0)
            {
                jump = false;
            }
        }

    }
    if(pic3_x-mon_x<=4&&pic3_x-mon_x>=0)
    {
       
        /*if(mon_x>=pic3_x||mon_x<=pic3_x)*/
       

            flag++;

        
       

    }
	
	

	if(flag*10>=120)
	{
		gameOver = 1;
		flag=0;
	  fire = 0;
      bullet_x = 205;
     bullet_y =138;
     Coinx[5],Coiny[5],movingCoin[5];
     i;
     pic_x1=410,pic_y1=410;
     mon_x=397;
     mon_y=15;
     pic3_x=10, pic3_y=15;
     dx1=9,dy1=8;
	 image1,image2,image3,image4,image5,pic2_x, pic2_y;
    musicOn = true;
    jump = false;
	jumpUp=false;
    jumpDown = false;
    herooJump=0;
	punch=false;
    j;
	score=0;
    a[15];
   c[15];
 FILE *fp;
		if(score>highscore){
			highscore=score;
			fp=fopen("highscore.txt","w");
            fprintf(fp,"%d\n",score);
            fclose(fp);
			
		}
		return ;
	}

}

void change()
{
    for(int i=0; i<=5; i++)
    {
        pic_x-=dx;
        pic2_x-=dx;
        if(pic2_x<=0)
        {
            pic2_x=800;
            pic_x=0;
            for(int i=0; i<=5; i++)
            {
                pic_x-=dx;
                pic2_x-=dx;



            }

        }

    }

}

void monChange()
{
	if(gameState==0){
	
	mon_x=mon_x-5;
    if(mon_x<=-190)
    {
		int ran=rand()%600;
        mon_x=800+ran;
    }
   
	}

}





void bulletMove()

{  

  if(bullet_x < 800){
  bullet_x = bullet_x+5;
	}
  else{
     bullet_x=-(int)1e9;
  }
}





int main()
{
    //place your own initialization codes here.
    int sum=60;
    for(int i=5; i>=0; i--)
    {
        bCordinate[i].x=350;
        bCordinate[i].y=sum;
        sum+=85;
    }
    
        PlaySound("wavedfile.wav",NULL,SND_LOOP|SND_ASYNC);

    iInitialize(800, 600, "Animation with image");

    initialize();
	initializeM();
    //iSetTimer(1,scores);
    iSetTimer(1,herooJumpp);
    iSetTimer(5, change);
    //iSetTimer(20, coinMove);
    iSetTimer(20,monChange);
	iSetTimer(20,bulletMove);
	iSetTimer(10,update);
	


    dx =1;
   
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
    image3 = iLoadImage("monster1.png");
    image4= iLoadImage("Coin.png");
	image5= iLoadImage("gameover.png");
	image6=iLoadImage("1600848581254.png");
	image7=iLoadImage("1600848443819.png");
	image8=iLoadImage("1600848228003.png");
	image9=iLoadImage("scorebg.jpg");
	image10=iLoadImage("instruct.jpg");





    iStart(); // it will start drawing
    return 0;

}

