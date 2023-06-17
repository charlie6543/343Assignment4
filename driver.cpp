// Driver
// Contains a main method to test the Library class
// Purpose: To test the Library class
// Assumptions: All files are in the same folder
// Author: Charlie Li
// Description: Run the code to test the Library class.
#include <iostream>
#include <fstream>
#include "fictionbook.h"
#include "periodical.h"
#include "childrenbook.h"
#include "bintree.h"
#include "patron.h"
#include "library.h"
#include <vector>
#include <iomanip>

// Main
// Tests the Library class with three files
// PRE: 1. data4books.txt in the same folder
// 2. data4patrons.txt in the same folder
// 3. data4commands.txt in the same folder
// POST: The Library class tested
int main() {
  ifstream books("data4books.txt");
  ifstream patrons("data4patrons.txt");
  ifstream commands("data4commands.txt");
  Library test;
  test.initializeProducts(books);
  test.initializePatrons(patrons);
  test.runCommands(commands);
  books.close();
  patrons.close();
  commands.close();
};