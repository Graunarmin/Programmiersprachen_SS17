# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include "aufgabe13.hpp"

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
for(auto& i: vCircles)
{
  i = Circle{std::rand() % 50, Vec2{std::rand() % 50, std::rand()%50}};
}

std::cout<< "Kreisradien: \n";
print(vCircles);

std::sort(vCircles.begin(), vCircles.end(), compare());
std::cout<< "Und sortiert mit functor: \n";
print(vCircles);

REQUIRE(std::is_sorted(vCircles.begin(), vCircles.end()));
}

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
