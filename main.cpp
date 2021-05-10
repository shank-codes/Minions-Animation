#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

float angle[]={0,0,0,0,0},j,k=0;
int turn[]={0,1,0,0},i,act=0,eyem=0,f=0;
//int mood=0;
static int submenu_id;
static int submenu_id1;

void Idle()
{
    //hi
    if(act==1)
    {
        if(turn[2]==0&&angle[2]<30)
                angle[2]+=0.5;
        if(angle[2]>=30)
                turn[2]=1;
        if(turn[2]==1&&angle[2]>-30)
                angle[2]-=0.5;
        if(angle[2]<=-30)
                turn[2]=0;
    }

    // get excited
    if(act==2)
    {
        for(i=0;i<2;i++)
        {
            if(turn[i]==0&&angle[i]<45)
                angle[i]+=0.2;
            if(angle[i]>=45)
                turn[i]=1;
            if(turn[i]==1&&angle[i]>-45)
                angle[i]-=0.2;
            if(angle[i]<=-45)
                turn[i]=0;
        }
        if(j<=10&&k==0)
            j+=0.3;
        if(j>10)
            k=1;
        if(j>=-10&&k==1)
            j-=0.3;
        if(j<-10)
            k=0;
    }
    // look around
    if(eyem==1)
    {
        if(angle[4]<360)
                angle[4]+=0.5;
        else
            angle[4]=0;
    }
}
void myReshape(int w,int h)
{
    if(w<=h)
        gluOrtho2D(-1,1,-h/w,h/w);
    else
        gluOrtho2D(-w/h,w/h,-1,1);
    glViewport(0,0,w,h);
}

