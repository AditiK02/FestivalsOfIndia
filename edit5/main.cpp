#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define TEXTID 3
#define PI 3.14
float p=-0.005;
float s=-0.005;
float u=-0.005;
float m=-0.005;
float n=-0.005;
float o=-0.005;


/**** Global Declarations and initializations *****/



GLUquadricObj *quadratic;



float t_val = 0.1;

int array_size = 11000; //  number of snow flakes

float snow[11000][2];   //  coordinates of snow flakes

int j;                  //snow[specifies flake number][0=specifies x coordinate  1=specifies y coordinate]

GLfloat angle = 0.0f;

GLfloat x , y , z;

bool right = true;

int flag = 1;

float l1,l2,l3;//snow part end






/***** Funtion to output text on screen *****/



void print_bitmap_string(float x, float y, float z, char* s)

{

   int i;

   GLvoid* font_style=GLUT_BITMAP_TIMES_ROMAN_24; // font name

   int len=(int) strlen (s);

   glPushMatrix();

   glRasterPos3f(x,y,z);

   for(i=0;i<len;i++){

         glutBitmapCharacter(font_style, s[i]);

	}



    glPopMatrix();

}





/**** Welcome Screen ****/

/*

void welcome_screen()

{

	glClearColor(0.0,0.0,0.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0,0,5,0,0,0,0,1,0);

	char welcome[7][200];

	strcpy(welcome[0],"WELCOME");

	strcpy(welcome[1],"Christmas Scene Simulation");

	strcpy(welcome[2],"");

	strcpy(welcome[3],"");

	strcpy(welcome[4],"");

	strcpy(welcome[5],"Press s to Start  & q to quit the Simulation");

	strcpy(welcome[6],"Press d for Description");

	glColor3f(0,1,1);

	print_bitmap_string(-1,3.5,-7,welcome[0]);

	glColor3f(1,1,1);

	print_bitmap_string(-2,2.5,-7,welcome[1]);

	glColor3f(1,0,1);

	print_bitmap_string(-6.1,-0.7,-7,welcome[2]);

	glColor3f(.8,0.5,1);

	print_bitmap_string(-6.2,-1.3,-7,welcome[3]);

	print_bitmap_string(-6.2,-2,-7,welcome[4]);

	glColor3f(1.0,1.0,0.0);

	print_bitmap_string(2.2,-1.3,-7,welcome[5]);

	glColor3f(1.0,1.0,0.0);

	print_bitmap_string(2.2,-2,-7,welcome[6]);



}*/



/***** Description Screen *****/


/*
void descscreen()

{

	glClearColor(1.0,1.0,1.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0,0,5,0,0,0,0,1,0);

	char text[8][200];

	strcpy(text[0],"DESCRIPTION");

	strcpy(text[1],"This project demonstrates a Christmas Scene Simulation.");

	strcpy(text[2],"The project is build using the OpenGL API and the source code is written in C.");

	strcpy(text[3],"The prime portion of this project concentrates on demonstration of realistic snowflakes and well animated christmas");

	strcpy(text[4],"characters and decorations. The lights of snow covered christmas tree and snowny mountains brings the desktop alive.");

	strcpy(text[5],"The movement of the snowman is in loop and need not be controlled by the user. The snowflakes falling feature can be");

	strcpy(text[6],"controlled by the user by pressing the 'a' key. The christmas tree is decorated with lights. The christmas presents ");

	strcpy(text[7],"have a 3-dimentional outlook and a wrapped cude rendering.");

	glColor3f(1,0,0);

	print_bitmap_string(-1,3.5,-7,text[0]);

	glColor3f(0,0,0);

	print_bitmap_string(-8,2.5,-7,text[1]);

	print_bitmap_string(-8,2,-7,text[2]);

	print_bitmap_string(-8,1,-7,text[3]);

	print_bitmap_string(-8,0.5,-7,text[4]);

	print_bitmap_string(-8,0,-7,text[5]);

	print_bitmap_string(-8,-0.5,-7,text[6]);

	print_bitmap_string(-8,-1,-7,text[7]);

}
*/


/****** Keyboard Functions *******/

/*

void mKeyboardFunc(unsigned char key, int x, int y){

    switch (key) {

        case 'a':

		case 'A':

                for(j=0; j <array_size ; j++){

                    snow[j][0] += 0.005;   // moving the snow in x direction

                    snow[j][1] -= 0.005;   // moving the snow in y direction

                }

                glutPostRedisplay();

                break;



        case 's' :

        case 'S' : flag = 2;

					glutPostRedisplay();

					break;



		case 'd':

		case 'D': flag = 3;

					glutPostRedisplay();

					break;



        case 'e':

        case 'E': exit(0);



        case 'w':

        case 'W': flag = 1;

					glutPostRedisplay();

					break;

		case 'q':

			break;



        }

}

*/

/***** Initializing the snow array ******/



void initSnow(){

    int i;

    for(i=0; i < array_size; i++){

        int r1 = rand()%6000;

        int r2 = rand()%1000;

        while(r2 < 50){

            r2 = rand()%1000;

        }

        snow[i][0] = r1*-0.01;//x co-ordinate

        snow[i][1] = r2*0.01;//y co-ordinate

    }

}





/***** Reshape function ******/



void resize(int w, int h){

   GLdouble size;

   GLdouble aspect;



   /* Use the whole window. */

   glViewport(0, 0, w, h);



   /* We are going to do some 2-D orthographic drawing. */

   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();



   GLfloat ar = (GLfloat)w/h;

   gluPerspective(45,ar,0.1,100);



   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

}





/***** Function to Draw Snow ******/



