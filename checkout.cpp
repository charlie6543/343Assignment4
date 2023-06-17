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
#include "checkout.h"
#include "library.h"
#include "productfactory.h"
#include "patron.h"
#include "product.h"

// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Checkout object
// PRE: None
// POST: An empty Checkout object created
Checkout::Checkout(){
  patron = nullptr;
  product = nullptr;
}

// ----------------------------------------------------------------
// destructor
// Deletes all information in this Checkout
// PRE: None
// POST: All information in this Checkout deleted
Checkout::~Checkout(){}

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
bool Checkout::runCommand(istream& command, Library& data){
  // initializing variables
  string line = "";
  int patronID = 0;
  NodeData* comparison = nullptr;
  char productType, temp = ' ';
  
  // read id of patron
  command >> line;
  
  // getPatron from library
  patronID = stoi(line);
  this->patron = data.getPatron(patronID);
  
  // if nullptr returned, getline and return false
  if(this->patron == nullptr){
    cout << "ERROR: Patron ID not valid. Could not check out.\n";
    isSuccess = false;
    getline(command, line);
    return false;
  }
  command.get();
  productType = command.peek();
  
  // get book with factory
  ProductFactory factory;
  comparison = factory.createComparison(command);
  if(comparison == nullptr){
    cout << "ERROR: Product type not found. Could not check out.\n";
    isSuccess = false;
    getline(command, line);
    return false;
  }
  
  // getProduct from library
  NodeData* tempProduct;
  tempProduct = data.getProduct(productType, comparison);
  delete comparison;
  comparison = nullptr;
  // if nullptr returned, getline and return false
  if(tempProduct == nullptr){
    cout << "ERROR: Product not in Library. Could not check out.\n";
    isSuccess = false;
    getline(command, line);
    return false;
  }
  
  // checkout in patron changes all necessary data in
  // both product and patron objects
  this->product = dynamic_cast<Product*>(tempProduct);
  if(!patron->checkout(this->product, getClass())){
    cout << "ERROR: The product could not be checked out.\n";
    isSuccess = false;
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
string Checkout::getClass(){
  return "Checkout";
}

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
void Checkout::print(){
  if(isSuccess) cout << "Successfully checked out ";
  else cout << "Attempted to check out ";
  product->print();
  cout << " to ";
  patron->print();
};