// Factory
// Contains: A virutal destructor
// Purpose: For more specific factories to inherit from
// Assumptions: None
// Author: Charlie Li
// Use: Inherit from this class. In the child class, write a
// method to create a specific class given a char or istream.
// This is done to avoid violating the open-closed principle.
#include "factory.h"

// ----------------------------------------------------------------
// destructor
// Deletes all data in this Factory
// PRE: None
// POST: All data in this Factory deleted
Factory::~Factory(){};