#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

//Vector Tests

//Konstruktoren
TEST_CASE (" default_Constructor ", "[default_Constructor]")
{
Vec2 nullVector{}; //sollte Vektor mit x_ == y_ == 0 erzeugen

REQUIRE (nullVector.x_ == 0);
REQUIRE (nullVector.y_ == 0);
REQUIRE (nullVector.x_ == nullVector.y_);
}

TEST_CASE (" value_Constructor ", "[value_Constructor]")
{
Vec2 valueVector{5.4f,2.0f};
REQUIRE (valueVector.x_ == 5.4f);
REQUIRE (valueVector.y_ == 2.0f);
}

//Operatoren (Member)
TEST_CASE (" plusGleich ", "[plusGleich]")
{
Vec2 plusGleich1{1.0f,2.0f};
Vec2 plusGleich2{4.0f,6.0f};
Vec2 plusGleich3{0.0f,3.0f};

plusGleich1 += plusGleich2;
plusGleich2 += plusGleich3;
plusGleich3 += plusGleich1;

REQUIRE (plusGleich1.x_ == 5.0f);
REQUIRE (plusGleich1.y_ == 8.0f);
REQUIRE (plusGleich2.x_ == 4.0f);
REQUIRE (plusGleich2.y_ == 9.0f);
REQUIRE (plusGleich3.x_ == 5.0f);
REQUIRE (plusGleich3.y_ == 11.0f);
}

TEST_CASE (" minusGleich ", "[minusGleich]")
{
Vec2 minusGleich1{4.0f,2.0f};
Vec2 minusGleich2{2.0f,1.0f};
Vec2 minusGleich3{0.0f,1.0f};

minusGleich1 -= minusGleich2;
minusGleich2 -= minusGleich3;
minusGleich3 -= minusGleich1;

REQUIRE (minusGleich1.x_ == 2.0f);
REQUIRE (minusGleich1.y_ == 1.0f);
REQUIRE (minusGleich2.x_ == 2.0f);
REQUIRE (minusGleich2.y_ == 0.0f);
REQUIRE (minusGleich3.x_ == -2.0f);
REQUIRE (minusGleich3.y_ == 0.0f);
}

TEST_CASE (" malGleich ", "[malGleich]")
{
Vec2 malGleich1{4.0f,2.0f};
Vec2 malGleich2{2.5f,3.7f};
Vec2 malGleich3{1.0f,3.5f};
Vec2 malGleich4{1.4f,8.2f};

malGleich1 *= 2.5f;
malGleich2 *= 1.3;
malGleich3 *= -2.0f;
malGleich4 *= 0.0f;

REQUIRE (malGleich1.x_ == 10.0f);
REQUIRE (malGleich1.y_ == 5.0f);
REQUIRE (malGleich2.x_ == 3.25f);
REQUIRE (malGleich2.y_ == 4.81f);
REQUIRE (malGleich3.x_ == -2.0f);
REQUIRE (malGleich3.y_ == -7.0f);
REQUIRE (malGleich4.x_ == 0.0f);
REQUIRE (malGleich4.y_ == 0.0f);
}

TEST_CASE (" divGleich ", "[divGleich]"){

Vec2 divGleich1{4.0f,2.0f};
Vec2 divGleich2{3.5f,1.7f};
Vec2 divGleich3{0.0f,1.0f};
Vec2 divGleich4{1.0f,1.0f};

divGleich1 /= 2.0f;
divGleich2 /= 1.5f;
divGleich3 /= -3.0f;
divGleich4 /= 0.0f;

REQUIRE (divGleich1.x_ == 2.0f);
REQUIRE (divGleich1.y_ == 1.0f);
REQUIRE (divGleich2.x_ == Approx(2.333333f));
REQUIRE (divGleich2.y_ == Approx(1.133333f));
REQUIRE (divGleich3.x_ == 0.0f);
REQUIRE (divGleich3.y_ == Approx(-0.33333f));
}

//Operatoren (keine Member)
TEST_CASE (" plus ", "[plus]")
{
Vec2 plus1{1.3f, 2.6f};
Vec2 plus2{8.7f, 4.4f};

Vec2 summe = plus1 + plus2;
REQUIRE (summe.x_ == 10.0f);
REQUIRE (summe.y_ == 7.0f);
}

TEST_CASE (" minus ", "[minus]")
{
Vec2 minus1{3.5f, 10.0f};
Vec2 minus2{2.7f, 1.0f};

Vec2 differenz = minus1 - minus2;
REQUIRE (differenz.x_ == Approx(0.8f));
REQUIRE (differenz.y_ == 9.0f);
}

