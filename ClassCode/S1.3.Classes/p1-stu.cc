#include <iostream>
using namespace std;
#include <string>

class Student {
public:
  Student() {
    number = "000000000";
    name = "Default name";
  }

  Student(string s1, string s2) {
    number = s1;
    name = s2;
  }

  string getName() { return name; }

  void setName(string n) { name = n; }

  string setNumber() { return number; }

  void setNumber(string n) { number = n; }

  void print() { cout << "Student: " << number << " " << name << endl; }

private:
  string number;
  string name;
};

int main() {
  Student matilda("100567888", "Matilda");
  Student joe;

  matilda.print();
  joe.print();

  joe.setName("Joe");
  cout << endl;

  matilda.print();
  joe.print();

  joe.setNumber("10928394");
  cout << endl;

  matilda.print();
  joe.print();

  return 0;
}
