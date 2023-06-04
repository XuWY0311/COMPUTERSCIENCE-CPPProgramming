#ifndef _p2reversequeue_h
#define _p2reversequeue_h
#include <string>
#include <queue>

// using namespace std;

/* Function prototypes */

/*
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(std::queue<std::string> & queue);

/*
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(std::queue<std::string> & queue);

#endif // _p2reversequeue_h
