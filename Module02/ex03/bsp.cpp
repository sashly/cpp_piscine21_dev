#include "Point.hpp"

//var denominator:Number = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
//var a:Number = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / denominator;
//var b:Number = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / denominator;
//var c:Number = 1 - a - b;
//return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;

bool	bsp( Point const p1, Point const p2, Point const p3, Point const p ) {

	float	denominator;
	float	a;
	float	b;
	float	c;

//	std::cout << p1 << ", " << p2 << ", " << p3 << ", " << p << ";\n";
	denominator = (p2.gety().toFloat() - p3.gety().toFloat())
			* (p1.getx().toFloat() - p3.getx().toFloat())
			+ (p3.getx().toFloat() - p2.getx().toFloat())
			* (p1.gety().toFloat() - p3.gety().toFloat());
	a = ((p2.gety().toFloat() - p3.gety().toFloat())
			* (p.getx().toFloat() - p3.getx().toFloat())
			+ (p3.getx().toFloat() - p2.getx().toFloat())
			* (p.gety().toFloat() - p3.gety().toFloat())) / denominator;
	b = ((p3.gety().toFloat() - p1.gety().toFloat())
			* (p.getx().toFloat() - p3.getx().toFloat())
			+ (p1.getx().toFloat() - p3.getx().toFloat())
			* (p.gety().toFloat() - p3.gety().toFloat())) / denominator;
	c = 1 - a - b;
	return ((a > 0 && a < 1) && (b > 0 && b < 1) && (c > 0 && c < 1));
}
