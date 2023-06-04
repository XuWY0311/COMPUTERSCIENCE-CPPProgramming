
/* P2:
 * File: p2reversequeue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
#include "CSC3002OJActive/assignment2/p2reversequeue.h"
#include <stack>
#include <string>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
    stack<string> tempStack;
    // Put items into the stack;
    while (!queue.empty()) {
        tempStack.push(queue.front());
        queue.pop();
    }
    // Get items out of the stack;
    while (!tempStack.empty()) {
        queue.push(tempStack.top());
        tempStack.pop();
    }


}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & q) {
    queue<string> tempQueue;
    cout << "The queue contains: ";
    while (!q.empty()) {
        if (q.size() != 1){
            cout << q.front() << " ";
            tempQueue.push(q.front());
            q.pop();
        } else {
            cout << q.front();
            tempQueue.push(q.front());
            q.pop();
        }
    }
    q = tempQueue;
    cout << endl;
}

/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}
