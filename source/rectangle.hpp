# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
# include "vec2.hpp"
# include "color.hpp"
# include "window.hpp"
#include <cmath>
#include <cstdlib>

//rectangle class definition
class Rectangle{

public:

	Vec2 min_;
	Vec2 max_;
	Color clr_;

	Rectangle();

	Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr);

	Vec2 const& getMin() const;
	Vec2 const& getMax() const;
	Color const& getColor() const;

	//Umfang
	float circumference() const; //const, weil das Rechteck nicht veraendert wird

	//Zeichnen
	void draw(Window const& window)const;
	void draw(Window const& window, Color const& clr)const;
};


# endif // RECTANGLE_HPP