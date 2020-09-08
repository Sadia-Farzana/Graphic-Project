#include <cstdio>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include <unistd.h>
#include<cmath>
# define PI           3.14159265358979323846

using namespace std;

void myDisplay();
int start_flag=0;
using namespace std;

///text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

void sound()
{
    PlaySound("b.wav", NULL, SND_ASYNC|SND_FILENAME);


}
//char s[30];
void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.05f;
void updateTruck(int value)
{
    if(truckPosition > 2.0)
        truckPosition = -1.2f;

    truckPosition += truckSpeed;

	glutPostRedisplay();


	glutTimerFunc(100, updateTruck, 0);
}

GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
void updateCar(int value)
{
    if(carPosition < - 1.5)
        carPosition = 1.2f;

    carPosition -= carSpeed;

	glutPostRedisplay();


	glutTimerFunc(100, updateCar, 0);
}

GLfloat batPosition = 0.0f;
GLfloat batSpeed = 0.05f;
void batfly(int value)
{
    if(batPosition < - 1.8)
        batPosition = 1.2f;

 batPosition -= batSpeed;

	glutPostRedisplay();
	glutTimerFunc(100, batfly, 0);
}

GLfloat coludPosition = 0.0f;
GLfloat cloudSpeed = 0.01f;
void cloud(int value)
{
    if(coludPosition <  2.0)
       coludPosition = 1.2f;
coludPosition  -= cloudSpeed ;

	glutPostRedisplay();
	glutTimerFunc(100, cloud, 0);
}

void circleSolid(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}



void sky(int val)
{

        glBegin(GL_POLYGON); //Sky
        glColor3ub(14, 10, 40);
        glVertex2f(-1,1);
        glVertex2f(1, 1);
        glColor3f(0.7, 0.7, 1.0);
        glVertex2f(1, -.1);
        glVertex2f(-1, -.1);
        glEnd();

  // soil

    glBegin(GL_QUADS);

    glVertex2f(1.0, 0.25);
    glColor3ub(67,59,35);
       glVertex2f(-1.0, 0.25);
     glColor3ub(27,10,59);
     glVertex2f(-1.0, -1.0);
 glColor3ub(67,59,35);
    glVertex2f(1.0, -1.0);
      glColor3ub(112,88,16);
    glEnd();

}

void lightning()
{
glPushMatrix();
glTranslatef(batPosition,0.0f,0.0f );
    //cloud

     glColor3ub(217, 236, 239);
    circleSolid(+0.46f,+0.72f,0.060);
    glColor3ub(217, 236, 239);
    circleSolid(+0.53f,+0.72f,0.065);
    glColor3ub(217, 236, 239);
    circleSolid(+0.60f,+0.72f,0.056);

    glBegin(GL_POLYGON); //inSky
        glColor3ub(217, 236, 239);
        glVertex2f(+.45,+.50);
        glVertex2f(+.46, +.55);
        glColor3f(0.7, 0.7, 1.0);
        glVertex2f(+.52, +.68);
        glVertex2f(+.50, +.60);
        glEnd();

         /*glBegin(GL_POLYGON); //inSky
        glColor3ub(217, 236, 239);
        glVertex2f(+.52,+.68);
        glVertex2f(+.50, +.60);
        glColor3f(0.7, 0.7, 1.0);
        glVertex2f(+.47, +.73);
        glVertex2f(+.45, +.75);
        glEnd();*/

        glPopMatrix();
}





void hills()

{

  //Hills
 //glColor3ub(67, 88, 152);
  // glBegin(GL_QUADS);
   // glVertex2f(1.0, 0.35);
   // glVertex2f(-1.0, 0.35);
 // glVertex2f(-1.0, 0.15);
 //   glVertex2f(1.0, 0.15);
  // glEnd();



    glColor3ub(8, 15, 37); //right 2nd hill
    glBegin(GL_TRIANGLES);
    glVertex2f(0.9, 0.25);
    glColor3ub(67, 88, 152);
    glVertex2f(0.65, 0.58);
    glVertex2f(0.2, 0.25);
    glEnd();
    glColor3ub(8, 15, 40); // right tree er por 1st hill
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4, 0.25);
    glColor3ub(67, 88, 152);
    glVertex2f(0.15, 0.6);
    glVertex2f(-0.3, 0.25);
    glEnd();
   glColor3ub(8, 15, 37); //right most hill
    glBegin(GL_TRIANGLES);
    glVertex2f(1.075, 0.25);
     glColor3ub(67, 88, 152);
    glVertex2f(0.85, 0.7);
    glColor3ub(67, 88, 152);
    glVertex2f(0.6, 0.25);
    glEnd();




  //  glColor3ub(8, 15, 37); //
   // glBegin(GL_TRIANGLES);
   // glVertex2f(-0.34, 0.15);
   //  glColor3ub(67, 88, 152);
   // glVertex2f(-0.47, 0.6);
   // glVertex2f(-0.63, 0.15);
   // glEnd();

   glColor3ub(67, 88, 152);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.63, 0.25);

   glColor3ub(28, 15, 31);

    glVertex2f(-0.85, 0.7);
     glColor3ub(67, 88, 152);
    glVertex2f(-1, 0.25);
    glEnd();
    }




