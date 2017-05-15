# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <iostream>
# include <vector>

TEST_CASE("addiere v1 und v2 in v3", "[add]")
{
  std::vector <int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector <int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector <int> v3(9);

  std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int a, int b){return a + b;});

  std::copy(std::begin(v3), std::end(v3),
   std::ostream_iterator<int>(std::cout, "\n"));

  int x = 10;
  REQUIRE(std::all_of(v3.begin(), v3.end(), [x](int a){return a == x;}));
}


  int main(int argc, char* argv[]){

    return Catch::Session().run(argc, argv);
  }
