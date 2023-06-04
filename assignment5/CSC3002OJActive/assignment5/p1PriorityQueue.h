/*
 * File: p1PriorityQueue.h
 * --------------
 * This interface exports the PriorityQueue template class, which implements
 * a queue in which the elements are dequeued in priority order.
 */

#ifndef _p1priorityqueue_h
#define _p1priorityqueue_h

#include "lib.h"

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a linear structure called a priority queue in which
 * values are processed in order of priority.  As in conventional English
 * usage, lower priority numbers correspond to higher effective priorities,
 * so that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> pq;
 * -----------------------------------
 * Initializes a new empty queue.
 */

   PriorityQueue();

/*
 * Destructor: ~PriorityQueue
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this queue.
 */

   ~PriorityQueue();

/*
 * Method: size
 * Usage: int n = pq.size();
 * -------------------------
 * Returns the number of values in the queue.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (pq.isEmpty()) . . .
 * ------------------------------
 * Returns true if the queue contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: pq.clear();
 * ------------------
 * Removes all elements from this queue.
 */

   void clear();

/*
 * Method: enqueue
 * Usage: pq.enqueue(value);
 *        pq.enqueue(value, priority);
 * -----------------------------------
 * Adds value to the priority queue.  If priority is specified, the new
 * value goes immediately after any other entries with that priority.
 * If no value for priority is supplied, the priority value defaults to 0.
 */

   void enqueue(ValueType value, double priority = 0);

/*
 * Method: dequeue
 * Usage: ValueType first = pq.dequeue();
 * --------------------------------------
 * Removes and returns the first item in the queue.  This method
 * signals an error if called on an empty queue.
 */

   ValueType dequeue();

/*
 * Method: peek
 * Usage: ValueType first = pq.peek();
 * -----------------------------------
 * Returns the first value in the queue without removing it.  This
 * method signals an error if called on an empty queue.
 */

   ValueType peek() const;

/*
 * Copy constructor and assignment operator
 * ----------------------------------------
 * These methods implement deep copying for queues.
 */

   PriorityQueue(const PriorityQueue<ValueType> & src);
   PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);

/* Private section */

/*
 * Implementation notes
 * --------------------
 * This implementation of PriorityQueue uses a linked list to store
 * the elements.  Each cell in the list maintains a priority value,
 * which is used to determine the order of the elements.
 */

private:

/* Type for linked list cell */

   struct Cell {
      ValueType data;                   /* The data value                  */
      double priority;                  /* The priority of this value      */
      Cell *link;                       /* Link to the next cell           */
   };

/* Instance variables */

   Cell *head;                          /* Pointer to the cell at the head */
   int count;                           /* Number of elements in the queue */

/* Private method prototypes */

   void deepCopy(const PriorityQueue<ValueType> & src);

};



#endif