void drawSnow(){



    glColor3d(0.95, 0.95, 0.95); // Color of the snow

    srand(time(NULL));



    int i;

    for(i=0; i < array_size; i++){

        glPushMatrix();

            glTranslated(snow[i][0], snow[i][1], -4);

            glRotated(65, -1.0, 0.0, 0.8);

            glutSolidCube(0.015);

        glPopMatrix();

        glPushMatrix();

            glTranslated(-snow[i][0], snow[i][1], -4);

            glRotated(65, -1.0, 0.0, 0.8);

            glutSolidCube(0.015);

        glPopMatrix();

    }

}



/******* Funtion for Drawing lights on the tree ******/



void drawLights(){



    // Eight Lights on the tree



    glColor3d(l1-0.01,l2,l3);

    glPushMatrix();

        glTranslated(-0.3,0.5, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l2,l3+0.06,l1);

    glPushMatrix();

        glTranslated(0.3, 0.95, -5);

        glRotated(65, -1.0, 0.0, 0.5);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l1, l3, l2-0.05);

    glPushMatrix();

        glTranslated(0, 1.6, -5);

        glRotated(65, -1.0, 0.0, 0.5);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l2-0.04, l1+0.02, l3);

    glPushMatrix();

        glTranslated(0.4, 0.25, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l3+0.02, l1-0.08, l2-0.06);

    glPushMatrix();

        glTranslated(-0.2,0.05, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l3-0.04, l2+0.07, l1-0.07);

    glPushMatrix();

        glTranslated(-0.5,1, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l3+0.06,l1,l1);

    glPushMatrix();

        glTranslated(-0.1,1.2, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();



    glColor3d(l2, l3+0.02, l3-0.04);

    glPushMatrix();

        glTranslated(0.2, 0.55, -5);

        glRotated(65, -1.0, 0.0, 0.8);

        glutSolidCube(0.1);

    glPopMatrix();

}



/****** Function to Draw Snowman *******/



void drawSnowMan(GLfloat x , GLfloat y , GLfloat z){



    glColor3f(0.0,0.0,0.0);

    glPushMatrix();        // Eyes

        glTranslatef(x,y+0.8,z+0.5);

        glutSolidSphere(0.05, 200, 200);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(x +0.2,y+0.8,z + 0.5);

        glutSolidSphere(0.05, 200, 200);

    glPopMatrix();



    glColor3d(1, 0, 0);  // Nose

    glPushMatrix();

        glTranslatef(x+ 0.1,y + 0.65,z + 0.5);

        glRotatef(-260.0, 1.0, -1.5, 0.0);

        glutSolidCone(0.08, 0.2, 10, 2);

    glPopMatrix();



    glColor3f(1,1,1);  // Body Structure

    glPushMatrix();

	glTranslatef(x, y + 0.1, z );

        glutSolidSphere(0.55, 200, 200);

    glPopMatrix();

    glColor3f(1,1,1);

    glPushMatrix();

        glTranslatef(x, y - 0.99, z);

        glutSolidSphere(0.95, 200, 200);

    glPopMatrix();

    glColor3f(1,1,1);

    glPushMatrix();

        glTranslatef(x, y+0.7, z);

        glutSolidSphere(0.35, 200, 200);

    glPopMatrix();



}





/***** Function to draw the rotated snowman ******/



void rotatingSnowMan(){

    x = -2.7, y = 0.3  , z = -7;
//    a= 7.3,b=10.3,c=3;
//     a=x+10
    glPushMatrix();

    glTranslatef(x,y,z);

    glRotatef(angle,0.0,0.0,1.0);

    glTranslatef(-x,-y,-z);

    drawSnowMan(x,y,z);

   // drawSnowMan(x+10,y+10,z+10);

    glPopMatrix();

}





/****** Function to Draw the Tree ******/



void drawTree(){

    glColor3d(0.1, 0.5, 0.1);  // Tree color



    //Tree Cones

    glPushMatrix();

        glTranslated(0.0, 1.1, -6);

        glRotated(65, -1.0, 0.0, 0.0);

        glutSolidCone(0.85, 1.6, 100, 100);

    glPopMatrix();



    glPushMatrix();

        glTranslated(0.0,0.6,-6);

        glRotated(65, -1.0, 0.0, 0.0);

        glutSolidCone(0.9, 1.5, 100, 100);

    glPopMatrix();



    glPushMatrix();

        glTranslated(0.0,0.25,-6);

        glRotated(65, -1.0, 0.0, 0.0);

        glutSolidCone(0.95, 1.5, 100, 100);

    glPopMatrix();



    // Tree base

    glColor3d(0.29, 0.13, 0.13);

    glPushMatrix();

        glTranslated(0.0,-1.15,-6);

        glRotated(65, -1.0, 0.0, 0.0);

        gluCylinder(quadratic, 0.3f, 0.3f, 1.25f, 32, 32);

    glPopMatrix();



    // Tree shadow

    glColor3d(0.6, 0.6, 0.6);

    glPushMatrix();

        glTranslated(0.0,-0.8,-6);

        glRotated(70, -1.0, 0.0, 0.0);

        glutSolidTorus(0.33, 0.60, 200, 200);

    glPopMatrix();

}





/****** Function to Draw the ground/mountains ******/



void drawGround()

{

	//Upper Ground Circle

    glColor3f(0.93,0.94,0.94);

    glPushMatrix();

        glTranslatef(-7,-10,-12.5);

        glutSolidSphere(10,200, 1000);

    glPopMatrix();



    //Middle Ground Circle

    glColor3f(0.96,0.97,0.95);

    glPushMatrix();

        glTranslatef(1.5,-10,-10.5);

        glutSolidSphere(10,200, 1000);

    glPopMatrix();



    //Back Ground Circle

    glColor3f(0.91,0.92,0.90);

    glPushMatrix();

        glTranslatef(13,-10,-19.5);

        glutSolidSphere(10,200, 1000);

    glPopMatrix();



}





