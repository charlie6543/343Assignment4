// ProductFactory
// Contains methods to create product-specific objects, comparisons,
// or headers.
// Purpose: To create a specific Product given a char/istream 
// indication of which Product to create.
// Assumptions: The char/istream is valid/formatted correctly.
// Author: Charlie Li
// Use: Call the ProductFactory with the char/istream representing
// the Product you want to create.
#include <iostream>
#include "factory.h"
#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
class NodeData;
class Library;

using namespace std;

class ProductFactory : public Factory{
public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates a ProductFactory
// PRE: None
// POST: A Factory
ProductFactory();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this ProductFactory
// PRE: None
// POST: All data in this Factory deleted
~ProductFactory();

// ----------------------------------------------------------------
// createProduct
// Returns a Product based on the given productType
// PRE: A char representing the product to be created
// POST: A Product of the given productType returned
NodeData* createProduct(char productType);

// ----------------------------------------------------------------
// createComparison
// Returns a Product based on the given istream. This Product is
// only for comparison purposes, and has incomplete data fields.
// PRE: A formatted istream that begins with the char representation
// of the product type. It should contain only the information 
// needed to run comparisons with other Products.
// POST: A Product of the given istream returned
NodeData* createComparison(istream& bookData);

// ----------------------------------------------------------------
// printHeader
// Prints the corresponding header for a certain product type
// PRE: A char representing the product type
// POST: A printed header formatted according to the product type
void printHeader(char productType);
};
#endif