void gravyard()
{


  glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.42, -0.75);
    glVertex2f(0.89, -0.75);
    glVertex2f(0.89, -0.50);
    glVertex2f(0.42, -0.50);
    glEnd();


    glColor3ub(145, 163, 176);
    glBegin(GL_QUADS);
    glVertex2f(0.42, -0.50);
    glVertex2f(0.89, -0.50);
    glVertex2f(0.78, -0.65);
    glVertex2f(0.53, -0.65);

     glColor3ub(83, 104, 114);
    glBegin(GL_QUADS);
    glVertex2f(0.49, -0.50);
    glVertex2f(0.84, -0.50);
    glVertex2f(0.84, -0.46);
    glVertex2f(0.49, -0.46);

    glEnd();

     glColor3ub(83, 104, 114);
    glBegin(GL_QUADS);
    glVertex2f(0.53, -0.46);
    glVertex2f(0.80, -0.46);
    glVertex2f(0.80, -0.43);
    glVertex2f(0.53, -0.43);

    glEnd();

    glColor3ub(83, 104, 114);
    glBegin(GL_QUADS);
    glVertex2f(0.56, -0.43);
    glVertex2f(0.77, -0.43);
    glVertex2f(0.77, -0.40);
    glVertex2f(0.56, -0.40);

    glEnd();

        glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.62, -0.40);
    glVertex2f(0.71, -0.40);
    glVertex2f(0.71, -0.35);
    glVertex2f(0.62, -0.35);
//cross need to correct
    glEnd();

       glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.56, -0.35);
    glVertex2f(0.77, -0.35);
    glVertex2f(0.77, -0.28);
    glVertex2f(0.56, -0.28);

    glEnd();

        glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.62, -0.28);
    glVertex2f(0.71, -0.28);
    glVertex2f(0.71, -0.20);
    glVertex2f(0.62, -0.20);

    glEnd();


        glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.25, -0.61);
    glVertex2f(0.39, -0.61);
    glVertex2f(0.39, -0.45);
    glVertex2f(0.25, -0.45);

    glEnd();

      glColor3ub(83, 104, 114);
    glBegin(GL_TRIANGLES);
glVertex2f( 0.39, -0.45 );
glVertex2f( 0.25, -0.45 );
glVertex2f( 0.32, -0.33 );
glEnd();


    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.24, -0.29);
    glVertex2f(0.40, -0.29);
    glVertex2f(0.40, -0.26);
    glVertex2f(0.24, -0.26);

     glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.30, -0.35 );
    glVertex2f(0.34, -0.35);
    glVertex2f(0.34, -0.21);
    glVertex2f(0.30, -0.21);



    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.24, -0.29);
    glVertex2f(0.40, -0.29);
    glVertex2f(0.40, -0.26);
    glVertex2f(0.24, -0.26);



//small2
 glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.81, -0.42);
    glVertex2f(0.92, -0.42);
    glVertex2f(0.92, -0.26);
    glVertex2f(0.81, -0.26);
    glEnd();

      glColor3ub(83, 104, 114);
    glBegin(GL_TRIANGLES);
glVertex2f( 0.92, -0.26 );
glVertex2f( 0.81, -0.26 );
glVertex2f( 0.87, -0.19 );
glEnd();


glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.85, -0.20);
    glVertex2f(0.89, -0.20);
    glVertex2f(0.89, -0.12);
    glVertex2f(0.85, -0.12);
    glEnd();

  glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.81, -0.18);
    glVertex2f(0.93, -0.18);
    glVertex2f(0.93, -0.15);
    glVertex2f(0.81, -0.15);
    glEnd();



    //small112
 glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.42, -0.42);
    glVertex2f(0.50, -0.42);
    glVertex2f(0.50, -0.36);
    glVertex2f(0.42, -0.36);
    glEnd();


    glColor3ub(83, 104, 114);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.50, -0.36);
    glVertex2f(0.42, -0.36);
    glVertex2f(0.46, -0.33);
    glEnd();

     glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.33);
    glVertex2f(0.47, -0.33);
    glVertex2f(0.47, -0.25);
    glVertex2f(0.45, -0.25);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.43, -0.31);
    glVertex2f(0.49, -0.31);
    glVertex2f(0.49, -0.29);
    glVertex2f(0.43, -0.29);
    glEnd();
    //upper
     glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.40, -0.21);
    glVertex2f(0.57, -0.21);
    glVertex2f(0.57, -0.12);
    glVertex2f(0.40, -0.12);
    glEnd();

     glColor3ub(83, 104, 114);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.57, -0.12);
    glVertex2f(0.40, -0.12);
    glVertex2f(0.49, -0.08);
    glEnd();


      glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.08);
    glVertex2f(0.50, -0.08);
    glVertex2f(0.50, -0.00);
    glVertex2f(0.48, -0.00);
    glEnd();

       glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.44, -0.05);
    glVertex2f(0.54, -0.05);
    glVertex2f(0.54, -0.03);
    glVertex2f(0.44, -0.03);
    glEnd();

 //UPER RIGHT

     glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.63, -0.17);
    glVertex2f(0.78, -0.17);
    glVertex2f(0.78, -0.09);
    glVertex2f(0.63, -0.09);
    glEnd();

     glColor3ub(83, 104, 114);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.78, -0.09);
    glVertex2f(0.63, -0.09);
    glVertex2f(0.70, -0.06);
    glEnd();


      glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.69, -0.06);
    glVertex2f(0.71, -0.06);
    glVertex2f(0.71, +0.00);
    glVertex2f(0.69, -0.00);
    glEnd();

       glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.66, -0.05);
    glVertex2f(0.75, -0.05);
    glVertex2f(0.75, -0.03);
    glVertex2f(0.66, -0.03);
    glEnd();
}



void badurMoon()
{
  glPushMatrix();
glTranslatef(batPosition,0.0f,0.0f );
       //face
     glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.24);
    glVertex2f(0.49, -0.24);
    glVertex2f(0.49, -0.18);
    glVertex2f(0.45, -0.18);
    glEnd();

    //leg
        glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.46, -0.26);
    glVertex2f(0.46, -0.24);
    glVertex2f(0.45, -0.24);
    glEnd();

    //right
         glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.26);
    glVertex2f(0.49, -0.26);
    glVertex2f(0.49, -0.24);
    glVertex2f(0.48, -0.24);
    glEnd();

