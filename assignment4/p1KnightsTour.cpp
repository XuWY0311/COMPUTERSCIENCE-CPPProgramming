/* P1
 * File: p1KnightsTour.cpp
 * ---------------------
 * This program find a knight's tour on an N x M chessboard.
 */

#include "CSC3002OJActive/assignment4/p1KnightsTour.h"
/*
 * Function: solveKnightsTour
 * Usage: solveKnightsTour(n, m);
 * ------------------------------
 * Solves the knight's tour problem for a n x m chessboard.
 */

void solveKnightsTour(int n, int m) {
   
   Grid<int> board(n, vector<int>(m, 0));

   if (findKnightsTour(board, 0, 0, 1)) {
      displayBoard(board);
   } else {
      displayBoard(board);
      cout << "No tour exists for this board." << endl;
   }
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays each of the squares in the board along with its sequence
 * number in the tour.
 */

void displayBoard(Grid<int> & board) {
   for (int i = board.size() - 1; i >= 0; i--) {
      for (int j = 0; j < board[0].size(); j++) {
         cout << " " << setw(2) << board[i][j];
      }
      cout << endl;
   }
}

/*
 * Function: findKnightsTour
 * Usage: flag = findKnightsTour(board, row, col, seq);
 * ----------------------------------------------------
 * This function looks for a tour on the board, starting at
 * the position indicated by row and col. The seq parameter is
 * the sequence number of this move and is needed to keep
 * track of the steps on the tour. The function returns true
 * if a tour is found and false otherwise.
 *
 * This function begins by checking for three simple cases:
 *
 * 1. The position is off the board.
 * 2. The position has been previously visited.
 * 3. The tour is complete.
 *
 * In the first two cases, there can be no tour that begins
 * from that position on the board. In the last case, the
 * function can immediately return true.
 *
 * If the simple cases do not apply, the function marks the
 * current square and then tries all possible moves. If it
 * finds a tour from the resulting position, the function
 * returns true to the next highest level. If no moves lead
 * to a tour, the function must back out of this move and try
 * again at a higher level of the recursion.
 *
 * The for loops in this implementation are a little tricky.
 * They compute the row and column offsets for the next position by
 * noting that the row and column offsets add to 3 (either +1 and +2
 * or +2 and +1) and you need all four possible sign combinations.
 */

bool findKnightsTour(Grid<int> & board, int row, int col, int seq) {

   // Simple Cases
   // Simple Case 1:
   if (row > board.size() - 1 || col > board.size() - 1 || row < 0 || col < 0) {
      return false;
   }
   // Simple Case 2:
   if (board[row][col] != 0) {
      return false;
   }
   // Simple Case 3:
   if (seq == 64) {
      board[row][col] = 64;
      return true;
   }

   // Mark the current square
   board[row][col] = seq;

   // Recursion Decomposition
   // Check possible next steps
   bool result = false;
   if (result == false) {
      result = findKnightsTour(board, row - 1, col - 2, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row - 1, col + 2, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row - 2, col - 1, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row - 2, col + 1, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row + 1, col + 2, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row + 1, col - 2, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row + 2, col - 1, seq + 1);
   }
   if (result == false) {
      result = findKnightsTour(board, row + 2, col + 1, seq + 1);
   }

   // If on this sequare, we do not satisfy simple cases and we cannot go further, return back
   if (result == false) {
      board[row][col] = 0;
      return false;
   }

   return result;
}


/* DO NOT modify the main() part */
int main() {
   int n, m;
   cin>>n>>m;
   solveKnightsTour(n, m);
   return 0;
}
