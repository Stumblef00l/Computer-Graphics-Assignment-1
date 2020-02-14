#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// Point Class

struct Point
{
	int x,y;
	
	// Constructors

	Point() 
	{
		x = 0;
		y = 0;
	}

	Point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	
	//Operators

	void operator =(const Point &p)
	{
		x = p.x;
		y = p.y;
	}

	Point operator +(const Point &p)
	{
		return Point(x + p.x, y + p.y);
	}

};

// Global Variables

Point centre;
int radius;

/* Functions defining the actual algorithm */

//Function to plot a point

void putPixel(Point translatedPoint)
{
	glBegin(GL_POINTS);
	// Re-translating the point to its actual position
	Point actualPoint = centre + translatedPoint;
	glVertex2i(actualPoint.x, actualPoint.y);
	glEnd();
}

void bresenhamCircle()
{
	/*
		 We assume the centre circle to be shifted to the origin
		 in the bresenhamCirlce function, but shift it back
		 to the original centre before plotting it, inside the
		 putPixel function
	*/

	// Starting at the topmost point of the circle
	Point currPoint = Point(0,radius);

	/*
		To avoid any floating point operations, we multiply everything
		by 4.
	*/

	int decision = 5 - 4*radius;
	putPixel(currPoint);

	// The actual algorithm

	while (currPoint.y > currPoint.x)
	{
		if (decision < 0) {
			decision += 4*(2*(currPoint.x)+1);
			currPoint.x = currPoint.x + 1; 
		}
		else {
			decision += 4*(2*((currPoint.x)-(currPoint.y))+3);
			currPoint.y  = currPoint.y - 1;
			currPoint.x = currPoint.x + 1;
		}

		// Using 8 way symmetry

		putPixel(currPoint);
		putPixel(Point(currPoint.x, -currPoint.y));
		putPixel(Point(-currPoint.x, currPoint.y));
		putPixel(Point(-currPoint.x, -currPoint.y));
		putPixel(Point(currPoint.y, currPoint.x));
		putPixel(Point(-currPoint.y, currPoint.x));
		putPixel(Point(currPoint.y, -currPoint.x));
		putPixel(Point(-currPoint.y, -currPoint.x));
	}

}

// OpenGL display functions

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);

	bresenhamCircle();

	glFlush ();
}

int main(int argc, char **argv)
{	
	// Taking the Input Parameters

	cout << "Enter the coordinates of the centre:\n\n" << endl;
	cout << "X-coordinate   : "; 
	cin >> centre.x;
	cout << "Y-coordinate : "; 
	cin >> centre.y;
	cout << "Enter radius : "; 
	cin >> radius;

	// Initializing the Window and running the drawing algorithm

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Bresenham Cirlce Drawing Algorithm");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}