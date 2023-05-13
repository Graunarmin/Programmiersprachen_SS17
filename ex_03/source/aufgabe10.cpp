# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include <iostream>
# include <vector>

bool is_even(int n)
{
  return (n % 2) == 0;
}

template <typename Container, typename P>
Container filter(Container const& v, P const& pred)
{
  Container result(v.size());
  auto it = std::copy_if(v.begin(), v.end(), result.begin(), pred);
  result.resize(std::distance(result.begin(), it));
  return result;
}

TEST_CASE("filter ungeraden raus", "[even]")
{

  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> allEven = filter(v, is_even);

REQUIRE(std::all_of(allEven.begin(), allEven.end(), is_even));
}


int main(int argc, char* argv[])
{

  return Catch::Session().run(argc, argv);
}
