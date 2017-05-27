#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "list.hpp"

TEST_CASE("Default Constructor Liste", "[4.2]"){
  List <int> list{};

  REQUIRE(list.empty() == true);
  REQUIRE(list.size() == 0);
}

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
