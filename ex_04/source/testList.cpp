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
  auto l = list.last();
  auto e = list.end();
  REQUIRE(*b == 42);
  REQUIRE(*l == 12);
  REQUIRE(e != l);
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
  auto l = list.last();
  REQUIRE(*b == 42);
  REQUIRE(*(++b) == 3);
  REQUIRE(*(b++) == 3); //b auf 12, aber gibt alten Werts
  REQUIRE(*(b++) == 12);
  REQUIRE(b == nullptr);
  REQUIRE(b == list.end());
}

TEST_CASE("compare_operator", "[4.6 iterators]")
{
  List <int> list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto p = list.begin();
  auto z = p;

  auto b = list.last();

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
  auto p = list.last();
  REQUIRE(p.next() == nullptr);
  REQUIRE(p.next() == list.end());
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

TEST_CASE("provide acces to the last element with last", "[4.6 iterators]")
{
  List<int> list;
  list.push_front(42);
  list.push_front(8);
  REQUIRE(42 == *list.last());
  REQUIRE(list.end() == nullptr);
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

TEST_CASE("insert at position", "[4.9 insert]")
{
  List <int> list;
  list.insert(list.begin(),4);
  REQUIRE(list.size() == 1);
  REQUIRE(list.front() == 4);

  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  auto p = list.begin();
  list.insert(p, 13);
  REQUIRE(list.front() == 13);

  list.insert(list.end(), 68);
  REQUIRE(list.back() == 68);
  REQUIRE(*list.last() == 68);
  REQUIRE(list.end() == nullptr);
  ++p;
  ++p;
  list.insert(p, 2);
  REQUIRE(list.valueAt(p) == 3);
  //2 wird vor 3 einsortiert, aber 3 bleibt ja an pos p
  //Liste: 13, 42, 4,(2,) 3, 12, 68
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

TEST_CASE("copy list into vector","[4.11 copy]")
{
  List<int>list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);

  std::vector<int> vector(list.size());
  std::copy(list.begin(), list.end(), std::begin(vector));

  REQUIRE(vector[0] == 42);
  REQUIRE(vector[1] == 3);
  REQUIRE(vector[2] == 12);
}

TEST_CASE("Zuweisungsoperator und Swap", "[4.12 zuweisung]")
{
  //swap
  List<int>list;
  list.push_front(42);
  list.push_back(3);
  list.push_back(12);
  REQUIRE(list.front() == 42);

  List<int>list2;
  list2.push_back(1);
  list2.push_back(2);
  list2.push_back(3);
  REQUIRE(list2.front() == 1);

  list.swap(list2);
  REQUIRE(list.front() == 1);
  REQUIRE(list2.front() == 42);

  //free swap
  swap(list, list2);
  REQUIRE(list.front() == 42);
  REQUIRE(list2.back() == 3);

  //Zuweisung
  List<int>list3;
  REQUIRE(list3.begin() == nullptr);

  list3 = list;
  REQUIRE(list3.front() == 42);
  REQUIRE(list.front() == 42);
  REQUIRE(list.size() == list3.size());

  List<int>list4;
  list3 = list4;
  REQUIRE(list3.size() == 0);
  REQUIRE(list3.size() == list4.size());
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

int main(int argc, char* argv[]){

  return Catch::Session().run(argc, argv);
}
