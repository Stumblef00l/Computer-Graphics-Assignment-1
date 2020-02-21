#ifndef BRESENHAM_LINE
#define BRESENHAM_LINE

#include<bits/stdc++.h>
#include <GL/glut.h>
#include "../Point.h"

using namespace std;

/**
 *  Class to implement Bresenham Line Algorithm.
 */
class BresenhamLineDrawing
{
	private:

		Point A, B; //!< the end-points of the line.

		/**
          * Method to plot a Point.
          * @param translatedPoint the Point to be plotted.
          */
		void putPixel(Point actualPoint)
		{
			glBegin(GL_POINTS);
			glVertex2i(actualPoint.x, actualPoint.y);
			glEnd();
		}

	public:

		/**
          * Constructor of the BresenhamLineDrawing class.
          * @param a the start point of the line.
          * @param b the end point of the line.
          */
		BresenhamLineDrawing(Point a, Point b)
		{
			A = a;
			B = b;
		}
		
		/**
          * Method to change the start point of the line. 
          * @param a the new start point.
          */
		void changeStart(Point a)
		{
			A = a;
		}

		/**
          * Method to change the end point of the line. 
          * @param b the new end point.
          */
		void changeEnd(Point b)
		{
			B = b;
		}

		/**
          * Method to implement the Bresenham Line algorithm. 
          */
		void bresenhamLine()
		{
			// Handling degenerate lines.
			if(A == B) {
				putPixel(A);
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
					putPixel(currPoint);
					currPoint.x = currPoint.x + 1;
				}
				putPixel(B);
			}


			// Line parallel to y axis

			else if (dx == 0) {
				while(currPoint != B) {
					putPixel(currPoint);
					if(dy > 0)
						currPoint.y = currPoint.y + 1;
					else
						currPoint.y = currPoint.y - 1;
				}
				putPixel(B);
			}

			// Positive Slope
			else if(dy > 0) {

				// Slope <  1
				if(dx >= dy) {
					int d = 2*dy - dx;
					int incrE = 2*dy;
					int incrNE = 2*(dy - dx);

					putPixel(A);

					while(currPoint.x < B.x) {
						if (d <= 0)
							d += incrE;
						else {
							d += incrNE;
							currPoint.y = currPoint.y + 1;
						}
						currPoint.x = currPoint.x + 1;
						putPixel(currPoint);
					}
				}

				// Slope > 1

				else {
					int d = dy - 2*dx;
					int incrN = -2*dx;
					int incrNE = 2*(dy - dx);

					putPixel(A);

					while(currPoint.y < B.y) {
						if (d > 0)
							d += incrN;
						else {
							d += incrNE;
							currPoint.x = currPoint.x + 1;
						}
						currPoint.y = currPoint.y + 1;
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
					putPixel(A);

					while(currPoint.x < B.x) {
						if (d >= 0)
							d += incrE;
						else {
							d += incrSE;
							currPoint.y = currPoint.y - 1;
						}
						currPoint.x = currPoint.x + 1;
						putPixel(currPoint);
					}
				}

				// Slope < -1

				else {
					int d = dy + 2*dx;
					int incrS = 2*dx;
					int incrSE = 2*(dy + dx);

					putPixel(A);

					while(currPoint.y > B.y) {
						if (d <= 0)
							d += incrS;
						else {
							d += incrSE;
							currPoint.x = currPoint.x + 1;
						}
						currPoint.y = currPoint.y - 1;
						putPixel(currPoint);
					}
				}
			}
		}
};

#endif