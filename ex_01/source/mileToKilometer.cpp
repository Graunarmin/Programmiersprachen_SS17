#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <iostream>
#include <string>

double mileToKilometer(double o){
	return (o * 1.609);
}

TEST_CASE (" describe_mileToKilometer ", "[mileToKilometer]"){
REQUIRE (mileToKilometer (1.00) == 1.609);
REQUIRE (mileToKilometer (1.7) == 2.7353);
REQUIRE (mileToKilometer (5.8) == 9.3322);
}

int main(int argc, char* argv[]){
std::cout << "Please enter the distance in miles: \n";
double o;
std::cin >> o;
std::cout << o << " miles are " << mileToKilometer(o) << " kilometers. \n";
std::cout << "\n";
return Catch::Session().run(argc, argv);
}