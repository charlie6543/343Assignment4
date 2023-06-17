// NodeData
// Contains methods to destroy, set data, compare, print, and get
// class.
// Purpose: A pure virtual class for other classes to inherit from.
// Assumption: istream is properly formatted
// Author: Charlie Li
// Use: Inherit from NodeData to generalize into one singular
// variable type
#include "nodedata.h"

// ----------------------------------------------------------------
// destructor
// Deletes all memory in this object
// PRE: None
// POST: All memory in this object deleted
NodeData::~NodeData(){};