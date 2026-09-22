#include <iostream>
#include <iomanip>
using namespace std;

#include "Book.h"

Book::Book(int i, string t, string a, int y)
{
    id = i;
    title = t;
    author = a;
    year = y;
}

int Book::getId() {return id;}
string Book::getTitle() {return title;}
string Book::getAuthor() {return author;}
int Book::getYear() {return year;}

void Book::set(int i, string t, string a, int y){
    id = i;
    title = t; 
    author = a;
    year = y;
}

void Book::print()
{
    cout << "--Book Id: " << id << ", Title: " << title << ", Author: " << author << ", Year: " << year << endl; 
}
