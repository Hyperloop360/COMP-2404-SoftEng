#ifndef ADDRESS_H
#define ADDRESS_H

class Student;

class Address
{
  friend class Student;
  friend void where(Student&);

  public:
    Address(int=0, string="Default street", string="Default city", string="Default province");
    ~Address();
    void print() const;

  private:
    int    number;
    string street;
    string city;
    string province;
};

#endif
