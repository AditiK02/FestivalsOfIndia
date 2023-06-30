#ifdef _WIN32
#include<windows.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define PI 3.1416
GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;

void drawHouse();
//Display text fn
void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
	glRasterPos3f(x, y, z);
	for(char* c = stringToDisplay; *c != '\0'; c++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
	}
}

void displayRasterTextsmall(float x ,float y ,float z ,char *stringToDisplay) {
	glRasterPos3f(x, y, z);
	for(char* c = stringToDisplay; *c != '\0'; c++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10 , *c);
	}
}



void init()
{
	glClearColor(0.3,0.2,0.3,0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glOrtho(-1200,1200,-700,700,0,50);                   //<-----CHANGE THIS TO GET EXTRA SPACE
//  gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);

}



void introScreen()
{
    //glClearColor(0.3,0.2,0.3,0);
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	glColor3f(1.0, 0.0, 0.0);
	displayRasterText(-425, 490, 0.0,"NMAM INSTITUTE OF TECHNOLOGY");
		glColor3f(1.0, 1.0, 1.0);
	displayRasterText(-700, 385, 0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
		glColor3f(1.0, 0.0, 1.0);
	displayRasterText(-225, 300, 0.0,"A MINI PROJECT ON ");*/

		glColor3f(1.0, 0.0, 0.5);
	displayRasterText(-190, 490, 0.0,"FESTIVALS OF INDIA");   //-200,385,0.0

   		glColor3f(1.0, 0.7, 0.8);
	  displayRasterText(-20, 200, 0.0," BY-");

	  	glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-800, 80, 0.0," Akash Shetty");
	displayRasterText(600, 80, 0.0," Aditi Kumari");


		glColor3f(1.0, 0.7, 0.8);
	displayRasterText(-200, -30, 0.0,"Under The Guidance Of");

		glColor3f(1.0, 1.0, 1.0);
	displayRasterText(600, -200, 0.0,"Dr. Pradeep Kanchan");

	glColor3f(1.0, 1.0, 1.0);
	displayRasterText(-800, -200, 0.0,"Mr. Puneeth R P");
		//glColor3f(1.0, 0.0, 0.0);
	//displayRasterText(-250, -300, 0.0,"Academic Year 2022-2023");
   //     glColor3f(1.0, 1.0, 1.0);


    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	displayRasterTextsmall(-120, -500, 0.0,"PRESS A TO SWITCH");

	glFlush();
 	glutSwapBuffers();

}




void newdisp(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glFlush();
}







void displayNewWin1(){
    glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_COLOR_BUFFER_BIT);

    //   glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
   // drawDiwaliLamp();
    glClearColor(0.3,0.2,0.3,0);

    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, 400, 0.0,"DIWALI IS A FETSIVAL OF LIGHTS                                      press D");

	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, 100, 0.0,"HOLI IS THE FESTIVAL OF COLOURS                                  press H");

	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, -200, 0.0,"CHRISTMAS CELEBRATE'S BIRTH OF JESUS CHRIST     press C");

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	displayRasterTextsmall(-120, -500, 0.0,"PRESS F FOR BACK");

	glFlush();
 	glutSwapBuffers();

}

/*void drawmoon()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-100.0, -100.0);
        glVertex2f(-100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, -100.0);
    glEnd();
}
*/
void fillLowerBG()
{
     GLubyte upperGreenColor[] = {20, 71, 1};
     GLubyte lowerGreenColor[] = {68, 210, 12};

     glBegin(GL_POLYGON) ;
     glColor3ubv(upperGreenColor);
     glVertex3i(-5, -1,-1);
     glVertex3i(5, -1,-1);
     glColor3ubv(lowerGreenColor);
     glVertex3i(5, -5,-1);
     glVertex3i(-5, -5,-1);

     glEnd();
}

