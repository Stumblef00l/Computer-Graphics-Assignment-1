#include <bits/stdc++.h>
#include <GL/glut.h>
#include "Point.h"
#include "BresenhamLine.h"

using namespace std;

Point startingPoint,endPoint; // End Points of the line

// OpenGL display functions

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}


void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	BresenhamLineDrawing drawer = BresenhamLineDrawing(startingPoint, endPoint);
	drawer.bresenhamLine();
	glFlush ();
}

int main(int argc, char **argv)
{	
	// Taking the Input Parameters

	cout << "Enter the coordinates of the first end point:\n\n" << endl;
	cout << "X-coordinate   : "; 
	cin >> startingPoint.x;
	cout << "Y-coordinate : "; 
	cin >> startingPoint.y; 
	
	cout << "\nEnter the coordinates of the second end point:\n\n" << endl;
	cout << "X-coordinate   : "; 
	cin >> endPoint.x;
	cout << "Y-coordinate : "; 
	cin >> endPoint.y;

	// Initializing the Window and running the drawing algorithm

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1024, 768);
	glutCreateWindow ("Bresenham Line Drawing Algorithm");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}