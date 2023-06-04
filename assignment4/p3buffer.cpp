/* P3:
 * File: p3beffer.cpp
 * -------------------
 * This file implements EditorBuffer
 */
#include <iostream>
#include "CSC3002OJActive/assignment4/p3buffer.h"
#include "CSC3002OJActive/assignment4/SimpleTextEditor.h"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start -> next = start;
   start -> prev = start;
}

/* TODO PART:
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer() {
   Cell *cp = start;
   while (cp != start) {
      Cell *next = cp -> next;
      delete cp;
      cp = next;
   }
   delete start;
}

/* TODO PART:
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
   if (cursor -> next != start) {
      cursor = cursor -> next;
   }
}

void EditorBuffer::moveCursorBackward() {
   if (cursor -> prev != start) {
      cursor = cursor -> prev;
   }
}

void EditorBuffer::moveCursorToStart() {
   cursor = start -> next;
}

void EditorBuffer::moveCursorToEnd() {
   cursor = start -> prev;
}

/* TODO PART:
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {
   Cell *cp = new Cell;
   cp -> ch = ch;
   cp -> next = cursor -> next;
   cp -> prev = cursor;
   cursor -> next -> prev = cp;
   cursor -> next = cp;
   cursor = cp;
}

void EditorBuffer::deleteCharacter() {
   if (cursor -> next != start) {
      Cell *oldCell = cursor -> next;
      cursor -> next = oldCell -> next;
      if (oldCell -> next != start) {
         oldCell -> next -> prev = cursor;
      }
      delete oldCell;
   } 
}

/* TODO PART:
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const {
   string result;
   Cell *cp = start -> next;
   while (cp != start) {
      result = result + (cp -> ch);
      cp = cp -> next;
   } 
   return result;
}

int EditorBuffer::getCursor() const {
   int result = 0;
   Cell *cp = start -> next;
   while (cp != cursor) {
      result = result + 1;
      cp = cp -> next;
   }
   return result + 1;
}

/* DO NOT modify the main() part */
int main(){
    string cmd;
    EditorBuffer buffer;
    while(getline(cin,cmd)){
        executeCommand(buffer, cmd);
    }        
    return 0;
}