void fillUpperBG()
{
     glBegin(GL_POLYGON);
                         glColor3ub(0,0,0);
                         glVertex3f(-10,10,-5);
                         glColor3ub(60,60,60);
                         glVertex3f(10,10,-5);
                         glColor3ub(1,5,2);
                         glVertex3f(10,-10,-5);
                         glColor3ub(3,3,1);
                         glVertex3f(-10,-10,-5);
     glEnd();

     glColor3f(1,1,1);
     int dir;
     int i;
     float j;
     glPointSize(1.5);
     glEnable(GL_POINT_SMOOTH);
     glBegin(GL_POINTS);
                        for(i=0; i<5; i++)
                        {
                                 glVertex2f(-5 + 10*(rand()%100 / 100.0), 3*(rand()%100 / 100.0));
                        }
     glEnd();
     glDisable(GL_POINT_SMOOTH);
}

void drawGrass()
{
    // GLubyte lightGreenColor[] = {37, 186, 7};
     //GLubyte darkGreenColor[] = {20, 71, 1};
     GLubyte lightGreenColor[] = {124, 252, 0};
GLubyte darkGreenColor[] = {0, 100, 0};
     float beginX = -5;
     float beginY = -0.5;
     glBegin(GL_TRIANGLES) ;
     while(beginX<5)
     {
         glColor3ubv(lightGreenColor);
         glVertex2f(beginX, beginY);
         glColor3ubv(darkGreenColor);
         glVertex3f(beginX - 0.025, beginY - 0.5,0);
         glVertex3f(beginX + 0.025, beginY - 0.5,0);
         beginX += 0.05;
     }
     glEnd();
}

drawUnitFence()
{
     GLubyte upBrownColor1[] = {144, 97, 7};
     GLubyte downBrownColor1[] = {146, 100, 10};
     GLubyte upBrownColor2[] = {84, 47, 0};
     GLubyte downBrownColor2[] = {180, 121, 6};

     glBegin(GL_QUADS) ;
     glColor3ubv(upBrownColor1);
     glVertex3f( 0, 0, 0 );
     glVertex3f( 0.75, 0, 0 );
     glColor3ubv(downBrownColor1);
     glVertex3f( 0.75, -0.50, 0 );
     glVertex3f( 0, -0.50, 0 );


     glColor3ubv(upBrownColor1);
     glVertex3f( 0, -1.30, 0 );
     glVertex3f( 0.75, -1.30, 0 );
     glColor3ubv(downBrownColor1);
     glVertex3f( 0.75, -1.80, 0 );
     glVertex3f( 0, -1.80, 0 );

     glColor3ubv(upBrownColor2);
     glVertex3f( 0.75, 0.50, 0 );
     glVertex3f( 1.55, 0.50, 0 );
     glColor3ubv(downBrownColor2);
     glVertex3f( 1.55, -2.30, 0 );
     glVertex3f( 0.75, -2.30, 0 );

     glEnd();
}

void drawFence()
{
     float beginX = -5;
     float beginY = -0.3;

     while(beginX < 5)
     {
         glPushMatrix();
         glTranslatef(beginX, beginY, -1);
         glScalef(0.3,0.3,0.2);
         drawUnitFence();
         glPopMatrix();
         beginX += 0.4;
    }

}

void sideLight(int color)
{
     //RED: 0
     //GREEN: 1
     //BLUE: 2

     int i;
     float radius;
     float degInRad;

    GLubyte red[]  = { 255, 0, 0};
    GLubyte green[]  = {   0, 255,   0};
    GLubyte blue[]  = { 0,  0, 255};

    glPushMatrix();
          radius=0.6;
          glScalef(0.07,0.3,1);
          glBegin(GL_POLYGON);
              switch(color)
              {
                           case 0:
                                glColor3ubv(red);
                                break;
                           case 1:
                                glColor3ubv(green);
                                break;
                           case 2:
                                glColor3ubv(blue);
                                break;
                           default:
                                glColor3ubv(red);
                                break;
              }

               glVertex3f(0,0,0.1);
               glColor3ub(0,0,0);
               for (i=0; i <= 361; i++)
               {
                    degInRad = i*3.14/180;
                    glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0.1);
               }
               glEnd();
    glPopMatrix();
}
void diya()
{
     int i;
     float radius;
    float degInRad;
    float centerX,centerY;

          radius=0.5;
                       centerX=-1.5, centerY=0;
                        glBegin(GL_POLYGON);
                         glColor3ub(1,1,1);                             //glColor3ub(21,6,1);
                        glVertex3f(centerX,centerY,0.1);
                         glColor3ub(1,1,1);                                        //glColor3ub(91,35,5);
                       for (i=1800; i <= 360; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius +centerX,sin(degInRad)*radius+centerY,0.1);
                       }
                       glEnd();
         glPushMatrix();
                        glScalef(0.2,0.5,1);
                        radius=0.3;
                        centerX= -4.5, centerY=0.7;
                        glBegin(GL_POLYGON);
                          glColor3ub(25,24,1);                          // glColor3ub(255,248,0);
                        glVertex3f(centerX,centerY,0.1);
                         glColor3ub(25,12,1);                          //    glColor3ub(255,127,0);
                        degInRad;
                       for (i=0; i <= 361; i++)
                       {
                          degInRad = i*3.14/180;
                          glVertex3f(cos(degInRad)*radius +centerX,sin(degInRad)*radius+centerY,0.1);
                       }
                       glEnd();

         glPopMatrix();
}

