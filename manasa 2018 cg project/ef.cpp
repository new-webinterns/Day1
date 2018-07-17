//#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159

float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
float cRadius = 10.0f; // our radius distance from our character
float lastx, lasty;
float positionz[10];
float positionx[10];
static int slices = 16;
static int stacks = 16,i=0;
int df=10;

void wall(double thickness)
{
    glPushMatrix();


    glScaled(25,thickness,50);
    glutSolidCube(1);
    glPopMatrix();
}
void wall1(double thickness)
{
    glPushMatrix();
    glScaled(25,50,thickness);
    glutSolidCube(1);
    glPopMatrix();
}
void display();





void cube()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glutSolidCube(1);
    glPopMatrix();
}

void ground(double thickness)
{
    glPushMatrix();
    glTranslated(0,-0.78,60);
    glScaled(200,thickness,200);
    glutSolidCube(1);
    glPopMatrix();
}

void drawhalfcircle(float radius)  // the empty one
{
  //  float radius = 70;
    float twoPI = 2 * PI;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI/2; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewportto the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection
    glLoadIdentity ();
    gluPerspective (87, (GLfloat)w / (GLfloat)h, 1, 5000.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void mouseMovement(int x, int y)
{

    int diffx=x-lastx; //check the difference between the current x and the last x position
    int diffy=y-lasty; //check the difference between the current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot += (float) diffy;
    if (xrot >140) xrot -= 140;
    if (xrot < -90) xrot += 90; //set the xrot to xrot with the addition of the difference in the y position
    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
}


void keyboard (unsigned char key, int x, int y)
{


    if (key=='q')
    {
    xrot += 1;
    if (xrot >90) xrot -= 90;
    }

    if (key=='z')
    {
    xrot -= 1;
    if (xrot < -90) xrot += 90;
    }

    if (key=='w')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f);
    xpos += float(sin(yrotrad))*10;
    zpos -= float(cos(yrotrad))*10;
    ypos -= 0;
    }

    if (key=='s')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f);
    xpos -= float(sin(yrotrad))*10;
    zpos += float(cos(yrotrad))*10;
    ypos += 0;
    }

    if (key=='d')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos += float(cos(yrotrad))*10;
    zpos += float(sin(yrotrad))*10;
    }

    if (key=='a')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos -= float(cos(yrotrad))*10;
    zpos -= float(sin(yrotrad))*10;
    }
    if(key=='r')
    {
        xpos=0;
        ypos= 0;
        zpos=50;
        glTranslatef(xpos,ypos,zpos);
    }

    if(key=='-')
    {
                float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f)*2;
        ypos+=float((yrotrad)/2);
        glTranslated(xpos,ypos,zpos);
    }


    if(key=='+')
    {
                float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f)*2;
        ypos-=float((yrotrad)/2);
        glTranslated(xpos,ypos,zpos);
    }

    if (key=='1')
    {

        glTranslatef(xpos,-100,zpos);
        glutPostRedisplay();
    }

    if (key=='2')
    {
        glTranslated(xpos,-200,zpos);
        glFlush();
    }


        if (key=='3')
    {

        glTranslated(xpos,-400,zpos);

    }


    if (key==27)
    {
    exit(0);
    }

}


