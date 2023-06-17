// ProductFactory
// Contains methods to create product-specific objects, comparisons,
// or headers.
// Purpose: To create a specific Product given a char/istream 
// indication of which Product to create.
// Assumptions: The char/istream is valid/formatted correctly.
// Author: Charlie Li
// Use: Call the ProductFactory with the char/istream representing
// the Product you want to create.
#include "productfactory.h"
#include "nodedata.h"
#include "fictionbook.h"
#include "childrenbook.h"
#include "periodical.h"
#include <iomanip>
#include <fstream>
// ----------------------------------------------------------------
// no-arg constructor
// Creates a ProductFactory
// PRE: None
// POST: A Factory
ProductFactory::ProductFactory(){}

// ----------------------------------------------------------------
//destructor
// Deletes all data in this ProductFactory
// PRE: None
// POST: All data in this Factory deleted
ProductFactory::~ProductFactory(){}

// ----------------------------------------------------------------
// createProduct
// Returns a Product based on the given productType
// PRE: A char representing the product to be created
// POST: A Product of the given productType returned
NodeData* ProductFactory::createProduct(char productType){
  NodeData* toReturn = nullptr;
  
  // switch statement to create product
  switch(productType){
    case 'F': {
      toReturn = new FictionBook();
      break;
    }
    case 'C': {
      toReturn = new ChildrenBook();
      break;
    }
    case 'P': {
      toReturn = new Periodical();
      break;
    }
    default: {
      cout << "ERROR: Could not find product type.\n";
      break;
    }
  }
  return toReturn;
}

// ----------------------------------------------------------------
// createComparison
// Returns a Product based on the given istream. This Product is
// only for comparison purposes, and has incomplete data fields.
// PRE: A formatted istream that begins with the char representation
// of the product type. It should contain only the information 
// needed to run comparisons with other Products.
// POST: A Product of the given istream returned
NodeData* ProductFactory::createComparison(istream& bookData){
  // initializing vars
  NodeData* toReturn = nullptr;
  char type = ' ';
  //cout << type << endl;
  string data = "";
  bookData.get(type);
  bookData.get();
  
  switch(type){
    case 'F': {
      // get H or return
      bookData.get(type);
      if(type != 'H') 
      // get whitespace
      bookData.get();
      toReturn = new FictionBook;
      toReturn->setComparison(bookData);
      break;
    }
    case 'C': {
      // get H or return
      bookData.get(type);
      if(type != 'H') return nullptr;
      // get whitespace
      bookData.get();
      toReturn = new ChildrenBook;
      toReturn->setComparison(bookData);
      break;
    }
    case 'P': {
      // get H or return
      bookData.get(type);
      if(type != 'H') return nullptr;
      // get whitespace
      bookData.get();
      toReturn = new Periodical;
      toReturn->setComparison(bookData);
      break;
    }
    default: {
      break;
    }
  }
  return toReturn;
}

// ----------------------------------------------------------------
// printHeader
// Prints the corresponding header for a certain product type
// PRE: A char representing the product type
// POST: A printed header formatted according to the product type
void ProductFactory::printHeader(char productType){
  // switch to print the corresponding header for each product type
  switch(productType){
    case 'F':
      cout << "\nFiction Books:\n";
      cout << left << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL" << 
        setw(TITLE_MAX_LENGTH + 2) << "TITLE";
      cout << left << setw(AUTHOR_MAX_LENGTH + 2) 
        << "AUTHOR" << "YEAR\n";
      break;
    case 'C':
      cout << "\nChildrens Books:\n";
      cout << left << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL" << 
        setw(TITLE_MAX_LENGTH + 2) << "TITLE";
      cout << left << setw(AUTHOR_MAX_LENGTH + 2) 
        << "AUTHOR" << "YEAR\n";
      break;
    case 'P':
      cout << "\nPeriodicals:\n";
      cout << left << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL" << 
        setw(TITLE_MAX_LENGTH + 2) << "TITLE";
      cout << left << setw(MONTH_OUTPUT_WIDTH + 2)
        << "MONTH" << "YEAR\n";
      break;
    default:
      cout << "ERROR: Could not find product type.\n";
      break;
  }
};