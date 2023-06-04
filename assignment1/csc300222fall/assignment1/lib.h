#ifndef LIB_H
#define LIB_H

#include <string>

/* stanford standard library */

/*
 * Function: getLine
 * Usage: string line = getLine(prompt);
 * -------------------------------------
 * Reads a line of text from <code>cin</code> and returns that line
 * as a string.  The newline character that terminates the input is
 * not stored as part of the return value.  If supplied, the optional
 * <code>prompt</code> string is printed before reading the value.
 */

std::string getLine(std::string prompt = "");

/*
 * Function: toUpperCase
 * Usage: string s = toUpperCase(str);
 * -----------------------------------
 * Returns a new string in which all lowercase characters have been converted
 * into their uppercase equivalents.
 */

std::string toUpperCase(std::string str);

/*
 * Function: toLowerCase
 * Usage: string s = toLowerCase(str);
 * -----------------------------------
 * Returns a new string in which all uppercase characters have been converted
 * into their lowercase equivalents.
 */

std::string toLowerCase(std::string str);


/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(stream, prompt);
 * -----------------------------------------------------------
 * Asks the user for the name of a file.  The file is opened using
 * the reference parameter <code>stream</code>, and the function
 * returns the name of the file.  If the requested file cannot be
 * opened, the user is given additional chances to enter a valid file.
 * The optional <code>prompt</code> argument provides an input prompt
 * for the user.
 */

std::string promptUserForFile(std::ifstream & stream, std::string prompt = "");
std::string promptUserForFile(std::ofstream & stream, std::string prompt = "");

#endif