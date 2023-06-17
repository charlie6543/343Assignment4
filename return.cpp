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
#include "return.h"
#include "patron.h"
#include "nodedata.h"
#include "product.h"
#include "productfactory.h"
#include "library.h"

// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Return object
// PRE: None
// POST: All memory in this object deleted
Return::Return(){
  Patron* patron = nullptr;
  Product* product = nullptr;
  isSuccess = false;
}

// ----------------------------------------------------------------
// destructor
// Deletes all memory in this object
// PRE: None
// POST: All memory in this object deleted
Return::~Return(){}

// ----------------------------------------------------------------
// runCommand
// Given the patron and book information, will update all
// information to return the book.
// PRE: 1. A properly formatted istream containing patron and book
// information.
// 2. The main Library containing all relevant patron and book
// information.
// POST: All information in the Library, Patron, and Book updated
// so the Book is returned.
bool Return::runCommand(istream& command, Library& data){
  Patron* patron = nullptr;
  Product* product = nullptr;
  isSuccess = false;
  // initializing variables
  string line = "";
  int patronID = 0;
  NodeData* comparison = nullptr;
  NodeData* tempProduct = nullptr;
  char productType, temp = ' ';
  
  // read id of patron
  command >> line;
  
  // getPatron from library
  patronID = stoi(line);
  patron = data.getPatron(patronID);
  
  // if nullptr returned, getline and return false
  if(patron == nullptr){
    cout << "ERROR: Patron ID was not valid. Cannot return.\n";
    getline(command, line);
    return false;
  }
  command.get();
  productType = command.peek();
  
  // get book with factory
  ProductFactory factory;
  comparison = factory.createComparison(command);
  if(comparison == nullptr){
    cout << "ERROR: Book type not valid. Cannot return.\n";
    getline(command, line);
    return false;
  }
  
  // getProduct from library
  tempProduct = data.getProduct(productType, comparison);
  delete comparison;
  comparison = nullptr;
  // if nullptr returned, getline and return false
  if(tempProduct == nullptr){
    cout << "ERROR: Product not in Library. Cannot return.\n";
    getline(command, line);
    return false;
  }
  
  // remove method in patron changes all necessary data members
  product = dynamic_cast<Product*>(tempProduct);
  if(!patron->returnProduct(product, getClass())){
    cout << "ERORR: The product could not be returned.\n";
    getline(command, line);
    return false;
  }
  getline(command, line);
  isSuccess = true;
  return true;
}

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The name of the class returned.
string Return::getClass(){
  return "Return";
}

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
void Return::print(){
  if(isSuccess) cout << "Successfully returned ";
  else cout << "Attempted to return ";
  product->print();
  cout << " from ";
  patron->print();
};