void display()
{
glClearColor (0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.7,0.7,0.7);
glPushMatrix();
glTranslated(-30,500,-60);
glColor3d(1,1,1);
glScaled(100,100,10);

glPopMatrix();

{

{//tower
{//bottom

    {//side1
     {//base

    glPushMatrix();//left base 1
    glTranslatef(-55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 1
    glTranslatef(55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 2
    glTranslatef(-53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 2
    glTranslatef(53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 3
    glTranslatef(-51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 3
    glTranslatef(51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();

    glPushMatrix();//arch
    glScaled(3,7.2,5);
    glTranslatef(-1,0,-1);
   glRotatef(90,0,0,1);
   glRotatef(-25,0,1,0);
    glPointSize(30);
    glColor3f(0,0,1);
    drawhalfcircle(10);
    glPopMatrix();

    }

    glPushMatrix();//left left bottom beam
    glTranslatef(-47,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(47,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(32,40,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-32,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


        glPushMatrix();//beam1
    glTranslatef(32,60,19);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam2
    glTranslatef(32,65,23);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam3
    glTranslatef(-32,60,19);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam4
    glTranslatef(-32,65,23);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();



    {//left
        glPushMatrix();//cross 1a
    glTranslatef(48,18,4);
    glRotated(140,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(48,18,4);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(42,34,10);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(42,34,10);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(37,50,15);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(37,53,18);
    glRotated(60,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();
    }
    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-48,18,4);
    glRotated(-140,0,0,1);
    glRotated(10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-48,18,4);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-42,34,10);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-42,34,10);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(-37,50,15);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-37,53,18);
    glRotated(-60,0,0,1);
    glRotated(15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

    }
    }

    {//side2
    glTranslatef(0,0,120);
    glRotatef(180,0,1,0);
    {
             {//base

    glPushMatrix();//left base 1
    glTranslatef(-55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 1
    glTranslatef(55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 2
    glTranslatef(-53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 2
    glTranslatef(53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 3
    glTranslatef(-51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 3
    glTranslatef(51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();


    glPushMatrix();//arch
    glScaled(3,7.2,5);
    glTranslatef(-1,0,-1);
   glRotatef(90,0,0,1);
   glRotatef(-25,0,1,0);
    glPointSize(30);
    glColor3f(0,0,1);
    drawhalfcircle(10);
    glPopMatrix();

    }

    glPushMatrix();//left left bottom beam
    glTranslatef(-47,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(47,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(32,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-32,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


        glPushMatrix();//beam1
    glTranslatef(32,60,19);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam2
    glTranslatef(32,65,23);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam3
    glTranslatef(-32,60,19);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam4
    glTranslatef(-32,65,23);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();

    {//left
        glPushMatrix();//cross 1a
    glTranslatef(48,18,4);
    glRotated(140,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(48,18,4);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(42,34,10);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(42,34,10);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(37,50,15);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(37,53,18);
    glRotated(60,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();
    }
    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-48,18,4);
    glRotated(-140,0,0,1);
    glRotated(10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-48,18,4);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-42,34,10);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-42,34,10);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(-37,50,15);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-37,53,18);
    glRotated(-60,0,0,1);
    glRotated(15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

    }
    }
    }

    {//side3
        glTranslatef(-60,0,60);
    glRotatef(90,0,1,0);
{

         {//base

    glPushMatrix();//left base 1
    glTranslatef(-55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 1
    glTranslatef(55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 2
    glTranslatef(-53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 2
    glTranslatef(53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 3
    glTranslatef(-51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 3
    glTranslatef(51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();

    glPushMatrix();//arch
    glScaled(3,7.2,5);
    glTranslatef(-1,0,-1);
   glRotatef(90,0,0,1);
   glRotatef(-25,0,1,0);
    glPointSize(30);
    glColor3f(0,0,1);
    drawhalfcircle(10);
    glPopMatrix();


    }

    glPushMatrix();//left left bottom beam
    glTranslatef(-47,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(47,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(32,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-32,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


        glPushMatrix();//beam1
    glTranslatef(32,60,19);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam2
    glTranslatef(32,65,23);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam3
    glTranslatef(-32,60,19);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam4
    glTranslatef(-32,65,23);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();

    {//left
        glPushMatrix();//cross 1a
    glTranslatef(48,18,4);
    glRotated(140,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(48,18,4);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(42,34,10);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(42,34,10);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(37,50,15);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(37,53,18);
    glRotated(60,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();
    }
    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-48,18,4);
    glRotated(-140,0,0,1);
    glRotated(10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-48,18,4);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-42,34,10);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-42,34,10);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(-37,50,15);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-37,53,18);
    glRotated(-60,0,0,1);
    glRotated(15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

    }
    }
    }
    {//side4
    glTranslatef(0,0,120);
    glRotatef(180,0,1,0);
    {
             {//base

    glPushMatrix();//left base 1
    glTranslatef(-55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 1
    glTranslatef(55,0,0);
    glScalef(25,4,10);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 2
    glTranslatef(-53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 2
    glTranslatef(53,4,0);
    glScalef(25,4,9.7);
    cube();
    glPopMatrix();


    glPushMatrix();//left base 3
    glTranslatef(-51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();


    glPushMatrix();//right base 3
    glTranslatef(51,8,0);
    glScalef(25,5,9.4);
    cube();
    glPopMatrix();

    glPushMatrix();//arch
    glScaled(3,7.2,5);
    glTranslatef(-1,0,-1);
   glRotatef(90,0,0,1);
   glRotatef(-25,0,1,0);
    glPointSize(30);
    glColor3f(0,0,1);
    drawhalfcircle(10);
    glPopMatrix();


    }

    glPushMatrix();//left left bottom beam
    glTranslatef(-47,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(47,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(32,42,12);
    glRotated(110,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-32,42,12);
    glRotated(70,0,0,1);
    glRotated(-20,0,1,0);
    glScalef(77,4,5.6);
    cube();
    glPopMatrix();


        glPushMatrix();//beam1
    glTranslatef(32,60,19);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam2
    glTranslatef(32,65,23);
    glRotated(180,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam3
    glTranslatef(-32,60,19);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();


        glPushMatrix();//beam4
    glTranslatef(-32,65,23);
    glRotated(-180,0,0,1);
    glRotated(10,0,1,0);
    glScalef(15,2,2);
    cube();
    glPopMatrix();

    {//left
        glPushMatrix();//cross 1a
    glTranslatef(48,18,4);
    glRotated(140,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(48,18,4);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(42,34,10);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(42,34,10);
    glRotated(60,0,0,1);
    glRotated(-10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(37,50,15);
    glRotated(140,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(37,53,18);
    glRotated(60,0,0,1);
    glRotated(-15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();
    }
    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-48,18,4);
    glRotated(-140,0,0,1);
    glRotated(10,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-48,18,4);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(21,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-42,34,10);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(27,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-42,34,10);
    glRotated(-60,0,0,1);
    glRotated(10,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

        glPushMatrix();//cross 3a
    glTranslatef(-37,50,15);
    glRotated(-140,0,0,1);
    glRotated(15,0,1,0);
    glScalef(29,2,3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-37,53,18);
    glRotated(-60,0,0,1);
    glRotated(15,0,1,0);
    glScalef(22,2,3);
    cube();
    glPopMatrix();

    }
    }
    }



glPushMatrix();//level 1
glTranslatef(0,75,60);
glScalef(15,8,15);
glColor3f(1,0,0);
glRotatef(90,1,0,0);
glRotated(45,0,0,1);
glutSolidTorus(1,2.8,100,4);
glPopMatrix();
}

{//middle
    {//side1
        glPushMatrix();//left left bottom beam
    glTranslatef(-30,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(30,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(15,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-15,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(27,91,26);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(27,91,26);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(25,107,28);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(25,107,28);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(23,122,30);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(23,122,30);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(21,137,32);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(21,137,32);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(19,152,34);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(19,152,34);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(18,165,35);
    glRotated(180,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }

    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-27,91,26);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-27,91,26);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-25,107,28);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-25,107,28);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(-23,122,30);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-23,122,30);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-21,137,32);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-21,137,32);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(-19,152,34);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(-19,152,34);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(-18,165,35);
    glRotated(-180,0,0,1);
    glRotated(4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }


    }

    {//side2

        glTranslatef(0,0,120);
    glRotatef(180,0,1,0);
    {

        glPushMatrix();//left left bottom beam
    glTranslatef(-30,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(30,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(15,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-15,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(27,91,26);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(27,91,26);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(25,107,28);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(25,107,28);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(23,122,30);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(23,122,30);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(21,137,32);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(21,137,32);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(19,152,34);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(19,152,34);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(18,165,35);
    glRotated(180,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }

    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-27,91,26);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-27,91,26);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-25,107,28);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-25,107,28);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(-23,122,30);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-23,122,30);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-21,137,32);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-21,137,32);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(-19,152,34);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(-19,152,34);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(-18,165,35);
    glRotated(-180,0,0,1);
    glRotated(4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }
    }
    }

    {//side3

        glTranslatef(-60,0,60);
    glRotatef(90,0,1,0);
{

        glPushMatrix();//left left bottom beam
    glTranslatef(-30,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(30,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(15,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-15,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(27,91,26);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(27,91,26);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(25,107,28);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(25,107,28);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(23,122,30);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(23,122,30);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(21,137,32);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(21,137,32);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(19,152,34);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(19,152,34);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(18,165,35);
    glRotated(180,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }

    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-27,91,26);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-27,91,26);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-25,107,28);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-25,107,28);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(-23,122,30);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-23,122,30);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-21,137,32);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-21,137,32);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(-19,152,34);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(-19,152,34);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(-18,165,35);
    glRotated(-180,0,0,1);
    glRotated(4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }

}
    }

    {//side4

        glTranslatef(0,0,120);
    glRotatef(180,0,1,0);
    {

        glPushMatrix();//left left bottom beam
    glTranslatef(-30,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(30,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(15,125,30);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-15,125,30);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(100,4,4);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(27,91,26);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(27,91,26);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(25,107,28);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(25,107,28);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(23,122,30);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(23,122,30);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(21,137,32);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(21,137,32);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(19,152,34);
    glRotated(130,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(19,152,34);
    glRotated(60,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(18,165,35);
    glRotated(180,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }

    {//right
        glPushMatrix();//cross 1a
    glTranslatef(-27,91,26);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-27,91,26);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(22,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-25,107,28);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-25,107,28);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 3a
    glTranslatef(-23,122,30);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-23,122,30);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-21,137,32);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-21,137,32);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    glPushMatrix();//cross 5a
    glTranslatef(-19,152,34);
    glRotated(-130,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 5b
    glTranslatef(-19,152,34);
    glRotated(-60,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


        glPushMatrix();//beam
    glTranslatef(-18,165,35);
    glRotated(-180,0,0,1);
    glRotated(4,0,1,0);
    glScalef(17,2,1.3);
    cube();
    glPopMatrix();
    }
    }
    }

glPushMatrix();//level 2
glTranslatef(0,175,60);
glScalef(12,8,12);
glColor3f(0,0,1);
glRotatef(90,1,0,0);
glRotated(45,0,0,1);
glutSolidTorus(1,2.8,100,4);
glPopMatrix();





}

{//top

    {//side1

    glPushMatrix();//left left bottom beam
    glTranslatef(-13,278,43);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(13,278,43);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(5,210,35);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-5,210,35);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,303,45);
    glRotated(90,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(130,6,3);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(14,200,35);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(14,200,35);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(10,233,39);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(10,233,39);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(8,263,42);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(8,263,42);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(6,287,44);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(6,287,44);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }


        {//right
        glPushMatrix();//cross 1a
    glTranslatef(-14,200,35);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-14,200,35);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-10,233,39);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-10,233,39);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(-8,263,42);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-8,263,42);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-6,287,44);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-6,287,44);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }



    }


    {//side2
    glTranslatef(0,0,120);
    glRotatef(180,0,1,0);
    {

    glPushMatrix();//left left bottom beam
    glTranslatef(-13,278,43);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(13,278,43);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(5,210,35);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-5,210,35);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,303,45);
    glRotated(90,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(130,6,3);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(14,200,35);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(14,200,35);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(10,233,39);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(10,233,39);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(8,263,42);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(8,263,42);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(6,287,44);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(6,287,44);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }


        {//right
        glPushMatrix();//cross 1a
    glTranslatef(-14,200,35);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-14,200,35);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-10,233,39);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-10,233,39);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(-8,263,42);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-8,263,42);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-6,287,44);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-6,287,44);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }
    }

}
    {//side3
     glTranslatef(-60,0,60);
    glRotatef(90,0,1,0);

    {

    glPushMatrix();//left left bottom beam
    glTranslatef(-13,278,43);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(13,278,43);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(5,210,35);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-5,210,35);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,303,45);
    glRotated(90,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(130,6,3);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(14,200,35);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(14,200,35);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(10,233,39);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(10,233,39);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(8,263,42);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(8,263,42);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(6,287,44);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(6,287,44);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }


        {//right
        glPushMatrix();//cross 1a
    glTranslatef(-14,200,35);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-14,200,35);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-10,233,39);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-10,233,39);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(-8,263,42);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-8,263,42);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-6,287,44);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-6,287,44);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }
    }

}
    {//side4

    glTranslatef(0,0,120);
    glRotatef(180,0,1,0);


    {

    glPushMatrix();//left left bottom beam
    glTranslatef(-13,278,43);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

        glPushMatrix();//right right bottom beam
    glTranslatef(13,278,43);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(200,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();//right left bottom beam
    glTranslatef(5,210,35);
    glRotated(97,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();


    glPushMatrix();//left right bottom beam
    glTranslatef(-5,210,35);
    glRotated(83,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(60,3,3);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,303,45);
    glRotated(90,0,0,1);
    glRotated(-6,0,1,0);
    glScalef(130,6,3);
    cube();
    glPopMatrix();


    {//left
        glPushMatrix();//cross 1a
    glTranslatef(14,200,35);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(14,200,35);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(10,233,39);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(10,233,39);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(8,263,42);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(8,263,42);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(6,287,44);
    glRotated(120,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(6,287,44);
    glRotated(70,0,0,1);
    glRotated(-4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }


        {//right
        glPushMatrix();//cross 1a
    glTranslatef(-14,200,35);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross1b
    glTranslatef(-14,200,35);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2a
    glTranslatef(-10,233,39);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 2b
    glTranslatef(-10,233,39);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(37,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3a
    glTranslatef(-8,263,42);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 3b
    glTranslatef(-8,263,42);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(28,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4a
    glTranslatef(-6,287,44);
    glRotated(-120,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();


    glPushMatrix();//cross 4b
    glTranslatef(-6,287,44);
    glRotated(-70,0,0,1);
    glRotated(4,0,1,0);
    glScalef(23,2,1.3);
    cube();
    glPopMatrix();

    }
    }

}
}


{//end

    glPushMatrix();//level 3(a)
glTranslatef(0,370,60);
glScalef(5,7,5);
glColor3f(1,0,0);
glRotatef(90,1,0,0);
glRotated(45,0,0,1);
glutSolidTorus(2,2.8,100,4);
glPopMatrix();


    glPushMatrix();//level 3(b)
glTranslatef(0,390,60);
glScalef(20,20,20);
cube();
glPopMatrix();


    glPushMatrix();//level 3(c)
glTranslatef(0,400,60);
glScalef(5,7,5);
glColor3f(0,0,1);
glRotatef(90,1,0,0);
glRotated(45,0,0,1);
glutSolidSphere(2,15,15);
glPopMatrix();

glPushMatrix();//level 3(c)
glTranslatef(0,450,60);
glScalef(3,80,3);
cube();
glPopMatrix();

glPushMatrix();
glTranslatef(0,430,60);
glColor3d(1,0,0);
glScaled(10,10,10);
glBegin(GL_POLYGON);
glVertex3d(0,3,0);
glVertex3d(0,6,0);
glVertex3d(5,6,0);
glEnd();
glPopMatrix();


}
}//end of tower

    {//ground
    glPushMatrix();
    glColor3f(0.545098,0.270588,0.0745098);
    ground(0.1);
    glPopMatrix();

    glPushMatrix();//green ground
    glColor3f(0.180392 ,0.545098 ,0.341176);
    glTranslated(0,-0.79,60);
glScaled(600,0.1,600);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();//blue ground water
    glColor3f(0,0.74902,1);
    glTranslated(0,-0.80,60);
glScaled(1500,0.1,1500);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();//grey floor
    glColor3f(.411765,.411765,.411765);
    glTranslated(0,-0.83,60);
glScaled(3000,0.1,3000);
glutSolidCube(1);
glPopMatrix();

//moon
glPushMatrix();
glColor3f(0.9,0.9,0.9);
glTranslatef(500,700,-500);
glutSolidSphere(50,slices,stacks);
glPopMatrix();

//buildings
{


for(i=1;i<=6;i++)
    {
    {

    glPushMatrix();
    glTranslated(-1200,0,-1350+(500*i));//left
    glScaled(3,3,3);
    {
    //orange house
    glPushMatrix();
    glTranslated(0,0,-170+(1*i));
    {
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(0.698039,0.133333,0.133333);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(.698038,0.133333,0.133333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of orange house

    //green house
    glPushMatrix();
    glTranslated(0,0,-120+(1*i));
    glScaled(1,2,1);
    {
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,1,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of green house


    //purple house
    glPushMatrix();
    glTranslated(0,0,-60+(1*i));
    glScalef(1,4,1.3);
    {
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,0,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,0.960784,0.933333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of purple house



}
glPopMatrix();//end of left

glPushMatrix();
glRotated(180,0,1,0);//right
    glTranslated(-1200,0,-1350+(500*i));
    glScaled(3,3,3);
    {

        //orange house
    glPushMatrix();
    glTranslated(0,0,-170+(1*i));
    {
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(0.698039,0.133333,0.133333);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(.698038,0.133333,0.133333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of orange house

    //green house
    glPushMatrix();
    glTranslated(0,0,-120+(1*i));
    glScaled(1,2,1);
    {
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,1,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of green house


    //purple house
    glPushMatrix();
    glTranslated(0,0,-60+(1*i));
    glScalef(1,4,1.3);
    {
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,0,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,0.960784,0.933333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of purple house




}
glPopMatrix();

glPushMatrix();
glRotated(90,0,1,0);//back
    glTranslated(-1150,0,-1350+(500*i));
    glScaled(3,3,3);
    {
    //orange house
    glPushMatrix();
    glTranslated(0,0,-170+(1*i));
    {
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(0.698039,0.133333,0.133333);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(.698038,0.133333,0.133333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of orange house

    //green house
    glPushMatrix();
    glTranslated(0,0,-120+(1*i));
    glScaled(1,2,1);
    {
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,1,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of green house


    //purple house
    glPushMatrix();
    glTranslated(0,0,-60+(1*i));
    glScalef(1,4,1.3);
    {
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,0,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,0.960784,0.933333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of purple house




}
glPopMatrix();

glPushMatrix();
glRotated(270,0,1,0);//front
    glTranslated(-1175,0,-1350+(500*i));
    glScaled(3,3,3);
    {
        //orange house
    glPushMatrix();
    glTranslated(0,0,-170+(1*i));
    {
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.54902,0);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(0.698039,0.133333,0.133333);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(.698038,0.133333,0.133333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of orange house

    //green house
    glPushMatrix();
    glTranslated(0,0,-120+(1*i));
    glScaled(1,2,1);
    {
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0.498039);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,1,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.443137,0.776471,0.443137);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of green house


    //purple house
    glPushMatrix();
    glTranslated(0,0,-60+(1*i));
    glScalef(1,4,1.3);
    {
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-40,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-90.0,12.5,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,-25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(.415686,.352941,.803922);
    glTranslated(-65.0,12.5,25.0);
    glRotated(90.0,0.0,0.0,1.0);
    wall1(0.5);
    glPopMatrix();

    glPushMatrix();//roof
    glColor3f(1,0,1);
    glTranslated(-65,25,0);
    glScalef(60,1,60);
   // glRotated(45,1,1,0);
    glutSolidCube(1);
    glPopMatrix();
//window
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.713725,0.756863);
    glTranslated(-39.5,12.5,-18.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(8,1,8);
    glutSolidCube(1);
    glPopMatrix();
    //door
    glPushMatrix();
    glColor3f(1,0.960784,0.933333);
    glTranslated(-39.5,9,0.0);
    glRotated(90.0,0.0,0.0,1.0);
    glScaled(18,1,10);
    glutSolidCube(1);
    glPopMatrix();
    //chimney
    glPushMatrix();
    glColor3f(1,1,0.941176);
    glTranslated(-38,28,15);
    glScalef(2,6,2);
    glutSolidCube(1);
    glPopMatrix();


}
glPopMatrix();//end of purple house



}
glPopMatrix();



    }

}//for

}

//bridge
{
    glPushMatrix();
    glColor3f(1,.9,0);
    glTranslatef(0,0,-365);
    glScaled(30,2,650);
    glutSolidCube(1);
    glPopMatrix();
}


//trees
{

for(i=0;i<=59;i++)//back boundary
{


glPushMatrix();
glTranslated(-295+(10*i),2,310);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,310);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-295+(10*i),2,320);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,320);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-295+(10*i),2,330);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,330);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-295+(10*i),2,340);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,340);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-295+(10*i),2,350);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,350);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-295+(10*i),2,360);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295+(10*i),0,360);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

}

for(i=0;i<=53;i++)//right boundary
{

glPushMatrix();
glTranslated(295,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(295,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(285,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(285,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(275,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(275,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(265,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(265,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(255,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(255,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

}

for(i=0;i<=53;i++)//left boundary
{

glPushMatrix();
glTranslated(-295,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-295,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-285,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-285,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-275,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-275,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-265,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-265,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-255,2,300-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-255,0,300-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

}

for(i=0;i<=22;i++)//front boundary
{

glPushMatrix();
glTranslated(-245+(10*i),2,-230);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-245+(10*i),2,-230);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(245-(10*i),2,-230);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(245-(10*i),2,-230);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-245+(10*i),2,-220);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-245+(10*i),2,-220);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(245-(10*i),2,-220);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(245-(10*i),2,-220);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-245+(10*i),2,-210);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-245+(10*i),2,-210);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(245-(10*i),2,-210);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(245-(10*i),2,-210);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-245+(10*i),2,-200);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-245+(10*i),2,-200);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(245-(10*i),2,-200);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(245-(10*i),2,-200);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();



}

for(i=0;i<=10;i++)//back
{

glPushMatrix();
glTranslated(-100+(10*i),2,160);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),0,160);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-100+(10*i),2,170);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),0,170);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-100+(10*i),2,180);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),0,180);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-100+(10*i),2,190);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),0,190);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-100+(10*i),2,200);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),0,200);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}

