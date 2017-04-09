#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x1,y1,x2,y2,x3,y3,x4,y4;

void edgeTest(float x1, float y1, float x2, float y2, int * le, int * re)
{
	float temp,mx,x;
	int i;
	if((y2-y1)<0)
	{
		temp = y2;
		y2 = y1;
		y1 = temp;
		
		temp = x2;
		x2 = x1;
		x1 = temp;
	}
	if((y2-y1) != 0)
	{
		mx = (x2-x1)/(y2-y1);
	}
	else
		mx = x2-x1;

	x = x1;
	for(i=y1; i<=y2; i++)
	{
		if(x < le[i])
		{
			le[i] = x;
		}
		if(x > re[i])
		{
			re[i] = x;
		}
		x += mx; 
	}
}

void drawPixel(float x, float y)
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void scanFill(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	int le[500],re[500];
	int i,j;
	for(i=0; i<500; i++)
	{
		le[i] = 500;
		re[i] = 0;
	}
	edgeTest(x1,y1,x2,y2,le,re);
	edgeTest(x2,y2,x3,y3,le,re);
	edgeTest(x3,y3,x4,y4,le,re);
	edgeTest(x4,y4,x1,y1,le,re);

	for(j=0; j<500; j++)
	{
		if(le[j] <= re[j])
		{
			for(i=le[j]; i<re[j]; i++)
			{
				drawPixel(i, j);
			}
		}
	}
}

void display()
{
	x1 = 200; y1 = 200; x2 = 100; y2 = 300; x3 = 200; y3 = 400; x4 = 300; y4 = 300;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	scanFill(x1,y1,x2,y2,x3,y3,x4,y4);
	glFlush();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Polygon Filling");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}