#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <iostream>

int by_twenty(){
	int z = 20;
	int i = 1;
	while (i <= 20){
		if (z % i != 0){
			z += 20;
			i = 1;
		}
		i++;
	}
	return z;
}

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

int checksum(int q){
	int qsum = 0;
	while(q > 0){
		qsum += q % 10;
		q /= 10;
	}
	return qsum;
}

TEST_CASE (" describe_checksum ", "[checksum]")
{
REQUIRE (checksum (56) == 11);
REQUIRE (checksum (121) == 4);
REQUIRE (checksum (117353) == 20);
}

int sumMultiples(){
	int sum = 0;
	for (int i = 1; i <= 1000; i++){
		if (i % 3 == 0 || i % 5 == 0){
			sum += i;
		}
	}
	return sum;
}

double fract(double g){
	int f = g;
	return g - f;
}

TEST_CASE (" describe_fract ", "[fract]"){
REQUIRE (fract (12.67) == Approx(0.67));
REQUIRE (fract (20.896) == Approx(0.896));
REQUIRE (fract (0.756) == Approx(0.756));
}


double cylinder_volume(double r, double h){
	return (h * M_PI * pow(r, 2));
}

TEST_CASE (" describe_cylinder_volume ", "[cylinder_volume]")
{
REQUIRE (cylinder_volume (3, 4) == Approx(113.097));
REQUIRE (cylinder_volume (2, 5) == Approx(62.832));
REQUIRE (cylinder_volume (10, 9) == Approx(2827.433));
}

double cylinder_surface(double r, double h){
	return (2 * M_PI * r * (r + h));
}

TEST_CASE (" describe_cylinder_surface ", "[cylinder_surface]")
{
REQUIRE (cylinder_surface (3, 4) == Approx(131.947));
REQUIRE (cylinder_surface (2, 5) == Approx(87.965));
REQUIRE (cylinder_surface (10, 9) == Approx(1193.805));
}

long int factorial(int n){
	if(n <= 1){
		return 1;
	}
	else{
		return (factorial(n-1) * n);
	}
}

TEST_CASE (" describe_factorial ", "[factorial]")
{
REQUIRE (factorial (2) == 2);
REQUIRE (factorial (3) == 6);
REQUIRE (factorial (5) == 120);
}

double binomial(int m, int k){
	if (k == 0 || m == k){
		return -1;
	}
	else{
		return (factorial(m) / (factorial(k)* factorial(m-k)));
	}
}

TEST_CASE (" describe_binomial ", "[binomial]")
{
REQUIRE (binomial (4, 2) == 6);
REQUIRE (binomial (5, 3) == 10);
REQUIRE (binomial (3, 2) == 3);
}

bool brutal_prime_check(int p){
	int a = 2;
	while (a <= p-1){
		if(p % a == 0){
			return false;
		}
		a++;
	}
	return true;
}

TEST_CASE (" describe_brutal_prime_check ", "[brutal_prime_check]")
{
REQUIRE (brutal_prime_check (2) == true);
REQUIRE (brutal_prime_check (9) == false);
REQUIRE (brutal_prime_check (13) == true);
}

double mileToKilometer(double o){
	return (o * 1.609);
}

TEST_CASE (" describe_mileToKilometer ", "[mileToKilometer]")
{
REQUIRE (mileToKilometer (1.00) == 1.609);
REQUIRE (mileToKilometer (1.7) == 2.7353);
REQUIRE (mileToKilometer (5.8) == 9.3322);
}


int main(int argc, char* argv[]){

  std::cout << "\n";
  std::cout << "Hello, World!\n";
  std::cout << "\n";

  std::cout << "The smallest number divisibel by 20 is " << by_twenty() << ".\n";
  std::cout << "\n";

  std::cout << "Please enter two integers to find their gcd: \n";
  int a; 
  int b;
  std::cin >> a >> b;
  std::cout << "The gcd of " << a << " and " << b << " is " << gcd(a,b) << ".\n";
  std::cout << "\n";

  std::cout << "Please enter an integer to find its checksum: \n";
  int q;
  std::cin >> q;
  std::cout << "The checksum of " << q << " is "<< checksum(q) << ".\n";
  std::cout << "\n";

  std::cout << "The sum of all numbers up until 1000 divisibel by 3 or 5 is " << sumMultiples() << ".\n";
  std::cout << "\n";

  std::cout << "Please enter a floating point number to compute its decimals: \n";
  double g;
  std::cin >> g;
  std::cout << "The decimals of " << g << " are: " << fract(g) << ".\n";
  std::cout << "\n"; 

  std::cout << "Please enter first radius then height of the cylinder: \n";
  double r;
  double h;
  std::cin >> r >> h;
  std::cout << "The cyliner volume is " << cylinder_volume(r,h) << " and the surface is " << cylinder_surface(r,h) <<".\n";
  std::cout << "\n";

  int x = 0;
  while (x == 0){
  	std::cout << "Please enter an integer to find its factorial: \n";
 	int n;
 	std::cin >> n;
 	if (n >= 1){
  		std::cout << "The factorial of " << n << " is " << factorial(n) << ".\n";
  		x = 1;
  	}
  	else if (n == 0){
  		std::cout << "The factorial of 0 is 1.\n";
  		x = 1;
  	}
  	else{
  		std::cout << "ERROR: Please enter a number greater than 0.\n";
  		x = 0;
   	}
  }
  std::cout << "\n";

  int z = 0;
  while (z == 0){
  	std::cout << "Please enter two intergers to find their binomial coefficient: \n";
  	int m;
  	int k;
  	std::cin >> m >> k;
  	if (m > k){
  		std::cout << "The binomial coefficient of "<< m << " and " << k << " is "<< binomial(m,k) << ".\n";
  		z = 1;
  	}
  	else if (m == k){
  		std::cout << "The binomial coefficient of "<< m << " and " << k << " is "<< "1.\n";
  		z = 1;
  	}
  	else{
  		std::cout << "ERROR: The first number has to be greater than the second one.\n";
  		z = 0;
  	}
  }
  std::cout << "\n";

  std::cout << "Please enter an interger to test if it is prime: \n";
  int p;
  std::cin >> p;
  if (brutal_prime_check(p) == true){
  	std::cout << p << " is prime. \n";
  }
  else{
  	std::cout << p << " is not prime. \n";
  }
  std::cout << "\n";

  std::cout << "Please enter the distance in miles: \n";
  double o;
  std::cin >> o;
  std::cout << o << " miles are " << mileToKilometer(o) << " kilometers. \n";
  std::cout << "\n";

  return Catch::Session().run(argc, argv);

}