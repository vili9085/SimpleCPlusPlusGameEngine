#ifndef VECTOR2_H
#define VECTOR2_H
#include <ostream>
namespace preydator{
	class Vector2
	{
	public:

		Vector2();
		Vector2(double x, double y);
		Vector2 normalized();
		double length();
	
		const Vector2 & operator+=(const Vector2 & other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		const Vector2 & operator*=(const float other) {
			x *= other;
			y *= other;
			return *this;
		}
		const Vector2 & operator*=(const Vector2 other){
			x *= other.x;
			y *= other.y;
			return *this;

		}
	
	
		~Vector2();

		double x = 0; //ska användas så pass ofta i tillämpningsprogrammet att de inte passar som privata variabler.
		double y = 0; //ska användas så pass ofta i tillämpningsprogrammet att de inte passar som privata variabler.

	private:

		friend std::ostream & operator <<(std::ostream & os, Vector2 & vec);
	
	};
	 inline Vector2 operator*(Vector2 lhs, const float & rhs) {
	
		 lhs *= rhs;
		 return lhs;
	}
	 inline Vector2 operator*(Vector2 lhs, const Vector2 & rhs) {
		 lhs *= rhs;
		 return lhs;

	 }
 
}


#endif