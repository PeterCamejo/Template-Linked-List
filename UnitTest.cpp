#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "TemplateList.cpp"

  

TEST_CASE("Prepend is tested" , "[prepend(T value)]"){
  TLinkedList<int> ll;
  ll.prepend(3);
  REQUIRE(ll.toString() == "3");
  ll.prepend(2);
  ll.prepend(1);
  REQUIRE(ll.toString() == "1 : 2 : 3");
  
}

TEST_CASE("Append is tested" , "[append(T value)]"){
  TLinkedList<char> ll;
  ll.append('a');
  REQUIRE(ll.toString() == "a");
  ll.append('b');
  ll.append('c');
  REQUIRE(ll.toString() == "a : b : c");
}

TEST_CASE("Size is tested" , "[size()]"){
  TLinkedList<int> ll;
  ll.prepend(2);
  ll.prepend(3);
  ll.prepend(4);
  REQUIRE(ll.size() == 3);
}
TEST_CASE("Remove is tested" , "[remove(T value)]"){
  TLinkedList<int> ll;
  ll.prepend(5);
  ll.prepend(6);
  ll.prepend(7);
  REQUIRE(ll.toString() == "7 : 6 : 5");
  ll.remove(6);
  REQUIRE(ll.toString() == "7 : 5");
  ll.remove(5);
  REQUIRE(ll.toString() == "7");
}

TEST_CASE("Search is tested" , "[search(T value)]"){
  TLinkedList<int> ll ;
  TLinkedList<int> :: node * n = new TLinkedList<int>::node(4);
  ll.prepend(4);
  ll.prepend(5);
  ll.prepend(6);
  TLinkedList<int>::node * test = ll.search(4);
  REQUIRE(test->data == 4);
  REQUIRE(ll.toString() == "6 : 5 : 4");
}

TEST_CASE("Pop is tested" , "[pop(T value)]"){
  TLinkedList<int> ll;
  ll.prepend(5);
  ll.prepend(6);
  ll.prepend(7);
  REQUIRE(ll.size() == 3);
  TLinkedList<int> :: node * test = ll.pop(6);
  REQUIRE(ll.size() == 2);
  REQUIRE(ll.toString() == "7 : 5");
  REQUIRE(test->data == 6);
}

TEST_CASE("Empty list remove attempt tested" , "[none]"){
  TLinkedList<int> ll;  // empty list
  std::cout << "TESTING EXCEPTIONS:" << std::endl;
  std::cout << "__________________________________" << std::endl;
  std::cout << "Output from remove() on empty list: ";
  ll.remove(3);
  REQUIRE(2  == 2);
}

TEST_CASE("Empty list search attempt tested" , "[search(T value)]"){
  TLinkedList<int> ll ;
  std::cout << "Output from search() on empty list: ";
  TLinkedList<int> :: node * t = ll.search(3);
  REQUIRE(2 == 2);
}

TEST_CASE("Empty list pop() attempt tested" , "[pop(T value)]"){
  TLinkedList<int>ll;
  std::cout << "Output from pop() on empty list: ";
  TLinkedList<int> :: node * test = ll.pop(3);
  REQUIRE(2==2);
}

TEST_CASE("Remove called on value not in list tested" , "[remove(T value)]" ){
  TLinkedList<int> ll;
  ll.prepend(3); // 3 prepended : List not longer empty
  std::cout << "Output from remove() on value not in list: ";
  ll.remove(2);
  REQUIRE(2==2);
}
TEST_CASE("Search called on value not in list tested" , "[search(T value)]"){
  TLinkedList<int> ll;
  ll.prepend(4);
  std::cout << "Output from search() on value not in list: ";
  TLinkedList<int>::node * test = ll.search(2);
  REQUIRE(2==2);
}

TEST_CASE("Pop called on value not in list tested" , "[pop(T value)]"){
  TLinkedList<int> ll;
  ll.prepend(4);
  ll.prepend(5);
  ll.prepend(6);
  std::cout << "Output from pop() on value not in list: ";
  TLinkedList<int> :: node * test = ll.pop(2);
  REQUIRE(ll.toString() == "6 : 5 : 4");
}