/***** Function to Draw Gifts *****/



void drawGifts()

{

	//Gift One

	glColor3f(1,0,0);

    glPushMatrix();

    glTranslatef(0,-0.62,-5);

    glRotatef(45,1,0,0);

    glRotatef(45,0,1,0);

    glutSolidCube(0.3);

    glPopMatrix();



    // Gift Two

    glColor3f(1,1,0);

    glPushMatrix();

    glTranslatef(0.5,-0.52,-5);

    glRotatef(45,1,0,0);

    glRotatef(45,0,1,0);

    glutSolidCube(0.3);

    glPopMatrix();



    // Gift Three

    glColor3f(0,1,0);

    glPushMatrix();

    glTranslatef(0.3,-1.00,-5);

    glRotatef(45,1,0,0);

    glRotatef(45,0,1,0);

    glutSolidCube(0.3);

    glPopMatrix();



    // Gift Four

    glColor3f(0,1,1);

    glPushMatrix();

    glTranslatef(-0.4,-0.9,-5);

    glRotatef(45,1,0,0);

    glRotatef(45,0,1,0);

    glutSolidCube(0.3);

    glPopMatrix();

}





/** Draws the border of the gifts **/



void drawGiftsLine(){



	glColor3f(1,1,1); // Line Color



	// line for gift one (RED BOX)

	glPushMatrix();

	glLineWidth(2);

	glTranslatef(0,-0.53,-1.03);

	glBegin(GL_LINES);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0,-0.054,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0.13,0.165,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(-0.13,0.165,-2.1);

	glEnd();

	glPopMatrix();



	//line for gift two (YELLOW BOX)

	glPushMatrix();

	glLineWidth(2);

	glTranslatef(0.345,-0.453,-1.03);

	glBegin(GL_LINES);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0,-0.054,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0.13,0.165,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(-0.13,0.165,-2.1);

	glEnd();

	glPopMatrix();



	//line for gift three (GREEN BOX)

	glPushMatrix();

	glLineWidth(2);

	glTranslatef(0.21,-0.79,-1.03);

	glBegin(GL_LINES);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0,-0.054,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0.13,0.165,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(-0.13,0.165,-2.1);

	glEnd();

	glPopMatrix();



	//line for gift three (FIROZI BOX)

	glPushMatrix();

	glLineWidth(2);

	glTranslatef(-0.278,-0.726,-1.03);

	glBegin(GL_LINES);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0,-0.054,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(0.13,0.165,-2.1);

		glVertex3f(0,0.082,-2.1);		// origin pt of the box border

		glVertex3f(-0.13,0.165,-2.1);

	glEnd();

	glPopMatrix();

}





/****** Display Function *******/


/*
void display(void){

	glClearColor(0.45,0.45,1.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0,0,1,0,0,0,0,1,0);

    drawGround();

    rotatingSnowMan();

    drawTree();

    drawSnow();

    drawLights();

    drawGiftsLine();

    drawGifts();

}

*/

/****** Idle Function which rotates the snowman ******/



void idle(){



   if(right){

       angle += 0.9f ;

       if(angle > 7.0f)

	    right = false;

   }



   if(!right){

	angle -= 0.9f;

	if(angle  < -4.0f)

	    right = true;

   }



   srand(time(NULL));

   l1 = ((float) (rand()) / (float) (RAND_MAX));	  // randomizing

   l2 = ((float) (rand()) / (float) (RAND_MAX))*0.99; // color of the

   l3 = ((float) (rand()) / (float) (RAND_MAX));      // lights



   glutPostRedisplay();



}





/**** Function to set flag value to switch b/w different windows *****/


/*
void scene(){

		if(flag == 1){

			glutIdleFunc(NULL);		// Flag Value for welcome screen

			welcome_screen();

		}



		if(flag == 2){



			glutIdleFunc(idle);

			display();			// Flag value for the christmas scene

		}



		if(flag == 3){

		glutIdleFunc(NULL);

		descscreen();			// Flag Value for the description screen

		}



		glFlush();

}

*/



/******* MAIN FUNCTION *******/


/*
int main(int argc, char *argv[]){



    // Initializations



    glutInit(&argc, argv);

    glutInitWindowSize(1200, 600); // window size

    glutInitWindowPosition(50,40); // window position

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

    glutCreateWindow("Christmas");



    quadratic = gluNewQuadric();



    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST); //enabling z-buffer



    // Function Calls



    glutReshapeFunc(resize);

//    glutDisplayFunc(scene);

    glDepthFunc(GL_LESS);

    glutFullScreen();			// fullscreen view of the program

    glutKeyboardFunc(mKeyboardFunc);

    initSnow();



*/





/*

void print_bitmap_string(float x, float y, float z, char* s)

{

   int i;

   GLvoid* font_style=GLUT_BITMAP_TIMES_ROMAN_24; // font name

   int len=(int) strlen (s);

   glPushMatrix();

   glRasterPos3f(x,y,z);

   for(i=0;i<len;i++){

         glutBitmapCharacter(font_style, s[i]);

	}



    glPopMatrix();


}*/

void displayNewWinDiwali();
void next();

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

void renderbitmap(float x,float y,void *font,char *string)
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c!='\0'; c++)
    {
        glutBitmapCharacter(font,*c);
    }
}







