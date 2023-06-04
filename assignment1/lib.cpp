#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "csc300222fall/assignment1/lib.h"

using namespace std;

std::string toUpperCase(std::string str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string toLowerCase(std::string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string promptUserForFile(std::ifstream & stream, std::string prompt) {
   if (prompt == "") prompt = "Input file: ";
   while (true) {
	  auto filename = getLine(prompt);
      stream.open(filename.c_str(), ios::in);
      if (!stream.fail()) return filename;
      stream.clear();
      cout << "Unable to open that file.  Try again." << endl;
   }

}

std::string promptUserForFile(std::ofstream & stream, std::string prompt) {
   if (prompt == "") prompt = "Input file: ";
   while (true) {
	  auto filename = getLine(prompt);
      stream.open(filename.c_str(), ios::out);
      if (!stream.fail()) return filename;
      stream.clear();
      cout << "Unable to open that file.  Try again." << endl;
   }
}

std::string getLine(std::string prompt) {
	cout << prompt;
	string str;
	getline(cin, str);
	return str;
}