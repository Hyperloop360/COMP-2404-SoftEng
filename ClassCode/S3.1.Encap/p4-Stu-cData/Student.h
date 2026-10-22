#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(string="000000000", string="Default name", string="Default major", float=0.0f);
    ~Student();
    void print() const;

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
