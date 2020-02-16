#ifndef BRESENHAM_CIRCLE
#define BRESENHAM_CIRCLE

#include<bits/stdc++.h>
#include <GL/glut.h>
#include "Point.h"

using namespace std;

class BresenhamCircleDrawing
{
	private:

		Point center; // Center
        int radius; // Radius

		/* Functions defining the actual algorithm */

		//Function to plot a point
		void putPixel(Point translatedPoint)
		{
			glBegin(GL_POINTS);
            Point actualPoint = translatedPoint + center;
			glVertex2i(actualPoint.x, actualPoint.y);
			glEnd();
		}

	public:

		// Constructor
		BresenhamCircleDrawing(Point c, int r)
		{
			center = c;
            radius = r;
		}
		
		// Method to change the starting point
		void changeCenter(Point c)
		{
			center = c;
		}

		// Method to change the end Point
		void changeRadius(int r)
		{
			radius = r;
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

            int decision = 1 - radius;

            int deltaE = 3;
            int deltaSE = 5 -2*radius;

            putPixel(currPoint);

            // The actual algorithm

            while (currPoint.y > currPoint.x)
            {
                if (decision < 0) {
                    decision += deltaE;
                    deltaE += 2;
                    deltaSE += 2;
                }
                else {
                    decision += deltaSE;
                    deltaE += 2;
                    deltaSE += 4;
                    currPoint.y  = currPoint.y - 1;
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

                currPoint.x = currPoint.x + 1; 
            }
        }
};

#endif