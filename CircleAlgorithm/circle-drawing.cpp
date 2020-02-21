#include <bits/stdc++.h>
#include <GL/glut.h>
#include "BresenhamCircle.h"
#include "../Point.h"

using namespace std;

// Global Variables
Point center;
int radius;

/**
  * Method to initialize.
  */
void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}

/**
  * Method to display the circle.
  */
void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);

	BresenhamCircleDrawing drawer = BresenhamCircleDrawing(center, radius);
	drawer.bresenhamCircle();

	glFlush ();
}

int main(int argc, char **argv)
{	
	// Taking the Input Parameters

	cout << "Enter the coordinates of the center:\n\n" << endl;
	cout << "X-coordinate   : "; 
	cin >> center.x;
	cout << "Y-coordinate : "; 
	cin >> center.y;
	cout << "Enter radius : "; 
	cin >> radius;

	// Initializing the Window and running the drawing algorithm

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1024, 768);
	glutCreateWindow ("Bresenham Cirlce Drawing Algorithm");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}