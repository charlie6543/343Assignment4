// FictionBook
// Contains methods and comparisons to be used by FictionBook
// book objects to set data, get checked out or returned, or
// printed.
// Purpose: A representation of a FictionBook.
// Assumptions: istreams are formatted properly
// Author: Charlie Li
// Use: To be stored in a library and checked out/returned by
// patrons.
#include "fictionbook.h"
#include "nodedata.h"
#include "product.h"
#include <iomanip>
// ----------------------------------------------------------------
// no arg constructor
// Creates an empty FictionBook
// PRE: None
// POST: An empty FictionBook
FictionBook::FictionBook(){
  author = "";
  name = "";
  copiesAvailable = 5;
  year = 0;
}

// ----------------------------------------------------------------
// destructor
// Destroys all data from this FictionBook
// PRE: None
// POST: All data from this FictionBook deleted
FictionBook::~FictionBook(){}

// ----------------------------------------------------------------
// setData
// initializes the data members of this object
// PRE: An istream with the correct formatting
// POST: All relevant data members of this object set
bool FictionBook::setData(istream& command){
  // get all words up to first comma (author)
  string lineRead = " ";
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->author += lineRead + " ";
  }
  
  // remove comma
  this->author = 
    this->author.substr(0, (this->author.size() - 2));

  // get all words up to second comma (title)
  lineRead = " ";
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->name += lineRead + " ";
  }

  // remove comma
  this->name = this->name.substr(0, (this->name.size() - 2));

  // get last value (year)
  command >> lineRead;
  this->year = stoi(lineRead);
  
  // return eof
  return !command.eof();
}

// ----------------------------------------------------------------
// setComparison
// initializes a FictionBook with an istream that only takes in data
// members necessary for comparison.
// PRE: An istream with the correct formatting and only the data
// members necessary for comparison.
// POST: All data members necessary for comparison set
bool FictionBook::setComparison(istream& command){
  // get all words up to first comma (author)
  string lineRead = " ";
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->author += lineRead + " ";
  }
  
  // remove comma
  this->author = this->author.substr(0, (this->author.size() - 2));
  
  // get all words up to second comma (title)
  lineRead = " ";
  while(command && lineRead.at(lineRead.size() - 1) != 44){
    command >> lineRead;
    this->name += lineRead + " ";
  }

  // remove comma
  this->name = this->name.substr(0, (this->name.size() - 2));

  copiesAvailable = 0;
  year = 0;
  
  return !command.eof();
}

// comparison operators

// ----------------------------------------------------------------
// operator<
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is less than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is less than the other;
// false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool FictionBook::operator<(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "FictionBook") return -1;
  // JUST RETURN AN INT THEN FUCKER ??
  // cant its an operator func right :thinking:
  FictionBook const& that = 
  dynamic_cast<FictionBook const&>(other);

  // doing comparisons
  if(this->author < that.author) return true;
  else if(this->author > that.author) return false;
  else if(this->name < that.name) return true;
  return false;
}

// ----------------------------------------------------------------
// operator<=
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is less than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is less than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool FictionBook::operator<=(const NodeData& other) const{
  // checking class and casting
  if(other.getClass() != "FictionBook") return -1;
  FictionBook const& that = dynamic_cast<FictionBook const&>(other);

  // doing comparisons
  if(this->author < that.author) return true;
  else if(this->author > that.author) return false;
  else if(this->name < that.name) return true;
  else if(this->author == that.author && this->name == that.name)
    return true;
  return false;
}

// ----------------------------------------------------------------
// operator>
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is greater than the other. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is greater than the other;
// false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool FictionBook::operator>(const NodeData& other) const{
  return !(*this < other);
}

// ----------------------------------------------------------------
// operator>=
// Compares this FictionBook to a NodeData, returning true if this
// NodeData is greater than or equal to the other. Returns false 
// otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is greater than or equal to
// the other; false returned otherwise. -1 will be returned if the
// objects compared are different classes.
bool FictionBook::operator>=(const NodeData& other) const{
  return !(*this <= other);
}

// ----------------------------------------------------------------
// operator==
// Compares this FictionBook to a NodeData, returning true the two
// NodeData's are equal. Returns false otherwise.
// PRE: Another NodeData to compare to this one
// POST: True returned if this FictionBook is equal to the other;
// false returned otherwise.
bool FictionBook::operator==(const NodeData& other) const{
  // compare class and cast if other is a FictionBook
  if(other.getClass() != "FictionBook") return false;
  FictionBook const& that = 
  dynamic_cast<FictionBook const&>(other);

  // compare other data members and return
  return (that.author == this->author &&
    that.name == this->name);
}

// ----------------------------------------------------------------
// operator!=
// Compares this FictionBook to a NodeData, returning false the two
// NodeData's are equal. Returns true otherwise.
// PRE: Another NodeData to compare to this one
// POST: False returned if this FictionBook is equal to the other;
// true returned otherwise.
bool FictionBook::operator!=(const NodeData& other) const{
  return !(*this == other);
}

// ----------------------------------------------------------------
// getClass
// returns the name of the class
// PRE: None
// POST: The class name of the object calling the method
string FictionBook::getClass() const{
  return "FictionBook";
}

// ----------------------------------------------------------------
// checkout
// Decrements the number of copies available if possible and adds to
// the checkedOutBy array
// PRE: 1. The number of copies available is greater than 0.
// 2. A valid ID of a patron in the system.
// POST: The number of copies checked and decremented.
bool FictionBook::checkout(int ID){
  // checking invariants
  if(copiesAvailable - 1 < 0) return false;

  // setting the new copies
  checkedOutBy[5 - copiesAvailable--] = ID;
  return true;
}

// ----------------------------------------------------------------
// returnProduct
// Increments the number of copies available if possible and removes
// from the checkedOutBy array
// PRE: 1. The number of copies available is less than 1.
// 2. The valid ID of a patron that has checked out this product.
// POST: The number of copies checked and incremented.
bool FictionBook::returnProduct(int ID){
  if(copiesAvailable + 1 > 5) return false;
  if(checkedOutBy[5 - copiesAvailable] != ID) return false;

  checkedOutBy[5 - copiesAvailable++] = -1;
  return true;
}

// ----------------------------------------------------------------
// print
// Prints most data of this FictionBook in a format
// PRE: Data of this FictionBook set with setData
// POST: The data of this FictionBook printed in a format
void FictionBook::print() const{
  // only prints name, author, and year
  cout << left << setw(TITLE_MAX_LENGTH + 2) 
    << name.substr(0, AUTHOR_MAX_LENGTH);
  cout << left << setw(AUTHOR_MAX_LENGTH + 2) 
    << author.substr(0, TITLE_MAX_LENGTH) << year;
}

// ----------------------------------------------------------------
// displayBook
// Prints all data of this FictionBook in a format
// PRE: Data of this FictionBook set with setData
// POST: The data of this FictionBook printed in a format
void FictionBook::display() const{
  // prints all info
  cout << left << setw(AVAIL_OUTPUT_WIDTH) << copiesAvailable;
  print();
};
