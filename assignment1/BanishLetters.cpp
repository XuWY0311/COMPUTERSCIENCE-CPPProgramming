/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
#include <string>
#include "csc300222fall/assignment1/lib.h" //for local version
using namespace std;

int banishLetters() {
   // Deal with banish letters.
   string file;
   string line;
   string originalBanishLetters;
   string finalBanishLetters;
   while (getline(cin, line)) {
       originalBanishLetters = line;
       break;
   }
   for (int i = 0; i < originalBanishLetters.length(); i++) {
       char upperCase = toupper(originalBanishLetters[i]);
       char lowerCase = tolower(originalBanishLetters[i]);
       finalBanishLetters += upperCase;
       finalBanishLetters += lowerCase;
   }

   // Deal with the content.
   while (getline(cin, line)) {
       for (int i = 0; i < line.length(); i++) {
           // When the target character is not banish letter, store the character into a new line.
           if (finalBanishLetters.find(line[i]) >= finalBanishLetters.length()) {
              char ch = line[i];
              cout << ch;
           }
       }
       cout << endl;
   }
   return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
