#ifndef ADDRESS_H
#define ADDRESS_H

class Address {
public:
  Address(int = 0, string = "Default street", string = "Default city",
          string = "Default provice");
  ~Address();
  void print();

private:
  int number;
  string street;
  string city;
  string province;
};

#endif
