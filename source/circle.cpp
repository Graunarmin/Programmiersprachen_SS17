#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>

//Konstruktoren
//initialisiert Einheitskreis
Circle::Circle():
	radius_{1},
	center_{Vec2{}} {}

//initialisiert Kreis mit Radius und Mittelpunkt
Circle::Circle(float radius, Vec2 const& center):
	radius_{radius},
	center_{center} {}

//Methodens
float Circle::getRadius() const{
	return this -> radius_;
}

Vec2 const& Circle::getCenter() const{
	return this -> center_;
}

float Circle::circumference() const{
	return 2 * M_PI * this -> radius_;
}


