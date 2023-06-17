// CommandFactory
// Contains a method to create a command based off the given istream
// Purpose: To create a specific Command for the main class
// Assumptions: the istream is properly formatted and starts with the char representing the command
// Author: Charlie Li
// Use: Pass in the istream to create a command
#include "commandfactory.h"
#include "command.h"
#include "display.h"
#include "history.h"
#include "checkout.h"
#include "return.h"

// ----------------------------------------------------------------
// no-arg constructor
// Creates a CommandFactory
// PRE: None
// POST: A CommandFactory
CommandFactory::CommandFactory(){}

// ----------------------------------------------------------------
// destructor
// Deletes all data in this CommandFctory
// PRE: None
// POST: All data in this CommandFactory deleted
CommandFactory::~CommandFactory(){}

// ----------------------------------------------------------------
// createCommand
// Creates a command given a properly formatted istream
// PRE: A properly formatted istream with the first letter representing the Command to create
// POST: A Command of the given type created and returned
Command* CommandFactory::createCommand(istream& command){
  // initializing variables
  char commandType = ' ';
  Command* toReturn = nullptr;
  command.get(commandType);

  // switch statement to create command
  switch(commandType){
    case 'D':
      toReturn = new Display;
      break;
    case 'H':
      toReturn = new History;
      break;
    case 'C':
      toReturn = new Checkout;
      break;
    case 'R':
      toReturn = new Return;
      break;
    default:
      cout << "ERROR: Could not identify command.\n";
      string line;
      getline(command, line);
      break;
  }
  return toReturn;
};