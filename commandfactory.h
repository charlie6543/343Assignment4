// CommandFactory
// Contains a method to create a command based off the given istream
// Purpose: To create a specific Command for the main class
// Assumptions: the istream is properly formatted and starts with the 
// char representing the command
// Author: Charlie Li
// Use: Pass in the istream to create a command
#include "factory.h"

class Command;

class CommandFactory : public Factory{
public:
// ----------------------------------------------------------------
// no-arg constructor
// Creates a CommandFactory
// PRE: None
// POST: A CommandFactory
CommandFactory();

// ----------------------------------------------------------------
// destructor
// Deletes all data in this CommandFctory
// PRE: None
// POST: All data in this CommandFactory deleted
~CommandFactory();

// ----------------------------------------------------------------
// createCommand
// Creates a command given a properly formatted istream
// PRE: A properly formatted istream with the first letter 
// representing the Command to create
// POST: A Command of the given type created and returned
Command* createCommand(istream& command);

};