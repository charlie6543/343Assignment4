// Command
// Contains a pure virtual destructor, runCommand, getClass, and print 
// method for child classes to implement
// Purpose: Abstract command class for more specific command classes to
// inherit from
// Assumptions: All istreams are properly formatted
// Author: Charlie Li
// Use: When creating a command, inherit from this class and implement 
// the abstract methods.
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>

class Library;

using namespace std;

class Command{
protected:
bool isSuccess; // if command was successfully carried out

public:
// ----------------------------------------------------------------
// pure virtual destructor
// Deletes all data of this Command: to be overwritten by child classes
// PRE: None
// POST: All data of this Command deleted
virtual ~Command() = 0;

// ----------------------------------------------------------------
// runCommand
// for child class to implement: runs according to class
// PRE: 1. The properly formatted istream set to a valid command
// 2. The Library including all data members
// POST: A command run according to the object that is running it
virtual bool runCommand(istream& command, Library& database) = 0;

// ----------------------------------------------------------------
// getClass
// Returns the name of the class
// PRE: None
// POST: The name of the class returned.
virtual string getClass() = 0;

// ----------------------------------------------------------------
// print
// Prints any function that the object performed.
// PRE: None
// POST: Any function that the object performed printed.
virtual void print() = 0;
};
#endif