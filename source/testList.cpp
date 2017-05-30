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

  list.pop_front();
  REQUIRE(list.size() == 0);
  REQUIRE(list.empty() == true);
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

  list.pop_back();
  REQUIRE(list.size() == 0);
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

TEST_CASE("Iterator_Constructor", "[iterators]")
{
  ListIterator<int> iterator{};
  REQUIRE(iterator.next() == nullptr);

  ListNode<int> n{};
  ListIterator<int> otherIt{&n};
  REQUIRE(otherIt.next() == nullptr);
}

TEST_CASE ("Dereferenzierung", "[iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto b = list.begin();
  auto e = list.end();
  REQUIRE(*b == 42);
  REQUIRE(*e == 12);
  //Pfeiloperator??
}

TEST_CASE("Increment_Operators", "[iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto b = list.begin();
  auto e = list.end();
  REQUIRE(*b == 42);
  REQUIRE(*(++b) == 3);
  REQUIRE(*(b++) == 3); //b auf 12, aber gibt alten Werts
  b++;
}

TEST_CASE("compare_operator", "[iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto p = list.begin();
  auto z = p;

  auto b = list.end();

  REQUIRE(p == z);
  REQUIRE(p != b);
}

TEST_CASE("next", "[iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto b = list.begin();
  REQUIRE(*(b.next()) == 3);
  auto p = list.end();
  REQUIRE(p.next() == nullptr);

}

TEST_CASE ("should be an empty range after default construction",
"[iterators]")
{
  List <int> list;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE(b == e);
}

TEST_CASE ("provide acces to the first element with begin", "[iterators]")
{
  List <int> list;
  REQUIRE(list.begin() == nullptr);
  list.push_front(42);
  REQUIRE (42 == *list.begin());
}

TEST_CASE("provide acces to the last element with end", "[iterators]")
{
  List<int> list;
  list.push_front(42);
  list.push_front(8);
  REQUIRE (42 == *list.end());
}



int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
