/* P3:
 * File: WildcardMatch.cpp
 * -----------------------
 * This program tests the wildcardMatch method, which
 * matches a filename against a pattern containing the wildcard
 * characters * and ?.
 */

#include "CSC3002OJActive/assignment4/p4WildcardMatch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Method: wildcardMatch
 * Usage: if (wildcardMatch(filename, pattern)) . . .
 * --------------------------------------------------
 * This method checks to see whether filename matches the pattern,
 * which consists of three types of characters:
 *
 * 1. The character ?, which matches any single character
 * 2. The character *, which matches any string of characters
 * 3. Any other character, which matches only that character
 */


// Corrected Method (Recursion - Enumeration)
void wildcardMatchHelper(string filename, string pattern, int pointerOne = 0, int pointerTwo = 0, bool & isMatch) {
   if (isMatch == true) {
      return;
   }
   // Case 1: Finished
   if (pointerOne == filename.size() && pointerTwo == pattern.size()) {
      isMatch = true;
      return;
   } else {
   // Case 2: Unfinished
      // Step 1: Compare for unspecial pattern and question-mark pattern
      int p1 = pointerOne;
      int p2 = pointerTwo;
      while ((filename[p1] == pattern[p2] || pattern[p2] == '?') && p1 <= filename.size() - 1 && p2 <= pattern.size() - 1) {
         p1 = p1 + 1;
         p2 = p2 + 1;
      }
      if (p1 == filename.size() && p2 == pattern.size()) {
         isMatch = true;
         return;
      // Step 2: Compare for star-mark pattern   
      } else if (p2 <= pattern.size() - 1 && pattern[p2] == '*') {
         p2 = p2 + 1;
         // For 0-Mapping
         wildcardMatchHelper(filename, pattern, p1, p2, isMatch);
         // For 1-Mapping / n-Mapping
         p1 = p1 + 1;
         while (filename.size() != 0 && p1 <= filename.size() - 1) {
            wildcardMatchHelper(filename, pattern, p1, p2, isMatch);
            p1 = p1 + 1;
         }
      } else if (p2 == pattern.size() && pattern[p2 - 1] == '*') {
         isMatch = true;
         return;
      }
   }
}
bool wildcardMatch(string filename, string pattern) {
   bool isMatch = false;
   wildcardMatchHelper(filename, pattern, 0, 0, isMatch);
   return isMatch;
}


// Prev Method (Cutting)
//    bool matchResult = true;

//    int filenameLength = filename.length();
//    int patternLength = pattern.length();

//    // Step 1: Match the chars and positions of non-special patterns
//    // Step 1-1: Locate the chars and positions of non-special patterns in pattern string
//    vector<char> nonSpecialChar_Pattern;
//    vector<int> nonSpecialPosition_Pattern;
//    for (int i = 0; i < patternLength - 1; i++) {
//       if (pattern[i] != '?' && pattern[i] != '*') {
//          nonSpecialChar_Pattern.push_back(pattern[i]);
//          nonSpecialPosition_Pattern.push_back(i);
//       }
//    }
//    // Step 1-2: Find the corresponding chars and positions of non-special patterns in filename string
//    vector<int> nonSpecialPosition_Filename;
//    if (nonSpecialChar_Pattern.size() != 0) {
//       for (char nonSpecial : nonSpecialChar_Pattern) {
//          int prevPosition;
//          if (nonSpecialPosition_Filename.size() != 0) {
//             prevPosition = nonSpecialPosition_Filename.back() + 1;
//          } else {
//             prevPosition = 0;
//          }
//          size_t position = filename.find(nonSpecial, prevPosition);
//          if (position != string::npos) {
//             nonSpecialPosition_Filename.push_back(position);   
//          } else {
//             matchResult = false;
//             return matchResult;
//          }
//       }
//    } else {
//       auto minimalAmount = count(pattern.begin(), pattern.end(), '?');
//       auto starAmount = count(pattern.begin(), pattern.end(), '*');
//       if (starAmount > 0) {
//          if (filename.size() < minimalAmount) {
//             matchResult = false;
//             return matchResult;
//          }
//       } else {
//          if (filename.size() != minimalAmount) {
//             matchResult = false;
//             return matchResult;
//          }
//       }
//    }

//    // Step 2: Cut the filename string and pattern string and compare substrings one by one
//    for (int i = 0; i < nonSpecialPosition_Pattern.size(); i++) {
//       int position_Filename = nonSpecialPosition_Filename[i];
//       int position_Pattern = nonSpecialPosition_Pattern[i];
//       int subStringLength_Filename;
//       int subStringLength_Pattern;
//          // Case 1: For the first non special pattern
//       if (i == 0) {
//          string subString_Filename = filename.substr(0, position_Filename);
//          string subString_Pattern = pattern.substr(0, position_Pattern);
//          auto minimalAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '?');
//          auto starAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '*');
//          if (starAmount > 0) {
//             if (subString_Filename.size() < minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          } else {
//             if (subString_Filename.size() != minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          }
//       }
//          // Case 2: For the middle non special pattern
//       if (i != 0 && i != nonSpecialPosition_Pattern.size() - 1) {
//          int nextPosition_Filename = nonSpecialPosition_Filename[i + 1];
//          int nextPosition_Pattern = nonSpecialPosition_Pattern[i + 1];
//          subStringLength_Filename = nextPosition_Filename - position_Filename - 1;
//          subStringLength_Pattern = nextPosition_Pattern - position_Pattern - 1;
//          string subString_Filename = filename.substr(position_Filename + 1, subStringLength_Filename);
//          string subString_Pattern = pattern.substr(position_Pattern + 1, subStringLength_Pattern);
//          auto minimalAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '?');
//          auto starAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '*');
//          if (starAmount > 0) {
//             if (subString_Filename.size() < minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          } else {
//             if (subString_Filename.size() != minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          }
//       }
//          // Case 3: For the last non special pattern
//       if (i == nonSpecialPosition_Pattern.size() - 1) {
//          subStringLength_Filename = (filename.size() - 1 - position_Filename);
//          subStringLength_Pattern = (pattern.size() - 1 - position_Filename);
//          string subString_Filename = filename.substr(position_Filename + 1, subStringLength_Filename);
//          string subString_Pattern = pattern.substr(position_Pattern + 1, subStringLength_Pattern);
//          auto minimalAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '?');
//          auto starAmount = count(subString_Pattern.begin(), subString_Pattern.end(), '*');
//          if (starAmount > 0) {
//             if (subString_Filename.size() < minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          } else {
//             if (subString_Filename.size() != minimalAmount) {
//                matchResult = false;
//                return matchResult;
//             }
//          }
//       }    
//    }
//    return matchResult;



/* DO NOT modify the main() part */

int main() {
   string in_pair, filename, pattern;
   bool matchResult;
   while(getline(cin,in_pair)){
      int sp = in_pair.find(' ');
      filename = in_pair.substr(0, sp);
      pattern = in_pair.substr(sp+1, in_pair.size());
      matchResult = wildcardMatch(filename, pattern);
      cout << boolalpha  << matchResult << endl;
    }
   return 0;
}

