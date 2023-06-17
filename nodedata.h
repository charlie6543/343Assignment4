// NodeData
// Contains methods to destroy, set data, compare, print, and get
// class.
// Purpose: A pure virtual class for other classes to inherit from.
// Assumption: istream is properly formatted
// Author: Charlie Li
// Use: Inherit from NodeData to generalize into one singular
// variable type
#ifndef NODEDATA_H
#define NODEDATA_H
#include <iostream>
#include "consts.h"
using namespace std;

class NodeData{
public:
// ----------------------------------------------------------------
// destructor
// Deletes all memory in this object
// PRE: None
// POST: All memory in this object deleted
virtual ~NodeData() = 0;

// ----------------------------------------------------------------
// setData
// initializes the data members of this object
// PRE: An istream with the correct formatting (see below)
// FORMATTING: 
// POST: All relevant data members of this object set
virtual bool setData(istream& command) = 0;

// setComparison
// initializes a NodeData with an istream that only takes in data
// members necessary for comparison.
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
virtual bool setComparison(istream& command) = 0;

// virtual comparison operators

// ----------------------------------------------------------------
// operator<
// Compares this NodeData to another, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this NodeData is less than the other;
// false returned otherwise. -1 will be returned if the objects 
// compared are different classes.
virtual bool operator<(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// operator<=
// Compares this NodeData to another, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this NodeData is less than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
virtual bool operator<=(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// operator>
// Compares this NodeData to another, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this NodeData is greater than the other;
// false returned otherwise. -1 will be returned if the objects 
// compared are different classes.
virtual bool operator>(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// operator>=
// Compares this NodeData to another, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this NodeData is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
virtual bool operator>=(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// operator==
// Compares this NodeData to another, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this NodeData is equal to the other;
// false returned otherwise.
virtual bool operator==(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// operator!=
// Compares this NodeData to another, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this NodeData is equal to the other;
// true returned otherwise.
virtual bool operator!=(const NodeData& other) const = 0;

// ----------------------------------------------------------------
// getClass
// returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
virtual string getClass() const = 0;

// ----------------------------------------------------------------
// print
// Prints a formatted representation of the NodeData
// PRE: The data in NodeData must have been set with setData
// POST: A formatted representation of this NodeData printed
virtual void print() const = 0;

// ----------------------------------------------------------------
// display
// Displays all information in the NodeData
// PRE: The data in the NodeData must have been set with setData
// POST: All information in the NodeData displayed
virtual void display() const = 0;
};
#endif