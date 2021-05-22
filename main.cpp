#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

float angle[]={0,0,0,0,0},j,k=0,l=0,m;
int turn[]={0,1,0,0},i,act=0,eyem=0,f=0,text_no=0,view=1;
int moveL=0,moveR=0,o=0;
bool setAnimation=false;

static int submenu_id;
static int submenu_id1;
static int submenu_page;

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
        //hand movement with excitement
        /*
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
        */
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

    //move left
    if(moveL==1)
    {
        if(l<=501 && l>-500)
            l-=0.3;
    }
    if(moveR==1)
    {
        if(l>=-501 && l<=500)
            l+=0.3;
        else {
            l=500;
            moveR=0;
        }

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
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        glColor3f(0.9,0,0.9);
        glPushMatrix();
        glTranslatef(l,200,0);   //setting base of a semicircle as y=200
        circle(170,0,180);
        glPopMatrix();

        glBegin(GL_POLYGON);
        glVertex2f(-170+l,-50);
        glVertex2f(170+l,-50);
        glVertex2f(170+l,200);
        glVertex2f(-170+l,200);
        glEnd();

        glPushMatrix();
        glTranslatef(l,-50,0);   //setting base of a semicircle as y=-50
        glScalef(1,0.6,1);
        circle(170,180,360);     // semicircle from 180 to 360
        glPopMatrix();

        glPushMatrix();
        glTranslatef(l,0,0);
        glBegin(GL_POLYGON);//T
        glVertex2f(-10,350);
        glVertex2f(10,350);
        glVertex2f(10,400);
        glVertex2f(-10,400);
        glEnd();
        glBegin(GL_POLYGON);//T
        glVertex2f(-30,400);
        glVertex2f(30,400);
        glVertex2f(30,420);
        glVertex2f(-30,420);
        glEnd();
        glBegin(GL_POLYGON);//lB
        glVertex2f(170,200);
        glVertex2f(170,180);
        glVertex2f(200,180);
        glVertex2f(200,200);
        glEnd();
        glBegin(GL_POLYGON);//Lb
        glVertex2f(200,220);
        glVertex2f(200,160);
        glVertex2f(220,160);
        glVertex2f(220,220);
        glEnd();
        glBegin(GL_POLYGON);//RB
        glVertex2f(-170,200);
        glVertex2f(-200,200);
        glVertex2f(-200,180);
        glVertex2f(-170,180);
        glEnd();
        glBegin(GL_POLYGON);//Rb
        glVertex2f(-220,220);
        glVertex2f(-220,160);
        glVertex2f(-200,160);
        glVertex2f(-200,220);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(80,320);
        glVertex2f(90,300);
        glVertex2f(155,330);
        glVertex2f(140,350);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(130,360);
        glVertex2f(160,320);
        glVertex2f(170,330);
        glVertex2f(140,370);
        glEnd();
        glBegin(GL_POLYGON);//LTcheck
        glVertex2f(-155,330);
        glVertex2f(-90,300);
        glVertex2f(-80,320);
        glVertex2f(-140,350);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(-170,330);
        glVertex2f(-160,320);
        glVertex2f(-130,360);
        glVertex2f(-140,370);
        glEnd();
        glPopMatrix();
        return;
    }


    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
    {
        glColor3f(0.9,0,0.9);
        glPushMatrix();
        glBegin(GL_POLYGON);//T
        glVertex2f(-10,350);
        glVertex2f(10,350);
        glVertex2f(10,400);
        glVertex2f(-10,400);
        glEnd();
        glBegin(GL_POLYGON);//T
        glVertex2f(-30,400);
        glVertex2f(30,400);
        glVertex2f(30,420);
        glVertex2f(-30,420);
        glEnd();
        glBegin(GL_POLYGON);//lB
        glVertex2f(170,200);
        glVertex2f(170,180);
        glVertex2f(200,180);
        glVertex2f(200,200);
        glEnd();
        glBegin(GL_POLYGON);//Lb
        glVertex2f(200,220);
        glVertex2f(200,160);
        glVertex2f(220,160);
        glVertex2f(220,220);
        glEnd();
        glBegin(GL_POLYGON);//RB
        glVertex2f(-170,200);
        glVertex2f(-200,200);
        glVertex2f(-200,180);
        glVertex2f(-170,180);
        glEnd();
        glBegin(GL_POLYGON);//Rb
        glVertex2f(-220,220);
        glVertex2f(-220,160);
        glVertex2f(-200,160);
        glVertex2f(-200,220);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(80,320);
        glVertex2f(90,300);
        glVertex2f(155,330);
        glVertex2f(140,350);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(130,360);
        glVertex2f(160,320);
        glVertex2f(170,330);
        glVertex2f(140,370);
        glEnd();
        glBegin(GL_POLYGON);//LTcheck
        glVertex2f(-155,330);
        glVertex2f(-90,300);
        glVertex2f(-80,320);
        glVertex2f(-140,350);
        glEnd();
        glBegin(GL_POLYGON);//RTcheck
        glVertex2f(-170,330);
        glVertex2f(-160,320);
        glVertex2f(-130,360);
        glVertex2f(-140,370);
        glEnd();
        glPopMatrix();
    }
    if(mood==2)
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }
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
void hair(int mood)
{
    if(mood==1 /*&&( moveL==1 || moveR==1)*/)
    {
        return;
        /*
    glPushMatrix();
    glTranslatef(-20+l,265,0);
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
    glTranslatef(20+l,265,0);
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
    return;
    */
    }

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
void specsframe(int mood)
{
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        //LEFT
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-59+l,200,0);
    glBegin(GL_POLYGON);
    circle2(67,140,200);
    glVertex2f(-110,0);
    glVertex2f(-110,30);
    glEnd();
    glPopMatrix();
    //RIGHT
    glPushMatrix();
    glTranslatef(59+l,200,0);
    glBegin(GL_POLYGON);
    circle2(67,-20,40);
    glVertex2f(110,30);
    glVertex2f(110,0);
    glEnd();
    glPopMatrix();
        return;
    }
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
    if(moveL==1 || moveR==1)
    {
        glColor3f(0,0,0);
        glPushMatrix();
        glTranslatef(l,120,0);
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
        return;
    }
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
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        //RIGHT
        if(mood==0)
            glColor3f(1,1,0);
        if(mood==1)
            glColor3f(0.9,0,0.9);
        if(mood==2)
            glColor3f(1,0.3,0.3);

        glPushMatrix();
        glTranslatef(30+l,160,0);    //complete circle near eyes
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
        glVertex2f(0+l,-10);
        glVertex2f(100+l,-10);
        glVertex2f(100+l,10);
        glVertex2f(0+l,10);
        glEnd();

        //gloves
        glPushMatrix();
        glTranslatef(125+l,0,0);
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
        glTranslatef(-160+l,30,0);
        if(mood==0)
            glColor3f(1,1,0);
        if(mood==1)
            glColor3f(0.9,0,0.9);
        if(mood==2)
            glColor3f(1,0.3,0.3);
        circle(25,0,360);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-165+l,28,0);
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
            return;
    }
    //RIGHT
    if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }

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
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }
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
void cloth(int mood)
{
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        glPushMatrix();
        glTranslatef(l,-50,0);
        glScalef(1,0.6,1);
        glColor3f(0,0,1);
        circle(170,180,360);
        glPopMatrix();
        glBegin(GL_POLYGON);
        glVertex2f(-100+l,-100);
        glVertex2f(100+l,-100);
        glVertex2f(100+l,50);
        glVertex2f(-100+l,50);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(-100+l,30);
        glVertex2f(-90+l,50);
        glVertex2f(-170+l,90);
        glVertex2f(-170+l,70);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(100+l,30);
        glVertex2f(90+l,50);
        glVertex2f(170+l,90);
        glVertex2f(170+l,70);
        glEnd();
        return;
    }
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
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        //left
        glColor3f(0.75,0.75,0.75);
        glPushMatrix();
        glTranslatef(-59+l,200,0);
        circle(67,0,360);
        glColor3f(1,1,1);
        circle(50,0,360);
        glPopMatrix();
        //right
        glColor3f(0.75,0.75,0.75);
        glPushMatrix();
        glTranslatef(59+l,200,0);
        circle(67,0,360);
        glColor3f(1,1,1);
        circle(50,0,360);
        glPopMatrix();

        glColor3f(0.9,0,0.9);

        glPushMatrix();
        if(eyem==0)
            glTranslatef(-40+l,200,0);
        if(eyem==1)
        {
            glTranslatef(-60+l,200,0);
            glRotatef(angle[4],0,0,1);
            glTranslatef(15+l,0,0);
        }
        circle(22,0,360);
        glColor3f(0,0,0);
        circle(11,0,360);
        glPopMatrix();

        //right eyeball
        glColor3f(0.9,0,0.9);

        glPushMatrix();
        if(eyem==0)
            glTranslatef(40+l,200,0);
        if(eyem==1)
        {
            glTranslatef(60+l,200,0);
            glRotatef(angle[4],0,0,1);
            glTranslatef(15+l,0,0);
        }
        circle(22,0,360);
        glColor3f(0,0,0);
        circle(11,0,360);
        glPopMatrix();
        return;
    }
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
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }
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
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }
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
void legs(int mood)
{
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        glColor3f(0,0,1);
        glPushMatrix();
        glTranslatef(-50+l,-140,0);
        glBegin(GL_POLYGON);
        glVertex2f(-35,50);
        glVertex2f(30,50);
        glVertex2f(25,-50);
        glVertex2f(-25,-50);
        glEnd();
        glPopMatrix();

        glColor3f(0,0,1);
        glPushMatrix();
        glTranslatef(50+l,-140,0);
        glBegin(GL_POLYGON);
        glVertex2f(-35,50);
        glVertex2f(30,50);
        glVertex2f(25,-50);
        glVertex2f(-25,-50);
        glEnd();
        glPopMatrix();
        return;
    }
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
void shoes(int mood)
{
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        //left
        glPushMatrix();
        glTranslatef(-110+l,-410,0);
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
        glTranslatef(110+l,-410,0);
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
        return;
    }
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
    if(mood==1 &&( moveL==1 || moveR==1))
    {
        glColor3f(0.9,0,0.9);
        //Left
        glPushMatrix();
        glTranslatef(-50+l,-140,0);

        glBegin(GL_POLYGON);
        glVertex2f(-20,0);
        glVertex2f(25,0);
        glVertex2f(25,-67);
        glVertex2f(-20,-67);
        glEnd();
        glPopMatrix();
        //Right
        glPushMatrix();
        glTranslatef(50+l,-140,0);



        glBegin(GL_POLYGON);
        glVertex2f(-25,0);
        glVertex2f(20,0);
        glVertex2f(20,-67);
        glVertex2f(-25,-67);
        glEnd();
        glPopMatrix();
        return;
    }
    //Left
    glPushMatrix();
    glTranslatef(-50,-140,0);

   if(mood==0)
        glColor3f(1,1,0);
    if(mood==1)
        glColor3f(0.9,0,0.9);
    if(mood==2)
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }

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
    {
        if(l==500)
            glColor3f(1,0.3,0.3);
        else
            glColor3f(1,1,0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(-25,0);
    glVertex2f(20,0);
    glVertex2f(20,-67);
    glVertex2f(-25,-67);
    glEnd();
    glPopMatrix();
}
void displayText() {
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-400,-600,0);
    switch(text_no)
    {
    case 0:
        output(0,0,"");
        break;
    case 1:
        output(0,0,"HII everyone,hope everyone are doing fine in home : 2019");
        break;
    case 2:
        output(0,0,"U all are going to watch THE MINION MOVIE: 2020");
        break;
    case 3:
        output(0,0,"Look around all minions carefully: (2020)");
        break;
    case 4:
        output(0,0,"No we did't care for what minion said !!!");
        break;
    case 5:
        output(0,0,"So Evil minion started to spread corona virus !!!(2020)");
        break;
    case 6:
        output(0,0,"Brilliant minion saved its and its family life by wearing mask, Buttt!!");
        break;
    case 7:
        output(0,0,"Other minion did not care and got covid-19");
        break;
    default:
        output(0,0,"");
    }
    glPopMatrix();
}

