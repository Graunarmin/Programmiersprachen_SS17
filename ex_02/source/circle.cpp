#include "circle.hpp"

//Konstruktoren
//initialisiert Einheitskreis (black)
Circle::Circle():
	radius_{1},
	center_{Vec2{}},
	clr_{0.0} {}

//initialisiert Kreis mit Radius, Mittelpunkt und Farbe
Circle::Circle(float radius, Vec2 const& center, Color const& clr):
	radius_{radius},
	center_{center},
	clr_{clr} {}

//Methoden
float Circle::getRadius() const{
	return this -> radius_;
}

Vec2 const& Circle::getCenter() const{
	return this -> center_;
}

Color const& Circle::getColor() const{
	return this -> clr_;
}

float Circle::circumference() const{
	return 2 * M_PI * this -> radius_;
}

void Circle::draw(Window const& window)const{
	for (int phi = 0; phi <= 360; ++phi){ //Grad in Bogenmaß umrechnen!
		Vec2 startingPoint{(make_rotation_mat2 ((phi * 2 * M_PI)/360) * Vec2{getRadius(),0}) + Vec2{getCenter()}};
		Vec2 endPoint{(make_rotation_mat2 (((phi+1) * 2 * M_PI)/360) * Vec2{getRadius(),0}) + Vec2{getCenter()}};
		window.draw_line(startingPoint.x_, startingPoint.y_, endPoint.x_, endPoint.y_, clr_.r_, clr_.g_, clr_.b_);
	}
}

void Circle::draw(Window const& window, Color const& clr)const{
	for (int phi = 0; phi <= 360; ++phi){ 
		Vec2 startingPoint{(make_rotation_mat2 ((phi * 2 * M_PI)/360) * Vec2{getRadius(),0}) + Vec2{getCenter()}};
		Vec2 endPoint{(make_rotation_mat2 (((phi+1) * 2 * M_PI)/360) * Vec2{getRadius(),0}) + Vec2{getCenter()}};
		window.draw_line(startingPoint.x_, startingPoint.y_, endPoint.x_, endPoint.y_, clr.r_, clr.g_, clr.b_);
		//clr hier ohne _, sonst bezieht es sich auf die Farben des urspr. Objekts!
	}
}

bool Circle::is_inside(Vec2 const& v){
	return sqrt(pow((getCenter().x_ - v.x_),2) + pow((getCenter().y_ - v.y_),2)) <= getRadius();
}

