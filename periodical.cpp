// Periodical
// Contains methods and comparisons to be used by Periodical
// book objects to set data, get checked out or returned, or
// printed.
// Purpose: A representation of a Periodical book.
// Assumptions: istreams are formatted properly
// Author: Charlie Li
// Use: To be stored in a library and checked out/returned by
// patrons.
#include "periodical.h"
#include "nodedata.h"
#include "product.h"
#include <iomanip>

// ----------------------------------------------------------------
// no arg constructor
// Creates an empty Periodical
// PRE: None
// POST: An empty Periodical
Periodical::Periodical(){
  name = "";
  year = 0;
  month = 0;
  copiesAvailable = 1;
}

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Periodical
// PRE: None
// POST: All data in this Periodical deleted
Periodical::~Periodical(){}

// ----------------------------------------------------------------
// setData
// initializes the data members of this object
// PRE: An istream with the correct formatting
// POST: All relevant data members of this object set
bool Periodical::setData(istream& command){
  // get all words up to first comma (title)
  string lineRead = " ";
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->name += lineRead + " ";
  }

  // remove comma
  this->name = this->name.substr(0, (this->name.size() - 2));

  // get next value (month)
  command >> lineRead;
  this->month = stoi(lineRead);
  
  // get next value (year)
  command >> lineRead;
  this->year = stoi(lineRead);
  
  // return eof
  return !command.eof();
}

// ----------------------------------------------------------------
// setComparison
// initializes a Periodical with an istream that only takes in data
// members necessary for comparison.
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool Periodical::setComparison(istream& command){
  string lineRead = "";
  
  // get next value (year)
  command >> lineRead;
  this->year = stoi(lineRead);
  
  // get next value (month)
  command >> lineRead;
  this->month = stoi(lineRead);

  // get all words up to first comma (title)
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->name += lineRead + " ";
  }
  
  // remove comma
  this->name = this->name.substr(0, (this->name.size() - 2));
  return command.eof();
}

// comparison operators

// ----------------------------------------------------------------
// operator<
// Compares this Periodical to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is less than the other;
// false returned otherwise. -1 will be returned if the objects
// compared are different classes.
bool Periodical::operator<(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "Periodical") return -1;
  Periodical const& that = 
  dynamic_cast<Periodical const&>(other);

  // doing comparisons
  if(this->year < that.year) return true;
  else if(this->year > that.year) return false;
  else if(this->month < that.month) return true;
  else if(this->month > that.month) return false;
  else if(this->name < that.name) return true;
  
  // if all if branches were passed, then all are equal
  return false;
}

// ----------------------------------------------------------------
// operator<=
// Compares this Periodical to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is less than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool Periodical::operator<=(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "Periodical") return -1;
  Periodical const& that = 
  dynamic_cast<Periodical const&>(other);

  // doing comparisons
  if(this->year < that.year) return true;
  else if(this->year > that.year) return false;
  else if(this->month < that.month) return true;
  else if(this->month > that.month) return false;
  else if(this->name < that.name) return true;
  else if(this->name > that.name) return false;
  
  // if all if branches were passed, then all are equal
  return true;
}

// ----------------------------------------------------------------
// operator>
// Compares this Periodical to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is greater than the other;
// false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool Periodical::operator>(const NodeData& other) const{
  return !(*this < other);
}

// ----------------------------------------------------------------
// operator>=
// Compares this Periodical to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the 
// objects compared are different classes.
bool Periodical::operator>=(const NodeData& other) const{
  return !(*this <= other);
}

// ----------------------------------------------------------------
// operator==
// Compares this Periodical to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this Periodical is equal to the other;
// false returned otherwise.
bool Periodical::operator==(const NodeData& other) const{
  // compare class and cast if other is a periodical
  if(other.getClass() != "Periodical") return false;
  Periodical const& that = 
  dynamic_cast<Periodical const&>(other);

  // compare other data members and return
  return (that.year == this->year && that.month == this->month &&
    that.name == this->name);
}

// ----------------------------------------------------------------
// operator!=
// Compares this Periodical to a NodeData, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this Periodical is equal to the other;
// true returned otherwise
bool Periodical::operator!=(const NodeData& other) const{
  return !(*this == other);
}

// ----------------------------------------------------------------
// getClass
// returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
string Periodical::getClass() const{
  return "Periodical";
}

// ----------------------------------------------------------------
// checkout
// Decrements the number of copies available if possible and adds to
// the checkedOutBy array
// PRE: 1. The number of copies available is greater than 0.
// 2. A valid ID of a patron in the system.
// POST: The number of copies checked and decremented.
bool Periodical::checkout(int ID){
  // checking invariants
  if(copiesAvailable - 1 < 0) return false;

  // setting the new copies
  checkedOutBy[0] = ID;
  copiesAvailable--;
  return true;
}

// ----------------------------------------------------------------
// returnProduct
// Increments the number of copies available if possible and removes
// from the checkedOutBy array
// PRE: 1. The number of copies available is less than 1.
// 2. The valid ID of a patron that has checked out this product.
// POST: The number of copies checked and incremented.
bool Periodical::returnProduct(int ID){
  if(copiesAvailable + 1 > 1) return false;
  if(checkedOutBy[0] != ID) return false;

  checkedOutBy[0] = -1;
  copiesAvailable++;
  return true;
}

// ----------------------------------------------------------------
// print
// Prints a formatted representation of this Periodical
// PRE: Data members already set with setData
// POST: A formatted representation of this Periodical printed
void Periodical::print() const{
  // only prints title and date
  cout << left << setw(TITLE_MAX_LENGTH + 2) 
    << name.substr(0, TITLE_MAX_LENGTH);
  cout << left << setw(MONTH_OUTPUT_WIDTH) << month << year;
}

// ----------------------------------------------------------------
// display
// Displays all information in the Periodical
// PRE: The data in the Periodical must have been set with setData
// POST: All information in the Periodical displayed
void Periodical::display() const{
  // prints all data, including copiesAvailable
  cout << left << setw(AVAIL_OUTPUT_WIDTH) << copiesAvailable;
  print();
};