//LEFT
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.46, -0.25);
    glVertex2f(0.46, -0.25);
    glEnd();

   //PAKHNA
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.22);
    glVertex2f(0.58, -0.22);
    glVertex2f(0.58, -0.20);
    glVertex2f(0.48, -0.20);
    glEnd();

   //design
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.20);
    glVertex2f(0.58, -0.20);
    glVertex2f(0.58, -0.18);
    glVertex2f(0.54, -0.18);
    glEnd();

      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.36, -0.22);
    glVertex2f(0.46, -0.22);
    glVertex2f(0.46, -0.20);
    glVertex2f(0.36, -0.20);
    glEnd();

       glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.36, -0.20);
    glVertex2f(0.45, -0.20);
    glVertex2f(0.38, -0.18);
    glVertex2f(0.36, -0.18);
    glEnd();
//head


  glColor3ub(22, 22, 28);
       glBegin(GL_TRIANGLES);
       glVertex2f( 0.47, -0.18 );
       glVertex2f( 0.45, -0.18 );
       glVertex2f( 0.46, -0.16 );
       glEnd();
//right
        glColor3ub(22, 22, 28);
       glBegin(GL_TRIANGLES);
       glVertex2f( 0.49, -0.18);
       glVertex2f( 0.47, -0.18 );
       glVertex2f( 0.48, -0.16 );
       glEnd();
       glPopMatrix();


       //BADUR IN MOON
glPushMatrix();
glTranslatef(batPosition,0.0f, 0.0f);
         glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.65, +0.50);
    glVertex2f(-0.60, +0.50);
    glVertex2f(-0.60, +0.58);
    glVertex2f(-0.65, +0.58);
    glEnd();

    //LEFT ONE
           glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.60 , +0.55);
    glVertex2f(-0.80, +0.55);
    glVertex2f(-0.80, +0.53);
    glVertex2f(-0.60, +0.53);
    glEnd();

    //RIGHT
            glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.45 , +0.55);
    glVertex2f(-0.61, +0.55);
    glVertex2f(-0.61, +0.53);
    glVertex2f(-0.45, +0.53);
    glEnd();


    //HEAD RIGHT
            glColor3ub(22, 22, 28);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.62 , +0.50);
    glVertex2f(-0.60, +0.50);
    glVertex2f(-0.61, +0.48);
    glEnd();


    //HEAD LEFT
            glColor3ub(22, 22, 28);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.65 , +0.50);
    glVertex2f(-0.63, +0.50);
    glVertex2f(-0.64, +0.48);
    glEnd();



    //LEFT ONE HEAD
           glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.60 , +0.61);
    glVertex2f(-0.62, +0.61);
    glVertex2f(-0.62, +0.58);
    glVertex2f(-0.60, +0.58);
    glEnd();

     //LEFT ONE HEAD
           glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.63 , +0.61);
    glVertex2f(-0.65, +0.61);
    glVertex2f(-0.65, +0.58);
    glVertex2f(-0.63, +0.58);
    glEnd();

    //LEFT ONE HEAD
           glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.65 , +0.53);
    glVertex2f(-0.80, +0.53);
    glVertex2f(-0.80, +0.50);
    glVertex2f(-0.79, +0.50);
    glEnd();


           glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.45 , +0.53);
    glVertex2f(-0.60, +0.53);
    glVertex2f(-0.47, +0.50);
    glVertex2f(-0.45, +0.50);
    glEnd();


            glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.45 , +0.58);
    glVertex2f(-0.47, +0.58);
    glVertex2f(-0.60, +0.55);
    glVertex2f(-0.45, +0.55);
    glEnd();


            glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(-0.78 , +0.58);
    glVertex2f(-0.80, +0.58);
    glVertex2f(-0.80, +0.55);
    glVertex2f(-0.65, +0.55);
    glEnd();
    glPopMatrix();
}

void badur()
{
 glPushMatrix();
glTranslatef(batPosition,batPosition, 0.0f);
       //face
     glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.24);
    glVertex2f(0.49, -0.24);
    glVertex2f(0.49, -0.18);
    glVertex2f(0.45, -0.18);
    glEnd();

    //leg
        glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.46, -0.26);
    glVertex2f(0.46, -0.24);
    glVertex2f(0.45, -0.24);
    glEnd();

    //right
         glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.26);
    glVertex2f(0.49, -0.26);
    glVertex2f(0.49, -0.24);
    glVertex2f(0.48, -0.24);
    glEnd();

//LEFT
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.45, -0.26);
    glVertex2f(0.46, -0.25);
    glVertex2f(0.46, -0.25);
    glEnd();

   //PAKHNA
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.22);
    glVertex2f(0.58, -0.22);
    glVertex2f(0.58, -0.20);
    glVertex2f(0.48, -0.20);
    glEnd();

   //design
      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.20);
    glVertex2f(0.58, -0.20);
    glVertex2f(0.58, -0.18);
    glVertex2f(0.54, -0.18);
    glEnd();

      glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.36, -0.22);
    glVertex2f(0.46, -0.22);
    glVertex2f(0.46, -0.20);
    glVertex2f(0.36, -0.20);
    glEnd();

       glColor3ub(22, 22, 28);
    glBegin(GL_QUADS);
    glVertex2f(0.36, -0.20);
    glVertex2f(0.45, -0.20);
    glVertex2f(0.38, -0.18);
    glVertex2f(0.36, -0.18);
    glEnd();
//head


  glColor3ub(22, 22, 28);
       glBegin(GL_TRIANGLES);
       glVertex2f( 0.47, -0.18 );
       glVertex2f( 0.45, -0.18 );
       glVertex2f( 0.46, -0.16 );
       glEnd();
