#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
using namespace std;

//BinTree
//A Binary Search Tree. Sorts and stores data.
//Contains: various methods to create and manipulate
//a binary search tree. Sorting is automatically done.
//Purpose: create a binary search tree class that creates
//binary search trees.
//Assumptions: All data stored will be strings.

//Author: Charlie Li
//Use: Create a binary search tree with insert, or by
//converting an array to a binary search tree. Delete,
//copy, print, find values, or convert to an array.

class BinTree{

private:
//simple Node to hold data and left/right pointers
struct Node{
  NodeData* value;
  Node* left;
  Node* right;
};
Node* root; //the first element in the tree

//-----------------------------------------------------------
//Helper methods:
//Each helper corresponds with a public method
ostream& inorderHelper(Node* cur, ostream& out) const;

void sidewaysHelper(Node* cur, int i) const;

NodeData* findNodeHelper(NodeData* cur, NodeData* find) const;

bool removeHelper(Node*& current, const NodeData& target, NodeData*& data);

void deleteCurrent(Node*& current, NodeData*& data);

NodeData* findAndDeleteJustSmaller(Node*& current);

void emptyHelper(Node* cur);

bool comparisonHelper(const Node* curA, const Node* curB) const;

void equalsHelper(const Node* cur);

bool retrieveHelper(const NodeData& find, Node* cur, NodeData*& data) const;

bool siblingHelper(const NodeData& sibling, Node* cur, NodeData& data) const;

bool parentHelper(const NodeData& child, Node* cur, NodeData& data) 
const;

int toArrayHelper(NodeData* arr[], Node* cur, int i);

void toTreeHelper(NodeData* arr[], int min, int max);

public:
//-----------------------------------------------------------
//No-Arg Constructor
//Creates a default empty BinTree
//
//PRE: None
//POST: An empty BinTree
BinTree();

//-----------------------------------------------------------
//Destructor
//Deletes an BinTree
//
//PRE: A BinTree to delete
//POST: The given BinTree deleted with no memory leaks
~BinTree();

//-----------------------------------------------------------
//isEmpty
//Checks if the BinTree is empty.
//
//PRE: None
//POST: Checks if this BinTree has any data in it; returns
//returns true if not
bool isEmpty() const;

//-----------------------------------------------------------
//makeEmpty
//Delete all data and nodes in this BinTree 
//
//PRE: None
//POST: Deletes all data in this BinTree, making it empty
void makeEmpty();

//-----------------------------------------------------------
//operator=
//Sets this BinTree equal to another
//
//PRE: A BinTree to set this BinTree equal to
//POST: All data in this BinTree set equal to the data of the
//given BinTree, with this BinTree returned.
BinTree& operator=(const BinTree& other);

//-----------------------------------------------------------
//operator==
//Compares two BinTrees and returns true if they are equal
//
//PRE: A BinTree to compare to this BinTree
//POST: True returned if both BinTrees are equal,
//and false returned if both BinTrees are not equal
bool operator==(const BinTree& other) const;

//-----------------------------------------------------------
//operator!=
//Compares two BinTrees and returns false if they are equal
//
//PRE: A BinTree to compare to this BinTree
//POST: False returned if both BinTrees are equal,
//and true returned if both BinTrees are not equal
bool operator!=(const BinTree& other) const;

//-----------------------------------------------------------
//insert
//Adds a NodeData object into the tree in sorted position
//
//PRE: A NodeData pointer to insert into this BinTree
//POST: The given NodeData inserted into this BinTree in
//sorted order
bool insert(NodeData* insert);

//-----------------------------------------------------------
//operator<<
//Outputs the data in this BinTree in inorder order
//
//PRE: 1. An ostream to output to
//2. A BinTree to print the data of
//POST: The data in the given BinTree printed to the given
//ostream. The ostream will be returned.
friend ostream& operator<<(ostream& out, 
const BinTree& other);

//-----------------------------------------------------------
//retrieve
//Retrieves the NodeData address of a given object in the
//tree
//
//PRE: 1. A valid NodeData object to find
//2. A garbage value
//POST: True returned if the data was found; false if not.
//2. If found, the garbage value will instead point towards
//the located data
bool retrieve(const NodeData& find, NodeData*& data) const;

//-----------------------------------------------------------
//remove
//Removes a given NodeData object from the tree
//
//PRE: 1. A valid NodeData object to remove
//2. A garbage value
//POST: 1. True returned if the data was removed; false if
//not
//2. If removed, the garbage value will instead point towards
//the removed value
bool remove(const NodeData& remove, NodeData*& data);

//-----------------------------------------------------------
//displaySideways
//Displays a visual representation of the structure and data
//of this BinTree
//
//PRE: A valid BinTree (Binary Search Tree) in order
//POST: This BinTree displayed sideways, with the root at 
//the left
void displaySideways() const;

//-----------------------------------------------------------
//getSibling
//Retrieves the sibling of a given NodeData object in the 
//tree
//
//PRE: 1. A valid NodeData object to find the sibling of
//2. A garbage value
//POST: 1. True returned if the sibling was found; false
//otherwise
//2. If found, the garbage value will instead point towards 
//the sibling value
bool getSibling(const NodeData& sibling, NodeData& data) 
const;

//-----------------------------------------------------------
//getParent
//Retrieves the parent of a given NodeData object in the tree
//
//PRE: 1. A valid NodeData object to find the parent of
//2. A garbage value
//POST: 1. True returned if the parent was found; false
//otherwise
//2. If found, the garbage value will instead point towards 
//the parent value
bool getParent(const NodeData& child, NodeData& data)
const;

//-----------------------------------------------------------
//bstreeToArray
//Fills a NodeData array with an inorder traversal of this 
//BinTree
//
//PRE: A statically allocated array of 100 nullptr elements
//POST: The given array will be filled with the data in
//this BinTree. This BinTree will be left empty.
void bstreeToArray(NodeData* arr[]);

//-----------------------------------------------------------
//arrayToBSTree
//Builds a BinTree object given a sorted array of NodeData
//objects
//
//PRE: A sorted array of NodeData objects
//POST: A BinTree object holding the data from the array.
//The array will be left empty.
void arrayToBSTree(NodeData* arr[]);
};
#endif