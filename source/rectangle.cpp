#include "rectangle.hpp"


//Konstruktoren
Rectangle::Rectangle():
	min_{0.0f, 0.0f},
	max_{1.0f, 1.0f},
	clr_{0.0} {}

// Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
// 	min_{min},
// 	max_{max} {}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr):
	min_{min},
	max_{max},
	clr_{clr} {}


//Methoden
Vec2 const& Rectangle::getMin() const{
	return this -> min_;
}

Vec2 const& Rectangle::getMax() const{
	return this -> max_;
}

Color const& Rectangle::getColor() const{
	return this -> clr_;
}

float Rectangle::circumference() const{
	return 2 * (std::abs(std::abs(this -> max_.x_) - std::abs(this -> min_.x_))+ std::abs(std::abs(this -> max_.y_) - std::abs(this -> min_.y_)));
}

void Rectangle::draw(Window const& window)const{
	window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, clr_.r_, clr_.g_, clr_.b_);
	window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, clr_.r_, clr_.g_, clr_.b_);
	window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, clr_.r_, clr_.g_, clr_.b_);
	window.draw_line(max_.x_, min_.y_, min_.x_, min_.y_, clr_.r_, clr_.g_, clr_.b_);
}

void Rectangle::draw(Window const& window, Color const& clr)const{
	window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, clr.r_, clr.g_, clr.b_);
	window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, clr.r_, clr.g_, clr.b_);
	window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, clr.r_, clr.g_, clr.b_);
	window.draw_line(max_.x_, min_.y_, min_.x_, min_.y_, clr.r_, clr.g_, clr.b_);
}

bool Rectangle::is_inside(Vec2 const& v){
	return(v.x_ <= getMax().x_ && v.x_ >= getMin().x_ && v.y_<= getMax().y_ && v.y_ >= getMin().y_);
}














