/*//#include <GL/glut.h>
#ifdef _WIN32
#include<windows.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

float window_position = 0.1; // initial position of window
bool window_open = false; // flag for window state

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   // draw house walls
   glBegin(GL_QUADS);
   glVertex3f(-0.5, -0.5, -0.5);
   glVertex3f(-0.5, 0.5, -0.5);
   glVertex3f(-0.5, 0.5, 0.5);
   glVertex3f(-0.5, -0.5, 0.5);
   glEnd();

   // draw roof
   glBegin(GL_TRIANGLES);
   glVertex3f(-0.6, 0.5, -0.5);
   glVertex3f(-0.4, 0.5, -0.5);
   glVertex3f(-0.5, 0.7, -0.5);
   glEnd();

   // draw door
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_QUADS);
   glVertex3f(-0.5, -0.5, -0.51);
   glVertex3f(-0.5, -0.2, -0.51);
   glVertex3f(-0.5, -0.2, 0.1);
   glVertex3f(-0.5, -0.5, 0.1);
   glEnd();

   // draw window
   if (window_open) {
      glColor3f(1.0, 1.0, 0.0); // yellow color for open window
   } else {
      glColor3f(0.0, 0.0, 1.0); // blue color for closed window
   }
   glBegin(GL_QUADS);
   glVertex3f(-0.5, window_position + 0.1, -0.51);
   glVertex3f(-0.5, window_position + 0.3, -0.51);
   glVertex3f(-0.5, window_position + 0.3, 0.1);
   glVertex3f(-0.5, window_position + 0.1, 0.1);
   glEnd();

   glFlush();
}

void keyboard(unsigned char key, int x, int y) {
   switch(key) {
      case 'o': // open window
         window_position = 0.3; // move window up
         window_open = true; // set flag to true
         break;
      case 'c': // close window
         window_position = 0.1; // move window down
         window_open = false; // set flag to false
         break;
   }
   glutPostRedisplay(); // redraw the window
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("House Side View");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard); // set keyboard callback function
   glutMainLoop();
   return 0;
}
*/
/*
#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   // draw house walls
   glBegin(GL_QUADS);
   glVertex2f(-0.8, -0.5);
   glVertex2f(-0.8, 0.5);
   glVertex2f(-0.2, 0.5);
   glVertex2f(-0.2, -0.5);
   glEnd();

   // draw roof
   glBegin(GL_TRIANGLES);
   glVertex2f(-0.9, 0.5);
   glVertex2f(-0.1, 0.5);
   glVertex2f(-0.5, 0.9);
   glEnd();

   // draw door
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_QUADS);
   glVertex2f(-0.4, -0.5);
   glVertex2f(-0.4, 0.2);
   glVertex2f(-0.6, 0.2);
   glVertex2f(-0.6, -0.5);
   glEnd();

   // draw window
   glBegin(GL_QUADS);
   glVertex2f(-0.7, 0.1);
   glVertex2f(-0.7, 0.3);
   glVertex2f(-0.5, 0.3);
   glVertex2f(-0.5, 0.1);
   glEnd();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("House Side View");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}


*/
/*

#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   // draw house walls
   glBegin(GL_QUADS);
   glVertex3f(-0.5, -0.5, -0.5);
   glVertex3f(-0.5, 0.5, -0.5);
   glVertex3f(-0.5, 0.5, 0.5);
   glVertex3f(-0.5, -0.5, 0.5);
   glEnd();

   // draw roof
   glBegin(GL_TRIANGLES);
   glVertex3f(-0.6, 0.5, -0.5);
   glVertex3f(-0.4, 0.5, -0.5);
   glVertex3f(-0.5, 0.7, -0.5);
   glEnd();

   // draw door
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_QUADS);
   glVertex3f(-0.5, -0.5, -0.51);
   glVertex3f(-0.5, -0.2, -0.51);
   glVertex3f(-0.5, -0.2, 0.1);
   glVertex3f(-0.5, -0.5, 0.1);
   glEnd();

   // draw window
   glBegin(GL_QUADS);
   glVertex3f(-0.5, 0.1, -0.51);
   glVertex3f(-0.5, 0.3, -0.51);
   glVertex3f(-0.5, 0.3, 0.1);
   glVertex3f(-0.5, 0.1, 0.1);
   glEnd();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("House Side View");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
*/

