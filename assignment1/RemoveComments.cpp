/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.*/


 

void removeComments(istream & is, ostream & os) {
    // Design signals.
    bool singleLineSignal = false;
    bool multiLineSignal = false;
    // Read the istream lines by lines.
    string line;
    while (getline(is, line)) {
        // Recover the singleLineSignal.
        singleLineSignal = false;
        for (int i = 0; i < line.length(); i++) {
        // Case 1: Any text beginning with // and extending through the end of the line.
            if (line[i] == '/' && line[i + 1] == '/' && multiLineSignal == false) {
                singleLineSignal = true;
            } 
        // Case 2: Any text beginning with /* and ending with */, possibly many lines later.
            if (line[i] == '/' && line[i + 1] == '*' && singleLineSignal == false) {
                multiLineSignal = true;
            }
            
            if (line[i - 1] != '/' && line[i] == '*' && line[i + 1] == '/' && multiLineSignal == true) {
                multiLineSignal = false;
                singleLineSignal = false;
            }
        // Store the content into the os.
            if (singleLineSignal == false && multiLineSignal == false) {
                // Deal with the edge case.
                if (!(line[i] == '*' && line[i + 1] == '/')) {
                    if (i == 0) {
                        char ch = line[i];
                        os << ch;
                    } else {
                      if (!(line[i] == '/' && line[i - 1] == '*')) {
                        char ch = line[i];
                        os << ch;
                      }
                    }
                }
            }
        }
        // Output line by line. 
        if (multiLineSignal == false) {
            os << endl;
        }
    }
}

void TestRemoveComments() {
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}

