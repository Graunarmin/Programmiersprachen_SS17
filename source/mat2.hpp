# ifndef MAT2_HPP
# define MAT2_HPP

// Mat2 definition
struct Mat2{

	float x1_;
	float x2_;
	float y1_;
	float y2_;

	Mat2(); 

	Mat2(float x1, float x2, float y1, float y2);

	Mat2(Mat2 const& m);

	Mat2& operator *= (Mat2 const& m);

};

Mat2 const operator *(Mat2 const& m1 , Mat2 const& m2);

# endif //MAT2_HPP