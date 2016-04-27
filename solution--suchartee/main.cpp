/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Suchartee Kitisopakul <suchartee@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A short program that create animated shapes
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "point.h"
#include "shapes.h"

using std::cout;
using std::endl;
using std::vector;


void draw(const vector<Shape*> & v) {
	const double xSize = 80;
	const double ySize = 25;

	const double xScale = 1;
	const double yScale = 1.9;

	for (double yp = 0; yp < ySize; yp++) {
		double y = yp * yScale;

		for (double xp = 0; xp < xSize; xp++) {
			double x = xp * xScale;

			if (yp == 0 || yp == ySize - 1) {
				cout << "-";
				continue;
			}

			if (xp == 0 || xp == xSize - 1) {
				cout << "|";
				continue;
			}

			bool includePoint = false;

			for (int c = 0; c < v.size(); c++){
				if (v[c]->contains(Point(x, y)))
					includePoint = true;
			}
			
			if (includePoint)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

// ----------------------------------------------------------------------------

int main() {
	const int frames = 40;
	const int frameSleep = 70;  //milliseconds

	//For each frame
	for (double d = 0; d < frames; d++) {
		//Create shapes
		Rectangle r(Point(5 + d, 5), 2, 8);
		Square    s(Point(50 - (d / 2), 5 + (d / 2)), 7);
		Ellipse   e(Point(10 - (d / 3), 35 + (d / 3)), Point(25 - (d / 3), 35 + (d / 3)), 22 + d);
		Circle    c(Point(50 + (d / 5), 35), 15);

		vector<Shape*> shapes = { &r, &s, &e, &c };

		//Call draw()
		draw(shapes);

		//Wait before drawing the next frame
		std::this_thread::sleep_for(std::chrono::milliseconds(frameSleep));
	}

	system("pause");
	return 0;
}
