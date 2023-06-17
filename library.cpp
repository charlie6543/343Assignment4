// Library
// Contains methods to intialize books and products, run commands,
// and give external methods access to data.
// Purpose: Stores books and patrons for a library and runs commands
// for interactions between books and patrons.
// Assumptions: istreams are all formatted correctly.
// Author: Charlie Li
// Use: Call initialize or runCommands method to fill the library
// and run commands. If access is needed (by command classes),
// use getter methods.
#include <iostream>
#include <fstream>
#include "patron.h"
#include "bintree.h"
#include "command.h"
#include "commandfactory.h"
#include "productfactory.h"
#include "library.h"
#include "nodedata.h"
// ----------------------------------------------------------------
// no-arg constructor
// Creates a Library
// PRE: None
// POST: A Library
Library::Library(){}

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Library
// PRE: None
// POST: All data in this Library deleted
Library::~Library(){
  for(int i = 0; i < 26; i++){
    // deletes all products
    if(products[i] != nullptr) {
      delete products[i];
      products[i] = nullptr;
    }
  }

  // deletes all patrons
  for(int i = 0; i < 10000; i++){
    if(patrons[i] != nullptr){
      delete patrons[i];
      patrons[i] = nullptr;
    }
  }
}

// ----------------------------------------------------------------
// initializePatrons
// Initializes all patrons from a formatted file of all patrons to 
// be entered
// PRE: a string of a valid file name containing properly formatted 
// lines of all patrons
// POST: All patrons from the file initialized into the Library
void Library::initializePatrons(istream& patronFile){
  string temp = "";

  // loop to add all patrons
  while(patronFile && !patronFile.eof()){
    if(patronFile.peek() == EOF) break;

    // creating new patron based off istream
    Patron* newPatron = new Patron();
    newPatron->setData(patronFile);
    
    // get id and insert to hash table
    patrons[newPatron->getID()] = newPatron;
    
    getline(patronFile, temp);
  }
}

// ----------------------------------------------------------------
// initializeProducts
// Initializes all products from a formatted file of all products to 
// be entered
// PRE: a string of a valid file name containing properly formatted 
// lines of all products
// POST: All products from the file initialized into the Library
void Library::initializeProducts(istream& productFile){
  // initializing variables
  ProductFactory factory;
  char product = ' ';
  string line = "";
  bool end = false;
  
  // loop to read all lines and pass to factory
  while(productFile && !productFile.eof()){
    // getting char of product
    productFile.get(product);
    if(productFile.eof()) break;

    // getting product from factory and setting data
    NodeData* newProduct = factory.createProduct(product);
    productFile.get();
    
    // insert newProduct to tree
    if(newProduct != nullptr) {
      newProduct->setData(productFile);
      
      // find hash position using product and insert to tree
      
      // creating new tree if no other products of this type
      if(this->products[product - 'A'] == nullptr) 
        this->products[product - 'A'] = new BinTree();
      this->products[product - 'A']->insert(newProduct);
    }
    getline(productFile, line);
  }
}

// ----------------------------------------------------------------
// runCommands
// Runs all commands from a formatted file of all commands to be run
// PRE: A string of a valid file name containing properly formatted 
// lines of all products
// POST: All commands from the file run
void Library::runCommands(istream& commandFile){
  // initializing variables
  Command* command = nullptr;
  CommandFactory factory;

  // running loop to read all commands
  while(commandFile && !commandFile.eof()){
    command = factory.createCommand(commandFile);
    if(commandFile.eof()) break;
    if(command != nullptr){
      commandFile.get();
      command->runCommand(commandFile, *this);
    }
    delete command;
    command = nullptr;
  }
}

// ----------------------------------------------------------------
// getPatron
// Gets a Patron given their ID
// PRE: An int of a valid Patron ID
// POST: A pointer to the given Patron
Patron* Library::getPatron(int id){
  if(id > 9999 || id < 0) return nullptr;
  if(patrons[id] == nullptr) return nullptr;
  else return patrons[id];
}

// ----------------------------------------------------------------
// getProducts
// Gets a BinTree of Products given a char representing a Product
// PRE: A char representing a Product type
// POST: A pointer to a BinTree returned 
const BinTree* Library::getProducts(char type) const{
  if(products[type - 'A'] == nullptr) return nullptr;
  return products[type - 'A'];
}

// ----------------------------------------------------------------
// getProduct
// Gets a NodeData given a char representing their type and a 
// NodeData with all data fields necessary for comparison
// PRE: 1. A char representing the Product type
// 2. A NodeData of the same type, with all data fields necessary 
// for comparison. The target NodeData must be in the Library
// POST: The target NodeData returned
NodeData* Library::getProduct(char type, NodeData* comparison){
  // getting proper BinTree
  if(products[type - 'A'] == nullptr) return nullptr;
  BinTree* tree = products[type - 'A'];
  
  // retrieving nodeData
  NodeData* toReturn = nullptr;
  if(!tree->retrieve(*comparison, toReturn)) return nullptr;
  return toReturn;
};