//right
        glColor3ub(22, 22, 28);
       glBegin(GL_TRIANGLES);
       glVertex2f( 0.49, -0.18);
       glVertex2f( 0.47, -0.18 );
       glVertex2f( 0.48, -0.16 );
       glEnd();
       glPopMatrix();

}


 void wall()
{
   glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.42);
    glVertex2f(0.27, -0.42);
    glVertex2f(0.27, -0.39);
    glVertex2f(-0.32, -0.39);
    glEnd();


       glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.47);
    glVertex2f(0.26, -0.47);
    glVertex2f(0.26, -0.44);
    glVertex2f(-0.32, -0.44);
    glEnd();


        glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.48);
    glVertex2f(0.26, -0.48);
    glVertex2f(0.26, -0.45);
    glVertex2f(-0.32, -0.45);
    glEnd();


      glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.42);
    glVertex2f(0.26, -0.42);
    glVertex2f(0.26, -0.39);
    glVertex2f(-0.32, -0.39);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.36);
    glVertex2f(0.30, -0.36);
    glVertex2f(0.30, -0.33);
    glVertex2f(-0.32, -0.33);
    glEnd();

     glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33, -0.30);
    glVertex2f(0.25, -0.30);
    glVertex2f(0.25, -0.27);
    glVertex2f(-0.33, -0.27);
    glEnd();


      glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.37, -0.24);
    glVertex2f(0.30, -0.24);
    glVertex2f(0.30, -0.21);
    glVertex2f(-0.37, -0.21);
    glEnd();


     glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.37, -0.18);
    glVertex2f(0.36, -0.18);
    glVertex2f(0.36  , -0.15);
    glVertex2f(-0.37, -0.15);
    glEnd();

     glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.34, -0.44);
    glVertex2f(-0.31, -0.44);
    glVertex2f(-0.31  , -0.08);
    glVertex2f(-0.34, -0.08);
    glEnd();

    glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, -0.44);
    glVertex2f(-0.29, -0.44);
    glVertex2f(-0.29  , -0.08);
    glVertex2f(-0.32, -0.08);
    glEnd();

    glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.26, -0.44);
    glVertex2f(-0.21, -0.44);
    glVertex2f(-0.21  , -0.08);
    glVertex2f(-0.26, -0.08);
    glEnd();


    glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.02, -0.44);
    glVertex2f(0.03 , -0.44);
    glVertex2f(0.03, -0.08);
    glVertex2f(-0.02, -0.08);
    glEnd();

        glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.06, -0.44);
    glVertex2f(0.11 , -0.44);
    glVertex2f(0.11, -0.08);
    glVertex2f(0.06, -0.08);
    glEnd();

        glColor3ub( 0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.14, -0.44);
    glVertex2f(0.19 , -0.44);
    glVertex2f(0.19, -0.08);
    glVertex2f(0.14, -0.08);
    glEnd();



}
void house()
{
        //Moon2
    glColor3ub(248,247,157);
    circleSolid(-0.50f,+0.4f,0.330);

        //Moon2
    glColor3ub(248,247,157);
    circleSolid(-0.49f,+0.45f,0.340);
 //Moon2
    glColor3ub(248,247,157);
    circleSolid(-0.50f,+0.5f,0.340);
     //Moon2
    glColor3ub(248,247,157);
    circleSolid(-0.50f,+0.55f,0.330);



      //right
    glBegin(GL_POLYGON);
      glColor3ub (15,14,14);
    glVertex2f(-.45f, -.80f);

    glVertex2f(-0.25f, -.70f);
    glVertex2f(-0.25f,-0.43);
    glVertex2f(-.45f,-0.40);
    glEnd();
//window
   glBegin(GL_POLYGON);
      glColor3ub(235,234,137);
    glVertex2f(-.38f, -.63f);
    glVertex2f(-0.30f, -.60f);

    glVertex2f(-0.30f,-0.47);
    glVertex2f(-.38f,-0.50);
  glEnd();

  //windowgrill
   glBegin(GL_POLYGON);
      glColor3ub (0,0,0);
    glVertex2f(-.34f, -.63f);
    glVertex2f(-0.33f, -.63f);
    glVertex2f(-0.33f,-0.47);
    glVertex2f(-.34f,-0.47);
  glEnd();
  //windowgrill
    glBegin(GL_POLYGON);
       glColor3ub (0,0,0);
    glVertex2f(-.38f, -.57f);
    glVertex2f(-0.30f, -.55f);
    glVertex2f(-0.30f,-0.56f);
    glVertex2f(-.38f,-0.56f);
  glEnd();
    //hin2shade
   glBegin(GL_TRIANGLES);
   glColor3ub (15,14,14);
    glVertex2f(-.45f, -.45f);
glVertex2f(-0.34f, -.25f);
   glColor3ub (15,14,14);
    glVertex2f(-0.25f,-0.43f);
   glEnd();

//leftHOUSE

    glBegin(GL_POLYGON);
    glColor3ub (1, 1,7);
    glVertex2f(-.82f, -.70f);

    glVertex2f(-0.45f, -.80f);
    glVertex2f(-0.45f,-0.46f);
   glColor3ub (53, 56,58);
    glVertex2f(-.82f,-0.46f);
    glEnd();

    glPushMatrix();
glTranslatef(0.0f,0.0f,batPosition );
    //skull
    glColor3ub (4,5,4);
    circleSolid(-0.83f,-0.75f,0.048);
//skull
    glColor3ub (7,5,4);
    glBegin(GL_POLYGON);
    glVertex2f(-.86f, -.76f);
    glVertex2f(-0.80f, -.76f);
    glVertex2f(-0.80f,-0.83f);
    glVertex2f(-.86f,-0.83f);
    glEnd();
    //eyes
 glColor3ub(255,255,255);
    circleSolid(-0.85f,-0.74f,0.010);
    glColor3ub(255,255,255);
    circleSolid(-0.81f,-0.74f,0.010);
    //teeth
     glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2f(-.84f, -.78f);
    glVertex2f(-0.84f, -.83f);
    glEnd();

    //teeth
     glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2f(-.82f, -.78f);
    glVertex2f(-0.82f, -.83f);
   glEnd();
   glPopMatrix();

 //left_shade
    glColor3ub(15,18,29);
    glBegin(GL_POLYGON);
    glVertex2f(-.85f, -.49f);
    glVertex2f(-0.45f, -.50f);
    glColor3ub(32,32,32);
    glVertex2f(-0.34f,-0.25f);
    glVertex2f(-.78f,-0.27f);
    glEnd();

    //rightwindow
  glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.78f, -.62f);
    glVertex2f(-0.71f, -.65f);
    glVertex2f(-0.71f,-0.55f);
    glVertex2f(-.78f,-0.55f);
    glEnd();
    //rightwindow
      glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.75f, -.65f);
    glVertex2f(-0.74f, -.65f);
    glVertex2f(-0.74f,-0.55f);
    glVertex2f(-.75f,-0.55f);
    glEnd();
  //rightgrill
      glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.78f, -.60f);
    glVertex2f(-0.71f, -.60f);
    glVertex2f(-0.71f,-0.59f);
    glVertex2f(-.78,-0.59f);
    glEnd();


    //rightwindgrill
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.57f, -.67f);
    glVertex2f(-0.49f, -.69f);
    glVertex2f(-0.49f,-0.57f);
    glVertex2f(-.57f,-0.57f);
    glEnd();


    //rightwindow2
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.57f, -.67f);
    glVertex2f(-0.49f, -.69f);
    glVertex2f(-0.49f,-0.57f);
    glVertex2f(-.57f,-0.57f);
    glEnd();
