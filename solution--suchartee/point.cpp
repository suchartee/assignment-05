#include <cmath>
#include "point.h"

/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

using std::pow;
using std::sqrt;

//Constructor: Initializing x and y values
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

double Point::distance(const Point & a) const {
	return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
}
