/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include <cmath>
#include "shapes.h"

using std::abs;

//---------------------------------------------------------------------------RECTANGLE
Rectangle::Rectangle(Point center, double dx, double dy) : center(center), dx(dx), dy(dy) {}

bool Rectangle::contains(const Point & p) const {
	return    abs(p.getX() - center.getX()) <= dx
		&& abs(p.getY() - center.getY()) <= dy;
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------SQUARE
Square::Square(Point center, double side)
	: Rectangle(center, side / 2, side / 2) {}
//------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------Ellipse
Ellipse::Ellipse(Point f1, Point f2, double radius) : f1(f1), f2(f2), radius(radius) {}

bool Ellipse::contains(const Point & p) const {
	return p.distance(f1) + p.distance(f2) <= radius;
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------CIRCLE
Circle::Circle(Point center, double radius)
	: Ellipse(center, center, radius) {}
//------------------------------------------------------------------------------------