void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0; i<100; i++)

    {
        float angle = 4.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

void all()
{
    glOrtho(-0.05, 0.85, -0.05, 0.40, 0.0, 10.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
   // glutFullScreen();
//top green color part on the building backgound
    glColor3f (0.204,0.51,0.204);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.00f, 0.0f);

//Sky part
    glColor3f (0.1,0.03,0.2);  //sky color dark blue
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glEnd();
//cloud and sun
    //loop for sun
    if(s<=0.95)
        s=s+.00002;
    else
        s=-0.00000005;

    if(u<=0.40)
        u=u+.000002;
    else
        u=-0.00000005;
    glutPostRedisplay();

    glColor3f(1.0, 1.0, 1.0);    //this is white moon //yellow is(1,1,0)
    circle(0.05,0.05,s-0.05, u+0.25);
    //1st sky cloud motion

        if(m<=2.0)
        m=m+.000035;
    else
        m=-0.0000005;
    //3rd sky  cloud motion
    if(n<=2.0)
        n=n+.00015;
    else
        n=-0.0000003;

    //2nd sky cloud motion
    if(o<=2.0)
        o=o+.000005;
    else
        o=-0.0000005;

    //sky cloud 1
    glColor3f(0.3, 0.5, 0.7); //cloud color
    circle(0.03,0.03,m-0.04, 0.28);
    circle(0.03,0.03,m-0.055, 0.29);
    circle(0.03,0.03,m-0.07, 0.295);
    circle(0.03,0.03,m-.02, 0.29);
    circle(0.03,0.03,m-0.05, 0.31);

  //sky cloud 2
    circle(0.03,0.03,o-.44, 0.35);
    circle(0.03,0.03,o-0.455, 0.36);
    circle(0.03,0.03,o-0.47, 0.365);
    circle(0.03,0.03,o-.42, 0.36);
    circle(0.03,0.03,o-0.45, 0.38);
    //sky cloud 3
   circle(0.03,0.03,n-0.74, 0.31);
    circle(0.03,0.03,n-0.755, 0.32);
    circle(0.03,0.03,n-0.77, 0.325);
    circle(0.03,0.03,n-0.72, 0.32);
    circle(0.03,0.03,n-0.75, 0.354);
/*
//first building
    glBegin(GL_QUADS);
    glColor3f (0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);
//first building side
    glColor3f (0.196078, 0.803922, 0.196078);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.25f, 0.0f);
    glVertex3f(0.04f, 0.23f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.08f, 0.0f);
    glVertex3f(0.13f, 0.12f, 0.0f);
    glVertex3f(0.07f, 0.12f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.15f, 0.0f);
    glVertex3f(0.13f, 0.19f, 0.0f);
    glVertex3f(0.07f, 0.19f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.07f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.21f, 0.0f);
    glVertex3f(0.13f, 0.24f, 0.0f);
    glVertex3f(0.07f, 0.24f, 0.0f);
*/
/*
//2nd building
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(0.15f, 0.05f, 0.0f);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.05f, 0.0f);

// 2nd building windows by floor sequence
//2nd building 1st floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.07f, 0.0f);
    glVertex3f(0.19f, 0.09f, 0.0f);
    glVertex3f(0.16f, 0.09f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.07f, 0.0f);
    glVertex3f(0.24f, 0.09f, 0.0f);
    glVertex3f(0.21f, 0.09f, 0.0f);

//2nd building 2nd floor.

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.12f, 0.0f);
    glVertex3f(0.19f, 0.14f, 0.0f);
    glVertex3f(0.16f, 0.14f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.12f, 0.0f);
    glVertex3f(0.24f, 0.14f, 0.0f);
    glVertex3f(0.21f, 0.14f, 0.0f);
//2nd building 3rd floor.
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.17f, 0.0f);
    glVertex3f(0.19f, 0.19f, 0.0f);
    glVertex3f(0.16f, 0.19f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.21f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.17f, 0.0f);
    glVertex3f(0.24f, 0.19f, 0.0f);
    glVertex3f(0.21f, 0.19f, 0.0f);

//2nd building 4th floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.22f, 0.0f);
    glVertex3f(0.19f, 0.24f, 0.0f);
    glVertex3f(0.16f, 0.24f, 0.0f);

    glVertex3f(0.21f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.22f, 0.0f);
    glVertex3f(0.24f, 0.24f, 0.0f);
    glVertex3f(0.21f, 0.24f, 0.0f);
//2nd building 5th floor
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.16f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.27f, 0.0f);
    glVertex3f(0.19f, 0.29f, 0.0f);
    glVertex3f(0.16f, 0.29f, 0.0f);

    glVertex3f(0.21f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.27f, 0.0f);
    glVertex3f(0.24f, 0.29f, 0.0f);
    glVertex3f(0.21f, 0.29f, 0.0f);

//3rd building
    glColor3f (0 ,0,0);
    glVertex3f(0.25f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.32f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
//3rd building windows
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.07f, 0.0f);
    glVertex3f(0.29f, 0.13f, 0.0f);
    glVertex3f(0.26f, 0.13f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.17f, 0.0f);
    glVertex3f(0.29f, 0.23f, 0.0f);
    glVertex3f(0.26f, 0.23f, 0.0f);

    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.26f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.26f, 0.0f);
    glVertex3f(0.29f, 0.30f, 0.0f);
    glVertex3f(0.26f, 0.30f, 0.0f);

    // last border black on building footer
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.04f, 0.05f, 0.0f);
    glVertex3f(0.04f, 0.06f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.05f, 0.04f, 0.0f);

    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.05f, 0.04f, 0.0f);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.05f, 0.0f);
    glVertex3f(0.30f, 0.04f, 0.0f);
    glEnd();

    glBegin(GL_LINES);

//1st building win 1
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.08f ,0.0f );
    glVertex3f( 0.10f, 0.12f ,0.0f );
//sideline 1 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.05f, 0.05f ,0.0f );
    glVertex3f( 0.05f, 0.25f ,0.0f );

//sideline 2 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.05f ,0.0f );
    glVertex3f( 0.15f, 0.30f ,0.0f );
//sideline 1 building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.25f, 0.05f ,0.0f );
    glVertex3f( 0.25f, 0.32f ,0.0f );

// 1st building win 2
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.15f ,0.0f );
    glVertex3f( 0.10f, 0.19f ,0.0f );
//1st building win 3
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.10f, 0.21f ,0.0f );
    glVertex3f( 0.10f, 0.24f ,0.0f );
// 2nd building 1st floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.10f ,0.0f );
    glVertex3f( 0.25f, 0.10f ,0.0f );
// 2nd building 2nd floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.15f ,0.0f );
    glVertex3f( 0.25f, 0.15f ,0.0f );
// 2nd floor 3rd floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.20f ,0.0f );
    glVertex3f( 0.25f, 0.20f ,0.0f );
// 2nd floor 4th floor
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.15f, 0.25f ,0.0f );
    glVertex3f( 0.25f, 0.25f ,0.0f );

//3rd building
    glColor3f(0.0 ,0.0,0.0);
    glVertex3f( 0.25f, 0.14f ,0.0f );
    glVertex3f( 0.30f, 0.14f ,0.0f );

    glVertex3f( 0.25f, 0.24f ,0.0f );
    glVertex3f( 0.30f, 0.24f ,0.0f );
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f (0.5, 0.0, 0.0);
    glVertex3f(0.15f, 0.30f, 0.0f);
    glVertex3f(0.06f, 0.25f, 0.0f);
    glVertex3f(0.15f, 0.26f, 0.0f);

    glColor3f (0.4, 0.4, 0.4);
    glVertex3f(0.25f, 0.30f, 0.0f);
    glVertex3f(0.25f, 0.32f, 0.0f);
    glVertex3f(0.22f, 0.30f, 0.0f);
    glEnd();
*/
    glBegin(GL_QUADS);
    //black font Road here
    glColor3f (0.4, 0.4, 0.4);
    glVertex3f(-0.05f, -0.05f, 0.0f);
    glVertex3f(-0.05f, 0.03f, 0.0f);
    glVertex3f(0.90f, 0.03f, 0.0f);
    glVertex3f(0.90f, -0.05f, 0.0f);

    // road devider1
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(-0.05f, -0.01f, 0.0f);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.02f, 0.0f, 0.0f);
    glVertex3f(-0.02f, -0.01f, 0.0f);
// road devider2
    glVertex3f(0.03f, 0.0f, 0.0f);
    glVertex3f(0.03f, -0.01f, 0.0f);
    glVertex3f(0.08f, -0.01f, 0.0f);
    glVertex3f(0.08f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.13f, 0.0f, 0.0f);
    glVertex3f(0.13f, -0.01f, 0.0f);
    glVertex3f(0.18f, -0.01f, 0.0f);
    glVertex3f(0.18f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.23f, 0.0f, 0.0f);
    glVertex3f(0.23f, -0.01f, 0.0f);
    glVertex3f(0.28f, -0.01f, 0.0f);
    glVertex3f(0.28f, 0.0f, 0.0f);

// road devider4
    glVertex3f(0.33f, 0.0f, 0.0f);
    glVertex3f(0.33f, -0.01f, 0.0f);
    glVertex3f(0.38f, -0.01f, 0.0f);
    glVertex3f(0.38f, 0.0f, 0.0f);
// road devider5
    glVertex3f(0.43f, 0.0f, 0.0f);
    glVertex3f(0.43f, -0.01f, 0.0f);
    glVertex3f(0.48f, -0.01f, 0.0f);
    glVertex3f(0.48f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.53f, 0.0f, 0.0f);
    glVertex3f(0.53f, -0.01f, 0.0f);
    glVertex3f(0.58f, -0.01f, 0.0f);
    glVertex3f(0.58f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.63f, 0.0f, 0.0f);
    glVertex3f(0.63f, -0.01f, 0.0f);
    glVertex3f(0.68f, -0.01f, 0.0f);
    glVertex3f(0.68f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.73f, 0.0f, 0.0f);
    glVertex3f(0.73f, -0.01f, 0.0f);
    glVertex3f(0.78f, -0.01f, 0.0f);
    glVertex3f(0.78f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.83f, 0.0f, 0.0f);
    glVertex3f(0.83f, -0.01f, 0.0f);
    glVertex3f(0.88f, -0.01f, 0.0f);
    glVertex3f(0.88f, 0.00f, 0.0f);
    glEnd();
    glBegin(GL_QUADS);
    // bus stand
    glColor3f (0.0, 0.05, 1.0);
    glVertex3f(-0.05f, 0.16f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(0.00f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);

//bus stand upper corner
    glColor3f (0, 0, 0);
    glVertex3f(-0.05f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.15f, 0.0f);
    glVertex3f(0.03f, 0.16f, 0.0f);
    glVertex3f(-0.05f, 0.16f, 0.0f);

//bus stand lower corner
    glColor3f (0.3, 0.3, 0.3);
    glVertex3f(-0.05f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.12f, 0.0f);
    glVertex3f(0.01f, 0.05f, 0.0f);
    glVertex3f(-0.05f, 0.05f, 0.0f);

// bus stand large pillar
    glColor3f (0, 0, 0);
    glVertex3f(0.0f, 0.05f, 0.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.15f, 0.0f);
    glVertex3f(-0.01f, 0.05f, 0.0f);

// bus stand small pillar
    glColor3f (0, 0, 0);
    glVertex3f(-0.02f, 0.10f, 0.0f);
    glVertex3f(-0.02f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.15f, 0.0f);
    glVertex3f(-0.03f, 0.10f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);

    //clubhouse frame beside house
    glColor3f (1.0, 0.0, 1.0);
    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);

    //clubshouse frame upper
    glColor3f (0.255,0.102,0.255);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    //clubhouse frame sider
    glColor3f (0.51,0.255,0.255);
    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);


    //windows clubhouse in row 1
    glColor3f (1,1,1);
    glVertex3f(0.60f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.10f, 0.0f);
    glVertex3f(0.62f, 0.12f, 0.0f);
    glVertex3f(0.60f, 0.12f, 0.0f);

    glVertex3f(0.60f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.13f, 0.0f);
    glVertex3f(0.62f, 0.15f, 0.0f);
    glVertex3f(0.60f, 0.15f, 0.0f);

    //windows clubhouse in row 2
    glColor3f (1,1,1);
    glVertex3f(0.63f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.10f, 0.0f);
    glVertex3f(0.65f, 0.12f, 0.0f);
    glVertex3f(0.63f, 0.12f, 0.0f);

    glVertex3f(0.63f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.13f, 0.0f);
    glVertex3f(0.65f, 0.15f, 0.0f);
    glVertex3f(0.63f, 0.15f, 0.0f);

    //windows clubhouse in row 3
    glColor3f (1,1,1);
    glVertex3f(0.66f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.10f, 0.0f);
    glVertex3f(0.68f, 0.12f, 0.0f);
    glVertex3f(0.66f, 0.12f, 0.0f);

    glVertex3f(0.66f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.13f, 0.0f);
    glVertex3f(0.68f, 0.15f, 0.0f);
    glVertex3f(0.66f, 0.15f, 0.0f);

    //windows clubhouse in row 4
    glColor3f (1,1,1);
    glVertex3f(0.69f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.10f, 0.0f);
    glVertex3f(0.71f, 0.12f, 0.0f);
    glVertex3f(0.69f, 0.12f, 0.0f);

    glVertex3f(0.69f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.13f, 0.0f);
    glVertex3f(0.71f, 0.15f, 0.0f);
    glVertex3f(0.69f, 0.15f, 0.0f);

    //windows clubhouse in row 5
    glColor3f (1,1,1);
    glVertex3f(0.73f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.10f, 0.0f);
    glVertex3f(0.75f, 0.12f, 0.0f);
    glVertex3f(0.73f, 0.12f, 0.0f);

    glVertex3f(0.73f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.13f, 0.0f);
    glVertex3f(0.75f, 0.15f, 0.0f);
    glVertex3f(0.73f, 0.15f, 0.0f);


    //clubhouse door
    glColor3f (1,1,1);
    glVertex3f(0.65f, 0.05f, 0.0f);
    glVertex3f(0.65f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.08f, 0.0f);
    glVertex3f(0.70f, 0.05f, 0.0f);

    glEnd();
    glBegin(GL_LINES);
    // clubhouse lines
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.80f, 0.20f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.55f, 0.20f, 0.0f);
    glVertex3f(0.60f, 0.22f, 0.0f);

    glVertex3f(0.60f, 0.22f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.20f, 0.0f);

    glVertex3f(0.84f, 0.07f, 0.0f);
    glVertex3f(0.84f, 0.22f, 0.0f);

    glVertex3f(0.80f, 0.05f, 0.0f);
    glVertex3f(0.84f, 0.07f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.80f, 0.05f, 0.0f);

    glVertex3f(0.55f, 0.05f, 0.0f);
    glVertex3f(0.55f, 0.20f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    //shohid miner ground

    glColor3f (1.0, 0.5, .0);
    glVertex3f(0.35f, 0.10f, 0.0f);
    glVertex3f(0.32f, 0.20f, 0.0f);
    glVertex3f(0.53f, 0.20f, 0.0f);
    glVertex3f(0.50f, 0.10f, 0.0f);
    //minar 1
    //left piller
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.34f, 0.17f, 0.0f);
    glVertex3f(0.35f, 0.17f, 0.0f);
    glVertex3f(0.35f, 0.22f, 0.0f);
    glVertex3f(0.34f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.36f, 0.17f, 0.0f);
    glVertex3f(0.37f, 0.17f, 0.0f);
    glVertex3f(0.37f, 0.22f, 0.0f);
    glVertex3f(0.36f, 0.22f, 0.0f);
    //upper piller
    glVertex3f(0.34f, 0.22f, 0.0f);
    glVertex3f(0.34f, 0.23f, 0.0f);
    glVertex3f(0.37f, 0.23f, 0.0f);
    glVertex3f(0.37f, 0.22f, 0.0f);
    glEnd();
    //background red color
    glColor3f (1.0, 0.0, 0.0);
    circle(0.03,0.03,0.425, 0.21);
    //main miner(miner 2)
    //left piller
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(0.40f, 0.17f, 0.0f);
    glVertex3f(0.41f, 0.17f, 0.0f);
    glVertex3f(0.41f, 0.22f, 0.0f);
    glVertex3f(0.40f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.44f, 0.17f, 0.0f);
    glVertex3f(0.45f, 0.17f, 0.0f);
    glVertex3f(0.45f, 0.22f, 0.0f);
    glVertex3f(0.44f, 0.22f, 0.0f);

    //up1
    glVertex3f(0.40f, 0.22f, 0.0f);
    glVertex3f(0.39f, 0.24f, 0.0f);
    glVertex3f(0.40f, 0.24f, 0.0f);
    glVertex3f(0.41f, 0.22f, 0.0f);
    //up2
    glVertex3f(0.44f, 0.22f, 0.0f);
    glVertex3f(0.43f, 0.24f, 0.0f);
    glVertex3f(0.44f, 0.24f, 0.0f);
    glVertex3f(0.45f, 0.22f, 0.0f);
    //up vertical
    glVertex3f(0.39f, 0.24f, 0.0f);
    glVertex3f(0.39f, 0.25f, 0.0f);
    glVertex3f(0.44f, 0.25f, 0.0f);
    glVertex3f(0.44f, 0.24f, 0.0f);

    //minar 2
    //left piller
    glVertex3f(0.47f, 0.17f, 0.0f);
    glVertex3f(0.48f, 0.17f, 0.0f);
    glVertex3f(0.48f, 0.22f, 0.0f);
    glVertex3f(0.47f, 0.22f, 0.0f);
    //right piller
    glVertex3f(0.50f, 0.17f, 0.0f);
    glVertex3f(0.51f, 0.17f, 0.0f);
    glVertex3f(0.51f, 0.22f, 0.0f);
    glVertex3f(0.50f, 0.22f, 0.0f);
    //upper piller
    glVertex3f(0.47f, 0.22f, 0.0f);
    glVertex3f(0.47f, 0.23f, 0.0f);
    glVertex3f(0.51f, 0.23f, 0.0f);
    glVertex3f(0.51f, 0.22f, 0.0f);
    glEnd();

    //glClear(GL_COLOR_BUFFER_BIT);
    if(p<=2.0)
        p=p+.0002;
    else
        p=-0.00000005;
    glutPostRedisplay();
    //glutOverlayDisplayFunc();
    glBegin(GL_QUADS); //upper body
    glColor3f(1.0,0.0,0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
    glColor3f(1.0,0.0,0);
    glVertex3f(p-0.05,-0.015,0);
    glVertex3f(p-0.05,0.025,0);
    glVertex3f(p+0.16,0.025,0);
    glVertex3f(p+0.16,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p-0.01,0.02,0);

    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glVertex3f(p+0.125,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0,0.0,0);
    glVertex3f(p+0.01,0.03,0);
    glVertex3f(p+0.025,0.05,0);
    glVertex3f(p+0.05,0.05,0);
    glVertex3f(p+0.05,0.03,0);
    //windows 2
    glVertex3f(p+0.06,0.03,0);
    glVertex3f(p+0.06,0.05,0);
    glVertex3f(p+0.08,0.05,0);
    glVertex3f(p+0.095,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    circle(0.02,0.02,p+0.0, -0.01); //tier 1
    circle(0.02,0.02,p+0.10, -0.01); //tier 2


    /*car2*/
/*
    glBegin(GL_QUADS); //upper body
    glColor3f(0.255,0.102,0.255);
    glVertex3f(p-0.31,0.06,0);
    glVertex3f(p-0.31,0.02,0);
    glVertex3f(p-0.40,0.02,0);
    glVertex3f(p-0.40,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
    glVertex3f(p-0.46,-0.015,0);
    glVertex3f(p-0.46,0.025,0);
    glVertex3f(p-0.25,0.025,0);
    glVertex3f(p-0.25,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p-0.31,0.02,0);
    glVertex3f(p-0.31,0.06,0);
    glVertex3f(p-0.29,0.02,0);

    glVertex3f(p-0.40,0.02,0);
    glVertex3f(p-0.40,0.06,0);
    glVertex3f(p-0.425,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0,0.0,0);
    glVertex3f(p-0.31,0.03,0);
    glVertex3f(p-0.325,0.05,0);
    glVertex3f(p-0.35,0.05,0);
    glVertex3f(p-0.35,0.03,0);
    //windows 2
    glVertex3f(p-0.36,0.03,0);
    glVertex3f(p-0.36,0.05,0);
    glVertex3f(p-0.38,0.05,0);
    glVertex3f(p-0.395,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    circle(0.02,0.02,p-0.30, -0.01); //tier 1
    circle(0.02,0.02,p-0.40, -0.01); //tier 2
*/
    //bus
    glBegin(GL_QUADS); //lower body
    glColor3f(0.0 ,0.0, 1.0);
    glVertex3f(p-0.55,-0.02,0);
    glVertex3f(p-0.55,0.05,0);
    glVertex3f(p-0.75,0.05,0);
    glVertex3f(p-0.75,-0.02,0);
    //upper body

    glVertex3f(p-0.75,0.08,0);
    glVertex3f(p-0.75,0.05,0);
    glVertex3f(p-0.55,0.05,0);
    glVertex3f(p-0.55,0.08,0);


    //windows 1
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.56,0.02,0);
    glVertex3f(p-0.56,0.07,0);
    glVertex3f(p-0.59,0.07,0);
    glVertex3f(p-0.59,0.02,0);
    //windows 2
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.60,0.02,0);
    glVertex3f(p-0.60,0.07,0);
    glVertex3f(p-0.63,0.07,0);
    glVertex3f(p-0.63,0.02,0);

    //windows 3
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.64,0.02,0);
    glVertex3f(p-0.64,0.07,0);
    glVertex3f(p-0.67,0.07,0);
    glVertex3f(p-0.67,0.02,0);
    //windows 4
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.68,0.02,0);
    glVertex3f(p-0.68,0.07,0);
    glVertex3f(p-0.71,0.07,0);
    glVertex3f(p-0.71,0.02,0);
    //windows 5
    glColor3f(1.0,1.0,1);
    glVertex3f(p-0.72,0.02,0);
    glVertex3f(p-0.72,0.07,0);
    glVertex3f(p-0.735,0.07,0);
    glVertex3f(p-0.735,0.02,0);


    glEnd();

    //tier1
    glColor3f(0.0,0.0,0);
    circle(0.025,0.025,p-0.60, -0.01); //tier 1
    circle(0.025,0.025,p-0.70, -0.01); //tier 2
