# include "color.hpp"

//Konstruktoren
Color::Color():
	r_{0.0f},
	g_{0.0f},
	b_{0.0f} {}

Color::Color(float a):
	r_{a},
	g_{a},
	b_{a} {}

Color::Color(float r, float g, float b):
	r_{r},
	g_{g},
	b_{b} {}
	
