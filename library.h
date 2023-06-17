// Library
// Contains methods to intialize books and products, run commands,
// and give external methods access to data.
// Purpose: Stores books and patrons for a library and runs commands
// for interactions between books and patrons.
// Assumptions: istreams are all formatted correctly.
// Author: Charlie Li
// Use: Call initialize or runCommands method to fill the library
// and run commands. If access is needed (by command classes),
// use getter methods.
#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>

class BinTree;
class Patron;
class NodeData;

using namespace std;

class Library{
private:
BinTree* products[26] = {nullptr}; // all books in library system
Patron* patrons[10000] = {nullptr}; // all patrons in library system

public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates a Library
// PRE: None
// POST: A Library
Library();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Library
// PRE: None
// POST: All data in this Library deleted
~Library();

// ----------------------------------------------------------------
// initializePatrons
// Initializes all patrons from a formatted file of all patrons to 
// be entered
// PRE: a string of a valid file name containing properly formatted 
// lines of all patrons
// POST: All patrons from the file initialized into the Library
void initializePatrons(istream& patronFile);

// ----------------------------------------------------------------
// initializeProducts
// Initializes all products from a formatted file of all products to 
// be entered
// PRE: a string of a valid file name containing properly formatted 
// lines of all products
// POST: All products from the file initialized into the Library
void initializeProducts(istream& productFile);

// ----------------------------------------------------------------
// runCommands
// Runs all commands from a formatted file of all commands to be run
// PRE: A string of a valid file name containing properly formatted 
// lines of all products
// POST: All commands from the file run
void runCommands(istream& commandFile);

// ----------------------------------------------------------------
// getPatron
// Gets a Patron given their ID
// PRE: An int of a valid Patron ID
// POST: A pointer to the given Patron
Patron* getPatron(int id);

// ----------------------------------------------------------------
// getProducts
// Gets a BinTree of Products given a char representing a Product
// PRE: A char representing a Product type
// POST: A pointer to a BinTree returned 
const BinTree* getProducts(char type) const;

// ----------------------------------------------------------------
// getProduct
// Gets a NodeData given a char representing their type and a 
// NodeData with all data fields necessary for comparison
// PRE: 1. A char representing the Product type
// 2. A NodeData of the same type, with all data fields necessary 
// for comparison. The target NodeData must be in the Library
// POST: The target NodeData returned
NodeData* getProduct(char type, NodeData* comparison);
};
#endif