#ifndef LIB_H
#define LIB_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

/* stanford standard library */
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
 * Function: integerToString
 * Usage: string s = integerToStrin
 * --------------------------------
 * Converts an integer into the cor
 * For example, calling <code>integ
 * the string <code>"123"</code>.
 */
std::string integerToString(int n);
/*
 * Function: error
 * Usage: error(msg);
 * ------------------
 * Signals an error condition in a program by throwing an
 * <code>ErrorException</code> with the specified message.
 */
void error(std::string msg);
/*
 * Function: stringToReal
 * Usage: double d = stringToReal(str);
 * ------------------------------------
 * Converts a string representing a real number into its corresponding
 * value.  If the string is not a legal floating-point number or contains
 * extraneous characters other than whitespace, <code>stringToReal</code>
 * calls <code>error</code> with an appropriate message.
 */
double stringToReal(const std::string& str);
double stringToDouble(const std::string& str);   // alias
int stringToInteger(const std::string& str);
/*
 * Function: startsWith
 * Usage: if (startsWith(str, prefix)) ...
 * ---------------------------------------
 * Returns <code>true</code> if the string <code>str</code> starts with
 * the specified prefix, which may be either a string or a character.
 */
bool startsWith(const std::string& str, char prefix);
bool startsWith(const std::string& str, const std::string& prefix);
 /*
 * Friend function: writeQuotedString
 * Usage: writeQuotedString(outfile, str, forceQuotes);
 * ----------------------------------------------------
 * Writes the string str to outfile surrounded by double quotes, converting
 * special characters to escape sequences, as necessary.  If the optional
 * parameter forceQuotes is explicitly set to false, quotes are included
 * in the output only if necessary.
 */
void writeQuotedString(std::ostream & os, const std::string & str,
         bool forceQuotes = true);
/*
 * Friend function: stringNeedsQuoting
 * Usage: if (stringNeedsQuoting(str)) ...
 * ---------------------------------------
 * Checks whether the string needs quoting in order to be read correctly.
 */
bool stringNeedsQuoting(const std::string & str);
/*
 * Friend function: writeGenericValue
 * Usage: writeGenericValue(os, value, forceQuotes);
 * -------------------------------------------------
 * Writes a generic value to the output stream.  If that value is a string,
 * this function uses writeQuotedString to write the value.
 */
template <typename ValueType>
void writeGenericValue(std::ostream & os, const ValueType & value,
         bool forceQuotes) {
 os << value;
}
template <>
inline void writeGenericValue(std::ostream & os, const std::string & value,
          bool forceQuotes) {
 writeQuotedString(os, value, forceQuotes);
}
std::string ltrim(const std::string &s);
std::string rtrim(const std::string &s);
std::string trim(const std::string &s);
// std::string toUpperCase(std::string str) {
//  transform(str.begin(), str.end(), str.begin(), ::toupper);
//  return str;
// }

// std::string toLowerCase(std::string str) {
//  transform(str.begin(), str.end(), str.begin(), ::tolower);
//  return str;
// }



#endif // LIB_H