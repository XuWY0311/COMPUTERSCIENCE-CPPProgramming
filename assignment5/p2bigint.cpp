/* P2:
 * File: p2bigint.cpp
 * ----------------
 * This file implements the p2bigint.h interface.
 */

#include <cctype>
#include <string>
#include <stack>
#include <cmath>
#include "CSC3002OJActive/assignment5/lib.h"
using namespace std;

class BigInt {

public:

/*
 * Constructor: BigInt
 * Usage: BigInt big(str);
 * -----------------------
 * Creates a new BigInt from a string of decimal digits.
 */

   BigInt(string str);

/*
 * Destructor: ~BigInt
 * -------------------
 * Frees the memory used by a BigInt when it goes out of scope.
 */

   ~BigInt();

   BigInt(const BigInt& src);
   BigInt& operator=(const BigInt& src);

/*
 * Method: toString
 * Usage: string str = bigint.toString();
 * --------------------------------------
 * Converts a BigInt object to the corresponding string.
 */

   string toString() const;

   BigInt operator+(const BigInt & b2);
   BigInt operator*(const BigInt & b2) const;


/* Private section */

/*
 * Implementation notes: BigInt data structure
 * -------------------------------------------
 * The BigInt data structure stores the digits in the number in
 * a linked list in which the digits appear in reverse order with
 * respect to the items in the list.  Thus, the number 1729 would
 * be stored in a list like this:
 *
 *     start
 *    +-----+    +-----+    +-----+    +-----+    +-----+
 *    |  o--+--->|  9  |  ->|  2  |  ->|  7  |  ->|  1  |
 *    +-----+    +-----+ /  +-----+ /  +-----+ /  +-----+
 *               |  o--+-   |  o--+-   |  o--+-   | NULL|
 *               +-----+    +-----+    +-----+    +-----+
 *
 * The sign of the entire number is stored in a separate instance
 * variable, which is -1 for negative numbers and +1 otherwise.
 * Leading zeros are not stored in the number, which means that
 * the representation for zero is an empty list.
 */

private:

/*
 * Type: Cell
 * ----------
 * This structure type holds a single digit in the linked list.
 */

   struct Cell {
      Cell *leadingDigits;
      int finalDigit;
   };

/* Instance variables */

   Cell *start;          /* Linked list of digits */

/* Private methods */

   BigInt(Cell *digits) {
      start = digits;
   }

};

/*
 * Implementation notes: BigInt constructor
 * ----------------------------------------
 * The code for this constructor offers a minimal implementation
 * that matches what we would expect on an exam.  In a more
 * sophisticated implementation, it would make sense to include
 * a test to avoid storing leading zeros in the linked list.  In
 * this implementation, calling BigInt("00042") creates a
 * BigInt with a different internal representation than
 * BigInt("42"), which is probably a bad idea.
 */

BigInt::BigInt(string str) {
   // Deal with leading zeros
   while (str[0] == '0' && str.length() > 1) {
      str = str.substr(1);
   }

   // Construct
   start = NULL;
   for (int i = 0; i < str.length(); i++) {
      if (!isdigit(str[i])) {
         error("BigInt - illegal format");
         break;
      }
      Cell *node = new Cell;
      // Convert the int Char into Char
      node -> finalDigit = (str[i] - '0');
      node -> leadingDigits = NULL;
      // For the first element
      if (start == NULL) {
         start = node;
      } else {
      // For other elements   
         node -> leadingDigits = start;
         start = node;
      }
   }
}

/*
 * Implementation notes: BigInt destructor
 * ---------------------------------------
 * The code for the destructor is similar to that of the other
 * classes that contain a linked list.  You need to store the
 * pointer to the next cell temporarily so that you still have
 * it after you delete the current cell.
 */

