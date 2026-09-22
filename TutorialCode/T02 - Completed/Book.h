#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
  public:
    Book(int=0, string="Unknown", string="Unknown", int=0);
    int    getId();
    string getTitle();
    string getAuthor();
    int    getYear();
    void   set(int, string, string, int);
    void   print();

  private:
    int    id;
    string title;
    string author;
    int    year;
};

#endif

