#include <bits/stdc++.h>
#include <GL/glut.h>
#include "TreeDrawing.h"

using namespace std;

//Global variables

int n;
vector<pair<int,int>>adj;

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

	TreeDrawing drawer = TreeDrawing(adj);
	drawer.plotTree();

	glFlush ();
}

int main(int argc, char **argv)
{	
	// Taking the Input Parameters

	cout << "Enter number of nodes: " << endl; 
	cin >> n;
    cout << "\nEnter both sons of each node: " << endl;
	for(int i = 0; i < n; i++) {
        pair<int,int>p;
        cin >> p.first >> p.second;
        if(p.first != -1)
            p.first = p.first - 1;
        if(p.second != -1)
            p.second = p.second - 1;
        adj.push_back(p);
    }
	// Initializing the Window and running the drawing algorithm

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1024, 768);
	glutCreateWindow ("Tree Drawing Algorithm");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}

