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

TEST_CASE("bestimmte Kreise entfernen", "[delete]")
{
  std::vector<Circle> vCircles(5);

  int r{1};
  for(auto& i: vCircles)
  {
    i = Circle(r, Vec2{4,6});
    r += 3;
  }
  print(vCircles);

  std::vector<Circle> vCircles2(3);
  std::copy_if(vCircles.begin(), vCircles.end(), vCircles2.begin(), [](Circle c1){return c1.radius_ > 4;});
  print(vCircles2);

  REQUIRE(std::all_of(vCircles2.begin(), vCircles2.end(), [](Circle c){return c.radius_ > 4;}));
}

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
