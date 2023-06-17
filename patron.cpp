// Patron
// Contains methods to set data, compare, get, and display the 
// information of a Patron
// Purpose: To be used in the Library class to represent a
// Patron of the library.
// Assumptions: istream is properly formatted
// Author: Charlie Li
// Use: Insert into Library class and call add or remove in order
// to complete a return or checkout.
#include "patron.h"
#include "product.h"
#include <iomanip>

// ----------------------------------------------------------------
// no-arg constructor
// Creates an empty Patron
// PRE: None
// POST: An empty Patron created
Patron::Patron(){
  firstName = "";
  lastName = "";
  id = 0;
}

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Patron
// PRE: None
// POST: All data in this Patron deleted
Patron::~Patron(){}

// ----------------------------------------------------------------
// setData
// Sets data members of this Patron given a properly formatted
// istream
// PRE: A properly formatted istream
// POST: All data members of this Patron set
bool Patron::setData(istream& command){
  // initializing variables
  string read;

  // reading in id
  command >> read;
  id = stoi(read);
  if(id > 9999){
    id = 0;
    return false;
  }
  
  // reading in last name
  command >> read;
  lastName = read;
  
  // reading in first name
  command >> read;
  firstName = read;
  
  return command.eof();
}

// setComparison
// initializes a Patron with an istream that only takes in data
// members necessary for comparison.
// Note: Not used for Patron class: only calls setData
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool Patron::setComparison(istream& command){
  return setData(command);
}

// ----------------------------------------------------------------
// operator<
// Compares this Patron to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is less than the other;
// false returned otherwise. -1 will be returned if the objects
// compared are different classes.
bool Patron::operator<(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "Patron") return -1;
  Patron const& that = dynamic_cast<Patron const&>(other);

  // doing comparisons
  return this->id < that.id;
}

// ----------------------------------------------------------------
// operator<=
// Compares this Patron to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is less than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool Patron::operator<=(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "Patron") return -1;
  Patron const& that = dynamic_cast<Patron const&>(other);

  // doing comparisons
  return this->id <= that.id;
}

// ----------------------------------------------------------------
// operator>
// Compares this Patron to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is greater than the other;
// false returned otherwise. -1 will be returned if the objects 
// compared are different classes.
bool Patron::operator>(const NodeData& other) const{
  return !(*this < other);
}

// ----------------------------------------------------------------
// operator>=
// Compares this Patron to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool Patron::operator>=(const NodeData& other) const{
  return !(*this <= other);
}

// ----------------------------------------------------------------
// operator==
// Compares this Patron to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Patron is equal to the other;
// false returned otherwise
bool Patron::operator==(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "Patron") return false;
  Patron const& that = dynamic_cast<Patron const&>(other);

  return this->id == that.id; 
}

// ----------------------------------------------------------------
// operator!=
// Compares this NodeData to another, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this Patron is equal to the other;
// true returned otherwise
bool Patron::operator!=(const NodeData& other) const{
  return !(*this == other);
}

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
string Patron::getClass() const{
  return "Patron";
}

// ----------------------------------------------------------------
// getID
// Returns the ID of this Patron
// PRE: Data set by setData
// POST: The ID of this Patron returned
int Patron::getID() const{
  return id;
}

// ----------------------------------------------------------------
// print
// Prints the name and id of this patron.
// PRE: Data set by setData
// POST: The name and id of this patron printed
void Patron::print() const{
  cout << lastName << ", " << firstName << " ID: " << id << endl;
}

// ----------------------------------------------------------------
// display
// Prints the name, id, and checkout history of this patron
// PRE: Data set by setData
// POST: The name, id, and checkout history of this patron printed
void Patron::display() const{
  // prints name, id, and history
  print();
  cout << endl;
  printHistory();
}

// ----------------------------------------------------------------
// printHistory
// Prints the checkout history of this patron
// PRE: None
// POST: The checkout history of this patron printed
void Patron::printHistory() const{
  cout << "Checkout History:\n";
  cout << left << setw(ACTION_OUTPUT_WIDTH) << "ACTION";
  cout << "BOOK INFORMATION\n";

  // add checkout history
  for(int i = 0; i < checkoutHistory.size(); i++){
    cout << left << setw(ACTION_OUTPUT_WIDTH) << checkoutHistory[i].first;
    checkoutHistory[i].second->print();
    cout << endl;
  }
}

// ----------------------------------------------------------------
// checkout
// adds a Product to the checked out array
// PRE: 1. A Product reference to add to the checked out array
// 2. The class name of the command running this function.
// POST: 1. The Product reference added to the checked out array
// 2. The checkout history will also be changed to add the
// Product and command information.
// 3. False will be returned if the Product could not be added.
bool Patron::checkout(Product* toAdd, string command){
  // if checkout successful for product, add to vectors
  if(toAdd->checkout(id)){
    checkedOut.push_back(toAdd);
    checkoutHistory.push_back( {command, toAdd} );
    return true;
  }

  // otherwise, return false and do not change data
  return false;
}

// ----------------------------------------------------------------
// returnProduct
// removes a Product from the checked out array
// PRE: 1. A Product reference to remove from the checked out array.
// it must already be a part of the array.
// 2. The class name of the command running this function.
// POST: 1. The Product removed from the checked out array
// 1. The checkout history will also be changed to add the
// Product and command information.
// 2. False will be returned if the Product could not be returned
bool Patron::returnProduct(Product* toRemove, string command){
  // loop to search for the product
  for(int i = 0; i < checkedOut.size(); i++){
    // if the product is found:
    if(*checkedOut[i] == *toRemove){
      
      // attempt to return product and change product data
      if(toRemove->returnProduct(id)){
        
        // if successful, change vectors accordingly
        checkedOut.erase(checkedOut.begin() + i);
        checkoutHistory.push_back( {command, toRemove} );
        return true;
      }
        
      // otherwise, return false
      else return false;
    }
  }
  return false;
};