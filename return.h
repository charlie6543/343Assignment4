// Return
// Contains a method to perform a 'return' with a Patron and a Book.
// A Book can be returned by a Patron if it has been checked out
// by that Patron before.
// Purpose: To update the Library, Patron, and Book accordingly 
// when someone wants to return a Book.
// Assumptions: Library's data has been set. The input file is
// properly formatted.
// Author: Charlie Li
// Called from the CommandFactory class after getting char 'R'. Will
// fully execute and update information to return the book. Returns
// false if the book could not be returned.
#include "command.h"

class Library;
class Patron;
class Product;

class Return : public Command{
private:
Patron* patron; // patron attempting to return product
Product* product; // product that is being returned

public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Return object
// PRE: None
// POST: All memory in this object deleted
Return();

// ----------------------------------------------------------------
// destructor
// Deletes all memory in this object
// PRE: None
// POST: All memory in this object deleted
~Return();

// ----------------------------------------------------------------
// runCommand
// Given the patron and book information, will return the book.
// This will also overwrite any previous information from previous
// return commands.
// PRE: 1. A properly formatted istream containing patron and book
// information.
// 2. The main Library containing all relevant patron and book
// information.
// POST: All information in the Library, Patron, and Book updated
// so the Book is returned.
bool runCommand(istream& command, Library& database);

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