void animation(int action)
{
    switch(action)
    {
        case 1:
            text_no=1;
            act=1;
            break;
        case 2:
            act=2;
            text_no=2;
            break;
        case 3:
            act=0;
            eyem=1;
            text_no=3;
            break;
        case 4:
            eyem=0;
            text_no=4;
            break;
        case 5:
            moveL=1;moveR=0;
            text_no=5;
            break;
        case 6:
            if(l<500){
            moveR=1;moveL=0;
            text_no=6;
            }
            else text_no=7;

            break;
        case 7:
            moveR=0;moveL=0;
            act=0;
            text_no=7;
            setAnimation=false;
            break;
        default:
            break;
    }
}
void page1(){

    glColor3f(0,0,0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(-1260,-910);
    glVertex2f(1260,-910);
    glVertex2f(1260,710);
    glVertex2f(-1260,710);
    glEnd();

    glColor3f(0,0,1);
    output(-550, 600, "N.M.A.M INSTITUTE OF TECHNOLOGY");
    glColor3f(0,0,0);
    output(-750, 520, "Department of Computer Science and Engineering");

    output(-550, 400, "Mini Project Title:");
    output(-550, 350, "MINIONS");

    output(-550, 250, "Course Code : 18CS607");
    output(-550, 200, "Course Name : Computer Graphics Lab");

    output(-550, 100, "Semester : VI");
    output(0, 100, "Section : C");

    output(-550, -20, "Submitted To :");
    output(-550, -70, "Mr. PUNEETH R P");
    output(-550, -120, "Assistant Professor Gd. II");

    output(-550, -230, "Submitted By :");
    output(-550, -280, "SHASHANK (4NM18CS165)");
    output(-550, -330, "SAURAV S POOJARY (4NM18CS161)");

    output(-550, -520, "Date of submission : ");

    glBegin(GL_LINES);
    glVertex2i(-1050, 490);
    glVertex2i(1050,490);
    glEnd();

}
void page2()
{
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1260,-910);
    glVertex2f(1260,-910);
    glVertex2f(1260,710);
    glVertex2f(-1260,710);
    glEnd();
    glColor3f(1,0,0);
    output(-550, 600, "INTRODUCTION");
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(-550, 590);
    glVertex2i(-110,590);
    glEnd();
    glColor3f(0,0,1);
    output(-950, 400, "COVID-19 simple precautions");
    output(-950, 300, "--> Physical Distancing");
    output(-950, 250, "--> Wearing Mask");
    output(-950, 200, "--> Keeping Rooms Ventilated");
    output(-950, 150, "--> Avoiding Crowds");
    output(-950, 100, "--> Cleaning Hands and Coughing into a Bent Elbow or Tissue");
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    if(view == 1)
        page1();
    else if(view == 2)
        page2();
    else
    {
        land();
        displayText();
        if(setAnimation==true){
            o++;
            if(o>10000)
                animation(7);
            else if(o>6000)
                animation(6);
            else if(o>4000)
                animation(5);
            else if(o>3000)
                animation(4);
            else if(o>2000)
                animation(3);
            else if(o>1000)
                animation(2);
            else
                animation(1);
        }

        for(int i=-1000,mood=0;i<=1000, mood<3;i+=1000, mood++){
        glPushMatrix();
        glTranslatef(i,-200,0);
        if(act==2)
            glTranslatef(0,j,0);
        if(act==3)
            glRotatef(angle[3],0,0,1);
        body(mood);                     // l is needed
        hair(mood);
        specsframe(mood);

        if(mood==0)
            mouthhappy();
        if(mood==1)
            mouthzombie();             // l is needed
        if(mood==2)
            mouthangry();
        hand(mood);
        cloth(mood);
        eyes(mood);                    // l is needed
        legsi(mood);
        legs(mood);
        glPopMatrix();
        }
        for(int i=-1000,mood=0;i<=1000,mood<3;i+=1000,mood++)
        {
            glPushMatrix();
            glTranslatef(i,0,0);
            shoes(mood);
            glPopMatrix();
        }
    }
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();     //glutSwapBuffers swaps the buffers of the current window if double buffered
}

