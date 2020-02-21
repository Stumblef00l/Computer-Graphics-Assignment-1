#ifndef POINT
#define POINT

#include<bits/stdc++.h>

using namespace std;

/**
 *  Struct to represent a point.
 */
struct Point
{
	int x;      //!< the x co-ordinate of the point.
	int y;      //!< the y co-ordinate of the point.
	
	/**
       * Constructor for the Point class.
       * Initializes the x and y co-ordiantes to 0.
       */
	Point()                 
	{
		x = 0;
		y = 0;
	}

	/**
       * Parameterized constructor for the Point class.
       * @param x the x co-ordinate of the point.
       * @param y the y co-ordinate of the point.
       */
	Point(int x,int y)      
	{
		this->x = x;
		this->y = y;
	}
	
	/**
       * Assignment operator for the Point class.
       * @param p the point to be assigned. 
       */
	void operator =(const Point &p)
	{
		x = p.x;
		y = p.y;
	}

	/**
       * Addition operator for the Point class.
       * @param p the Point to be added.
       * @return a Point with the co-ordinates added.  
       */
	Point operator +(const Point &p)
	{
		return Point(x + p.x, y + p.y);
	}

	/**
       * Subtraction operator for the Point class.
       * @param p the Point to be subtracted.
       * @return a Point with the co-ordinates subtracted.  
       */
	Point operator -(const Point &p)
	{
		return Point(x - p.x, y - p.y);
	}

	/**
       * Equality operator for the Point class.
       * @param p the Point to be compared.
       * @return true if the points are equal, false otherwise.
       */
	bool operator ==(const Point &p)
	{
		return ((x == p.x) && (y == p.y));
	}

	/**
       * Inequality operator for the Point class.
       * @param p the Point to be compared.
       * @return false if the points are equal, true otherwise.
       */
	bool operator !=(const Point &p)
	{
		return !((x == p.x) && (y == p.y));
	}

};

#endif