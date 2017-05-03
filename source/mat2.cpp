#include "mat2.hpp"

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

Mat2 const operator *(Mat2 const& m1 , Mat2 const& m2){
	return Mat2{m1} *= m2;
}