/* firework1
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

void drawParticle(float x, float y) {
  glBegin(GL_QUADS);
  glVertex2f(x-2, y-2);
  glVertex2f(x+2, y-2);
  glVertex2f(x+2, y+2);
  glVertex2f(x-2, y+2);
  glEnd();
}

void drawFirework(float x, float y, float r, float g, float b) {
  int numParticles = 20;
  float radius = 10.0;

  glPointSize(2.0);
  glColor3f(r, g, b);

  for (int i = 0; i < numParticles; i++) {
    float angle = 2 * 3.14159 * i / numParticles;
    float px = x + radius * cos(angle);
    float py = y + radius * sin(angle);
    drawParticle(px, py);
  }
}

void launchFirework() {
  float x = rand() % 400 + 50;
  float y = rand() % 400 + 50;
  float velX = (rand() % 10 - 5) / 10.0;
  float velY = (rand() % 10 + 5) / 10.0;
  float r = (rand() % 100) / 100.0;
  float g = (rand() % 100) / 100.0;
  float b = (rand() % 100) / 100.0;

  drawFirework(x, y, r, g, b);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  launchFirework();

  glutSwapBuffers();
}

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Fireworks");

  srand(time(NULL));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 500, 0, 500, -1, 1);
  glMatrixMode(GL_MODELVIEW);

  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);

  glutMainLoop();

  return 0;
}
*/
/*
#include <GL/glut.h>
#include <math.h>

void drawDiya(float x, float y, float radius) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y);
  for (int i = 0; i <= 360; i++) {
    float angle = i * 3.14159 / 180.0;
    float px = x + radius * cos(angle);
    float py = y + radius * sin(angle);
    glVertex2f(px, py);
  }
  glEnd();

  // draw flame
  glColor3f(1.0, 0.6, 0.0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y + radius / 2);
  for (int i = 0; i <= 360; i++) {
    float angle = i * 3.14159 / 180.0;
    float px = x + radius / 4 * cos(angle);
    float py = y + radius / 2 + radius / 4 * sin(angle);
    glVertex2f(px, py);
  }
  glEnd();
}

void drawDesign(float x, float y, float radius) {
  // draw small triangles around the Diya
  glColor3f(1.0, 1.0, 1.0);
  for (int i = 0; i < 8; i++) {
    float angle = i * 45.0;
    float px = x + (radius - 5) * cos(angle * 3.14159 / 180.0);
    float py = y + (radius - 5) * sin(angle * 3.14159 / 180.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(px, py);
    glVertex2f(px + 10, py + 10);
    glVertex2f(px + 10, py - 10);
    glEnd();
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // draw the Diya
  glColor3f(1.0, 0.8, 0.0);
  drawDiya(250, 250, 50);

  // draw some decorative designs on the Diya
  drawDesign(250, 250, 50);

  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Diya");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 500, 0, 500, -1, 1);
  glMatrixMode(GL_MODELVIEW);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}


#include <GL/glut.h>
#include <math.h>

void drawDiya(float x, float y, float z, float radius, float height) {
  float angle, x1, z1;
  float delta = 10.0;
  float flameHeight = height / 3.0;

  // draw the body of the Diya
  glColor3f(1.0, 0.8, 0.0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x, y, z);
  for (angle = 0.0; angle <= 360.0; angle += delta) {
    x1 = x + radius * cos(angle * M_PI / 180.0);
    z1 = z + radius * sin(angle * M_PI / 180.0);
    glVertex3f(x1, y, z1);
  }
  glEnd();

  // draw the flame of the Diya
  glColor3f(1.0, 0.6, 0.0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x, y + height, z);
  for (angle = 0.0; angle <= 360.0; angle += delta) {
    x1 = x + radius / 2.0 * cos(angle * M_PI / 180.0);
    z1 = z + radius / 2.0 * sin(angle * M_PI / 180.0);
    glVertex3f(x1, y + height - flameHeight, z1);
  }
  glEnd();

  // draw some decorative designs on the Diya
  glColor3f(1.0, 1.0, 1.0);
  for (angle = 0.0; angle <= 360.0; angle += 45.0) {
    x1 = x + (radius - 5) * cos(angle * M_PI / 180.0);
    z1 = z + (radius - 5) * sin(angle * M_PI / 180.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y, z1);
    glVertex3f(x1 + 10, y, z1 + 10);
    glVertex3f(x1 + 10, y, z1 - 10);
    glEnd();
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  // draw the Diya
  drawDiya(0.0, 0.0, 0.0, 1.0, 2.0);

  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("3D Diya");

  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, 1.0, 0.1, 100.0);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Diya
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.8, 0.0); // Set color to yellow
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(1.0, 0.5, 0.0); // Set color to orange
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);

    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.0, 1.0, -1.0*(GLfloat)h/(GLfloat)w,
            1.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-1.0*(GLfloat)w/(GLfloat)h,
            1.0*(GLfloat)w/(GLfloat)h, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Diya using OpenGL in C Language");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawDiya()
{
    // Draw Diya
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.8, 0.0); // Set color to yellow
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(1.0, 0.5, 0.0); // Set color to orange
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);

    glEnd();

    // Draw decorations
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glVertex3f(-0.2, 0.3, 0.0);
    glVertex3f(0.2, 0.3, 0.0);
    glVertex3f(0.0, -0.3, 0.0);
    glEnd();
}

void drawHouse()
{
    // Draw house walls
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5); // Set color to gray
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glEnd();

    // Draw roof
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glVertex3f(-0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.0, 0.9, 0.0);
    glEnd();

    // Draw door
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glVertex3f(-0.2, -0.5, 0.0);
    glVertex3f(0.2, -0.5, 0.0);
    glVertex3f(0.2, -0.3, 0.0);
    glVertex3f(-0.2, -0.3, 0.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw house
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    drawHouse();
    glPopMatrix();

    // Draw Diya
    // Draw Diya
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);
    glRotatef(45.0, 0.0, 0.0, 1.0); // Rotate the Diya by 45 degrees around the Z-axis
    glTranslatef(0.0, 1.0, 0.0);
    drawDiya();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House with Decorated Diya");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}


#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, -1.0);
        glVertex2f(-1.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0.0);
        glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Night with Moon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/






#include <stdlib.h>

#include <stdio.h>

#include <time.h>

#include <string.h>

#include <GL/glut.h>





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

float l1,l2,l3;



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



}



/***** Description Screen *****/



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



/****** Keyboard Functions *******/



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





/******* MAIN FUNCTION *******/



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

    glutDisplayFunc(scene);

    glDepthFunc(GL_LESS);

    glutFullScreen();			// fullscreen view of the program

    glutKeyboardFunc(mKeyboardFunc);

    initSnow();



    glutMainLoop(); // Initiate the main loop

    return 0;

}
//cristmus.txt
//Displaying cristmus.txt.
