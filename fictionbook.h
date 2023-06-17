// FictionBook
// Contains methods and comparisons to be used by FictionBook
// book objects to set data, get checked out or returned, or
// printed.
// Purpose: A representation of a FictionBook book.
// Assumptions: istreams are formatted properly
// Author: Charlie Li
// Use: To be stored in a library and checked out/returned by
// patrons.
#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H
#include <iostream>
#include "book.h"

class FictionBook : public Book{
private:
string author; // author of the book
int copiesAvailable; //number of copies available for checkout
int checkedOutBy[5] = {-1}; // stores the id number of the patron
// that has copies of the book

public:
// ----------------------------------------------------------------
// no arg constructor
// Creates an empty FictionBook
// PRE: None
// POST: An empty FictionBook
FictionBook();

// ----------------------------------------------------------------
// destructor
// Destroys all data from this FictionBook
// PRE: None
// POST: All data from this FictionBook deleted
~FictionBook();

// ----------------------------------------------------------------
// setData
// initializes the data members of this object
// PRE: An istream with the correct formatting
// POST: All relevant data members of this object set
bool setData(istream& command);

// ----------------------------------------------------------------
// setComparison
// initializes a FictionBook with an istream that only takes in data
// members necessary for comparison.
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool setComparison(istream& command);

// comparison operators

// ----------------------------------------------------------------
// operator<
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is less than the other;
// false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool operator<(const NodeData& other) const;

// ----------------------------------------------------------------
// operator<=
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is less than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool operator<=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is greater than the other;
// false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool operator>(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>=
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool operator>=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator==
// Compares this FictionBook to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is equal to the other;
// false returned otherwise.
bool operator==(const NodeData& other) const;

// ----------------------------------------------------------------
// operator!=
// Compares this FictionBook to a NodeData, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this FictionBook is equal to the other;
// true returned otherwise.
bool operator!=(const NodeData& other) const;

// ----------------------------------------------------------------
// getClass
// returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
string getClass() const;

// ----------------------------------------------------------------
// checkout
// Decrements the number of copies available if possible and adds to
// the checkedOutBy array
// PRE: 1. The number of copies available is greater than 0.
// 2. A valid ID of a patron in the system.
// POST: The number of copies checked and decremented.
bool checkout(int ID);

// ----------------------------------------------------------------
// returnProduct
// Increments the number of copies available if possible and removes
// from the checkedOutBy array
// PRE: 1. The number of copies available is less than 1.
// 2. The valid ID of a patron that has checked out this product.
// POST: The number of copies checked and incremented.
bool returnProduct(int ID);

// ----------------------------------------------------------------
// print
// Prints most data of this FictionBook in a format
// PRE: Data of this FictionBook set with setData
// POST: The data of this FictionBook printed in a format
void print() const;

// ----------------------------------------------------------------
// displayBook
// Prints all data of this FictionBook in a format
// PRE: Data of this FictionBook set with setData
// POST: The data of this FictionBook printed in a format
void display() const;
};
#endif