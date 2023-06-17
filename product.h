// Product
// Contains a destructor, checkout, and return function
// to be independently implemented by child classes.
// Purpose: To represent an abstract product for a library.
// Assumptions: None
// Author: Charlie Li
// Uses: To be a general object for more specific Products to
// inherit from.
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include "nodedata.h"

using namespace std;

class Product : public NodeData{
protected:
string name; // name of the product

public:
// ----------------------------------------------------------------
// destructor
// Deletes all data in this object
// PRE: None
// POST: All data in this object deleted.
virtual ~Product() = 0;

// ----------------------------------------------------------------
// checkout
// To be implemented by child classes: if not applicable,
// child classes should return true without any other implementation.
// Otherwise, child classes will change data members to reflect
// being 'checked out' by the given patron.
// PRE: The ID of a valid patron in the Library system.
// POST: 1. Data members of child class changed to reflect being
// 'checked out'
// 2. True will be returned if the product was successfully checked 
// out, and false will be returned if the product could not be
// checked out
virtual bool checkout(int ID) = 0;

// ----------------------------------------------------------------
// returnProduct
// To be implemented by child classes: if not applicable,
// child classes will return true without any other implementation.
// Otherwise, child classes will change data members to reflect
// being 'returned' by the given patron.
// PRE: The ID of a valid patron in the Library system.
// POST: 1. Data members of child class changed to reflect being
// 'returned'
// 2. True will be returned if the product was successfully returned
// and false will be returned if the product could not be returned
virtual bool returnProduct(int ID) = 0;
};
#endif