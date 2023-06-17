// Checkout
// Contains: Methods to construct, delete, run, get the class name
// of, and print the results of an attempt to checkout a book to a
// patron.
// Purpose: Checks out a book to a patron.
// Assumptions: istream is correctly formatted. Book and patron
// information is already initialized.
// Author: Charlie Li
// Use: Pass in the formatted istream after parsing the letter to
// call display along with the library to initiate a checkout
// attempt between the patron and book given in the istream.
#include "command.h"
#include <iostream>

class Library;
class Product;
class Patron;

class Checkout : public Command{
private:
Product* product;
Patron* patron;

public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Checkout object
// PRE: None
// POST: An empty Checkout object created
Checkout();

// ----------------------------------------------------------------
// destructor
// Deletes all information in this Checkout
// PRE: None
// POST: All information in this Checkout deleted
~Checkout();

// ----------------------------------------------------------------
// runCommand
// Runs the checkout of one book to one patron,
// editing the necessary data in both classes
// PRE: 1. The istream file with the properly formatted data for the
// command
// 2. The Library containing all books and patrons
// POST: If valid, the given book will have its number of available 
// copies decremented
// And the given book will be added to the patron's
// checkout history and checked out books
bool runCommand(istream& command, Library& data);

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The name of the class returned.
string getClass();

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
void print();
};