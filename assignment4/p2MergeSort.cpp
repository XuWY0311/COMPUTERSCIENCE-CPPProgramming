
/* P2:
 * File: p2MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include <iostream>
#include "CSC3002OJActive/assignment4/p2MergeSort.h"
using namespace std;

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */

void sort(int array[], int n) {
   // Sort
   if (n <= 1) return;
   // Step 1
   int targetArray[n];
   for (int i = 0; i < n; i++) {
      targetArray[i] = array[i];
   }
   // Step 2
   int n1 = n / 2;
   int n2 = n - n1;
   int a1[n1];
   int a2[n2];
   for (int i = 0; i < n; i++) {
      if (i <= n1 - 1) {
         a1[i] = targetArray[i];
      } else {
         a2[i - n1] = targetArray[i];
      }
   }
   // Step 3
   sort(a1, n1);
   sort(a2, n2);
   for (int i = 0; i < n; i++) {
      targetArray[i] = 0;
   }

   // Merge
   // Step 4
   int p1 = 0;
   int p2 = 0;
   int i = 0;
   while (p1 < n1 && p2 < n2) {
      if (a1[p1] < a2[p2]) {
         targetArray[i] = a1[p1++];
      } else {
         targetArray[i] = a2[p2++];
      }
      i = i + 1;
   }
   while (p1 < n1) {
      targetArray[i] = a1[p1++];
      i = i + 1;
   }
   while (p2 < n2) {
      targetArray[i] = a2[p2++];
      i = i + 1;
   }

   // Copy the sorted array into the original array
   for (int i = 0; i < n; i++) {
      array[i] = targetArray[i];
   }
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}

/* DO NOT modify the main() part */
int main() {
   int n;
   cin>>n;
   int array[200010];
   for(int i=0;i<n;i++) cin>>array[i];
   sort(array, n);
   printArray(array, n);
   return 0;
}
