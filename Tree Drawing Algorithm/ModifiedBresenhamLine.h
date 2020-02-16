#ifndef MODIFIED_BRESENHAM_LINE
#define MODIFIED_BRESENHAM_LINE

#include<bits/stdc++.h>
#include<GL/glut.h>
#include "../Point.h"

using namespace std;

class ModifiedBresenhamLineDrawing
{
	private:

		Point A, B; // Endpoints (Centers)
        const int radiusA = 20;
        const int radiusB = 20; // Radii of the circles

		/* Functions defining the actual algorithm */

		//Function to plot a point
		void putPixel(Point actualPoint)
		{
			glBegin(GL_POINTS);
			glVertex2i(actualPoint.x, actualPoint.y);
			glEnd();
		}

	public:

		// Constructor
		ModifiedBresenhamLineDrawing(Point a, Point b)
		{
			A = a;
			B = b;
		}
		
		// Method to change the starting point
		void changeStart(Point a)
		{
			A = a;
		}

		// Method to change the end Point
		void changeEnd(Point b)
		{
			B = b;
		}

        // Method to check if a point is inside circle A
        bool checkInsideA(Point x)
        {
            Point temp = x - A;
            return ((temp.x)*(temp.x) + (temp.y)*(temp.y) <= radiusA*radiusA);
        }

        // Method to check if a point is inside circle B
        bool checkInsideB(Point x)
        {
            Point temp = x - B;
            return ((temp.x)*(temp.x) + (temp.y)*(temp.y) <= radiusB*radiusB);
        }

		void modifiedBresenhamLine()
		{
			// Handling degenerate lines.
			if(A == B) {
				return;
			}
			// Ensuring point A is the one with the lesser x coordinate, so we can move from left to right
			if(A.x == B.x) {
				if(A.y  > B. y)
					swap(A, B);
            }
			else {
				if(A.x > B.x)
					swap(A, B);
			}

			Point currPoint = A;

			int dy = B.y - A.y;
			int dx = B.x - A.x;

			/* Handling different cases */

			// Line parallel to x axis

			if (dy == 0) {
				while(currPoint != B) {
                    if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
					    putPixel(currPoint);
					currPoint.x = currPoint.x + 1;
				}
			}


			// Line parallel to y axis

			else if (dx == 0) {
				while(currPoint != B) {
                    if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
					    putPixel(currPoint);
					if(dy > 0)
						currPoint.y = currPoint.y + 1;
					else
						currPoint.y = currPoint.y - 1;
				}
			}

			// Positive Slope
			else if(dy > 0) {

				// Slope <  1
				if(dx >= dy) {
					int d = 2*dy - dx;
					int incrE = 2*dy;
					int incrNE = 2*(dy - dx);


					while(currPoint.x < B.x) {
						if (d <= 0)
							d += incrE;
						else {
							d += incrNE;
							currPoint.y = currPoint.y + 1;
						}
						currPoint.x = currPoint.x + 1;
                        if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
						    putPixel(currPoint);
					}
				}

				// Slope > 1

				else {
					int d = dy - 2*dx;
					int incrN = -2*dx;
					int incrNE = 2*(dy - dx);


					while(currPoint.y < B.y) {
						if (d > 0)
							d += incrN;
						else {
							d += incrNE;
							currPoint.x = currPoint.x + 1;
						}
						currPoint.y = currPoint.y + 1;
                        if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
						    putPixel(currPoint);
					}
				}
			}

			// Negative Slope
			else {
				// Slope >  -1
				if(dx >= -dy) {
					int d = 2*dy + dx;
					int incrE = 2*dy;
					int incrSE = 2*(dy + dx);

					while(currPoint.x < B.x) {
						if (d >= 0)
							d += incrE;
						else {
							d += incrSE;
							currPoint.y = currPoint.y - 1;
						}
						currPoint.x = currPoint.x + 1;
                        if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
						    putPixel(currPoint);
					}
				}

				// Slope < -1

				else {
					int d = dy + 2*dx;
					int incrS = 2*dx;
					int incrSE = 2*(dy + dx);


					while(currPoint.y > B.y) {
						if (d <= 0)
							d += incrS;
						else {
							d += incrSE;
							currPoint.x = currPoint.x + 1;
						}
						currPoint.y = currPoint.y - 1;
                        if(!(checkInsideA(currPoint) || checkInsideB(currPoint)))
						    putPixel(currPoint);
					}
				}
			}
		}
};

#endif