//    person();

    PlaySound("firecracker.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    glFlush();
    glutSwapBuffers();
}

void diwtext()
{

     glColor3f(1.0, 0.0, 0.5);
	displayRasterText(-190, 490, 0.0,"HAPPY DIWALI");


	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	displayRasterTextsmall(-120, -500, 0.0,"PRESS B FOR BACK");
//   drawDiwaliLamp();
}


//////christmass festival



void circlePerson(float x, float y, float radius){
    int i;
	int triangleAmount = 500;


	float twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y +1.2*(radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void person(float x,float y){
    glColor3f(0, 0, 0);
    circlePerson(x,y,0.02);
    glLineWidth(2);
    glBegin(GL_LINES);
        //body
        glVertex2f(x,y);
        glVertex2f(x,y-0.18);
        //legs
        glVertex2f(x,y-0.18);
        glVertex2f(x-0.03,y-0.25);
        glVertex2f(x,y-0.18);
        glVertex2f(x+0.03,y-0.25);
        //hands
        glVertex2f(x,y-0.09);
        glVertex2f(x-0.05,y-0.14);
        glVertex2f(x,y-0.09);
        glVertex2f(x+0.05,y-0.14);
    glEnd();
}

void init()
{
	//glClearColor(0.3,0.2,0.3,0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glOrtho(-1200,1200,-700,700,0,50);                   //<-----CHANGE THIS TO GET EXTRA SPACE
//  gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);

}



void introScreen()
{
    glClearColor(0.3,0.2,0.3,0);
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
void mousefirstscreen(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
//std::cout << x << std::endl;
//std::cout << y << std::endl;
    if(x >= 400 && x <= 400 && (y>=600&&y<=500)) {
        glutCreateWindow("diwali");
        glutDisplayFunc(displayNewWinDiwali);
       }

    glutPostRedisplay();
     }
}

void displayNewWin1(){
    glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_COLOR_BUFFER_BIT);

       glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
   // drawDiwaliLamp();

   // glClearColor(0.3,0.2,0.3,0);

    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, 400, 0.0,"DIWALI IS A FETSIVAL OF LIGHTS                                      ");

	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, 100, 0.0,"HOLI IS THE FESTIVAL OF COLOURS                                  ");

	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	displayRasterText(-900, -200, 0.0,"CHRISTMAS CELEBRATE'S BIRTH OF JESUS CHRIST     ");

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	displayRasterTextsmall(-120, -500, 0.0,"PRESS F FOR BACK");


	glRectf(400,400,600,500);
    glColor3f(1.0f, 0.0f, 1.0f);
    renderbitmap(450,450,GLUT_BITMAP_TIMES_ROMAN_24,"Diwali");
    next();
    glEnd();
    glFlush();
    glutMouseFunc(mousefirstscreen);
	//glutPostRedisplay();
 	//glutSwapBuffers();


}
void next()
{
     glColor3f(1.0f,0.3f,0.3f);

   glPushMatrix();

       glRectf(2,10,20,-2);
       glColor3f(1.0f, 1.0f, 1.0f);
    renderbitmap(700,300,GLUT_BITMAP_TIMES_ROMAN_24,"Next");
}

