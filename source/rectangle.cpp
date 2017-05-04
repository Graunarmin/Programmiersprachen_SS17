#include "rectangle.hpp"
#include "vec2.hpp"


//Konstruktoren
Rectangle::Rectangle():
	min_{0.0f, 0.0f},
	max_{1.0f, 1.0f} {}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
	min_{min},
	max_{max} {}


//Methoden
Vec2 const& Rectangle::getMin() const{
	return this -> min_;
}

Vec2 const& Rectangle::getMax() const{
	return this -> max_;
}

float Rectangle::circumference() const{
	return 2*(std::abs(std::abs(this -> max_.x_) - std::abs(this -> min_.x_))+std::abs(std::abs(this -> max_.y_) - std::abs(this -> min_.y_)));
}

