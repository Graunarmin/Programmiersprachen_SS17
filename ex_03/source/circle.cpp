#include "circle.hpp"

//Konstruktoren
//initialisiert Einheitskreis
Circle::Circle():
	radius_{1},
	center_{Vec2{}} {}

//initialisiert Kreis mit Radius und Mittelpunkt
Circle::Circle(int radius, Vec2 const& center):
	radius_{radius},
	center_{center} {}

//Methoden
int Circle::getRadius() const{
	return radius_;
}

Vec2 const& Circle::getCenter() const{
	return center_;
}

int Circle::circumference() const{
	return 2 * M_PI * radius_;
}

//Operatoren überladen
bool Circle::operator <(Circle const& c) const{
	return radius_ < c.radius_;
}

bool Circle::operator >(Circle const& c) const{
	return radius_ > c.radius_;
}

bool Circle::operator ==(Circle const& c) const{
	return radius_ == c.radius_;
}
