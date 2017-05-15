# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include <cmath>
# include <algorithm>
# include "vec2.hpp"

//circle class definition
class Circle{

public:

	int radius_;
	Vec2 center_;

	Circle();

	Circle(int radius, Vec2 const& center);

	int getRadius() const;
	Vec2 const& getCenter() const;

	//Umfang
	int circumference() const; //const, weil der Kreis nicht veraendert wird

	bool operator <(Circle const& c)const;
	bool operator >(Circle const& c)const;
	bool operator ==(Circle const& c)const;


};


# endif // CIRCLE_HPP
