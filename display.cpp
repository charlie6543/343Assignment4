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
#include "display.h"
#include "library.h"
#include "productfactory.h"
#include "bintree.h"
#include <iomanip>

// ----------------------------------------------------------------
// no arg constructor
// Creates a Display object
// PRE: None
// POST: A Display object
Display::Display(){
  isSuccess = false;
}

// ----------------------------------------------------------------
// destructor
// Destroys all data of this Display object
// PRE: None
// POST: All data of this Display object destroyed
Display::~Display(){}

// ----------------------------------------------------------------
// runCommand
// Displays all of the books in the given Library
// PRE: 1. The properly formatted istream set to a valid command
// 2. The Library including all data members
// POST: All books in the given Library printed by type
// alphabetically
bool Display::runCommand(istream& command, Library& database){
  // get all trees
  const Library* data = &database;
  const BinTree* tree = nullptr;
  ProductFactory header;
  for(char i = 'A'; i <= 'Z'; i++){
    tree = data->getProducts(i);
    if(tree != nullptr){
      isSuccess = true;
      // printing header and then tree
      header.printHeader(i);
      cout << *tree << endl;
    }
  }
  if(!isSuccess) 
    cout << "No books could be found. Cannot display.\n";
  return isSuccess;
}

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The name of the class returned.
string Display::getClass(){
  return "Display";
}

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
void Display::print(){
  if(isSuccess) cout << "Books were successfully printed.\n";
  else cout << "No books could be found.\n";
};