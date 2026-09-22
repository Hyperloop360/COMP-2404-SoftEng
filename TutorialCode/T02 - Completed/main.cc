#include <iostream>
using namespace std;
#include <string>

#include "Book.h"
#include "Library.h"

int  mainMenu();

int main()
{
  Library lib; // Declare in local scope

  string title, author;
  int    id, year;
  int    menuSelection;

  while (1) {
    menuSelection = mainMenu();

    if (menuSelection == 0) 
      break;
    else if (menuSelection == 1) {
      cout << "id:  ";
      cin  >> id;
      cout << "title:   ";
      cin.ignore();
      getline(cin, title);
      cout << "author: ";
      getline(cin, author);
      cout << "year:  ";
      cin  >> year;

      Book b(id, title, author, year);
      lib.addBook(b);
    }
  }
  lib.print();

  return 0;
}

int mainMenu()
{
  int numOptions = 1;
  int selection  = -1;

  cout << endl;
  cout << "(1) Add book" << endl;
  cout << "(0) Exit" << endl;

  while (selection < 0 || selection > numOptions) {
    cout << "Enter your selection: ";
    cin  >> selection;
  }

  return selection;
}

