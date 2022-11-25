#include <iostream>

struct Person {
  Person() { std::cout << "Person::ctor" << std::endl; }
  ~Person() { std::cout << "Person::dtor" << std::endl; }
  std::string name{};
};

struct Student : Person {
  Student() { std::cout << "Student::ctor" << std::endl; }
  ~Student() { std::cout << "Student::dtor" << std::endl; }
  int score{};
};

struct Teacher : Person {
  Teacher() { std::cout << "Teacher::ctor" << std::endl; }
  ~Teacher() { std::cout << "Teacher::dtor" << std::endl; }
};

struct TA : Teacher, Student {};

int main() {
  TA ta;
  ta.score = 5.0;

  return 0;
}