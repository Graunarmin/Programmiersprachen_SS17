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

TEST_CASE("Kreise sortieren", "[sort]")
{
  std::vector<Circle> vCircles(10);
  for(auto& j: vCircles)
  {
    j = Circle{std::rand() % 50, Vec2{std::rand() % 50, std::rand()%50}};
  }

  std::cout<< "Alle Kreisradien: \n";
  print(vCircles);

  std::sort(vCircles.begin(), vCircles.end());
  std::cout<< "Sortiert: \n";
  print(vCircles);


  //Aufgabe 8
  std::vector<Circle> vCircles2(10);
  for(auto& i: vCircles2)
  {
    i = Circle{std::rand() % 50, Vec2{std::rand() % 50, std::rand()%50}};
  }

  std::cout<< "Neue Kreisradien: \n";
  print(vCircles2);

  std::sort(vCircles2.begin(), vCircles2.end(), [](Circle c1, Circle c2) {return c1 < c2;});
  std::cout<< "Und sortiert: \n";
  print(vCircles2);

  REQUIRE(std::is_sorted(vCircles.begin(), vCircles.end()));
  REQUIRE(std::is_sorted(vCircles2.begin(), vCircles2.end()));
}


int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
