#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <math.h>

//Konstruktoren
Mat2::Mat2():
	x1_{1.0f},
	x2_{0.0f},
	y1_{0.0f},
	y2_{1.0f} {}

Mat2::Mat2(float x1, float x2, float y1, float y2):
	x1_{x1},
	x2_{x2},
	y1_{y1},
	y2_{y2} {}

Mat2::Mat2(Mat2 const& m):
	x1_{m.x1_},
	x2_{m.x2_},
	y1_{m.y1_},
	y2_{m.y2_} {}


//Determinante
float Mat2::det() const{
	return ((this -> x1_ * this -> y2_) - (this -> y1_ * this -> x2_));
}

//Operatoren
Mat2& Mat2::operator *=(Mat2 const& m){
	float tempX1 = (this -> x1_ * m.x1_) + (this -> x2_ * m.y1_);
	float tempX2 = (this -> x1_ * m.x2_) + (this -> x2_ * m.y2_);
	float tempY1 = (this -> y1_ * m.x1_) + (this -> y2_ * m.y1_);
	float tempY2 = (this -> y1_ * m.x2_) + (this -> y2_ * m.y2_);
	this -> x1_ = tempX1;
	this -> x2_ = tempX2;
	this -> y1_ = tempY1;
	this -> y2_ = tempY2;
	return *this;
}

Mat2 const operator *(Mat2 const& m1, Mat2 const& m2){
	return Mat2{m1} *= m2;
}

Vec2 const operator *(Mat2 const& m, Vec2 const& v){
	return Vec2{((m.x1_ * v.x_) + (m.x2_ * v.y_)), ((m.y1_*v.x_) + (m.y2_*v.y_))};
}

Vec2 const operator *(Vec2 const& v, Mat2 const& m){
	return Vec2{((m.x1_ * v.x_) + (m.x2_ * v.y_)), ((m.y1_*v.x_) + (m.y2_*v.y_))};
}

//Inverse
Mat2 const inverse (Mat2 const& m){
	if (m.det() == 0){ //Inverse geht nur, wenn Determinante ungleich 0 ist!
		return Mat2{-1.0f, -1.0f, -1.0f, -1.0f};
	}
	else{
		return Mat2{m.y2_*(1 / m.det()), (-1 * m.x2_)*(1 / m.det()), (-1 * m.y1_)*(1 / m.det()), m.x1_*(1 / m.det())};
	}
}

//Transponieren
Mat2 const transpose (Mat2 const& m){
	return Mat2{m.x1_, m.y1_, m.x2_, m.y2_};
}

//Rotationsmatrix
Mat2 const make_rotation_mat2 (float phi){
	return Mat2{(float)cos(phi), (float)-sin(phi), (float)sin(phi), (float)cos(phi)};
}