for(i=0;i<=10;i++)//back
{

glPushMatrix();
glTranslated(100-(10*i),2,160);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),0,160);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,170);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),0,170);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,180);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),0,180);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,190);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),0,190);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,200);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),0,200);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

}

for(i=0;i<=33;i++)//right
{

glPushMatrix();
glTranslated(140,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(140,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(130,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(130,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(120,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(120,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(110,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(110,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(100,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}

for(i=0;i<=33;i++)//left
{

glPushMatrix();
glTranslated(-100,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-140,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-140,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-130,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-130,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-120,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-120,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-110,2,200-(10*i));
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-110,0,200-(10*i));
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();

}


for(i=0;i<=3;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-40);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-40);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-40);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-40);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


for(i=0;i<=4;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-50);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-50);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-50);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-50);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


for(i=0;i<=5;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-60);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-60);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-60);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-60);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


for(i=0;i<=6;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-70);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-70);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-70);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-70);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=7;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-80);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-80);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-80);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-80);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-90);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-90);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-90);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-90);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-100);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-100);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-100);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-100);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-110);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-110);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-110);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-110);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-120);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-120);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-120);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-120);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}



    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-130);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-130);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-130);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-130);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}


    for(i=0;i<=8;i++)//front
{

glPushMatrix();
glTranslated(-100+(10*i),2,-130);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(-100+(10*i),2,-130);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(100-(10*i),2,-130);
glColor3f(0,1,0);
glRotated(-90,1,0,0);
glutSolidCone(5,20,slices,stacks);
glPopMatrix();
glPushMatrix();
glTranslated(100-(10*i),2,-130);
glScaled(3,5,3);
glColor3f(0.803922 ,0.521569, 0.247059);
glutSolidCube(1);
glPopMatrix();
}

}
    }

    glTranslated(0,450,0);
    {//stars


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,330);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,600,3100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1400,300,4150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2600,200,4440);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,4450);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,4170);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1200,500,4420);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1400,300,4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1600,900,4100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1800,1000,440);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2000,600,4450);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(40,300,-4100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,300,-4420);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,-4450);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,300,-4175);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4000,300,-4150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,300,-4480);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-4490);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,300,-140);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,4440);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,300,-4100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2200,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,700,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,400,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,450,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,900,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,1000,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2400,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,-1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,300,-1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,300,-1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3330,400,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,600,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,200,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,500,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,900,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,1000,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,600,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,300,-4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,300,-4400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,300,-4300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,300,-4900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,300,-4800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,300,-4500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,300,-4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,300,-4800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,300,-4400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(330,400,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,600,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,200,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,500,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,900,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,1000,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,600,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3330,300,-3200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,300,-3400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,-3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,300,-3300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,300,-3900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,300,-3800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,300,-3500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,300,-3200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,-3800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-5000,300,-3400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4440,400,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,600,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,200,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,700,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4000,400,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,500,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,900,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,1000,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-5000,600,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4300,300,2200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,300,2400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,2300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,300,2900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,300,2800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1200,300,2500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2400,300,2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2600,300,2200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2800,300,2800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,300,2400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,400,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,600,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2400,300,150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,200,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,400,170);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,500,20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,900,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,1000,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-5000,600,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4330,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2200,300,-20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,-50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2800,300,-175);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2000,300,-150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,300,-80);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-90);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,300,-10);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,300,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3330,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,200,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,500,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,900,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,1000,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4440,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,-1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,300,-1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4000,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,300,-1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-5000,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();




    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4440,400,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,600,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,200,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,700,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,400,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,500,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,900,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,1000,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,600,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4440,300,1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1200,300,1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2600,300,1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2800,300,1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,4800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2200,300,1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,300,1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,300,1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(40,400,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2200,600,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2600,200,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2800,700,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,500,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,900,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,1000,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,600,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3330,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,300,-300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,300,-900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,300,-800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,300,-500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,-800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4440,400,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(5000,600,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(40,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1600,200,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2800,700,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,500,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2600,900,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,1000,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-5000,600,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(30,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2200,300,400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1800,300,900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1200,300,500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,300,400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,600,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1400,300,150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2600,200,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3000,400,170);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1200,500,20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1400,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1600,900,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1800,1000,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2000,600,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(40,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4200,300,-20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4400,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4600,300,-50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4800,300,-175);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4000,300,-150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4200,300,-80);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4400,300,-90);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4600,300,-10);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4800,300,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-4000,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(30,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3200,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3600,200,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(3800,700,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(4000,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3200,500,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3600,900,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3800,1000,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-3000,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(20,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2200,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2600,300,-1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2800,300,-1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(2000,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2200,300,-1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2600,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2800,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-2000,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();




    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,-4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,-4400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,-4300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,-4900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,-4800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,-4500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-4600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,-4200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,-4800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,-4400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,-3200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,-3400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,-3300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,-3900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,-3800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,-3500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-3600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,-3200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,-3800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,-3400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,-2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,2200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,2400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,2300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,2900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,2800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,2500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,2600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,2200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,2800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,2400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,170);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,-20);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,-50);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,-175);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,-150);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,-80);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-90);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,-10);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,0);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,-100);
