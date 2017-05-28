#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "list.hpp"

TEST_CASE("Default Constructor Liste", "[constructor]")
{
  List <int> list{};

  REQUIRE(list.empty() == true);
  REQUIRE(list.size() == 0);
}

TEST_CASE ("add with push_front, delete with pop_front ", "[modifiers]")
{
  List <int> list;
  list.push_front(42);
  list.push_front(9);

  REQUIRE(list.front() == 9);

  list.pop_front();
  REQUIRE(list.front() == 42);
  REQUIRE(list.size() == 1);
  REQUIRE(list.front() == list.back());

}

TEST_CASE ("add with push_back, delete with pop_back ", "[modifiers]")
{
  List <int> list;
  list.push_back(42);
  list.push_back(9);

  REQUIRE(list.back() == 9);

  list.pop_back();
  REQUIRE(list.back() == 42);
  REQUIRE(list.size() == 1);
  REQUIRE(list.front() == list.back());

}

TEST_CASE ("should be empty after clearing", "[modifiers]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.clear();

REQUIRE(list.empty());

List<int> list1;
list.push_front(3);
list.push_back(8);
list.push_front(-4);
list.push_back(0);
list.~List();

REQUIRE(list.empty());
}

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
