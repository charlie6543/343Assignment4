#include "bintree.h"

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

//-----------------------------------------------------------
//No-Arg Constructor
//Creates a default empty BinTree
//
//PRE: None
//POST: An empty BinTree
BinTree::BinTree(){
  this->root = nullptr;
}

//-----------------------------------------------------------
//Destructor
//Deletes a BinTree
//
//PRE: A BinTree to delete
//POST: This BinTree deleted with no memory leaks
BinTree::~BinTree(){
  makeEmpty();
}

//-----------------------------------------------------------
//isEmpty
//Checks if the BinTree is empty.
//
//PRE: None
//POST: Checks if this BinTree has any data in it; returns
//returns true if not
bool BinTree::isEmpty() const{
  if(this->root == nullptr) return true;
  return false;
}

//-----------------------------------------------------------
//makeEmpty
//Delete all data and nodes in this BinTree 
//
//PRE: None
//POST: Deletes all data in this BinTree, making it empty
void BinTree::makeEmpty(){
  emptyHelper(root);
  root = nullptr;
}

void BinTree::emptyHelper(Node* cur){
  if(cur != nullptr){
    //calls delete on both sides of cur
    emptyHelper(cur->left);
    emptyHelper(cur->right);
    
    //deletes all data associated with cur
    delete cur->value;
    cur->value = nullptr;
    delete cur;
    cur = nullptr;
  }
}

//-----------------------------------------------------------
//insert
//Adds a NodeData object into the tree in sorted position
//
//PRE: A NodeData pointer to insert into this BinTree
//POST: The given NodeData inserted into this BinTree in
//sorted order
bool BinTree::insert(NodeData* dataptr){
  //creating new node to insert
  Node* ptr = new Node;
  ptr->value = dataptr;
  dataptr = nullptr;
  ptr->left = ptr->right = nullptr;
  
  //simplest case: root is empty, set root
  if (isEmpty()) {
    root = ptr;
  }
  else {
    //setting up vars for loop
    Node* current = root;
    bool inserted = false;

    // if item is less than current item
    //insert in left subtree,
    // otherwise insert in right subtree
    while (!inserted) {
      if (*ptr->value < *current->value) {
        if (current->left == nullptr) {//at leaf, insert left
          current->left = ptr;
          inserted = true;
        }
        else
          current = current->left;// one step left
        }
      else if(*ptr->value > *current->value) {
        if (current->right == nullptr) {//at leaf, insert right
          current->right = ptr;
          inserted = true;
        }
        else
          current = current->right;// one step right
      }
      else{
        //if duplicate: delete and return
        delete ptr;
        return false;
      }
    }
  }
  return true;
}

//-----------------------------------------------------------
//operator<<
//Outputs the data in this BinTree in inorder order
//
//PRE: 1. An ostream to output to
//2. A BinTree to print the data of
//POST: The data in the given BinTree printed to the given
//ostream. The ostream will be returned.
ostream& operator<<(ostream& out, 
const BinTree& other){
  other.inorderHelper(other.root, out);
  out << endl;
  return out;
}

ostream& BinTree::inorderHelper(Node* cur,
ostream& out) const{
  if(cur != nullptr){
    inorderHelper(cur->left, out); //left
    cur->value->display(); //cur
    cout << "\n";
    inorderHelper(cur->right, out); //right
  }
  return out;
}

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
bool BinTree::retrieve(const NodeData& find, NodeData*& data) const{
  return retrieveHelper(find, root, data);
}

bool BinTree::retrieveHelper(const NodeData& find, Node* cur,
NodeData*& data) const{
  if(cur != nullptr){
    //if we've found the desired value, return
    if(*cur->value == find){
      data = cur->value;
      return true;
    }
    
    //else, compare left and right and move accordingly
    else if(*cur->value > find) return retrieveHelper(find,
    cur->left, data);
    else return retrieveHelper(find, cur->right, data);
  }
  else return false; //base case, cur == nullptr
}

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
bool BinTree::remove(const NodeData& target, NodeData*& data) {
   return removeHelper(root, target, data);
}

bool BinTree::removeHelper(Node*& current,
const NodeData& target, NodeData*& data) {
  if (current == nullptr) {//base case, hit end
    return false;
  }

  // found item to remove
  if (target == *current->value) {
    deleteCurrent(current, data);
    return true;
  }
  if (target < *current->value) {
    return removeHelper(current->left, target, data);
  }

  // target >= *current->data
  return removeHelper(current->right, target, data);
}

//---------------------------------------------------------------------------//
// deleteCurrent
void BinTree::deleteCurrent(Node*& current, NodeData*& data) {
  data = current->value;
  
  // current has no children
  if (current->left == nullptr && current->right == nullptr) {
    delete current;
    current = nullptr;
  }

  // current has only right child
  else if (current->left == nullptr) {
    Node* temp = current;
    current = current->right;
    delete temp;
    temp = nullptr;
  }

   // current has only left child
  else if (current->right == nullptr) {
    Node* temp = current;
    current = current->left;
    delete temp;
    temp = nullptr;
  }

   // current has two children
  else {
    current->value = nullptr;
    current->value = findAndDeleteJustSmaller(current->left);
  }
}

//------------------------------------------------------------
// findAndDeleteJustSmaller
NodeData* BinTree::findAndDeleteJustSmaller(Node*& current) {
  if (current->right == nullptr) {
    //shifting elements and assigning data
    NodeData* item = current->value;
    Node* junk = current;
    current = current->left;
    delete junk;
    return item;
  }
  return findAndDeleteJustSmaller(current->right);
}


//-----------------------------------------------------------
//displaySideways
//Displays a visual representation of the structure and data
//of this BinTree
//
//PRE: A valid BinTree (Binary Search Tree) in order
//POST: This BinTree displayed sideways, with the root at 
//the left
void BinTree::displaySideways() const{
  sidewaysHelper(root, 0);
}

void BinTree::sidewaysHelper(Node* current, int level) const{
  if (current != nullptr) {
    level++;
    sidewaysHelper(current->right, level);

    //indent for readability
    //same number of spaces per depth level 
    for(int i = level; i >= 0; i--) {
      cout << "        ";
    }

    current->value->print();
    // display information of object
    sidewaysHelper(current->left, level);
  }
};