// Book
// Contains a destructor and a data member representing year of
// publication
// Purpose: To represent an abstract book for a library.
// Assumptions: None
// Author: Charlie Li
// Uses: To be a general object for more specific Books to
// inherit from.
#include "book.h"

// ----------------------------------------------------------------
// pure virtual destructor
// Deletes all data: to be overwritten by child classes
// PRE: None
// POST: Data of Book class deleted
Book::~Book(){};