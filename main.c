#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
void renderbitmap(float x,float y,void *font,char *string);
int y,y2,x1=0,x2=0;
int yx,yx2;
int c=0,c1=0;
void loadingData();
const float DEG2RAD = 3.14159/180.0;
int state=1;
int state2=1;
int state1=1;
void arrow(int x1)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(85+x1,100);
    glVertex2f(110+x1,100);
    glVertex2f(110+x1,90);
    glVertex2f(85+x1,90);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(110+x1,100);
    glVertex2f(110+x1,103);
    glVertex2f(115+x1,95);
    glVertex2f(110+x1,87);
    glVertex2f(110+x1,90);
    
    glEnd();
}
void write(char * str)
{
    
    char buf[100]={0};
    glColor3f(1.0,0.0,0.0);
    sprintf(buf,str);
    renderbitmap(97,104,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}
void timer1(int)
{
    glutPostRedisplay();
    glutTimerFunc(10000/60,timer1,0);
    
    
    switch(state1)
    {
        case 1:
            yx=140;
            if(yx+y>-2)
                y-=2;
            else
                state1=2;
            break;
        case 2:
            yx=300;
            if(yx+y>-8)
                y-=2;
            else
                state1=3;
            break;
        case 3:
            yx=450;
            if(yx+y>-35)
                y-=2;
            /* else
             state1=3;*/
            break;
    }
    
}
void datafall()
{
    
    glPointSize(10.0);
    
    glBegin(GL_POINTS);
    glColor3ub(153,0,153);
    glVertex2i(25,yx+y);
    glEnd();
    
    glBegin(GL_POINTS);
    glColor3ub(0.0,0.0,0.0);
    glVertex2i(10,yx+y+10);
    glEnd();
    
    glBegin(GL_POINTS);
    glColor3ub(255,255,102);
    glVertex2i(175,yx+y+5);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(0,0,102);
    glVertex2i(205,yx+y+15);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(119,136,153);
    glVertex2i(35,yx+y+5);
    
    glEnd();
    glBegin(GL_POINTS);
    
    glColor3ub(255,48,48);
    glVertex2i(50,yx+y+10);
    
    glEnd();
    glBegin(GL_POINTS);
    
    glColor3f(1.0,1.0,0.0);
    glVertex2i(145,yx+y+15);
    
    glEnd();
    glBegin(GL_POINTS);
    
    glColor3f(1.0,0.0,1.0);
    glVertex2i(165,yx+y+20);
    
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(255,114,86);
    glVertex2i(190,yx+y+25);
    glEnd();
    
}
void timer2(int)
{
    //glutPostRedisplay();
    //glutTimerFunc(1000000/60,timer2,0);
    switch(state2)
    {
        case 1:
            yx2=120;
            if(yx2+y2>-2)
                y2-=2;
            else
                state2=2;
            break;
        case 2:
            yx2=250;
            if(yx2+y2>-2)
                y2-=2;
            else
                state2=3;
            break;
        case 3:
            yx2=350;
            if(yx2+y2>-35)
                y2-=2;
            else
                state2=3;
            
            break;
            
    }
    
    // glutPostRedisplay();
}
void datafall2()
{
    
    glPointSize(10.0);
    
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0);
    glVertex2i(20,yx2+y2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(30,yx2+y2+15);
    glVertex2i(33,yx2+y2+15+5);
    glVertex2i(36,yx2+y2+15);
    glVertex2i(33,yx2+y2+15-5);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(0,0,255);
    glVertex2i(50,yx2+y2+10);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3ub(255,0,255);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(64.0+cos(rad)*2.0,yx2+y2+10+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(0,154,205);
    glVertex2i(75,yx2+y2+15);
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(92,yx2+y2+15);
    glVertex2i(95,yx2+y2+15+5);
    glVertex2i(98,yx2+y2+15);
    glVertex2i(95,yx2+y2+15-5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,255,255);
    glVertex2i(101,yx2+y2+15);
    glVertex2i(105,yx2+y2+15);
    glVertex2i(105,yx2+y2+15-5);
    glVertex2i(101,yx2+y2+15-5);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(145,yx2+y2+15);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex2i(135,yx2+y2+15);
    glEnd();
    glBegin(GL_POINTS);
    
    glColor3f(1.0,0.0,0.0);
    glVertex2i(170,yx2+y2+20);
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex2i(180,yx2+y2+15);
    glVertex2i(188,yx2+y2+15);
    glVertex2i(188,yx2+y2+15-5);
    glVertex2i(180,yx2+y2+15-5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(195,yx2+y2+15);
    glVertex2i(198,yx2+y2+15+5);
    glVertex2i(201,yx2+y2+15);
    glVertex2i(198,yx2+y2+15-5);
    glEnd();
}
void slide1()
{
    
    
    //////////////////////////////////////////////////////////////
    //to draw data
    datafall();
    ///////////////////////////////////////////////////////////cylinder line
    glColor3ub(255,255,255);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(85,100.5);
    glVertex2f(85,50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(125,100.5);
    glVertex2i(125,49);
    glEnd();
    
    ///////////////////////////////////////////////////////////////
    //to draw half ellipse
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    for(int i=180; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i*DEG2RAD;
        glVertex2f(105.0+cos(degInRad)*20.0,72.0+sin(degInRad)*20.0);
    }
    glEnd();
    
    //////////////////////////////////////////////////////////////////
    //to draw middle ellipse
    
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    for(int i=180; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i*DEG2RAD;
        glVertex2f(105.0+cos(degInRad)*20.0,50.0+sin(degInRad)*20.0);
    }
    glEnd();
    
    ///////////////////////////////////////////////////////////////////
    //to draw bottom ellipse
    glLineWidth(5.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    //glColor3f(1.0,1.0,0.0);
    for(int i=0; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i*DEG2RAD;
        glVertex2f(105.0+cos(degInRad)*20.0,100.0+sin(degInRad)*20.0);
    }
    glEnd();
    
    
    
    
    /////////////////////////////////////////////TYPE TEXT//////////////////
    glLineWidth(6.0);
    
    glBegin(GL_LINE_LOOP);//letter 'D'
    glColor3ub(153,50,204);
    glVertex2i(20,162);
    glVertex2i(20,198);
    glEnd();
    
    glBegin(GL_LINE_STRIP);//"D" top curve
    glColor3ub(153,50,204);
    for(int i=0; i <90; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f(20.0+cos(degInRad)*10.0,180.0+sin(degInRad)*17.0);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);//"D" down curve
    for(int i=270; i <=360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f(20.0+cos(degInRad)*10.0,180.0+sin(degInRad)*17.0);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'A'
    glColor3ub(255,20,147);
    glVertex2i(32,162);
    glVertex2i(36,182);
    glVertex2i(40,162);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'A' middle line
    glColor3ub(255,20,147);
    glVertex2i(34,172);
    glVertex2i(38,172);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'T'
    glColor3ub(255,20,147);
    glVertex2i(46,162);
    glVertex2i(46,182);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'T' header line
    glColor3ub(255,20,147);
    glVertex2i(42,182);
    glVertex2i(50,182);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'A'
    glColor3ub(255,20,147);
    glVertex2i(52,162);
    glVertex2i(56,182);
    glVertex2i(60,162);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'A' middle line
    glColor3ub(255,20,147);
    glVertex2i(54,172);
    glVertex2i(58,172);
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(10.0);
    glColor3ub(255,99,71);
    glVertex2i(62,162);
    glColor3ub(255,48,48);
    glVertex2i(65,162);
    glColor3ub(255,20,147);
    glVertex2i(68,162);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'w'
    glColor3ub(255,20,147);
    glVertex2i(68,28);
    glVertex2i(73,05);
    glVertex2i(75,15);
    glVertex2i(77,05);
    glVertex2i(82,28);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'A'
    glColor3ub(153,50,204);
    glVertex2i(81,05);
    glVertex2i(86,20);
    glVertex2i(90,05);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'A' middle line
    glColor3ub(153,50,204);
    glVertex2i(83,11);
    glVertex2i(88,11);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'R'  line
    glColor3ub(153,50,204);
    glVertex2i(92,22);
    glVertex2i(92,04);
    glEnd();
    
    glBegin(GL_LINE_STRIP);//"R" top curve
    glColor3ub(153,50,204);
    for(int i=0; i <90; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f(92.0+cos(degInRad)*3.0,13.0+sin(degInRad)*8.0);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);//"D" down curve
    for(int i=270; i <=360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f(92.0+cos(degInRad)*3.0,16.0+sin(degInRad)*6.0);
    }
    
    glEnd();
    glBegin(GL_LINES);//letter 'R'  line
    glColor3ub(153,50,204);
    glVertex2i(92,10);
    glVertex2i(96,05);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'E'  line
    glColor3ub(153,50,204);
    glVertex2i(105,20);
    glVertex2i(98,20);
    glVertex2i(98,05);
    glVertex2i(105,05);
    glEnd();
    glBegin(GL_LINES);//letter 'E'  line
    glColor3ub(153,50,204);
    glVertex2i(98,12);
    glVertex2i(105,12);
    glEnd();
    glBegin(GL_LINES);//letter 'H'  line
    glColor3ub(153,50,204);
    glVertex2i(107,21);
    glVertex2i(107,04);
    glEnd();
    glBegin(GL_LINES);//letter 'H'  line
    glColor3ub(153,50,204);
    glVertex2i(112,21);
    glVertex2i(112,04);
    glEnd();
    glBegin(GL_LINES);//letter 'H'  line
    glColor3ub(153,50,204);
    glVertex2i(107,12);
    glVertex2i(112,12);
    glEnd();
    glBegin(GL_LINE_LOOP);//letter 'O'  line
    glColor3ub(153,50,204);
    glVertex2i(114,20);
    glVertex2i(114,05);
    glVertex2i(120,05);
    glVertex2i(120,20);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'U'  line
    glColor3ub(153,50,204);
    glVertex2i(122,20);
    glVertex2i(122,05);
    glVertex2i(127,05);
    glVertex2i(127,20);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'S'  line
    glColor3ub(153,50,204);
    glVertex2i(129,9);
    glVertex2i(129,05);
    glVertex2i(133,05);
    glVertex2i(133,12);
    glVertex2i(129,12);
    glVertex2i(129,20);
    glVertex2i(133,20);
    glVertex2i(133,17);
    glEnd();
    glBegin(GL_LINE_STRIP);//letter 'E'  line
    glColor3ub(153,50,204);
    glVertex2i(138,20);
    glVertex2i(135,20);
    glVertex2i(135,05);
    glVertex2i(138,05);
    glEnd();
    glBegin(GL_LINES);//letter 'E'  line
    glColor3ub(153,50,204);
    glVertex2i(135,12);
    glVertex2i(138,12);
    glEnd();
    glutPostRedisplay();
}
void renderbitmap(float x,float y,void *font,char *string)//FUNCTION TO CONVERT CHAR INTO RASTERIZE
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string;*c !='\0';c++)
    {
        glutBitmapCharacter(font,*c);
    }
}

void slide2()
{
    glutTimerFunc(0,timer2,0);
    datafall2();
    glPointSize(5.0);
    glLineWidth(15.0);
    float x1,y1,x2,y2;
    float angle;
    double radius=4;
    x1 = 50,y1=180;
    
    
    
    
    
}
float x3=0,y3=0;
void slide3()
{
    if(x3<65 || y3<10){
        x3+=0.5;
        y3+=0.15;
    }
    
    ////////////////////////////////////DATA
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,140);
    glVertex2f(25,145);
    glVertex2f(30,140);
    glVertex2f(25,135);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(33,140);
    glVertex2f(38,140);
    glVertex2f(38,135);
    glVertex2f(33,135);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(40,138);
    glVertex2f(42,138);
    glVertex2f(42,141);
    glVertex2f(40,141);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,140);
    glVertex2f(53,140);
    glVertex2f(53,136);
    glVertex2f(43,136);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(55,145);
    glVertex2f(60,153);
    glVertex2f(65,145);
    glVertex2f(60,137);
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(66.0+x3+cos(rad)*1.0,140.0+y3+sin(rad)*2.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(20.0+x3+cos(rad)*2.0,135.0+y3+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(25,134);
    glVertex2f(35,134);
    glVertex2f(35,130);
    glVertex2f(25,130);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(37,134);
    glVertex2f(42,134);
    glVertex2f(42,129);
    glVertex2f(37,129);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,140);
    glVertex2f(46,140);
    glVertex2f(46,143);
    glVertex2f(44,143);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(46,140);
    glVertex2f(48,140);
    glVertex2f(48,143);
    glVertex2f(46,143);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,140);
    glVertex2f(53,140);
    glVertex2f(53,136);
    glVertex2f(43,136);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,131);
    glVertex2f(46,131);
    glVertex2f(46,128);
    glVertex2f(44,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(47,131);
    glVertex2f(49,131);
    glVertex2f(49,128);
    glVertex2f(47,128);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,131);
    glVertex2f(52,131);
    glVertex2f(52,128);
    glVertex2f(50,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(53,131);
    glVertex2f(55,131);
    glVertex2f(55,128);
    glVertex2f(53,128);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(56,133);
    glVertex2f(66,133);
    glVertex2f(66,128);
    glVertex2f(56,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(20,126);
    glVertex2f(30,126);
    glVertex2f(30,121);
    glVertex2f(20,121);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,126);
    glVertex2f(41,126);
    glVertex2f(41,121);
    glVertex2f(31,121);
    glEnd();
    
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(43.0+cos(rad)*1.0,123.0+sin(rad)*2.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(48.0+cos(rad)*2.0,122.5+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(52,123);
    glVertex2f(57,128);
    glVertex2f(62,123);
    glVertex2f(57,118);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,125);
    glVertex2f(68,125);
    glVertex2f(68,120);
    glVertex2f(63,120);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(20.0+cos(rad)*2.0,116.0+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(24,117);
    glVertex2f(26,117);
    glVertex2f(26,114);
    glVertex2f(24,114);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(29.0+cos(rad)*1.0,118.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(29.0+cos(rad)*1.0,114.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(31,119);
    glVertex2f(41,119);
    glVertex2f(41,114);
    glVertex2f(31,114);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(42,119);
    glVertex2f(47,119);
    glVertex2f(47,114);
    glVertex2f(42,114);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(48,114);
    glVertex2f(53,122);
    glVertex2f(58,114);
    glVertex2f(53,106);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(61.0+x3+cos(rad)*1.0,118.0+y3+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(59,116);
    glVertex2f(69,116);
    glVertex2f(69,111);
    glVertex2f(59,111);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,104);
    glVertex2f(25,109);
    glVertex2f(30,104);
    glVertex2f(25,99);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(20,110);
    glVertex2f(22,110);
    glVertex2f(22,107);
    glVertex2f(20,107);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,110);
    glVertex2f(29,110);
    glVertex2f(29,107);
    glVertex2f(27,107);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(31,109);
    glVertex2f(36,109);
    glVertex2f(36,104);
    glVertex2f(31,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(38,109);
    glVertex2f(43,109);
    glVertex2f(43,104);
    glVertex2f(38,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(44,108);
    glVertex2f(46,108);
    glVertex2f(46,105);
    glVertex2f(44,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(47,108);
    glVertex2f(49,108);
    glVertex2f(49,105);
    glVertex2f(47,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(54,107);
    glVertex2f(56,107);
    glVertex2f(56,104);
    glVertex2f(54,104);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(58.0+x3+cos(rad)*1.0,110.0+y3+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(57,107);
    glVertex2f(59,107);
    glVertex2f(59,104);
    glVertex2f(57,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(60,107);
    glVertex2f(62,107);
    glVertex2f(62,104);
    glVertex2f(60,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,109);
    glVertex2f(68,109);
    glVertex2f(68,104);
    glVertex2f(63,104);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(21.0+cos(rad)*2.0,98.0+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(28,101);
    glVertex2f(30,101);
    glVertex2f(30,98);
    glVertex2f(28,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,102);
    glVertex2f(41,102);
    glVertex2f(41,97);
    glVertex2f(31,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(42,102);
    glVertex2f(52,102);
    glVertex2f(52,97);
    glVertex2f(42,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(53,102);
    glVertex2f(58,102);
    glVertex2f(58,97);
    glVertex2f(53,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(59,101);
    glVertex2f(61,101);
    glVertex2f(61,98);
    glVertex2f(59,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(62,102);
    glVertex2f(67,102);
    glVertex2f(67,97);
    glVertex2f(62,97);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,90);
    glVertex2f(25,95);
    glVertex2f(30,90);
    glVertex2f(25,85);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(33,90);
    glVertex2f(38,90);
    glVertex2f(38,85);
    glVertex2f(33,85);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(40,88);
    glVertex2f(42,88);
    glVertex2f(42,91);
    glVertex2f(40,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,90);
    glVertex2f(53,90);
    glVertex2f(53,86);
    glVertex2f(43,86);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(55,95);
    glVertex2f(60,103);
    glVertex2f(65,95);
    glVertex2f(60,87);
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(66.0+cos(rad)*1.0,90.0+sin(rad)*2.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(20.0+cos(rad)*2.0,85.0+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(25,84);
    glVertex2f(35,84);
    glVertex2f(35,80);
    glVertex2f(25,80);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(37,84);
    glVertex2f(42,84);
    glVertex2f(42,79);
    glVertex2f(37,79);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,90);
    glVertex2f(46,90);
    glVertex2f(46,93);
    glVertex2f(44,93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(46,90);
    glVertex2f(48,90);
    glVertex2f(48,93);
    glVertex2f(46,93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,90);
    glVertex2f(53,90);
    glVertex2f(53,86);
    glVertex2f(43,86);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,81);
    glVertex2f(46,81);
    glVertex2f(46,78);
    glVertex2f(44,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(47,81);
    glVertex2f(49,81);
    glVertex2f(49,78);
    glVertex2f(47,78);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,81);
    glVertex2f(52,81);
    glVertex2f(52,78);
    glVertex2f(50,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(53,81);
    glVertex2f(55,81);
    glVertex2f(55,78);
    glVertex2f(53,78);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(56,83);
    glVertex2f(66,83);
    glVertex2f(66,78);
    glVertex2f(56,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(20,76);
    glVertex2f(30,76);
    glVertex2f(30,71);
    glVertex2f(20,71);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,76);
    glVertex2f(41,76);
    glVertex2f(41,71);
    glVertex2f(31,71);
    glEnd();
    
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(43.0+cos(rad)*1.0,73.0+sin(rad)*2.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(48.0+cos(rad)*2.0,72.5+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(52,73);
    glVertex2f(57,78);
    glVertex2f(62,73);
    glVertex2f(57,68);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,75);
    glVertex2f(68,75);
    glVertex2f(68,70);
    glVertex2f(63,70);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(20.0+cos(rad)*2.0,66.0+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(24,67);
    glVertex2f(26,67);
    glVertex2f(26,64);
    glVertex2f(24,64);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(29.0+cos(rad)*1.0,68.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(29.0+cos(rad)*1.0,64.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(31,69);
    glVertex2f(41,69);
    glVertex2f(41,64);
    glVertex2f(31,64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(42,69);
    glVertex2f(47,69);
    glVertex2f(47,64);
    glVertex2f(42,64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(48,64);
    glVertex2f(53,72);
    glVertex2f(58,64);
    glVertex2f(53,56);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(61.0+cos(rad)*1.0,68.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(59,66);
    glVertex2f(69,66);
    glVertex2f(69,61);
    glVertex2f(59,61);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,54);
    glVertex2f(25,59);
    glVertex2f(30,54);
    glVertex2f(25,49);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(20,60);
    glVertex2f(22,60);
    glVertex2f(22,57);
    glVertex2f(20,57);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,60);
    glVertex2f(29,60);
    glVertex2f(29,57);
    glVertex2f(27,57);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(31,59);
    glVertex2f(36,59);
    glVertex2f(36,54);
    glVertex2f(31,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(38,59);
    glVertex2f(43,59);
    glVertex2f(43,54);
    glVertex2f(38,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(44,58);
    glVertex2f(46,58);
    glVertex2f(46,55);
    glVertex2f(44,55);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(47,58);
    glVertex2f(49,58);
    glVertex2f(49,55);
    glVertex2f(47,55);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(54,57);
    glVertex2f(56,57);
    glVertex2f(56,54);
    glVertex2f(54,54);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(58.0+cos(rad)*1.0,60.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(57,57);
    glVertex2f(59,57);
    glVertex2f(59,54);
    glVertex2f(57,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(60,57);
    glVertex2f(62,57);
    glVertex2f(62,54);
    glVertex2f(60,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,59);
    glVertex2f(68,59);
    glVertex2f(68,54);
    glVertex2f(63,54);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt data
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(21.0+cos(rad)*2.0,48.0+sin(rad)*4.0);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(28,51);
    glVertex2f(30,51);
    glVertex2f(30,48);
    glVertex2f(28,48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,52);
    glVertex2f(41,52);
    glVertex2f(41,47);
    glVertex2f(31,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(42,52);
    glVertex2f(52,52);
    glVertex2f(52,47);
    glVertex2f(42,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(53,52);
    glVertex2f(58,52);
    glVertex2f(58,47);
    glVertex2f(53,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(59,51);
    glVertex2f(61,51);
    glVertex2f(61,48);
    glVertex2f(59,48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(62,52);
    glVertex2f(67,52);
    glVertex2f(67,47);
    glVertex2f(62,47);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//cloud
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(55.0+cos(rad)*7.0,170.0+sin(rad)*8.0);
    }
    glEnd();
    glBegin(GL_TRIANGLES);//cloud arrow
    glVertex2f(50,165);
    glVertex2f(55,165);
    glVertex2f(43,155);
    glEnd();
    
    ///////////////////////////////////////////////
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(150.0+cos(rad)*2.0,80.0+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(160.0+cos(rad)*2.0,90.0+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(170.0+cos(rad)*2.0,100.0+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(180.0+cos(rad)*2.0,80.0+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(150.0+cos(rad)*2.0,80.0+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(150.0+cos(rad)*1.0,100.0+sin(rad)*2.0);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(100.0+x3+cos(rad)*1.0,150.0-y3+sin(rad)*2.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(120.0+x3+cos(rad)*2.0,130.0-y3+sin(rad)*4.0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);//corrupt right side
    glColor3f(1.0,0.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(170.0+cos(rad)*1.0,75.0+sin(rad)*2.0);
    }
    glEnd();
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    glBegin(GL_TRIANGLE_FAN);//cloud right side
    glColor3f(1.0,1.0,1.0);
    for(int i=0; i < 360; i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(180.0+cos(rad)*9.0,140.0+sin(rad)*8.0);
    }
    glEnd();
    glBegin(GL_TRIANGLES);//cloud arrow
    glVertex2f(180,135);
    glVertex2f(185,135);
    glVertex2f(173,125);
    glEnd();
    ////////////////////////////WRITE TEXT
    char buf[100]={0};
    glColor3f(1.0,0.0,0.0);
    sprintf(buf,"Data");
    renderbitmap(52,170,GLUT_BITMAP_HELVETICA_18,buf);
    glColor3f(1.0,0.0,0.0);
    sprintf(buf,"Corrupt Data");
    renderbitmap(172,140,GLUT_BITMAP_HELVETICA_18,buf);
    glColor3f(1.0,0.0,0.0);
    sprintf(buf,"CLEANING");
    renderbitmap(95,104,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    
    ////////////////////////////////////////////////////////////////
    //ARROW
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(85,100);
    glVertex2f(120,100);
    glVertex2f(120,90);
    glVertex2f(85,90);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(120,100);
    glVertex2f(120,103);
    glVertex2f(125,95);
    glVertex2f(120,87);
    glVertex2f(120,90);
    glEnd();
}
void loadData()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(140,145);
    glVertex2f(145,145);
    glVertex2f(145,140);
    glVertex2f(140,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(147,145);
    glVertex2f(152,145);
    glVertex2f(152,140);
    glVertex2f(147,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(154,145);
    glVertex2f(159,145);
    glVertex2f(159,140);
    glVertex2f(154,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(161,145);
    glVertex2f(166,145);
    glVertex2f(166,140);
    glVertex2f(161,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(168,145);
    glVertex2f(173,145);
    glVertex2f(173,140);
    glVertex2f(168,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(170,145);
    glVertex2f(174,145);
    glVertex2f(174,140);
    glVertex2f(170,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(177,145);
    glVertex2f(182,145);
    glVertex2f(182,140);
    glVertex2f(177,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(184,145);
    glVertex2f(189,145);
    glVertex2f(189,140);
    glVertex2f(184,140);
    glEnd();
    ///////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(140,138);
    glVertex2f(145,138);
    glVertex2f(145,133);
    glVertex2f(140,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(147,138);
    glVertex2f(152,138);
    glVertex2f(152,133);
    glVertex2f(147,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(154,138);
    glVertex2f(159,138);
    glVertex2f(159,133);
    glVertex2f(154,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(161,138);
    glVertex2f(166,138);
    glVertex2f(166,133);
    glVertex2f(161,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(168,138);
    glVertex2f(173,138);
    glVertex2f(173,133);
    glVertex2f(168,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(170,138);
    glVertex2f(174,138);
    glVertex2f(174,133);
    glVertex2f(170,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(177,138);
    glVertex2f(182,138);
    glVertex2f(182,133);
    glVertex2f(177,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(184,138);
    glVertex2f(189,138);
    glVertex2f(189,133);
    glVertex2f(184,133);
    glEnd();
    //////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(140,131);
    glVertex2f(145,131);
    glVertex2f(145,126);
    glVertex2f(140,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(147,131);
    glVertex2f(152,131);
    glVertex2f(152,126);
    glVertex2f(147,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(154,131);
    glVertex2f(159,131);
    glVertex2f(159,126);
    glVertex2f(154,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(161,131);
    glVertex2f(166,131);
    glVertex2f(166,126);
    glVertex2f(161,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(168,131);
    glVertex2f(173,131);
    glVertex2f(173,126);
    glVertex2f(168,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(170,131);
    glVertex2f(174,131);
    glVertex2f(174,126);
    glVertex2f(170,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(177,131);
    glVertex2f(182,131);
    glVertex2f(182,126);
    glVertex2f(177,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(184,131);
    glVertex2f(189,131);
    glVertex2f(189,126);
    glVertex2f(184,126);
    glEnd();
    //////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(140,124);
    glVertex2f(145,124);
    glVertex2f(145,119);
    glVertex2f(140,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(147,124);
    glVertex2f(152,124);
    glVertex2f(152,119);
    glVertex2f(147,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(154,124);
    glVertex2f(159,124);
    glVertex2f(159,119);
    glVertex2f(154,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(161,124);
    glVertex2f(166,124);
    glVertex2f(166,119);
    glVertex2f(161,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(168,124);
    glVertex2f(173,124);
    glVertex2f(173,119);
    glVertex2f(168,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(170,124);
    glVertex2f(174,124);
    glVertex2f(174,119);
    glVertex2f(170,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(177,124);
    glVertex2f(182,124);
    glVertex2f(182,119);
    glVertex2f(177,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(184,124);
    glVertex2f(189,124);
    glVertex2f(189,119);
    glVertex2f(184,119);
    glEnd();
    ///////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(140,117);
    glVertex2f(145,117);
    glVertex2f(145,112);
    glVertex2f(140,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(147,117);
    glVertex2f(152,117);
    glVertex2f(152,112);
    glVertex2f(147,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(154,117);
    glVertex2f(159,117);
    glVertex2f(159,112);
    glVertex2f(154,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(161,117);
    glVertex2f(166,117);
    glVertex2f(166,112);
    glVertex2f(161,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(168,117);
    glVertex2f(173,117);
    glVertex2f(173,112);
    glVertex2f(168,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(170,117);
    glVertex2f(174,117);
    glVertex2f(174,112);
    glVertex2f(170,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(177,117);
    glVertex2f(182,117);
    glVertex2f(182,112);
    glVertex2f(177,112);
    glEnd();
    
    //////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(140,110);
    glVertex2f(145,110);
    glVertex2f(145,105);
    glVertex2f(140,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(147,110);
    glVertex2f(152,110);
    glVertex2f(152,105);
    glVertex2f(147,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(154,110);
    glVertex2f(159,110);
    glVertex2f(159,105);
    glVertex2f(154,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(161,110);
    glVertex2f(166,110);
    glVertex2f(166,105);
    glVertex2f(161,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(168,110);
    glVertex2f(173,110);
    glVertex2f(173,105);
    glVertex2f(168,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(170,110);
    glVertex2f(174,110);
    glVertex2f(174,105);
    glVertex2f(170,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(177,110);
    glVertex2f(182,110);
    glVertex2f(182,105);
    glVertex2f(177,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(184,110);
    glVertex2f(189,110);
    glVertex2f(189,105);
    glVertex2f(184,105);
    glEnd();
    //////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(140,103);
    glVertex2f(145,103);
    glVertex2f(145,98);
    glVertex2f(140,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(147,103);
    glVertex2f(152,103);
    glVertex2f(152,98);
    glVertex2f(147,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(154,103);
    glVertex2f(159,103);
    glVertex2f(159,98);
    glVertex2f(154,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(161,103);
    glVertex2f(166,103);
    glVertex2f(166,98);
    glVertex2f(161,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(168,103);
    glVertex2f(173,103);
    glVertex2f(173,98);
    glVertex2f(168,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(170,103);
    glVertex2f(174,103);
    glVertex2f(174,98);
    glVertex2f(170,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(177,103);
    glVertex2f(182,103);
    glVertex2f(182,98);
    glVertex2f(177,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(184,103);
    glVertex2f(189,103);
    glVertex2f(189,98);
    glVertex2f(184,98);
    glEnd();
    ////////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(140,96);
    glVertex2f(145,96);
    glVertex2f(145,91);
    glVertex2f(140,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(147,96);
    glVertex2f(152,96);
    glVertex2f(152,91);
    glVertex2f(147,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(154,96);
    glVertex2f(159,96);
    glVertex2f(159,91);
    glVertex2f(154,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(161,96);
    glVertex2f(166,96);
    glVertex2f(166,91);
    glVertex2f(161,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(168,96);
    glVertex2f(173,96);
    glVertex2f(173,91);
    glVertex2f(168,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(170,96);
    glVertex2f(174,96);
    glVertex2f(174,91);
    glVertex2f(170,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(177,96);
    glVertex2f(182,96);
    glVertex2f(182,91);
    glVertex2f(177,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(184,96);
    glVertex2f(189,96);
    glVertex2f(189,91);
    glVertex2f(184,91);
    glEnd();
    ////////////////////////////////////////////////////////////
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(140,89);
    glVertex2f(145,89);
    glVertex2f(145,84);
    glVertex2f(140,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(147,89);
    glVertex2f(152,89);
    glVertex2f(152,84);
    glVertex2f(147,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(154,89);
    glVertex2f(159,89);
    glVertex2f(159,84);
    glVertex2f(154,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(161,89);
    glVertex2f(166,89);
    glVertex2f(166,84);
    glVertex2f(161,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(168,89);
    glVertex2f(173,89);
    glVertex2f(173,84);
    glVertex2f(168,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(170,89);
    glVertex2f(174,89);
    glVertex2f(174,84);
    glVertex2f(170,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(177,89);
    glVertex2f(182,89);
    glVertex2f(182,84);
    glVertex2f(177,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(184,89);
    glVertex2f(189,89);
    glVertex2f(189,84);
    glVertex2f(184,84);
    glEnd();
}
void cleanedData()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,140);
    glVertex2f(25,145);
    glVertex2f(30,140);
    glVertex2f(25,135);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(33,140);
    glVertex2f(38,140);
    glVertex2f(38,135);
    glVertex2f(33,135);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(40,138);
    glVertex2f(42,138);
    glVertex2f(42,141);
    glVertex2f(40,141);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,140);
    glVertex2f(53,140);
    glVertex2f(53,136);
    glVertex2f(43,136);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(55,145);
    glVertex2f(60,153);
    glVertex2f(65,145);
    glVertex2f(60,137);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(25,134);
    glVertex2f(35,134);
    glVertex2f(35,130);
    glVertex2f(25,130);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(37,134);
    glVertex2f(42,134);
    glVertex2f(42,129);
    glVertex2f(37,129);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,140);
    glVertex2f(46,140);
    glVertex2f(46,143);
    glVertex2f(44,143);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(46,140);
    glVertex2f(48,140);
    glVertex2f(48,143);
    glVertex2f(46,143);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,140);
    glVertex2f(53,140);
    glVertex2f(53,136);
    glVertex2f(43,136);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,131);
    glVertex2f(46,131);
    glVertex2f(46,128);
    glVertex2f(44,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(47,131);
    glVertex2f(49,131);
    glVertex2f(49,128);
    glVertex2f(47,128);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,131);
    glVertex2f(52,131);
    glVertex2f(52,128);
    glVertex2f(50,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(53,131);
    glVertex2f(55,131);
    glVertex2f(55,128);
    glVertex2f(53,128);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(56,133);
    glVertex2f(66,133);
    glVertex2f(66,128);
    glVertex2f(56,128);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(20,126);
    glVertex2f(30,126);
    glVertex2f(30,121);
    glVertex2f(20,121);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,126);
    glVertex2f(41,126);
    glVertex2f(41,121);
    glVertex2f(31,121);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(52,123);
    glVertex2f(57,128);
    glVertex2f(62,123);
    glVertex2f(57,118);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,125);
    glVertex2f(68,125);
    glVertex2f(68,120);
    glVertex2f(63,120);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(24,117);
    glVertex2f(26,117);
    glVertex2f(26,114);
    glVertex2f(24,114);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(31,119);
    glVertex2f(41,119);
    glVertex2f(41,114);
    glVertex2f(31,114);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(42,119);
    glVertex2f(47,119);
    glVertex2f(47,114);
    glVertex2f(42,114);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(48,114);
    glVertex2f(53,122);
    glVertex2f(58,114);
    glVertex2f(53,106);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(59,116);
    glVertex2f(69,116);
    glVertex2f(69,111);
    glVertex2f(59,111);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,104);
    glVertex2f(25,109);
    glVertex2f(30,104);
    glVertex2f(25,99);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(20,110);
    glVertex2f(22,110);
    glVertex2f(22,107);
    glVertex2f(20,107);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,110);
    glVertex2f(29,110);
    glVertex2f(29,107);
    glVertex2f(27,107);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(31,109);
    glVertex2f(36,109);
    glVertex2f(36,104);
    glVertex2f(31,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(38,109);
    glVertex2f(43,109);
    glVertex2f(43,104);
    glVertex2f(38,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(44,108);
    glVertex2f(46,108);
    glVertex2f(46,105);
    glVertex2f(44,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(47,108);
    glVertex2f(49,108);
    glVertex2f(49,105);
    glVertex2f(47,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(54,107);
    glVertex2f(56,107);
    glVertex2f(56,104);
    glVertex2f(54,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(57,107);
    glVertex2f(59,107);
    glVertex2f(59,104);
    glVertex2f(57,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(60,107);
    glVertex2f(62,107);
    glVertex2f(62,104);
    glVertex2f(60,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,109);
    glVertex2f(68,109);
    glVertex2f(68,104);
    glVertex2f(63,104);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(28,101);
    glVertex2f(30,101);
    glVertex2f(30,98);
    glVertex2f(28,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,102);
    glVertex2f(41,102);
    glVertex2f(41,97);
    glVertex2f(31,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(42,102);
    glVertex2f(52,102);
    glVertex2f(52,97);
    glVertex2f(42,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(53,102);
    glVertex2f(58,102);
    glVertex2f(58,97);
    glVertex2f(53,97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(59,101);
    glVertex2f(61,101);
    glVertex2f(61,98);
    glVertex2f(59,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(62,102);
    glVertex2f(67,102);
    glVertex2f(67,97);
    glVertex2f(62,97);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,90);
    glVertex2f(25,95);
    glVertex2f(30,90);
    glVertex2f(25,85);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(33,90);
    glVertex2f(38,90);
    glVertex2f(38,85);
    glVertex2f(33,85);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(40,88);
    glVertex2f(42,88);
    glVertex2f(42,91);
    glVertex2f(40,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,90);
    glVertex2f(53,90);
    glVertex2f(53,86);
    glVertex2f(43,86);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(55,95);
    glVertex2f(60,103);
    glVertex2f(65,95);
    glVertex2f(60,87);
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(25,84);
    glVertex2f(35,84);
    glVertex2f(35,80);
    glVertex2f(25,80);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(37,84);
    glVertex2f(42,84);
    glVertex2f(42,79);
    glVertex2f(37,79);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,90);
    glVertex2f(46,90);
    glVertex2f(46,93);
    glVertex2f(44,93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(46,90);
    glVertex2f(48,90);
    glVertex2f(48,93);
    glVertex2f(46,93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(43,90);
    glVertex2f(53,90);
    glVertex2f(53,86);
    glVertex2f(43,86);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(44,81);
    glVertex2f(46,81);
    glVertex2f(46,78);
    glVertex2f(44,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(47,81);
    glVertex2f(49,81);
    glVertex2f(49,78);
    glVertex2f(47,78);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,81);
    glVertex2f(52,81);
    glVertex2f(52,78);
    glVertex2f(50,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(53,81);
    glVertex2f(55,81);
    glVertex2f(55,78);
    glVertex2f(53,78);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(56,83);
    glVertex2f(66,83);
    glVertex2f(66,78);
    glVertex2f(56,78);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(20,76);
    glVertex2f(30,76);
    glVertex2f(30,71);
    glVertex2f(20,71);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,76);
    glVertex2f(41,76);
    glVertex2f(41,71);
    glVertex2f(31,71);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(52,73);
    glVertex2f(57,78);
    glVertex2f(62,73);
    glVertex2f(57,68);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,75);
    glVertex2f(68,75);
    glVertex2f(68,70);
    glVertex2f(63,70);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(24,67);
    glVertex2f(26,67);
    glVertex2f(26,64);
    glVertex2f(24,64);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(31,69);
    glVertex2f(41,69);
    glVertex2f(41,64);
    glVertex2f(31,64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(42,69);
    glVertex2f(47,69);
    glVertex2f(47,64);
    glVertex2f(42,64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(48,64);
    glVertex2f(53,72);
    glVertex2f(58,64);
    glVertex2f(53,56);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(59,66);
    glVertex2f(69,66);
    glVertex2f(69,61);
    glVertex2f(59,61);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,54);
    glVertex2f(25,59);
    glVertex2f(30,54);
    glVertex2f(25,49);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(20,60);
    glVertex2f(22,60);
    glVertex2f(22,57);
    glVertex2f(20,57);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,60);
    glVertex2f(29,60);
    glVertex2f(29,57);
    glVertex2f(27,57);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(31,59);
    glVertex2f(36,59);
    glVertex2f(36,54);
    glVertex2f(31,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(38,59);
    glVertex2f(43,59);
    glVertex2f(43,54);
    glVertex2f(38,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(44,58);
    glVertex2f(46,58);
    glVertex2f(46,55);
    glVertex2f(44,55);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(47,58);
    glVertex2f(49,58);
    glVertex2f(49,55);
    glVertex2f(47,55);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(54,57);
    glVertex2f(56,57);
    glVertex2f(56,54);
    glVertex2f(54,54);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(57,57);
    glVertex2f(59,57);
    glVertex2f(59,54);
    glVertex2f(57,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(60,57);
    glVertex2f(62,57);
    glVertex2f(62,54);
    glVertex2f(60,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(63,59);
    glVertex2f(68,59);
    glVertex2f(68,54);
    glVertex2f(63,54);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(28,51);
    glVertex2f(30,51);
    glVertex2f(30,48);
    glVertex2f(28,48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(31,52);
    glVertex2f(41,52);
    glVertex2f(41,47);
    glVertex2f(31,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(42,52);
    glVertex2f(52,52);
    glVertex2f(52,47);
    glVertex2f(42,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(53,52);
    glVertex2f(58,52);
    glVertex2f(58,47);
    glVertex2f(53,47);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(59,51);
    glVertex2f(61,51);
    glVertex2f(61,48);
    glVertex2f(59,48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(62,52);
    glVertex2f(67,52);
    glVertex2f(67,47);
    glVertex2f(62,47);
    glEnd();
}
void slide4()
{
    char buf[100]={0};
    glColor3f(1.0,0.0,0.0);
    sprintf(buf,"LEGACY DATA");
    renderbitmap(36,34,GLUT_BITMAP_HELVETICA_18,buf);
    char str[10]="TRANSFORM";
    cleanedData();
    switch(c)
    {
        case 0:
            
            c=1;
            break;
        case 1:
            if(x1<=9)
            {
                
                arrow(x1);
                x1+=1;
            }
            else
                c=2;
            break;
        case 2:
            write(str);
            arrow(x1);
            loadData();
            break;
            glutPostRedisplay();
    }
    c1=0;x2=0;
}
///////////////////////////DATA
void loadingData()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(20,145);
    glVertex2f(25,145);
    glVertex2f(25,140);
    glVertex2f(20,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(27,145);
    glVertex2f(32,145);
    glVertex2f(32,140);
    glVertex2f(27,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(34,145);
    glVertex2f(39,145);
    glVertex2f(39,140);
    glVertex2f(34,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(41,145);
    glVertex2f(46,145);
    glVertex2f(46,140);
    glVertex2f(41,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(48,145);
    glVertex2f(53,145);
    glVertex2f(53,140);
    glVertex2f(48,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(50,145);
    glVertex2f(54,145);
    glVertex2f(54,140);
    glVertex2f(50,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(57,145);
    glVertex2f(62,145);
    glVertex2f(62,140);
    glVertex2f(57,140);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(64,145);
    glVertex2f(69,145);
    glVertex2f(69,140);
    glVertex2f(64,140);
    glEnd();
    ///////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(20,138);
    glVertex2f(25,138);
    glVertex2f(25,133);
    glVertex2f(20,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(27,138);
    glVertex2f(32,138);
    glVertex2f(32,133);
    glVertex2f(27,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(34,138);
    glVertex2f(39,138);
    glVertex2f(39,133);
    glVertex2f(34,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(41,138);
    glVertex2f(46,138);
    glVertex2f(46,133);
    glVertex2f(41,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(48,138);
    glVertex2f(53,138);
    glVertex2f(53,133);
    glVertex2f(48,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(50,138);
    glVertex2f(54,138);
    glVertex2f(54,133);
    glVertex2f(50,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(57,138);
    glVertex2f(62,138);
    glVertex2f(62,133);
    glVertex2f(57,133);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(64,138);
    glVertex2f(69,138);
    glVertex2f(69,133);
    glVertex2f(64,133);
    glEnd();
    //////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(20,131);
    glVertex2f(25,131);
    glVertex2f(25,126);
    glVertex2f(20,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,131);
    glVertex2f(32,131);
    glVertex2f(32,126);
    glVertex2f(27,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(34,131);
    glVertex2f(39,131);
    glVertex2f(39,126);
    glVertex2f(34,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(41,131);
    glVertex2f(46,131);
    glVertex2f(46,126);
    glVertex2f(41,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(48,131);
    glVertex2f(53,131);
    glVertex2f(53,126);
    glVertex2f(48,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,131);
    glVertex2f(54,131);
    glVertex2f(54,126);
    glVertex2f(50,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(57,131);
    glVertex2f(62,131);
    glVertex2f(62,126);
    glVertex2f(57,126);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(64,131);
    glVertex2f(69,131);
    glVertex2f(69,126);
    glVertex2f(64,126);
    glEnd();
    //////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,124);
    glVertex2f(25,124);
    glVertex2f(25,119);
    glVertex2f(20,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(27,124);
    glVertex2f(32,124);
    glVertex2f(32,119);
    glVertex2f(27,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(34,124);
    glVertex2f(39,124);
    glVertex2f(39,119);
    glVertex2f(34,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(41,124);
    glVertex2f(46,124);
    glVertex2f(46,119);
    glVertex2f(41,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(48,124);
    glVertex2f(53,124);
    glVertex2f(53,119);
    glVertex2f(48,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(50,124);
    glVertex2f(54,124);
    glVertex2f(54,119);
    glVertex2f(50,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(57,124);
    glVertex2f(62,124);
    glVertex2f(62,119);
    glVertex2f(57,119);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(64,124);
    glVertex2f(69,124);
    glVertex2f(69,119);
    glVertex2f(64,119);
    glEnd();
    ///////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(20,117);
    glVertex2f(25,117);
    glVertex2f(25,112);
    glVertex2f(20,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(27,117);
    glVertex2f(32,117);
    glVertex2f(32,112);
    glVertex2f(27,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(34,117);
    glVertex2f(39,117);
    glVertex2f(39,112);
    glVertex2f(34,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(41,117);
    glVertex2f(46,117);
    glVertex2f(46,112);
    glVertex2f(41,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(48,117);
    glVertex2f(53,117);
    glVertex2f(53,112);
    glVertex2f(48,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(50,117);
    glVertex2f(54,117);
    glVertex2f(54,112);
    glVertex2f(50,112);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(57,117);
    glVertex2f(62,117);
    glVertex2f(62,112);
    glVertex2f(57,112);
    glEnd();
    
    //////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(20,110);
    glVertex2f(25,110);
    glVertex2f(25,105);
    glVertex2f(20,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(27,110);
    glVertex2f(32,110);
    glVertex2f(32,105);
    glVertex2f(27,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(34,110);
    glVertex2f(39,110);
    glVertex2f(39,105);
    glVertex2f(34,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(41,110);
    glVertex2f(46,110);
    glVertex2f(46,105);
    glVertex2f(41,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(48,110);
    glVertex2f(53,110);
    glVertex2f(53,105);
    glVertex2f(48,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(50,110);
    glVertex2f(54,110);
    glVertex2f(54,105);
    glVertex2f(50,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(57,110);
    glVertex2f(62,110);
    glVertex2f(62,105);
    glVertex2f(57,105);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(64,110);
    glVertex2f(69,110);
    glVertex2f(69,105);
    glVertex2f(64,105);
    glEnd();
    //////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(20,103);
    glVertex2f(25,103);
    glVertex2f(25,98);
    glVertex2f(20,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(27,103);
    glVertex2f(32,103);
    glVertex2f(32,98);
    glVertex2f(27,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(34,103);
    glVertex2f(39,103);
    glVertex2f(39,98);
    glVertex2f(34,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(41,103);
    glVertex2f(46,103);
    glVertex2f(46,98);
    glVertex2f(41,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(48,103);
    glVertex2f(53,103);
    glVertex2f(53,98);
    glVertex2f(48,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(50,103);
    glVertex2f(54,103);
    glVertex2f(54,98);
    glVertex2f(50,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(57,103);
    glVertex2f(62,103);
    glVertex2f(62,98);
    glVertex2f(57,98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(64,103);
    glVertex2f(69,103);
    glVertex2f(69,98);
    glVertex2f(64,98);
    glEnd();
    ////////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(20,96);
    glVertex2f(25,96);
    glVertex2f(25,91);
    glVertex2f(20,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(27,96);
    glVertex2f(32,96);
    glVertex2f(32,91);
    glVertex2f(27,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(34,96);
    glVertex2f(39,96);
    glVertex2f(39,91);
    glVertex2f(34,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(41,96);
    glVertex2f(46,96);
    glVertex2f(46,91);
    glVertex2f(41,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(48,96);
    glVertex2f(53,96);
    glVertex2f(53,91);
    glVertex2f(48,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(50,96);
    glVertex2f(54,96);
    glVertex2f(54,91);
    glVertex2f(50,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(57,96);
    glVertex2f(62,96);
    glVertex2f(62,91);
    glVertex2f(57,91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(64,96);
    glVertex2f(69,96);
    glVertex2f(69,91);
    glVertex2f(64,91);
    glEnd();
    ////////////////////////////////////////////////////////////
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(20,89);
    glVertex2f(25,89);
    glVertex2f(25,84);
    glVertex2f(20,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(27,89);
    glVertex2f(32,89);
    glVertex2f(32,84);
    glVertex2f(27,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(34,89);
    glVertex2f(39,89);
    glVertex2f(39,84);
    glVertex2f(34,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(41,89);
    glVertex2f(46,89);
    glVertex2f(46,84);
    glVertex2f(41,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(48,89);
    glVertex2f(53,89);
    glVertex2f(53,84);
    glVertex2f(48,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(50,89);
    glVertex2f(54,89);
    glVertex2f(54,84);
    glVertex2f(50,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(57,89);
    glVertex2f(62,89);
    glVertex2f(62,84);
    glVertex2f(57,84);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(64,89);
    glVertex2f(69,89);
    glVertex2f(69,84);
    glVertex2f(64,84);
    glEnd();
}
void cylinderCap()
{
    glColor3ub(255,0,0);//top of the cylinder
    glLineWidth(5.0);
    glBegin(GL_TRIANGLE_FAN);
    //glColor3f(0.0,0.0,0.0);
    for(int i=0; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i*DEG2RAD;
        glVertex2f(165+cos(degInRad)*30,156.0+sin(degInRad)*5);
    }
    glEnd();
}
void slide5()
{
    char str[12]="   LOADING";
    loadingData();
    switch(c1)
    {
        case 0:
            c1=1;
            break;
        case 1:
            if(x2<=9)
            {
                arrow(x2);
                x2+=1;
            }
            else
                c1=2;
            break;
        case 2:
            c1=3;
            write(str);
            arrow(x2);
            loadData();
            glColor3ub(255,0,0);//cylinder lines
            glLineWidth(5.0);
            glBegin(GL_LINES);
            glVertex2i(135,157);
            glVertex2i(135,75);
            glEnd();
            glBegin(GL_LINES);
            glVertex2i(195,157);
            glVertex2i(195,75);
            glEnd();
            glColor3ub(255,0,0);//end of the cylinder
            //glColor3f(0.0,0.0,0.0);
            glBegin(GL_LINE_STRIP);
            
            for(int i=180; i < 360; i++)
            {
                //convert degrees into radians
                float degInRad = i*DEG2RAD;
                glVertex2f(165.0+cos(degInRad)*30,76.0+sin(degInRad)*5);
            }
            glEnd();
            break;
        case 3:
            cylinderCap();
            write(str);
            arrow(x2);
            loadData();
            glColor3ub(255,0,0);//cylinder lines
            glLineWidth(5.0);
            glBegin(GL_LINES);
            glVertex2i(135,157);
            glVertex2i(135,75);
            glEnd();
            glBegin(GL_LINES);
            glVertex2i(195,157);
            glVertex2i(195,75);
            glEnd();
            glColor3ub(255,0,0);//end of the cylinder
            //glColor3f(0.0,0.0,0.0);
            glBegin(GL_LINE_STRIP);
            
            for(int i=180; i < 360; i++)
            {
                //convert degrees into radians
                float degInRad = i*DEG2RAD;
                glVertex2f(165.0+cos(degInRad)*30,76.0+sin(degInRad)*5);
            }
            glEnd();
            break;
    }
    c=0;x1=0;
}

int slide=1;
void navigation(int key,int x,int y)
{
    //  boolean flag;
    if(key==GLUT_KEY_LEFT)
    {
        slide--;
        if(slide<1)
            slide+=1;
        //else
        //flag=true;
    }
    else if(key==GLUT_KEY_RIGHT)
    {
        slide++;
        if(slide>5)
            slide-=1;
    }
    glutPostRedisplay();
    glFlush();
}

void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,210,0,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch(slide)
    {
        case 1:glClearColor(0,0,0,1);
            //glutTimerFunc(3000,timer1,0);
            glClear(GL_COLOR_BUFFER_BIT);
            slide1();
            break;
        case 2:glClearColor(0,0,0,1);
            // glutTimerFunc(50,timer2,0);
            glClear(GL_COLOR_BUFFER_BIT);
            slide2();
            break;
        case 3:glClearColor(0,0,0,1);
            glClear(GL_COLOR_BUFFER_BIT);
            slide3();
            break;
        case 4:glClearColor(0,0,0,1);
            glClear(GL_COLOR_BUFFER_BIT);
            slide4();
            break;
        case 5:glClearColor(0,0,0,1);
            glClear(GL_COLOR_BUFFER_BIT);
            slide5();
            break;
    }
    glFlush();
    
}

int main(int argc,char ** argv )
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("DATA WAREHOUSE");
    glutInitWindowSize(400,400);
    glutDisplayFunc(display);
    glutSpecialFunc(navigation);
    glutTimerFunc(0,timer1,0);
    //glutDisplayFunc(display);
    //glutTimerFunc(50,timer2,0);
    glutMainLoop();
    return 0;
}

