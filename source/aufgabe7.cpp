# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <iostream>
# include <vector>
# include "circle.hpp"

void print(const std::vector<Circle> &vec)
{
  for(const auto& i: vec){
    std::cout << i.radius_ << ' ';
    std::cout << std::endl;
  }
}

TEST_CASE("filter alle vielfachen von drei", "[erase]")
{
  std::vector<Circle> vCircles(10);
  for(auto& j: vCircles)
  {
    j = Circle{std::rand() % 50, Vec2{std::rand() % 50, std::rand()%50}};
  }

  std::cout<< "Alle Kreisradien: \n";
  print(vCircles);

  std::sort(vCircles.begin(), vCircles.end());
  std::cout<< "Und sortiert: \n";
  print(vCircles);

  REQUIRE(std::is_sorted(vCircles.begin(), vCircles.end()));
}


int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
