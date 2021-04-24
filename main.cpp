#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

int view=0;
void *font = GLUT_BITMAP_9_BY_15;

void output(int x, int y, char *str)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(str);
  for (i = 0; i < len; i++)
  {
    glutBitmapCharacter(font, str[i]);
  }
}

void homePage()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10,10);
    glVertex2f(490,10);
    glVertex2f(490,690);
    glVertex2f(10,690);
    glEnd();

    glColor3f(0,0,1);
    output(160, 660, "N.M.A.M INSTITUTE OF TECHNOLOGY");
    glColor3f(0,0,0);
    output(120, 630, "Department of Computer Science and Engineering");

    output(120, 540, "Mini Project Title:");
    output(120, 520, "TETRIS GAME");

    output(120, 450, "Course Code : 18CS607");
    output(120, 470, "Course Name : Computer Graphics Lab");

    output(120, 400, "Semester : VI");
    output(300, 400, "Section : C");

    output(120, 350, "Submitted To :");
    output(120, 320, "Mr. PUNEETH R P");
    output(120, 300, "Assistant Professor Gd. II");

    output(120, 250, "Submitted By :");
    output(120, 220, "SHASHANK (4NM18CS165)");
    output(120, 200, "SAURAV S POOJARY (4NM18CS161)");

    output(120, 150, "Date of submission : ");

    glColor3f(1,0,1);
    output(120, 90, "Press a:Rules page  b:Game page ");

    glBegin(GL_LINES);
    glVertex2i(40,610);
    glVertex2i(460,610);
    glEnd();
}

void rulePage()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10,10);
    glVertex2f(490,10);
    glVertex2f(490,690);
    glVertex2f(10,690);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(40,590);
    glVertex2i(460,590);
    glEnd();

    glColor3f(0,0,1);
    output(220, 660, "TETRIS GAME");
    glColor3f(0,1,0);
    output(120, 610, "RULES");

    output(120, 540, "1.");
    output(120, 500, "2.");
    output(120, 460, "3.");
    output(120, 420, "4.");

    output(120, 120, "Press c:Home page  b:Game page ");



}
void gamePage()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10,10);
    glVertex2f(490,10);
    glVertex2f(490,690);
    glVertex2f(10,690);
    glEnd();

    output(120, 110, "Press c:Home page  a:Rules Page ");

    output(160, 660, "Game page");
}
void changePage(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
            glClear(GL_COLOR_BUFFER_BIT);
            view=1;
            break;
        case 'b':
            glClear(GL_COLOR_BUFFER_BIT);
            view=2;
            break;
        case 'c':
            glClear(GL_COLOR_BUFFER_BIT);
            view=0;
            break;
        case 7:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void myInit(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,700);
}

void display()
{
    if(view==0){
            homePage();
    }

    else if(view==1)
    {
         rulePage();
    }

    else if(view==2)
    {
        gamePage();
    }
    glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(450,70);
  glutInitWindowSize(700, 750);
  glutCreateWindow("Tetris Game");
  myInit();
  glutDisplayFunc(display);
  glutKeyboardFunc(changePage);
  glutMainLoop();
  return 0;
}