BigInt::~BigInt() {
   Cell *node = start;
   while (node != NULL) {
      Cell *nextNode = node -> leadingDigits;
      delete node;
      node = nextNode;
   } 
   start = NULL;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 */

BigInt::BigInt(const BigInt& src) {
   start = NULL;
   Cell *srcNode = src.start;
   Cell *prevNode = NULL;

   while (srcNode != NULL) {
      Cell *node = new Cell;
      node->finalDigit = srcNode->finalDigit;
      node->leadingDigits = NULL;

      if (prevNode == NULL) {
         start = node;
      } else {
         prevNode->leadingDigits = node;
      }

      prevNode = node;
      srcNode = srcNode->leadingDigits;
   }
}

BigInt& BigInt::operator=(const BigInt& src) {
   if (this != &src) {
      Cell *node = start;
      while (node != NULL) {
         Cell *nextNode = node->leadingDigits;
         delete node;
         node = nextNode;
      }
      start = NULL;

      Cell *srcNode = src.start;
      Cell *prevNode = NULL;
      while (srcNode != NULL) {
         Cell *node = new Cell;
         node->finalDigit = srcNode->finalDigit;
         node->leadingDigits = NULL;

         if (prevNode == NULL) {
            start = node;
         } else {
            prevNode->leadingDigits = node;
         }

         prevNode = node;
         srcNode = srcNode->leadingDigits;
      }
   }

   return *this;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * This method could also be written as a wrapper method that
 * calls a recursive function that creates the reversed string
 * one character at a time.
 */

string BigInt::toString() const {
   string reverseString;
   Cell *node = start;
   while (node != NULL) {
      int digit = node -> finalDigit;
      reverseString = reverseString + to_string(digit);
      node = node -> leadingDigits;
   }
   string resultString;
   for (int i = 0; i <= reverseString.length() - 1; i++) {
       resultString += reverseString[reverseString.length() - i - 1];
   } 
   return resultString;
}

BigInt BigInt::operator+(const BigInt & b2) {
   string left = this -> toString();
   BigInt result("0");
   Cell *currNodeLeft = this -> start;
   Cell *currNodeRight = b2.start;

   // Step 1: Before ends of two BigInt
   while ((currNodeLeft -> leadingDigits) != NULL && (currNodeRight -> leadingDigits) != NULL) {
      currNodeLeft -> finalDigit = (currNodeLeft -> finalDigit) + (currNodeRight -> finalDigit);
      // If need to forward
      if (currNodeLeft -> finalDigit >= 10) {
         currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
         (currNodeLeft -> leadingDigits) -> finalDigit = (currNodeLeft -> leadingDigits) -> finalDigit + 1;
      }
      currNodeLeft = currNodeLeft -> leadingDigits;
      currNodeRight = currNodeRight -> leadingDigits;
   }

   // Step 2: Reach one end or two ends
   // Case 1: Reach two ends
   if ((currNodeLeft -> leadingDigits) == NULL && (currNodeRight -> leadingDigits) == NULL) {
      currNodeLeft -> finalDigit = (currNodeLeft -> finalDigit) + (currNodeRight -> finalDigit);
      // If need to forward
      if (currNodeLeft -> finalDigit >= 10) {
         currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
         Cell *newNode = new Cell;
         newNode -> finalDigit = 1;
         newNode -> leadingDigits = NULL;
         currNodeLeft -> leadingDigits = newNode;
      }
   }   

   // Case 2: Reach the left end
   else if ((currNodeLeft -> leadingDigits) == NULL && (currNodeRight -> leadingDigits) != NULL) {
      // Deal with the original left end
      currNodeLeft -> finalDigit = (currNodeLeft -> finalDigit) + (currNodeRight -> finalDigit);
      // If need to forward
      if (currNodeLeft -> finalDigit >= 10) {
         currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
         Cell *newNode = new Cell;
         newNode -> finalDigit = 1;
         newNode -> leadingDigits = NULL;
         currNodeLeft -> leadingDigits = newNode;
         currNodeLeft = newNode;
      } else {
         Cell *newNode = new Cell;
         newNode -> finalDigit = 0;
         newNode -> leadingDigits = NULL;
         currNodeLeft -> leadingDigits = newNode;
         currNodeLeft = newNode;
      }
      currNodeRight = currNodeRight -> leadingDigits;     
      // Add the remaining right BigInt to the left one
      while (currNodeRight != NULL) {
         currNodeLeft -> finalDigit = (currNodeLeft -> finalDigit) + (currNodeRight -> finalDigit);
         if (currNodeLeft -> finalDigit >= 10) {
            currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
            Cell *newNode = new Cell;
            newNode -> finalDigit = 1;
            newNode -> leadingDigits = NULL;
            currNodeLeft -> leadingDigits = newNode;
            currNodeLeft = newNode;
         } else {
            if (currNodeRight -> leadingDigits != NULL) {
               Cell *newNode = new Cell;
               newNode -> finalDigit = 0;
               newNode -> leadingDigits = NULL;
               currNodeLeft -> leadingDigits = newNode;
               currNodeLeft = newNode;
            }
         }
         currNodeRight = currNodeRight -> leadingDigits;
      }
   }

   // Case 3: Reach the right end
   else if ((currNodeLeft -> leadingDigits) != NULL && (currNodeRight -> leadingDigits) == NULL) {
      // Deal with the original left end
      currNodeLeft -> finalDigit = (currNodeLeft -> finalDigit) + (currNodeRight -> finalDigit);
      // If need to forward
      if (currNodeLeft -> finalDigit >= 10) {
         currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
         (currNodeLeft -> leadingDigits) -> finalDigit = (currNodeLeft -> leadingDigits) -> finalDigit + 1;
      }
      currNodeLeft = currNodeLeft -> leadingDigits;
      // Check whether need to further forward     
      while (currNodeLeft -> leadingDigits != NULL) {
         if (currNodeLeft -> finalDigit >= 10) {
            currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
            (currNodeLeft -> leadingDigits) -> finalDigit = (currNodeLeft -> leadingDigits) -> finalDigit + 1;
         }
         currNodeLeft = currNodeLeft -> leadingDigits;
      }
      if (currNodeLeft -> finalDigit >= 10) {
         currNodeLeft -> finalDigit = currNodeLeft -> finalDigit - 10;
         Cell *newNode = new Cell;
         newNode -> finalDigit = 1;
         newNode -> leadingDigits = NULL;
         currNodeLeft -> leadingDigits = newNode;
         currNodeLeft = newNode;
      }
   }  
   string resultString = this -> toString();
   BigInt res(resultString);


   // Recover the left node
   BigInt prevLeft(left);
   (*this) = prevLeft;

   // Output the result
   result = res;
   return result;
}


BigInt BigInt::operator*(const BigInt & b2) const {
   Cell *currNodeLeft = this -> start;
   Cell *currNodeRight = b2.start;
   BigInt result("0");
   int digit = 0;
   while (currNodeRight != NULL) {
      int thisDigit = currNodeRight -> finalDigit;
      int multiplier = thisDigit * pow(10, digit);  
      for (int i = 1; i <= multiplier; i++) {
         result = (result + *this);
      }
      digit = digit + 1;
      currNodeRight = currNodeRight -> leadingDigits;
   }
   return result;
}

BigInt fact(int n) {
   BigInt result("1");
   for (int i = 1; i <= n; i++) {
      result = result * BigInt(integerToString(i));
   }
   return result;
}

int main() {
   BigInt nonInt("N");
   int d1, d2;
   cin>>d1>>d2;
   
   BigInt res1("0");
   BigInt res2("0");
   res1 = fact(d1);
   res2 = fact(d2);
   BigInt summation("0");
   summation = res2 + res1;
   cout << d1 << "! = " << res1.toString() << endl;
   cout << d2 << "! = " << res2.toString() << endl;
   cout << d1 << "! + " << d2 << "! = "<< summation.toString() << endl;

   return 0;
}