glutSolidSphere(4,slices,stacks);
glPopMatrix();


    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,-1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,-1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,-1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,-1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,-1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,-1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();




    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,1300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,1900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,1500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,1600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,1200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,1800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,1400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,-300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,-900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,-800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,-500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,-600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,-200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,-800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,-400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,400,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,600,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,200,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,700,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,400,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,500,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,900,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,1000,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,600,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();





    glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(0,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(200,300,400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(600,300,300);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(800,300,900);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(1000,300,800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-200,300,500);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-400,300,600);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-600,300,200);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-800,300,800);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3f(0.9,0.91,0.98);
glTranslatef(-1000,300,400);
glutSolidSphere(4,slices,stacks);
glPopMatrix();

}


    glutPostRedisplay();
    glLoadIdentity();


{//camera and man
    glTranslatef(0.0f,ypos-8, (-cRadius));//camera position
    glRotatef(xrot,1.0,0.0,0.0);//camera rotation angle
{

    glPushMatrix();
    glTranslatef(0.0f,-ypos-2.0f,-cRadius);
    glColor3f(1,0,0);
    glScalef(0.9,1.8,1);
    glutSolidSphere(1,slices,stacks);//chest
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,-ypos+0.7,-cRadius);
    glColor3f(0.870588,0.721569,0.529412);
    glScalef(0.8,1.3,0.8);
    glutSolidSphere(1,slices,stacks);//head
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2f,-ypos-1.3f,-cRadius);
    glRotatef(-30,0,0,1);
    glColor3f(1,0,0);
    glScalef(0.3,1,0.3);
    glutSolidSphere(1,slices,stacks);//left upper arm
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5f,-ypos-2.9f,-cRadius-0.2);
    glRotatef(20,1,0,0);
    glColor3f(0.870588,0.721569,0.529412);
    glScalef(0.3,1,0.3);
    glutSolidSphere(1,slices,stacks);//left lower arm
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2f,-ypos-1.3f,-cRadius);
    glRotatef(30,0,0,1);
    glColor3f(1,0,0);
    glScalef(0.3,1,0.3);
    glutSolidSphere(1,slices,stacks);//right upper arm
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f,-ypos-2.9f,-cRadius-0.2);
    glRotatef(20,1,0,0);
    glColor3f(0.870588,0.721569,0.529412);
    glScalef(0.3,1,0.3);
    glutSolidSphere(1,slices,stacks);//right lower arm
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f,-ypos-4.7f,-cRadius);
    glRotatef(5,0,0,1);
    glColor3f(0,0,1);
    glScalef(0.4,1.3,0.3);
    glutSolidSphere(1,slices,stacks);//right upper leg
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.7f,-ypos-6.7f,-cRadius);
    glRotatef(3,0,0,1);
    glColor3f(0,0,1);
    glScalef(0.3,1.2,0.27);
    glutSolidSphere(1,slices,stacks);//right lower leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6f,-ypos-4.7f,-cRadius);
    glRotatef(-5,0,0,1);
    glColor3f(0,0,1);
    glScalef(0.4,1.3,0.3);
    glutSolidSphere(1,slices,stacks);//left upper leg
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.7f,-ypos-6.7f,-cRadius);
    glRotatef(-3,0,0,1);
    glColor3f(0,0,1);
    glScalef(0.3,1.2,0.27);
    glutSolidSphere(1,slices,stacks);//left lower leg
    glPopMatrix();


    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,ypos-8,-zpos); //translate the screento the position of our camera(lower body)
}


}
   }
   glFlush();
   glutPostRedisplay();
    glutSwapBuffers();
}


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 200.0f, 200.0f, 200.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };



int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1440,1220);
    glutInitWindowPosition(0,0);
    glutCreateWindow("CG PROJECT 2017");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
     glutPassiveMotionFunc(mouseMovement);
    glutKeyboardFunc (keyboard);

     glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