float openAngle1 = 135;
int colRed[] = {255,177,15,94};
int cDir[] = {0,0,0,0};
int diyaRotator=361;

void drawBackground()
{
     glDisable(GL_LIGHTING);
     fillLowerBG();
     fillUpperBG();
     glPushMatrix();
          glScalef(0.2,1.2,0.1);   ///1=2, 1=0
          glTranslatef(0,0.1,-1.2);
          drawGrass();
     glPopMatrix();
     diya();
     drawFence();
   //  sideLight(0.6);
     glEnable(GL_LIGHTING);
}




void displayNewWinDiwali()
{
    glClearColor(0.1,0.03,0.2,0);

    glClear(GL_COLOR_BUFFER_BIT);
  // glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
   // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glColor3f(1.0, 0.0, 0.5);
	//displayRasterText(-190, 490, 0.0,"HAPPY DIWALI");

	//glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	//displayRasterTextsmall(-120, -500, 0.0,"PRESS B FOR BACK");


  //glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
//    drawmoon();
 PlaySound("firecracker.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    drawBackground();
    //PlaySound("firecracker.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//   drawmoon();
    glFlush();
 	glutSwapBuffers();


}


void displayNewWinHoli()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
       glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.5);
	displayRasterText(-190, 490, 0.0,"HAPPY HOLI");

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

	displayRasterTextsmall(-120, -500, 0.0,"PRESS B FOR BACK");
//   drawDiwaliLamp();
    glFlush();
 	glutSwapBuffers();


}

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void Sun_Model(){
    glPushMatrix();
    glTranslatef(500,0,0);
    circle(30);
    glPopMatrix();

}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();

}


void displayNewWinChristmas()
{
    glClearColor(1.0,1.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_COLOR_BUFFER_BIT);
       glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Moving_Sun_Model();

    glColor3f(1.0, 0.0, 0.5);
	displayRasterText(-190, 490, 0.0,"HAPPY CHRISTMAS");

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

	displayRasterTextsmall(-120, -500, 0.0,"PRESS B FOR BACK");
//    drawDiwaliLamp();
    glFlush();
 	glutSwapBuffers();


}


/*void keysback(unsigned char keyy,int A,int B)
{
    if (keyy=='B'|| keyy=='b')
    {
        glutDisplayFunc(displayNewWin1);
    }


}
*/
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);

    introScreen();

    //startScreenDisplay();
    //displayNewWin1();

	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}
void keys(unsigned char key,int A,int B)
{

    if(key=='A'||key=='a')
    {
        glutDisplayFunc(displayNewWin1);

    }
    else if(key=='F'||key=='f')
    {
        glutDisplayFunc(display);
    }
     else if (key=='D'|| key=='d')
    {
        glutDisplayFunc(displayNewWinDiwali);

    }
    else if (key=='H'|| key=='h')
    {
        glutDisplayFunc(displayNewWinHoli);

    }
    else if (key=='C'|| key=='c')
    {
        glutDisplayFunc(displayNewWinChristmas);

    }
    else if (key=='B'|| key=='b')
    {
        glutDisplayFunc(display);

    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Festivals of India");
    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keys);

//    glutReshapeFunc(reshape);
    glutMainLoop();
}
