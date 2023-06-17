// Command
// Contains a pure virtual destructor, runCommand, getClass, and print 
// method for child classes to implement
// Purpose: Abstract command class for more specific command classes to
// inherit from
// Assumptions: All istreams are properly formatted
// Author: Charlie Li
// Use: When creating a command, inherit from this class and implement 
// the abstract methods.
#include "command.h"

// ----------------------------------------------------------------
// pure virtual destructor
// Deletes all data of this Command: to be overwritten by child classes
// PRE: None
// POST: All data of this Command deleted
Command::~Command(){};