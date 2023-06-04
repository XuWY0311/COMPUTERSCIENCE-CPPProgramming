/*
 * File: p1priorityqueue.h
 * --------------
 * This file exports the PriorityQueue class, a collection in which values
 * are processed in priority order.
 */

#ifndef _p1priorityqueue_h
#define _p1priorityqueue_h

#include <vector>

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a priority queue in which values
 * are processed in order of priority.  As in conventional English usage,
 * lower priority numbers correspond to higher effective priorities, so
 * that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> pq;
 * -----------------------------------
 * Initializes a new priority queue, which is initially empty.
 */

   PriorityQueue();

/*
 * Destructor: ~PriorityQueue
 * --------------------------
 * Frees any heap storage associated with this priority queue.
 */

   virtual ~PriorityQueue();

/*
 * Method: size
 * Usage: int n = pq.size();
 * -------------------------
 * Returns the number of values in the priority queue.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (pq.isEmpty()) ...
 * ----------------------------
 * Returns true if the priority queue contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: pq.clear();
 * ------------------
 * Removes all elements from the priority queue.
 */

   void clear();

/*
 * Method: enqueue
 * Usage: pq.enqueue(value, priority);
 * -----------------------------------
 * Adds value to the queue with the specified priority.  Lower priority
 * numbers correspond to higher priorities, which means that all priority 1
 * elements are dequeued before any priority 2 elements.
 */

   void enqueue(ValueType value, double priority);

/*
 * Method: dequeue
 * Usage: ValueType first = pq.dequeue();
 * --------------------------------------
 * Removes and returns the highest priority value.  If multiple entries in
 * the queue have the same priority, those values are dequeued in the same
 * order in which they were enqueued.
 */

   ValueType dequeue();

/*
 * Method: peek
 * Usage: ValueType first = pq.peek();
 * -----------------------------------
 * Returns the value of highest priority in the queue, without removing it.
 */

   ValueType peek() const;

/*
 * Method: peekPriority
 * Usage: double priority = pq.peekPriority();
 * -------------------------------------------
 * Returns the priority of the first element in the queue, without removing
 * it.
 */

   double peekPriority() const;

/*
 * Method: toString
 * Usage: string str = pq.toString();
 * ----------------------------------
 * Converts the queue to a printable string representation.
 */

   std::string toString();

/* Private section */

/**********************************************************************/
/* Note: Everything below this point in the file is logically part    */
/* of the implementation and should not be of interest to clients.    */
/**********************************************************************/

/*
 * Implementation notes: PriorityQueue data structure
 * --------------------------------------------------
 * The PriorityQueue class is implemented using a data structure called a
 * heap.
 */

private:

/* Type used for each heap entry */

   struct HeapEntry {
      ValueType value;
      double priority;
      long sequence;
   };

/* Instance variables */

   std::vector<HeapEntry> heap;
   long enqueueCount;
   int count;
   int capacity;

/* Private function prototypes */

   void enqueueHeap(ValueType & value, double priority); // OPTIONAL
   ValueType dequeueHeap(); // OPTIONAL
   bool takesPriority(int i1, int i2); // OPTIONAL
   void swapHeapEntries(int i1, int i2); // OPTIONAL

};

// extern void error(std::string msg);





#endif
