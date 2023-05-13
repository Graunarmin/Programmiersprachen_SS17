# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "vec2.hpp"
# include "mat2.hpp"
# include "color.hpp"
# include "window.hpp"
# include <cmath>

//circle class definition
class Circle{

public:

	float radius_;
	Vec2 center_;
	Color clr_;

	Circle();

	Circle(float radius, Vec2 const& center, Color const& clr);

	float getRadius() const;
	Vec2 const& getCenter() const;
	Color const& getColor() const;

	//Umfang
	float circumference() const; //const, weil der Kreis nicht veraendert wird

	//Zeichnen
	void draw(Window const& window)const; 
	void draw(Window const& window, Color const& clr)const;

	bool is_inside(Vec2 const& v);

};


# endif // CIRCLE_HPP