TEST_CASE (" mal ", "[mal]")
{
Vec2 mal1{2.3f, 5.1f};
Vec2 mal2{9.0f, 7.8f};

Vec2 skalar1 = mal1 * 2.0f;
Vec2 skalar2 = mal2 * 1.5f;

REQUIRE (skalar1.x_ == 4.6f);
REQUIRE (skalar1.y_ == 10.2f);
REQUIRE (skalar2.x_ == 13.5f);
REQUIRE (skalar2.y_ == Approx(11.7f));
}

TEST_CASE (" div ", "[div]")
{
Vec2 div1{4.0f, 2.0f};
Vec2 div2{9.3f, 6.3f};
Vec2 div3{8.1f, 2.4f};

Vec2 quotient1 = div1 / 2.0f;
Vec2 quotient2 = div2 / 3.3f;
Vec2 quotient3 = div3 / 0.0f;

REQUIRE (quotient1.x_ == 2.0f);
REQUIRE (quotient1.y_ == 1.0f);
REQUIRE (quotient2.x_ == Approx(2.81818f));
REQUIRE (quotient2.y_ == Approx(1.90909f));
REQUIRE_FALSE (quotient3.x_ == 0.0f);
REQUIRE (!(quotient3.y_ == 0.0f));
}

TEST_CASE (" mal2 ", "[mal2]")
{
Vec2 mal3{3.0f, 2.0f};
Vec2 mal4{4.7f, 0.0f};

Vec2 skalar3 = mal3 * 6.8f;
Vec2 skalar4 = mal4 * 2.0f;

REQUIRE (skalar3.x_ == Approx(20.4f));
REQUIRE (skalar3.y_ == Approx(13.6f));
REQUIRE (skalar4.x_ == Approx(9.4f));
REQUIRE (skalar4.y_ == Approx(0.0f));
}


//Matrizen Tests

//Konstruktoren
TEST_CASE (" default_MatrConstr ", "[default_MatrConstr]")
{
Mat2 identMatr{};

REQUIRE (identMatr.x1_ == 1.0f);
REQUIRE (identMatr.x2_ == 0.0f);
REQUIRE (identMatr.y1_ == 0.0f);
REQUIRE (identMatr.y2_ == 1.0f);
}

TEST_CASE (" value_Matr_Constr ", "[value_Matr_Constr]")
{
Mat2 valueMatr{2.0f, 3.3f, 5.1f, 7.5f};

REQUIRE (valueMatr.x1_ == 2.0f);
REQUIRE (valueMatr.x2_ == 3.3f);
REQUIRE (valueMatr.y1_ == 5.1f);
REQUIRE (valueMatr.y2_ == 7.5f);
}

//Operatoren

