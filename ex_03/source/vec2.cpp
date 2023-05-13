#include "vec2.hpp"

//Konstruktoren

Vec2::Vec2():
	x_{0},
	y_{0} {}

Vec2::Vec2(int x, int y):
	x_{x},
	y_{y} {}

Vec2::Vec2(Vec2 const& v):
	x_{v.x_},
	y_{v.y_} {}


//Operationen

Vec2& Vec2::operator += (Vec2 const& v){
	this -> x_ += v.x_;
	this -> y_ += v.y_;
	return *this; //this wird durch das * zum referenzierten Element
}

Vec2& Vec2::operator -= (Vec2 const& v){
	this -> x_ -= v.x_;
	this -> y_ -= v.y_;
	return *this;

}

Vec2& Vec2::operator *= (int s){
	this -> x_ *= s;
	this -> y_ *= s;
	return *this;
}

Vec2& Vec2::operator /= (int s){
	this -> x_ /= s;
	this -> y_ /= s;
	return *this;
}

Vec2 const operator +(Vec2 const& u, Vec2 const& v){
	return Vec2{u} += v;
}

Vec2 const operator -(Vec2 const& u, Vec2 const& v){
	return Vec2{u} -= v;
}

Vec2 const operator *(Vec2 const& v, int s){
	return Vec2{v} *= s;
}

Vec2 const operator /(Vec2 const& v, int s){
	return Vec2{v} /= s;
}

Vec2 const operator *(int s, Vec2 const& v){
	return Vec2{v} *= s;
}