//rightwindow2grill
     glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.54f, -.69f);
    glVertex2f(-0.53f, -.69f);
    glVertex2f(-0.53f,-0.57f);
    glVertex2f(-.54f,-0.57f);
    glEnd();
//rightwindow2grill
      glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.57f, -.63f);
    glVertex2f(-0.49f, -.63f);
    glVertex2f(-0.49f,-0.62f);
    glVertex2f(-.57f,-0.62f);
    glEnd();


    //rightdoor
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.69f, -.70f);
    glVertex2f(-0.60f, -.72f);
    glVertex2f(-0.60f,-0.54f);
    glVertex2f(-.69f,-0.54f);
    glEnd();
 //rightdoorgrill
     glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.61f, -.72f);
    glVertex2f(-0.60f, -.72f);
    glVertex2f(-0.60f,-0.54f);
    glVertex2f(-.61f,-0.54f);
    glEnd();

    //rightdoorgrill
     glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.69f, -.52f);
    glVertex2f(-0.60f, -.52f);
    glVertex2f(-0.60f,-0.54f);
    glVertex2f(-.69f,-0.54f);
    glEnd();

    //houseupright
    glColor3ub (47,54,54);

    glBegin(GL_POLYGON);
    glVertex2f(-.50f, -.27f);
    glVertex2f(-0.36f, -.26f);
    glVertex2f(-0.36f,+0.20f);
    glColor3ub (0, 4,7);
    glVertex2f(-.50f,+0.20f);
    glEnd();


    //houseuprightwindow
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.43f, +.02f);
    glVertex2f(-0.36f, +.02f);
    glVertex2f(-0.36f,+0.15f);
    glVertex2f(-.43f,+0.15f);
    glEnd();


    //houseuprightwindowgrill
     glColor3ub (0, 0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.43f, +.08f);
    glVertex2f(-0.36f, +.08f);
    glVertex2f(-0.36f,+0.09f);
    glVertex2f(-.43f,+0.09f);
    glEnd();

    //houseuprightwindowgrill
    glColor3ub (0, 0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.39f, +.02f);
    glVertex2f(-0.38f, +.02f);
    glVertex2f(-0.38f,+0.15f);
    glVertex2f(-.39f,+0.15f);
    glEnd();


         //houseuprightshade
      glBegin(GL_TRIANGLES);
      glColor3ub (47,54,54);
   glVertex2f(-.50f, +0.20f);
    glColor3ub (0,7,4);
    glVertex2f(-0.43f, +.39f);
    glVertex2f(-0.36f,+0.20f);
   glEnd();



   //houseupleft
     glColor3ub (12, 25,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.77f, -.27f);
    glVertex2f(-0.65f, -.27f);
    glVertex2f(-0.65f,+0.16f);
     glColor3ub (47,54,54);
    glVertex2f(-.77f,+0.16f);
    glEnd();

    //houseupleftwindow
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.74f, +.01f);
    glVertex2f(-0.67f, +.01f);
    glVertex2f(-0.67f,+0.10f);
    glVertex2f(-.74f,+0.10f);
    glEnd();
//houseupleftwindowgrill
     glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.71f, +.01f);
    glVertex2f(-0.70f, +.01f);
    glVertex2f(-0.70f,+0.10f);
    glVertex2f(-.71f,+0.10f);
    glEnd();

   /* //houseupleftwindowgrill
     glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.74f, +.01f);
    glVertex2f(-0.67f, +.01f);
    glVertex2f(-0.67f,+0.10f);
    glVertex2f(-.74f,+0.10f);
    glEnd();*/
     //houseupleftshade
      glBegin(GL_TRIANGLES);
    glColor3ub (47,54,54);
    glVertex2f(-.77f, +0.16f);
     glColor3ub (4,5,5);
    glVertex2f(-0.71f, +.30f);
    glVertex2f(-0.65f,+0.16f);
   glEnd();
