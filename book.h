// Book
// Contains a destructor and a data member representing year of
// publication
// Purpose: To represent an abstract book for a library.
// Assumptions: None
// Author: Charlie Li
// Uses: To be a general object for more specific Books to
// inherit from.
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "product.h"

using namespace std;

class Book : public Product{
protected:
int year; // the book's year of publication

public:
// ----------------------------------------------------------------
// pure virtual destructor
// Deletes all data: to be overwritten by child classes
// PRE: None
// POST: Data of Book class deleted
~Book() = 0;
};
#endif