//back button code
void backbtn()
{
     glColor3f(1.0f,0.0f,0.3f);

   glPushMatrix();

       glRectf(-25,10,-5,-2);
       glColor3f(1.0f, 1.0f, 1.0f);
    renderbitmap(-18,3,GLUT_BITMAP_TIMES_ROMAN_24,"Back");

}





void display()
{

	//glClear(GL_COLOR_BUFFER_BIT);

    introScreen();

  //startScreenDisplay();
    // displayNewWinDiwali();
    glEnd();
	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
	//backbtn();
    //next();
}






void displayNewWinDiwali()
{

    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(0.1,0.03,0.2,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    diwtext();

    all();


    glutPostRedisplay();
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

void displayNewWinChristmas(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
   // glClear(GL_COLOR_BUFFER_BIT);
     //  glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
   // glColor3f(1.0, 0.0, 0.5);
	//displayRasterText(-190, 490, 0.0,"HAPPY CHRISTMAS");

	glClearColor(0.45,0.45,1.0,1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluLookAt(0,0,1,0,0,0,0,1,0);

    drawGround();

    rotatingSnowMan();

    drawTree();

    drawSnow();

    drawLights();

    drawGiftsLine();

    drawGifts();




	//glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

	//displayRasterTextsmall(-120, -500, 0.0,"PRESS B FOR BACK");
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
void keys(unsigned char key,int A,int B)
{

    if(key=='A'||key=='a')
    {
        glutDisplayFunc(displayNewWin1);

    }
    if(key=='F'||key=='f')
    {
        glutDisplayFunc(display);
    }
     if (key=='D'|| key=='d')
    {
        glutDisplayFunc(displayNewWinDiwali);

    }
    if (key=='H'|| key=='h')
    {
        glutDisplayFunc(displayNewWinHoli);

    }
    if (key=='C'|| key=='c')
    {
        glutDisplayFunc(displayNewWinChristmas);

    }
    if (key=='B'|| key=='b')
    {
        glutPostRedisplay();

        glutDisplayFunc(displayNewWin1);


    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Festivals of India");
    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keys);

//    glutReshapeFunc(reshape);

glutMainLoop();


    // Function Calls

    quadratic = gluNewQuadric();



    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST); //enabling z-buffer


    glutReshapeFunc(resize);

//    glutDisplayFunc(scene);

    glDepthFunc(GL_LESS);

    //glutFullScreen();			// fullscreen view of the program

//    glutKeyboardFunc(mKeyboardFunc);

    initSnow();
}
