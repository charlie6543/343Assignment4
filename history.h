// History
// Contains methods to construct, destroy, run, get class name of,
// and print the results of an attempt to get the history of a
// patron.
// Purpose: Prints the full checkout history of a patron.
// Assumption: istream is correctly formatted
// Author: Charlie Li
// Use: Pass in the formatted istream after parsing the char to
// call history along with the library. The patron ID will be parsed
// from the istream and used to print the history.
#include "command.h"
class Patron;

class History : public Command{
private:
Patron* patron; // patron to view the history of

public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty History object
// PRE: None
// POST: An empty History oject
History();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this History object
// PRE: None
// POST: All data in this History object deleted
~History();

// ----------------------------------------------------------------
// runCommand
// Prints the history of a patron. Will overwrite data.
// PRE: A properly formatted istream with the patron ID
// POST: The history of the given patron printed
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