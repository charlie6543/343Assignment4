// Patron
// Contains methods to set data, compare, get, and display the 
// information of a Patron
// Purpose: To be used in the Library class to represent a
// Patron of the library.
// Assumptions: istream is properly formatted
// Author: Charlie Li
// Use: Insert into Library class and call add or remove in order
// to complete a return or checkout.
#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include "nodedata.h"
#include <vector>
using namespace std;

class Product;

class Patron : public NodeData{
private:
string firstName; // first name of the patron
string lastName; // last name of the patron
int id; // unique identifier for the patron
vector<Product*> checkedOut; // all books the patron has checked out
vector<pair<string, Product*>> checkoutHistory;
// the complete checkout history of the patron

public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Patron
// PRE: None
// POST: An empty Patron created
Patron();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Patron
// PRE: None
// POST: All data in this Patron deleted
~Patron();

// ----------------------------------------------------------------
// setData
// Sets data members of this Patron given a properly formatted
// istream
// PRE: A properly formatted istream
// POST: All data members of this Patron set
bool setData(istream& command);

// setComparison
// initializes a Patron with an istream that only takes in data
// members necessary for comparison.
// Note: Not used for Patron class: only calls setData
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool setComparison(istream& command);

// ----------------------------------------------------------------
// operator<
// Compares this Patron to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is less than the other;
// false returned otherwise. -1 will be returned if the objects
// compared are different classes.
bool operator<(const NodeData& other) const;

// ----------------------------------------------------------------
// operator<=
// Compares this Patron to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is less than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool operator<=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>
// Compares this Patron to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is greater than the other;
// false returned otherwise. -1 will be returned if the objects 
// compared are different classes.
bool operator>(const NodeData& other) const;

// ----------------------------------------------------------------
// operator>=
// Compares this Patron to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool operator>=(const NodeData& other) const;

// ----------------------------------------------------------------
// operator==
// Compares this Patron to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is equal to the other;
// false returned otherwise
bool operator==(const NodeData& other) const;

// ----------------------------------------------------------------
// operator!=
// Compares this NodeData to another, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this Patron is equal to the other;
// true returned otherwise
bool operator!=(const NodeData& other) const;

// ----------------------------------------------------------------
// getClass
// returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
string getClass() const;

// ----------------------------------------------------------------
// getID
// Returns the ID of this Patron
// PRE: Data set by setData
// POST: The ID of this Patron returned
int getID() const;

// ----------------------------------------------------------------
// print
// Prints the name and id of this patron.
// PRE: Data set by setData
// POST: The name and id of this patron printed
void print() const;

// ----------------------------------------------------------------
// display
// Prints the name, id, and checkout history of this patron
// PRE: Data set by setData
// POST: The name, id, and checkout history of this patron printed
void display() const;

// ----------------------------------------------------------------
// printHistory
// Prints the checkout history of this patron
// PRE: None
// POST: The checkout history of this patron printed
void printHistory() const;

// ----------------------------------------------------------------
// checkout
// adds a Product to the checked out array
// PRE: 1. A Product reference to add to the checked out array
// 2. The class name of the command running this function.
// POST: 1. The Product reference added to the checked out array
// 2. The checkout history will also be changed to add the
// Product and command information.
// 3. False will be returned if the Product could not be added.
bool checkout(Product* toAdd, string command);

// ----------------------------------------------------------------
// returnProduct
// removes a Product from the checked out array
// PRE: 1. A Product reference to remove from the checked out array.
// it must already be a part of the array.
// 2. The class name of the command running this function.
// POST: 1. The Product removed from the checked out array
// 1. The checkout history will also be changed to add the
// Product and command information.
// 2. False will be returned if the Product could not be returned
bool returnProduct(Product* toRemove, string command);
};
#endif