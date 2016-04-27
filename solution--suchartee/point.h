/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#ifndef POINT_H
#define POINT_H

class Point {
private:
	double x;
	double y;

public:
	//Constructor: Initializing the point to default (0,0)
	Point(double x = 0, double y = 0);

	//Functions prototypes
	double getX() const;
	double getY() const;
	double distance(const Point & a) const;
};
#endif
