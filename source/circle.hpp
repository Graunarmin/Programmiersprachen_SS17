# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "vec2.hpp"
# include "color.hpp"

//circle class definition
class Circle{

public:

	float radius_;
	Vec2 center_;
	Color clr_;

	Circle();

	Circle(float radius, Vec2 const& center);

	Circle(float radius, Vec2 const& center, Color const& clr);

	float getRadius() const;
	Vec2 const& getCenter() const;

	//Umfang
	float circumference() const; //const, weil der Kreis nicht veraendert wird

};


# endif // CIRCLE_HPP