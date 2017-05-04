# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "vec2.hpp"

//circle class definition
class Circle{

public:

	float radius_;
	Vec2 center_;

	Circle();

	Circle(float radius, Vec2 const& center);

	float getRadius() const;
	Vec2 const& getCenter() const;

};


# endif // CIRCLE_HPP