//house2
      glColor3ub (1, 0,1);
    glBegin(GL_POLYGON);
    glVertex2f(-.75f, -.35f);
    glVertex2f(-0.45f, -.35f);
    glVertex2f(-0.45f,-0.1f);
     glColor3ub (47,54,54);
    glVertex2f(-.75f,-0.1f);
    glEnd();
 /*   //SPIDER
glColor3ub(255,255,0);
    circleSolid(-0.71f,-0.21f,0.010);
    //LEG
       glColor3ub (15, 14,17);
   glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2f(-0.72,-0.21f);
   glVertex2f(-0.74,-0.19f);
   glEnd();
    glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2f(-0.72,-0.19f);
   glVertex2f(-0.73,-0.18f);
   glEnd();
   glLineWidth(3);
   glBegin(GL_LINES);
   glVertex2f(-0.72,-0.22f);
   glVertex2f(-0.74,-0.20f);
   glEnd();

   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex2f(-0.67,-0.22f);
   glVertex2f(-0.62,-0.20f);
   glEnd(); */





    //house2window
     glColor3ub(235,234,137);
    glBegin(GL_POLYGON);
    glVertex2f(-.65f, -.28f);
    glVertex2f(-0.55f, -.28f);
    glVertex2f(-0.55f,-0.18f);
    glVertex2f(-.65f,-0.18f);
    glEnd();


    //house2windowgrill
      glColor3ub (0, 0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.61f, -.28f);
    glVertex2f(-0.60f, -.28f);
    glVertex2f(-0.60f,-0.18f);
    glVertex2f(-.61f,-0.18f);
    glEnd();
    //house2windowgrill
      glColor3ub (0, 0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.65f, -.24f);
    glVertex2f(-0.55f, -.24f);
    glVertex2f(-0.55f,-0.23f);
    glVertex2f(-.65f,-0.23f);
    glEnd();

    //h2shade
      glBegin(GL_TRIANGLES);
   glColor3ub (0,4,4);
    glVertex2f(-.76f, -.1f);
    glVertex2f(-0.60f, +.2f);
    glColor3ub (50,47,47);
    glVertex2f(-0.44f,-0.1f);
   glEnd();
   //circlewindow
    glColor3ub(0,0,0);
    circleSolid(-0.60f,+0.01f,0.050);
  glColor3ub(235,234,137);
    circleSolid(-0.60f,+0.00f,0.045);
//circlewindowgrill
      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.60f, -.05f);
    glVertex2f(-0.59f, -.05f);
    glVertex2f(-0.59f,+0.05f);
    glVertex2f(-.60f,+0.05f);
    glEnd();
//circlewindowgrill
      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.65f, -.01f);
    glVertex2f(-0.55f, -.01f);
    glVertex2f(-0.55f,+0.0f);
    glVertex2f(-.65f,+0.0f);
    glEnd();

    //Cross
  glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.61f, +.19f);
    glVertex2f(-0.59f, +.19f);
    glVertex2f(-0.59f,+0.38f);
    glVertex2f(-.61f,+0.38f);
    glEnd();
//Cross
  glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.66f, +.32f);
    glVertex2f(-0.54f, +.32f);
    glVertex2f(-0.54f,+0.34f);
    glVertex2f(-.66f,+0.34f);
    glEnd();


}

void silhouette()
{
    //LEFT_TREE_MAIN
    glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.95f, -.70f);
    glVertex2f(-0.83f, -.70f);
    glVertex2f(-0.85f,-0.10f);
    glVertex2f(-.91f,-0.17f);
    glEnd();
//leftbranch
     glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.91f,-0.25f);
    glVertex2f(-.88f,-0.18f);
    glVertex2f(-.95f,+0.05f);
    glVertex2f(-.98f,+0.07f);
     glEnd();

    //mainrightbranch
     glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.87f,-0.25f);
    glVertex2f(-.82f,-0.18f);
    glVertex2f(-.80f,+0.13f);
    glVertex2f(-.86f,+0.08f);
    glEnd();

    //mainrightbranchleft
     glColor3ub (15, 14,17);
   glLineWidth(21);
   glBegin(GL_LINES);
   glVertex2f(-0.84,+0.07f);
   glVertex2f(-0.93,+0.34f);
   glEnd();

    //mainrightbranchleft
     glColor3ub (15, 14,17);
   glLineWidth(10);
   glBegin(GL_LINES);
   glVertex2f(-0.88,+0.20f);
   glVertex2f(-0.84,+0.30f);
   glEnd();
  /* glColor3ub (15, 14,17);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex2f(-0.78,+0.30f);
   glVertex2f(-0.75,+0.50f);
   glEnd(); */


    //mainrightbranchright
     glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.84f,+0.07f);
    glVertex2f(-.81f,+0.04f);
    glVertex2f(-.74f,+0.30f);
    glVertex2f(-.78f,+0.28f);
     glEnd();

       glColor3ub (15, 14,17);
   glLineWidth(15);
   glBegin(GL_LINES);
   glVertex2f(-0.77,+0.26f);
   glVertex2f(-0.81,+0.40f);
   glEnd();





   //RIGHT_TREE_MAIN
    glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.20f, -.70f);
    glVertex2f(-0.04f, -.70f);
    glVertex2f(-0.08f,+0.08f);
    glVertex2f(-.15f,+0.01f);
    glEnd();
    //owlhead
 glColor3ub(31,37,40);
    circleSolid(-0.27f,+0.27f,0.035);
    //eyes
    glColor3ub(255,255,255);
    circleSolid(-0.25f,+0.27f,0.016);
