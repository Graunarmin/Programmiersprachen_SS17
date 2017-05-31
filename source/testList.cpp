#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "list.hpp"

TEST_CASE("Default Constructor Liste", "[4.2 constructor]")
{
  List <int> list{};

  REQUIRE(list.empty() == true);
  REQUIRE(list.size() == 0);
}

TEST_CASE("Copy Constructor Liste", "[4.8 constructor]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(9);

  List<int> copiedList{list};
  REQUIRE(copiedList.front() == 42);

  List<int> list2;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list3{list2};
  REQUIRE(list2 == list3);
  REQUIRE(list2 != list);
}

TEST_CASE ("move constructor", "[4.13 constructor]")
{
List<int> list ;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
List<int> list2(std::move(list));
REQUIRE(0 == list.size());
REQUIRE(list.empty());
REQUIRE(4 == list2.size());
}

TEST_CASE ("add with push_front, delete with pop_front ", "[4.3 modifiers]")
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

TEST_CASE ("add with push_back, delete with pop_back ", "[4.3 modifiers]")
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

TEST_CASE ("should be empty after clearing", "[4.4 modifiers]")
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

TEST_CASE("Iterator_Constructor", "[4.6 iterators]")
{
  ListIterator<int> iterator{};
  REQUIRE(iterator.next() == nullptr);

  ListNode<int> n{};
  ListIterator<int> otherIt{&n};
  REQUIRE(otherIt.next() == nullptr);
}

TEST_CASE ("Dereferenzierung", "[4.6 iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto b = list.begin();
  auto e = list.end();
  REQUIRE(*b == 42);
  REQUIRE(*e == 12);
  // ListIterator<int> it{b};
  // auto p = it -> m_next;
  // REQUIRE(*p == 12);
}

TEST_CASE("Increment_Operators", "[4.6 iterators]")
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
  REQUIRE(*(b++) == 12);
  REQUIRE(b == nullptr);
}

TEST_CASE("compare_operator", "[4.6 iterators]")
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

TEST_CASE("next", "[4.6 iterators]")
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
"[4.6 iterators]")
{
  List <int> list;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE(b == e);
}

TEST_CASE ("provide acces to the first element with begin", "[4.6 iterators]")
{
  List <int> list;
  REQUIRE(list.begin() == nullptr);
  list.push_front(42);
  REQUIRE (42 == *list.begin());
}

TEST_CASE("provide acces to the last element with end", "[4.6 iterators]")
{
  List<int> list;
  list.push_front(42);
  list.push_front(8);
  REQUIRE (42 == *list.end());
}

TEST_CASE("compare lists", "[4.7]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  List<int> list2;
  list2.push_front(42);
  list2.push_back(3);
  list2.push_back(12);
  REQUIRE(list == list2);

  list2.push_back(7);
  REQUIRE(list != list2);
}

TEST_CASE("reverse", "[4.10 reverse]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);
  list.reverse();
  REQUIRE(list.front() == 12);
  REQUIRE(list.size() == 3);

  List<int> list2;
  list2.reverse();
  REQUIRE(list2.begin() == nullptr);

  List<int> list3;
  list3.push_front(1);
  list3.reverse();
  REQUIRE(list3.front() == 1);

}

TEST_CASE("free reverse", "[4.10 reverse]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);
  REQUIRE(reverse(list).front() == 12);

  List<int> list2;
  reverse(list2);
  REQUIRE(list2.begin() == nullptr);

  List<int> list3;
  list3.push_front(1);
  REQUIRE(reverse(list3).front() == 1);
}




int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