//Matrizenmultiplikation (2x2)
TEST_CASE (" matrizen_multiplikation ", "[matrizen_multiplikation]")
{
Mat2 multMat1{2.0f, 3.3f, 5.1f, 7.5f};
Mat2 multMat2{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 multMat3{0.0f, 8.2f, 0.0f, 0.0f};

multMat1 *= multMat2;
multMat2 *= multMat3;

REQUIRE (multMat1.x1_ == Approx(-22.06f));
REQUIRE (multMat1.x2_ == Approx(8.39f));
REQUIRE (multMat1.y1_ == Approx(-48.75f));
REQUIRE (multMat1.y2_ == Approx(21.12f));
REQUIRE (multMat2.x1_ == 0.0f);
REQUIRE (multMat2.x2_ == 20.5f);
REQUIRE (multMat2.y1_ == 0.0f);
REQUIRE (multMat2.y2_ == -67.24f);
}

TEST_CASE (" multMat ", "[multMat]")
{
Mat2 mult1{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mult2{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 mult3{0.0f, 8.2f, 0.0f, 0.0f};

Mat2 product = mult1 * mult2;
Mat2 product2 = mult2 * mult3;
REQUIRE (product.x1_ == Approx(5.0f));
REQUIRE (product.x2_ == Approx(7.4f));
REQUIRE (product.y1_ == Approx(74.25f));
REQUIRE (product.y2_ == Approx(16.62f));
REQUIRE (product2.x1_ == Approx(0.0f));
REQUIRE (product2.x2_ == Approx(20.5f));
REQUIRE (product2.y1_ == Approx(0.0f));
REQUIRE (product2.y2_ == Approx(-67.24f));
}


//Multiplikationen Vektor mit Matrix
TEST_CASE (" matVec_mult ", "[matVec_mult]")
{
Mat2 mMult1{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mMult2{2.5f, 3.7f, -8.2f, 0.3f};
Vec2 vMult1{-2.3f, 5.1f};
Vec2 vMult2{4.7f, 0.0f};

Vec2 product = mMult1 * vMult1;
Vec2 product2 = mMult2 * vMult2;
Vec2 product3 = mMult2 * vMult1;
REQUIRE (product.x_ == Approx(-4.6f));
REQUIRE (product.y_ == Approx(-49.98f));
REQUIRE (product2.x_ == Approx(11.75f));
REQUIRE (product2.y_ == Approx(-38.54f));
REQUIRE (product3.x_ == Approx(13.12f));
REQUIRE (product3.y_ == Approx(20.39f));
}

TEST_CASE (" vecMat_mult ", "[vecMat_mult]")
{
Mat2 mMult3{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mMult4{2.5f, 3.7f, -8.2f, 0.3f};
Vec2 vMult3{-2.3f, 5.1f};
Vec2 vMult4{4.7f, 0.0f};

Vec2 product4 = vMult3 * mMult3;
Vec2 product5 = vMult4 * mMult4;
Vec2 product6 = vMult3 * mMult4;
REQUIRE (product4.x_ == Approx(-4.6f));
REQUIRE (product4.y_ == Approx(-49.98f));
REQUIRE (product5.x_ == Approx(11.75f));
REQUIRE (product5.y_ == Approx(-38.54f));
REQUIRE (product6.x_ == Approx(13.12f));
REQUIRE (product6.y_ == Approx(20.39f));
}

//Determinante
TEST_CASE (" determinante ", "[determinante]")
{
Mat2 detMat1{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 detMat2{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 detMat3{3.732f, 0.0f, -89.6f, 0.0f};

REQUIRE (detMat1.det() == 31.09f);
REQUIRE (detMat2.det() == -15.0f);
REQUIRE (detMat3.det() == 0.0f);
}

//Inverse
TEST_CASE (" inverse ", "[inverse]")
{
Mat2 mA{2.0f, -3.0f, 1.0f, 5.0f};
Mat2 invMat1 = inverse(mA);
Mat2 mB{};
Mat2 invMat2 = inverse(mB);
Mat2 mC{2.3f, 4.8f, 0.0f, 0.0f};
Mat2 invMat3 = inverse(mC);

REQUIRE (invMat1.x1_ == Approx(0.38461));
REQUIRE (invMat1.x2_ == Approx(0.23076));
REQUIRE (invMat1.y1_ == Approx(-0.07692));
REQUIRE (invMat1.y2_ == Approx(0.15384));
REQUIRE (invMat2.x1_ == 1.0f);
REQUIRE (invMat2.x2_ == 0.0f);
REQUIRE (invMat2.y1_ == 0.0f);
REQUIRE (invMat2.y2_ == 1.0f);
REQUIRE (invMat3.x1_ == -1.0f);
REQUIRE (invMat3.x2_ == -1.0f);
REQUIRE (invMat3.y1_ == -1.0f);
REQUIRE (invMat3.y2_ == -1.0f);
}

//Transponieren
TEST_CASE (" transpose ", "[transpose]")
{
Mat2 mA{2.5f, 3.7f, -8.2f, 0.3f};
Mat2 mTrans1 = transpose(mA);
Mat2 mB{2.0f, 0.0f, 5.1f, -7.5f};
Mat2 mTrans2 = transpose(mB);

REQUIRE (mTrans1.x1_ == 2.5f);
REQUIRE (mTrans1.x2_ == -8.2f);
REQUIRE (mTrans1.y1_ == 3.7f);
REQUIRE (mTrans1.y2_ == 0.3f);
REQUIRE (mTrans2.x1_ == 2.0f);
REQUIRE (mTrans2.x2_ == 5.1f);
REQUIRE (mTrans2.y1_ == 0.0f);
REQUIRE (mTrans2.y2_ == -7.5f);
}

//Rotationsmatrix
TEST_CASE (" rotation ", "[rotation]")
{

Mat2 mRot1 = make_rotation_mat2(M_PI / 2);
Mat2 mRot2 = make_rotation_mat2(0);
Mat2 mRot3 = make_rotation_mat2(-2.5);

REQUIRE (mRot1.x1_ == Approx(0.0f));
REQUIRE (mRot1.x2_ == Approx(-1.0f));
REQUIRE (mRot1.y1_ == Approx(1.0f));
REQUIRE (mRot1.y2_ == Approx(0.0f));
REQUIRE (mRot2.x1_ == 1.0f);
REQUIRE (mRot2.x2_ == 0.0f);
REQUIRE (mRot2.y1_ == 0.0f);
REQUIRE (mRot2.y2_ == 1.0f);
REQUIRE (mRot3.x1_ == Approx(-0.80114f));
REQUIRE (mRot3.x2_ == Approx(0.59847f));
REQUIRE (mRot3.y1_ == Approx(-0.59847f));
REQUIRE (mRot3.y2_ == Approx(-0.80114f));
}


int main(int argc, char *argv[]){


  return Catch::Session().run(argc, argv);
}
