# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
# include "vec2.hpp"
#include <cmath>
#include <cstdlib>

//rectangle class definition
class Rectangle{

public:

	Vec2 min_;
	Vec2 max_;

	Rectangle();

	Rectangle(Vec2 const& min, Vec2 const& max);

	Vec2 const& getMin() const;
	Vec2 const& getMax() const;

	//Umfang
	float circumference() const; //const, weil das Rechteck nicht veraendert wird

};


# endif // RECTANGLE_HPP