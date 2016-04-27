/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#ifndef SHAPES_H
#define SHAPES_H
#include "point.h"

//----------------------------------------------------------------------------SUPERCLASS
class Shape {
public:
	virtual bool contains(const Point & p) const = 0;					  //pure virtual
	virtual ~Shape() = default;
};
//--------------------------------------------------------------------------------------

//-----------------------------------RECTANGLE-&-ELLIPSE--INHERIT FROM SHAPE, SUBCLASSES
class Rectangle : public Shape {
private:
	Point center;
	double dx;
	double dy;

public:
	Rectangle(Point center = Point(), double dx = 0, double dy = 0);

	bool contains(const Point & p) const;
};

class Ellipse : public Shape {
private:
	Point f1;
	Point f2;
	double radius;

public:
	Ellipse(Point f1 = Point(), Point f2 = Point(), double radius = 0);

	bool contains(const Point & p) const;
};
//--------------------------------------------------------------------------------------

//------------------------------------------SQUARE--INHERIT FROM RECTANGLE, SUB-SUBCLASS
class Square : public Rectangle {
public:
	Square(Point center = Point(), double side = 0);
};
//--------------------------------------------------------------------------------------

//--------------------------------------CIRCLE--INHERIT FROM ELLIPSE CLASS, SUB-SUBCLASS
class Circle : public Ellipse {
public:
	Circle(Point center = Point(), double radius = 0);
};
//--------------------------------------------------------------------------------------
#endif
