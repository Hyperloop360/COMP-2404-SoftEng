#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
  public:
    Book(int=0, string="Unknown", string="Unknown");
    Book(const Book&);
    ~Book();
    string getAuthor();
    string getTitle();
    void print();

  private:
    int id;
    string title;
    string author;
};

#endif
