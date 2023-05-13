#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <iostream>

int gcd (int a, int b){
	int temp = 0;

	if (a < b){
		temp = b;
		b = a;
		a = temp;
	}
	if (a > b){
		temp = a;
		a = b;
		b = temp;
	}
	while(true){
		int r = a % b;
		if(r == 0)
			break;
		a = b;
		b = r;
	}
	return b;
}

TEST_CASE (" describe_gcd ", "[gcd]")
{
REQUIRE (gcd (2 ,4) == 2);
REQUIRE (gcd (9 ,6) == 3);
REQUIRE (gcd (3 ,7) == 1);
}

int main(int argc, char* argv[]){

  std::cout << "\n";

  std::cout << "Please enter two integers to find their gcd: \n";
  int a; 
  int b;
  std::cin >> a >> b;
  std::cout << "The gcd of " << a << " and " << b << " is " << gcd(a,b) << ".\n";
  std::cout << "\n";

  return Catch::Session().run(argc, argv);

}
