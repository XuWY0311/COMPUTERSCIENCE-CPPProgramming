/* Q2: 
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <iostream>
#include <string>
#include "csc300222fall/assignment1/FindDNAMatch.h" //for OJ
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
   int result = -1;
   string counterStrandS1 = matchingStrand(s1);

   for (int i = start; i <= (s2.length() - s1.length()); i++) {
      string subStringS2 = s2.substr(i, s1.length());
      if (counterStrandS1 == subStringS2) {
         result = i;
         break;
      } 
   }
   return result;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
   string result(strand.length(),' ');
   for (int i = 0; i < strand.length(); i++) {
      if (strand[i] == 'A') {
         result[i] = 'T';
      }
      else if (strand[i] == 'T') {
         result[i] = 'A';
      }
      else if (strand[i] == 'C') {
         result[i] = 'G';
      }
      else if (strand[i] == 'G') {
         result[i] = 'C';
      }
      else {
         result[i] = 'X';
      }
      
   }
   return result;
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   bool match = false;
   int lastMatchPosition = -1;
   for (int start = 0; start <= (s2.length() - s1.length()); start ++) {
      int matchPosition = findDNAMatch(s1, s2, start);
      if (matchPosition != (-1) && matchPosition != lastMatchPosition) {
         cout << s1 << " matches " << s2 << " at position " << matchPosition << endl;
         match = true;
         lastMatchPosition = matchPosition;
      }
   }
   if (match == false) {
      cout << s1 << " has no matches in " << s2;
   }
   
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    findAllMatches(s1, s2);
    return 0;
}