//pupil
      glColor3ub(0,0,0);
    circleSolid(-0.25f,+0.27f,0.005);
    glColor3ub(255,255,255);
    circleSolid(-0.29f,+0.27f,0.016);
    //pupil
    glColor3ub(0,0,0);
    circleSolid(-0.29f,+0.27f,0.005);

    glColor3ub(31,37,40);

    circleSolid(-0.27f,+0.21f,0.045);
    //nose
     glBegin(GL_TRIANGLES);
   glColor3ub (150,105,10);
    glVertex2f(-.25f, +.26f);
    glVertex2f(-0.27f, +.24f);
    glVertex2f(-0.29f,+0.26f);
   glEnd();


    //leftBranch1
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.15f, -0.1f);
    glVertex2f(-0.10f, +0.00f);
    glVertex2f(-0.24f,+0.16f);
    glVertex2f(-.27f,+0.12f);
    glEnd();

    //leftBranch2
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.27f, +0.12f);
    glVertex2f(-0.24f,+0.16f);
    glVertex2f(-0.40f,+0.24f);
    glVertex2f(-.39f,+0.22f);
    glEnd();
 //leftBranch3
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.39f, +0.22f);
    glVertex2f(-0.40f,+0.24f);
    glVertex2f(-0.48f,+0.24f);
    glVertex2f(-.46f,+0.22f);
    glEnd();

    //leftBranch3
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.39f, +0.22f);
    glVertex2f(-0.40f,+0.24f);
    glVertex2f(-0.48f,+0.24f);
    glVertex2f(-.46f,+0.22f);
    glEnd();
    //leftBranchloweSub
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.20f, +0.07f);
    glVertex2f(-0.24f,+0.12f);
    glVertex2f(-0.38f,+0.05f);
    glVertex2f(-.40f,+0.01f);
    glEnd();

    //leftBranchloweSub2
       glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.40f, +0.01f);
    glVertex2f(-0.38f,+0.05f);
    glVertex2f(-0.46f,+0.11f);
    glVertex2f(-.47f,+0.10f);
    glEnd();

    //MIDDLEBRANCH
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.07f, -0.1f);
    glVertex2f(-0.03f, +0.00f);
    glVertex2f(-0.18f,+0.25f);
    glVertex2f(-.21f,+0.23f);
    glEnd();

     //MIDDLEBRANCHleft
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.21f, +0.23f);
    glVertex2f(-0.18f, +0.25f);
    glVertex2f(-0.16f,+0.40f);
    glVertex2f(-.17f,+0.44f);
    glEnd();



     //MIDDLEBRANCHleft2
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.20f, +0.28f);
    glVertex2f(-0.18f, +0.32f);
    glVertex2f(-0.29f,+0.47f);
    glVertex2f(-.32f,+0.48f);
    glEnd();

    //MIDDLEBRANCHleft2
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.32f, +0.48f);
    glVertex2f(-0.29f, +0.47f);
    glVertex2f(-0.25f,+0.57f);
    glVertex2f(-.20f,+0.58f);
    glEnd();

 //MIDDLEBRANCHleft3
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.20f, +0.31f);
    glVertex2f(-0.20f, +0.35f);
    glVertex2f(-0.36f,+0.44f);
    glVertex2f(-.37f,+0.48f);
    glEnd();

    //MIDDLEBRANCHleft4
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.37f, +0.48f);
    glVertex2f(-0.36f, +0.44f);
    glVertex2f(-0.48f,+0.51f);
    glVertex2f(-.48f,+0.52f);
    glEnd();
        //MIDDLEBRANCHleft5
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.38f, +0.48f);
    glVertex2f(-0.34f, +0.44f);
    glVertex2f(-0.39f,+0.54f);
    glVertex2f(-.41f,+0.58f);
    glEnd();
//MIDDLEBRANCH
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.16f, +0.12f);
    glVertex2f(-0.12f, +0.11f);
    glVertex2f(-0.07f,+0.43f);
    glVertex2f(-.09f,+0.39f);
    glEnd();

    //MIDDLEBRANCH2
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.09f, +0.39f);
    glVertex2f(-0.07f, +0.43f);
    glVertex2f(-0.15f,+0.55f);
    glVertex2f(-.13f,+0.51f);
    glEnd();

      //MIDDLEBRANCHvshapebranch
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.12f, +0.47f);
    glVertex2f(-0.10f, +0.43f);
    glVertex2f(-.05f,+0.59f);
    glVertex2f(-.10f,+0.51f);
    glEnd();
  //rightmost
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.11f, +0.01f);
    glVertex2f(-0.03f, +0.0f);
    glVertex2f(+0.11f,+0.55f);
    glVertex2f(+.09f,+0.45f);
    glEnd();

     //rightmostleftbranch
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.04f, +0.15f);
    glVertex2f(0.0f, +0.12f);
    glVertex2f(-0.03f,+0.60f);
    glVertex2f(-.04f,+0.54f);
    glEnd();

      //rightmostleftbranch2
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(-.04f, +0.40f);
    glVertex2f(-0.04f, +0.32f);
    glVertex2f(+0.08f,+0.52f);
    glVertex2f(+.07f,+0.48f);
    glEnd();

      //rightmostleftbranch3
   glColor3ub (15, 14,17);
    glBegin(GL_POLYGON);
    glVertex2f(+.08f, +0.52);
    glVertex2f(+0.07f, +0.48f);
    glVertex2f(+0.01f,+0.64f);
    glVertex2f(+.03f,+0.57f);
    glEnd();

}





