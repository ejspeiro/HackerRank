// Code style adapted to fit HackerRank's preexisting code in this exercise.

#include <iostream>

using namespace std;

class Person{
 public:
  int age;
  Person(int initialAge);
  void amIOld();
  void yearPasses();
};

Person::Person(int initialAge){
  if (initialAge < 0) {
    age = 0;
    std::cout << "Age is not valid, setting age to 0." << std::endl;
  }
  age = initialAge;
}

void Person::amIOld(){
  if (age < 13) {
    std::cout << "You are young." << std::endl;
  } else if (age >= 13 && age < 18) {
    std::cout << "You are a teenager." << std::endl;
  } else {
    std::cout << "You are old." << std::endl;
  }
}

void Person::yearPasses(){
  age++;
}

int main(){

  int t;    // Read number of test cases.
  int age;  // Read age of a person per test case.
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> age;
    Person p(age);
    p.amIOld();
    for(int j = 0; j < 3; j++) {
      p.yearPasses();
    }
    p.amIOld();
    cout << '\n';
  }
}