void init()
{
    glClearColor(0.9,0.9,1,0);
    gluOrtho2D(-1350,1350,-1000,800);
}
void circle(int r,int s,int e)
{
    glBegin(GL_POLYGON);
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(r*cos(theta),r*sin(theta)); // points = (0,180) because r*sin(0) = 0,  r*cos(0) = 900
    }
    glEnd();
}
void circle2(int r,int s,int e)
{
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(r*cos(theta),r*sin(theta));
    }
}
void circle3(int r,int s,int e)
{
    float theta;
    for(int i=s;i>=e;i--)
    {
        theta=(i*3.142)/180;
        glVertex2f(r*cos(theta),r*sin(theta));
    }
}
void land()
{
    glColor3f(0,0.9,0);
    glPushMatrix();
    glTranslatef(0,-1000,0);  //produces a translation of land to -600 in y
    //glScalef(1,0.4,1);       // scaling with scaling factor S in y = 0.5
    //circle(1600,0,180);       // basically drawing a arc with radius = 900, starting = 0 , ending = 180
    glBegin(GL_POLYGON);
    glVertex2f(1350,0);
    glVertex2f(1350,640);
    glVertex2f(-1350,640);
    glVertex2f(-1350,0);
    glEnd();
    glPopMatrix();
}
void body(int mood)
{
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);

    glPushMatrix();
    glTranslatef(0,200,0);   //setting base of a semicircle as y=200
    circle(170,0,180);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex2f(-170,-50);
    glVertex2f(170,-50);
    glVertex2f(170,200);
    glVertex2f(-170,200);
    glEnd();

    glPushMatrix();
    glTranslatef(0,-50,0);   //setting base of a semicircle as y=-50
    glScalef(1,0.6,1);
    circle(170,180,360);     // semicircle from 180 to 360
    glPopMatrix();

    /*
    glPushMatrix();
    glTranslatef(400,200,0);
    circle(170,0,180);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex2f(230,-50);
    glVertex2f(570,-50);
    glVertex2f(570,200);
    glVertex2f(230,200);
    glEnd();

    glPushMatrix();
    glTranslatef(400,-50,0);
    glScalef(1,0.6,1);
    circle(170,180,360);
    glPopMatrix();
    */
}
void hair()
{
    glPushMatrix();
    glTranslatef(-20,265,0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    circle2(100,85,120);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle2(105,85,125);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle2(107,85,130);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle2(108,85,135);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,265,0);
    glBegin(GL_LINE_STRIP);
    circle3(100,95,60);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle3(105,95,55);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle3(107,95,50);
    glEnd();
    glBegin(GL_LINE_STRIP);
    circle3(108,95,45);
    glEnd();
    glPopMatrix();
}
void specsframe()
{
    //LEFT
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-59,200,0);
    glBegin(GL_POLYGON);
    circle2(67,140,200);
    glVertex2f(-110,0);
    glVertex2f(-110,30);
    glEnd();
    glPopMatrix();
    //RIGHT
    glPushMatrix();
    glTranslatef(59,200,0);
    glBegin(GL_POLYGON);
    circle2(67,-20,40);
    glVertex2f(110,30);
    glVertex2f(110,0);
    glEnd();
    glPopMatrix();
}
void mouthhappy()
{
    glColor3f(0.6289,0.9375,0.9179);
    glPushMatrix();
    glTranslatef(0,120,0);
    glScalef(1,0.7,1);
    glBegin(GL_POLYGON);
    glVertex2f(-90,-10);
    glVertex2f(-90,-90);
    glVertex2f(90,-90);
    glVertex2f(90,-10);
    glVertex2f(0,20);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(90,-20);
    glVertex2f(170,30);

    glVertex2f(-90,-20);
    glVertex2f(-170,30);

    glVertex2f(90,-80);
    glVertex2f(170,-30);

    glVertex2f(-90,-80);
    glVertex2f(-170,-30);

    glEnd();
    glPopMatrix();

}
void mouthangry()
{
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0,120,0);
    glScalef(1,0.5,1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-100,-80);
    glVertex2f(-80,-15);
    glVertex2f(80,-15);
    glVertex2f(100,-80);
    glEnd();
    glPopMatrix();
}
void mouthzombie()
{
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0,120,0);
    glScalef(1,0.5,1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-80,-60);
    glVertex2f(80,-60);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-80,-60);
    glVertex2f(-60,0);
    glVertex2f(-40,-60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(80,-60);
    glVertex2f(60,0);
    glVertex2f(40,-60);
    glEnd();
    glPopMatrix();
}
void hand(int mood)
{
    //RIGHT
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);

    glPushMatrix();
    glTranslatef(30,160,0);    //complete circle near eyes
    circle(25,0,360);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(165,28,0);
    if(act==1)
    {
        glRotatef(angle[2],0,0,1);
        glRotatef(40,0,0,1);
    }
    if(act==2)
    glRotatef(angle[0],0,0,1);
    if(act==0)
        glRotatef(angle[0],0,0,1);    //angle =0, z=1

    glBegin(GL_POLYGON);               //right hand rectangle
    glVertex2f(0,-10);
    glVertex2f(100,-10);
    glVertex2f(100,10);
    glVertex2f(0,10);
    glEnd();

    //gloves
    glPushMatrix();
    glTranslatef(125,0,0);
    glRotatef(90,0,0,1);
    glColor3f(0,0,0);
    glPushMatrix();
    glScalef(1,1.2,1);
    glTranslatef(-15,0,0);
    circle(12,0,360);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-6,0);
    circle(12,0,360);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12,0,0);
    circle(12,0,360);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-20,0);
    glVertex2f(17,0);
    glVertex2f(12,25);
    glVertex2f(-17,25);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    //LEFT
    glPushMatrix();
    glTranslatef(-160,30,0);
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);
    circle(25,0,360);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-165,28,0);
    if(act==2)
        glRotatef(angle[2],0,0,1);
    if(act==0)
        glRotatef(-60,0,0,1);
    if(act==1)
        glRotatef(40,0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(0,-10);
    glVertex2f(-100,-10);
    glVertex2f(-100,10);
    glVertex2f(0,10);
    glEnd();
    //gloves
    glPushMatrix();
    glTranslatef(-125,0,0);
    glRotatef(-90,0,0,1);
    glColor3f(0,0,0);
    glPushMatrix();
    glScalef(1,1.2,1);
    glTranslatef(-15,0,0);
    circle(12,0,360);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-6,0);
    circle(12,0,360);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12,0,0);
    circle(12,0,360);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-20,0);
    glVertex2f(17,0);
    glVertex2f(12,25);
    glVertex2f(-17,25);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void cloth()
{
    glPushMatrix();
    glTranslatef(0,-50,0);
    glScalef(1,0.6,1);
    glColor3f(0,0,1);
    circle(170,180,360);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-100,-100);
    glVertex2f(100,-100);
    glVertex2f(100,50);
    glVertex2f(-100,50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(-100,30);
    glVertex2f(-90,50);
    glVertex2f(-170,90);
    glVertex2f(-170,70);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2f(100,30);
    glVertex2f(90,50);
    glVertex2f(170,90);
    glVertex2f(170,70);
    glEnd();
}
void eyes(int mood)
{
    //left
    glColor3f(0.75,0.75,0.75);
    glPushMatrix();
    glTranslatef(-59,200,0);
    circle(67,0,360);
    glColor3f(1,1,1);
    circle(50,0,360);
    glPopMatrix();
    //right
    glColor3f(0.75,0.75,0.75);
    glPushMatrix();
    glTranslatef(59,200,0);
    circle(67,0,360);
    glColor3f(1,1,1);
    circle(50,0,360);
    glPopMatrix();

    //left eyeball
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);
    glPushMatrix();
    if(eyem==0)
        glTranslatef(-40,200,0);
    if(eyem==1)
    {
        glTranslatef(-60,200,0);
        glRotatef(angle[4],0,0,1);
        glTranslatef(15,0,0);
    }
    circle(22,0,360);
    glColor3f(0,0,0);
    circle(11,0,360);
    glPopMatrix();

    //right eyeball
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);
    glPushMatrix();
    if(eyem==0)
        glTranslatef(40,200,0);
    if(eyem==1)
    {
        glTranslatef(60,200,0);
        glRotatef(angle[4],0,0,1);
        glTranslatef(15,0,0);
    }
    circle(22,0,360);
    glColor3f(0,0,0);
    circle(11,0,360);
    glPopMatrix();

}
void legs()
{
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(-50,-140,0);
    glBegin(GL_POLYGON);
    glVertex2f(-35,50);
    glVertex2f(30,50);
    glVertex2f(25,-50);
    glVertex2f(-25,-50);
    glEnd();
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(50,-140,0);
    glBegin(GL_POLYGON);
    glVertex2f(-35,50);
    glVertex2f(30,50);
    glVertex2f(25,-50);
    glVertex2f(-25,-50);
    glEnd();
    glPopMatrix();
}
void shoes()
{
    //left
    glPushMatrix();
    glTranslatef(-110,-410,0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    circle2(15,140,240);
    glVertex2f(60,-15);
    glVertex2f(60,20);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(40,-15);
    glVertex2f(85,-15);
    glVertex2f(85,20);
    glVertex2f(40,20);
    glEnd();
    glPopMatrix();


    //right
    glPushMatrix();
    glTranslatef(110,-410,0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    circle3(15,40,-40);
    glVertex2f(-60,-15);
    glVertex2f(-60,20);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-40,-15);
    glVertex2f(-85,-15);
    glVertex2f(-85,20);
    glVertex2f(-40,20);
    glEnd();
    glPopMatrix();
}
void legsi(int mood)
{
    //Left
    glPushMatrix();
    glTranslatef(-50,-140,0);

   if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(1,0.3,0.3);
    if(mood==2)
        glColor3f(0.9,0,0.9);

    glBegin(GL_POLYGON);
    glVertex2f(-20,0);
    glVertex2f(25,0);
    glVertex2f(25,-67);
    glVertex2f(-20,-67);
    glEnd();
    glPopMatrix();
    //Right
    glPushMatrix();
    glTranslatef(50,-140,0);
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
        glColor3f(1,0.3,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-25,0);
    glVertex2f(20,0);
    glVertex2f(20,-67);
    glVertex2f(-25,-67);
    glEnd();
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    land();
    for(int i=-1000,mood=0;i<=1000, mood<3;i+=1000, mood++){
    glPushMatrix();
    glTranslatef(i,-200,0);
    if(act==2)
        glTranslatef(0,j,0);
    if(act==3)
        glRotatef(angle[3],0,0,1);
    body(mood);
    hair();
    specsframe();

    if(mood==0)
        mouthhappy();
    if(mood==1)
        mouthzombie();
    if(mood==2)
        mouthangry();
    hand(mood);
    cloth();
    eyes(mood);

    if(act==3)
       glPopMatrix();
    legsi(mood);
    legs();
    if(act!=3)
        glPopMatrix();
    }
    for(int i=-1000;i<=1000;i+=1000)
    {
        glPushMatrix();
        glTranslatef(i,0,0);
        shoes();
        glPopMatrix();
    }
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();     //glutSwapBuffers swaps the buffers of the current window if double buffered
}
void flag_menu(int num)
{
    switch(num)
    {
        case 1://mood=0;
                break;
        case 2://mood=1;
                break;
        case 4:act=1;
                break;
        case 5:act=2;
                break;
        case 7:eyem=1;
                break;
        case 8:eyem=0;
                break;
        case 9:act=0;
                eyem=0;
                break;
        case 10:exit(0);
        default:break;
    }
  glutPostRedisplay();
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,750);
    glutCreateWindow("Minion");
    init();
    glutIdleFunc(Idle);
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    submenu_id = glutCreateMenu(flag_menu);
	glutAddMenuEntry("left",1);
	glutAddMenuEntry("right",2);
	submenu_id1 = glutCreateMenu(flag_menu);
	glutAddMenuEntry("Hi",4);
	glutAddMenuEntry("Get Excited",5);
	glutAddMenuEntry("Look Around",7);
	glutAddMenuEntry("Look Straight",8);
	glutAddMenuEntry("Stop Moving",9);
	glutCreateMenu(flag_menu);
	glutAddSubMenu("Move", submenu_id);
	glutAddSubMenu("Animation",submenu_id1);
	glutAddMenuEntry("Quit",10);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
