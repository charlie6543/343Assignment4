// Display
// Contains: Methods to construct, delete, run, get the class name
// of, and print the results of an attempt to display the collection
// of books in a given Library.
// Purpose: Prints all information of all books in a given Library
// Assumptions: istream is correctly formatted
// Author: Charlie Li
// Use: Pass in the formatted istream after parsing the letter to
// call display and the library to print all books in the given
// library.
#include "command.h"

class Display : public Command{
public:
// ----------------------------------------------------------------
// no arg constructor
// Creates a Display object
// PRE: None
// POST: A Display object
Display();

// ----------------------------------------------------------------
// destructor
// Destroys all data of this Display object
// PRE: None
// POST: All data of this Display object destroyed
~Display();

// ----------------------------------------------------------------
// runCommand
// Displays all of the books in the given Library
// PRE: 1. The properly formatted istream set to a valid command
// 2. The Library including all data members
// POST: All books in the given Library printed by type
// alphabetically
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