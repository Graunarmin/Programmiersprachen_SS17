#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

bool is_not_divisible_by_3(unsigned int i)
{
  return (i % 3) != 0;
}

bool is_multiple_of_3(unsigned int i)
{
  return (i % 3) == 0;
}

void print(const std::vector<unsigned int> &vec)
{
  for(const auto& i: vec){
    std::cout << i << ' ';
    std::cout << std::endl;
  }
}

TEST_CASE("filter alle vielfachen von drei", "[erase]")
{

  std::vector<unsigned int> v(100);
  for(auto& j: v)
  {
    j = (unsigned int)std::rand() % 101;
  }
  std::cout<< "Alle Zahlen: \n";
  print(v);

  v.erase(std::remove_if(v.begin(), v.end(), is_not_divisible_by_3), v.end());
  std::cout<<"Hier nur die Vielfachen: \n";
  print(v);


  REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
