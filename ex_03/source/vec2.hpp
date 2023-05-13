# ifndef VEC2_HPP
# define VEC2_HPP

// Vec2 class definition
struct Vec2{

	int x_;
	int y_;

	Vec2();

	Vec2(int x, int y);

	Vec2(Vec2 const& v);

	Vec2& operator += (Vec2 const& v);
	Vec2& operator -= (Vec2 const& v);
	Vec2& operator *= (int s);
	Vec2& operator /= (int s);

};

Vec2 const operator +(Vec2 const& u, Vec2 const& v);
Vec2 const operator -(Vec2 const& u, Vec2 const& v);
Vec2 const operator *(Vec2 const& v, int s);
Vec2 const operator /(Vec2 const& v, int s);
Vec2 const operator *(int s, Vec2 const& v);



# endif // VEC2_HPP
