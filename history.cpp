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
#include "history.h"
#include "patron.h"
#include "library.h"

// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty History object
// PRE: None
// POST: An empty History oject
History::History(){
  isSuccess = false;
}

// ----------------------------------------------------------------
// destructor
// Deletes all data in this History object
// PRE: None
// POST: All data in this History object deleted
History::~History(){}

// ----------------------------------------------------------------
// runCommand
// Prints the history of a patron. Will overwrite data.
// PRE: A properly formatted istream with the patron ID
// POST: The history of the given patron printed
bool History::runCommand(istream& command, Library& database){
  // initializing variables
  isSuccess = false;
  string line = "";
  
  // get patron
  command >> line;
  patron = database.getPatron(stoi(line));
  if(patron == nullptr){
    cout << "ERROR: Patron not found. Cannot print history.\n";
    getline(command, line);
    return false;
  }
  
  // call patron print methods
  patron->print();
  patron->printHistory();
  cout << endl;
  isSuccess = true;
  
  // getline and return
  getline(command, line);
  return true;
}

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The name of the class returned.
string History::getClass(){
  return "History";
}

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
void History::print(){
  if(isSuccess){
    cout << "the history of ";
    patron->print();
    cout << " was successfully printed.\n";
  }
  else{
    cout << "Could not print history.\n";
  }
};