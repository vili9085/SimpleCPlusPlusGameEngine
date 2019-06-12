#include "Vector2.h"
#include <math.h>
//#include <iostream>

namespace preydator{
Vector2::Vector2() {

}

Vector2::Vector2(double x, double y) : x(x), y(y)
{
}


Vector2::~Vector2()
{
}

double Vector2::length() {
	return sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() {
	Vector2 normalized;
	double length = this->length();
	
	if (length != 0) {
		normalized.x = x / length;
		normalized.y = y / length;
			
	}
	//std::cout << normalized.x << "    " << normalized.y << std::endl;
	return normalized;
	
	
		
	
}
std::ostream & operator<<(std::ostream & os, const Vector2 & vec) {
	return os << vec.x << " " << vec.y;
}

}

