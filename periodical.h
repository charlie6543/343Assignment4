// Periodical
// Contains methods and comparisons to be used by Periodical
// book objects to set data, get checked out or returned, or
// printed.
// Purpose: A representation of a Periodical book.
// Assumptions: istreams are formatted properly
// Author: Charlie Li
// Use: To be stored in a library and checked out/returned by
// patrons.
#ifndef PERIODICAL_H
#define PERIODICAL_H
#include <iostream>
#include "book.h"

class Patron;

class Periodical : public Book{
private:
int month; // month of publication
int copiesAvailable; // number of copies available for checkout
int checkedOutBy[1] = {-1}; // stores the id number of the patron
// that has copies of the book

public:
// ----------------------------------------------------------------
// no arg constructor
// Creates an empty Periodical
// PRE: None
// POST: An empty Periodical
Periodical();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Periodical
// PRE: None
// POST: All data in this Periodical deleted
~Periodical();

// ----------------------------------------------------------------
// setData
// initializes the data members of this object
// PRE: An istream with the correct formatting
// POST: All relevant data members of this object set
bool setData(istream& command);

// ----------------------------------------------------------------
// setComparison
// initializes a Periodical with an istream that only takes in data
// members necessary for comparison.
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool setComparison(istream& command);

// comparison operators

// ----------------------------------------------------------------
// operator<
// Compares this Periodical to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is less than the other;
// false returned otherwise. -1 will be returned if the objects
// compared are different classes.
bool operator<(const NodeData& other) const;

// ----------------------------------------------------------------
// operator<=
// Compares this Periodical to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is less than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool operator<=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>
// Compares this Periodical to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is greater than the other;
// false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool operator>(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>=
// Compares this Periodical to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool operator>=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator==
// Compares this Periodical to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is equal to the other;
// false returned otherwise.
bool operator==(const NodeData& other) const;

// ----------------------------------------------------------------
// operator!=
// Compares this Periodical to a NodeData, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this Periodical is equal to the other;
// true returned otherwise
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
// Prints a formatted representation of this Periodical
// PRE: Data members already set with setData
// POST: A formatted representation of this Periodical printed
void print() const;

// ----------------------------------------------------------------
// display
// Displays all information in the Periodical
// PRE: The data in the Periodical must have been set with setData
// POST: All information in the Periodical displayed
void display() const;
};
#endif