void flag_menu(int num)
{
    switch(num)
    {
        case 1:
            l=0;
            moveL=1;
            moveR=0;
                break;
        case 2:
            moveL=0;
            moveR=1;
                break;
        case 4:
                text_no=1;
                act=1;
                break;
        case 5:act=2;
                break;
        case 7:eyem=1;
                break;
        case 8:eyem=0;
                break;
        case 9:
                l=0;
                act=0;
                moveL=0;
                moveR=0;
                eyem=0;
                break;
        case 10:exit(0);
        case 11:o=0; setAnimation=true; break;
        case 21: view=1; break;
        case 22: view=2; break;
        case 23: view=3; break;
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

    submenu_page = glutCreateMenu(flag_menu);
	glutAddMenuEntry("Home",21);
	glutAddMenuEntry("Instructions",22);
	glutAddMenuEntry("Movie",23);

	submenu_id1 = glutCreateMenu(flag_menu);
	glutAddMenuEntry("left",1);
	glutAddMenuEntry("right",2);
	glutAddMenuEntry("Hi",4);
	glutAddMenuEntry("Get Excited",5);
	glutAddMenuEntry("Look Around",7);
	glutAddMenuEntry("Look Straight",8);
	glutAddMenuEntry("Reset",9);

	glutCreateMenu(flag_menu);
	glutAddSubMenu("page",submenu_page);
	glutAddSubMenu("movement",submenu_id1);
	glutAddMenuEntry("Start Animation",11);
	glutAddMenuEntry("Quit",10);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