void road1()
{

    glColor3ub(32,32,32);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.57f, -1.0f);
    glVertex2f(-0.57f,-0.82);
    glVertex2f(-1.0f,-0.82);
    glEnd();

    glColor3ub(255,255,255);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex2f(-0.98,-0.91);
   glVertex2f(-0.92,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(-0.85,-0.91);
   glVertex2f(-0.79,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(-0.73,-0.91);
   glVertex2f(-0.67,-0.91);
   glEnd();
}

void road2()
{
    glColor3ub(32,32,32);
    glBegin(GL_POLYGON);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.82f);
    glVertex2f(-0.17f,-0.82f);
    glVertex2f(-0.17f,-1.0f);
    glEnd();

    glColor3ub(255,255,255);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex2f(0.28,-0.91);
   glVertex2f(0.34,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.4,-0.91);
   glVertex2f(0.46,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.52,-0.91);
   glVertex2f(0.58,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.64,-0.91);
   glVertex2f(0.7,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.76,-0.91);
   glVertex2f(0.82,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.88,-0.91);
   glVertex2f(0.94,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.22,-0.91);
   glVertex2f(0.16,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(0.1,-0.91);
   glVertex2f(0.04,-0.91);
   glEnd();
   glBegin(GL_LINES);
   glVertex2f(-0.02,-0.91);
   glVertex2f(-0.08,-0.91);
   glEnd();
}

void road3()
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.57f,-0.82);
    glVertex2f(-0.57f, -1.0f);
    glVertex2f(-0.17f,-1.0f);
    glVertex2f(-0.17f,-0.82f);
    glEnd();

    //some grass
    glColor3ub(0,0,0);
   glLineWidth(5);
   glBegin(GL_LINES);
   glVertex2f(-0.54,-0.91);
   glVertex2f(-0.48,-0.91);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(-0.42,-0.91);
   glVertex2f(-0.36,-0.91);
   glEnd();

   glBegin(GL_LINES);
   glVertex2f(-0.30,-0.91);
   glVertex2f(-0.24,-0.91);
   glEnd();
}


void truck()//This is the truck
{

    glPushMatrix();
    glTranslatef(truckPosition,0.0f, 0.0f);

   //body

    glColor3ub(42,41,56);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();
    //base of the truck
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();
    //front
    glColor3ub(84,105,27);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();
    //wheels
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);
    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();
    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();
    glPopMatrix();

}




void car()//This is the car
{
glPushMatrix();
glTranslatef(carPosition,0.0f, 0.0f);
      //body
    glColor3ub(160,160,160);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3ub(233,0,0);
    circleSolid(0.07,-0.938,0.035);
    circleSolid(0.2,-0.938,0.035);
    //
    glColor3ub(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glColor3ub(255,255,255);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(0.08,-0.838);
    glVertex2f(0.11,-0.774);
     glVertex2f(0.195,-0.836);
    glVertex2f(0.165,-0.774);
    glEnd();
glPopMatrix();

}



void fristDesign(){


        ///menu
        //middle
         glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2f(-.28,-.5);
        glVertex2f(.28,-0.5);
        glVertex2f(0.28,0.5);
        glVertex2f(-0.28,0.5);
       // glVertex2f(-0.28,0.9);

        glEnd();




        ///text info


        glColor3ub(179, 0, 0);
        renderBitmapString(-.15,.26,(void *)font1,"Haunted House");

        glColor3ub(0, 179, 0);
        renderBitmapString(-.18,0.06,(void *)font1,"Press SPACE to START");
        //renderBitmapString(38,72,(void *)font1,"Press ESC to Exit");

        glColor3ub(255, 0, 0);
        renderBitmapString(-0.189,-0.048,(void *)font2," 17-33890-1  Sadia Farzana ");
        renderBitmapString(-0.189,-0.12,(void *)font2," 17-33855-1	 Nafis Mustafa ");
        renderBitmapString(-0.189,-0.20,(void *)font2," 18-36325-1	 Sumaya Binte Choya  ");


}



void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(2.0);
    if(start_flag ==0 )
    {
      //  glClearColor(0, 392, 0,1);
        fristDesign();


    }

 //else{
 else if(start_flag == 1)
{
     glClearColor(255, 392, 0,1);




sky(1);


hills();
road1();
badur();
road2();
house();
badurMoon();
lightning();
wall();
 silhouette();
road3();

gravyard();

badur();
truck();
car();


 }

  glFlush ();

    }




void myKeyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

        case 'a'://press a to slow truck
            truckSpeed -= 0.03f;

            break;

        case 'd'://press d to fast truck
            truckSpeed += 0.05f;
            //sndPlaySound("sound filename.extension",SND_ASYNC);
            break;

        case 'q'://press j to slow down the bat
           batSpeed -= 0.03f;

            break;

             case 'w'://press d to fast truck
             batSpeed += 0.05f;

            break;


        case 'k'://press k to fast car
            carSpeed += 0.05f;
            break;

               case 'j'://press j to slow car
            carSpeed -= 0.03f;
            //sndPlaySound("sound filename.extension",SND_ASYNC);
            break;


        case 'h':

            sound();
            break;

             case 'o'://press o
            sndPlaySound("owl.wav",SND_ASYNC);
            break;



        case ' ':
            if(start_flag==0){

                start_flag = 1;}

                break;


            case 27:
                 exit(0);
             break;
             default:
            break;


    glutPostRedisplay();

    }

}



int main(int argc, char** argv)
{

    cout << endl << "Hunted House"<< endl << endl;

    cout << "Press a : To Slow down the Truck" << endl << endl;
    cout << "Press  d: to make the truck drive faster" << endl << endl;

    cout << "Press  k: to make the car drive faster" << endl << endl;
    cout << "Press  j: To Slow down the car" << endl << endl;

    cout << "Press  q:  To Slow down the bats " << endl << endl;
    cout << "Press  w: to make the bats faster" << endl << endl;

    cout << "Press  h: To play sound" << endl << endl;
    cout << "Press  o: To play owl sound" << endl << endl;






    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1300, 800);
    glutInitWindowPosition (50, 10);
    glutCreateWindow ("");



    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKeyboard);


    glutTimerFunc(1000, updateTruck, 0);
    glutTimerFunc(1000, updateCar, 0);
    glutTimerFunc(1000, batfly, 0);
    glutTimerFunc(100, cloud, 0);

    glutMainLoop();
}
