/*
 * File: PriorityQueueTest.cpp
 * ---------------------------
 * This file contains a unit test of the PriorityQueue class.
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CSC3002OJActive/assignment6/lib.h"
#include "CSC3002OJActive/assignment6/p1priorityqueue.h"
// #include "strlib.h"
using namespace std;

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
   clear();
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * -----------------------------------------------
 * All of the dynamic memory is allocated in the Vector class, so no work
 * is required at this level.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
   /* Empty */
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
   return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
   return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
   heap.clear();
   count = 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType v, double p) {
   // Step 1: Put the element on the initial position
   HeapEntry entry;
   entry.value = v;
   entry.priority = p;
   entry.sequence = 1;
   long maxSequence = 0;
   for (int i = 0; i < heap.size(); i++) {
      if (heap[i].priority == p && maxSequence <= heap[i].sequence) {
         maxSequence = heap[i].sequence;
      }
   } 
   if (maxSequence > 0) {
      entry.sequence = maxSequence + 1;
   }
   heap.push_back(entry);

   // Step 2: Swap with its parent if necessary (to maintain the structure of the MinHeap)
   int currIndex = heap.size() - 1;
   while (currIndex != 0) {
      int parentIndex = (currIndex - 1) / 2;
      if (heap[currIndex].priority < heap[parentIndex].priority || (heap[currIndex].priority == heap[parentIndex].priority && heap[currIndex].sequence < heap[parentIndex].sequence)) {
         swap(heap[currIndex], heap[parentIndex]);
         currIndex = parentIndex;
      } else {
         break;
      }
   }

   // Step 3: Update the count 
   count = count + 1;
}
/*
 * Implementation notes: dequeue, peek, peekPriority
 * -------------------------------------------------
 * These methods must check for an empty queue and report an error if there
 * is no first element.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
   if (count == 0) error("dequeue: Attempting to dequeue an empty queue");
   // Step 1: Record the value of the dequeued entry
   ValueType result = heap[0].value;

   // Step 2: Put the last entry on the top of the heap
   heap[0] = heap.back();
   heap.pop_back();

   // Step 3: Bubble down to maintain the structure of the MinHeap
   int currIndex = 0;
   while (currIndex < heap.size()) {
      int leftChildIndex = 2 * currIndex + 1;
      int rightChildIndex = 2 * currIndex + 2;
      int candidateIndex;
      if (leftChildIndex < heap.size() && rightChildIndex < heap.size()) {
         if (heap[leftChildIndex].priority < heap[rightChildIndex].priority || (heap[leftChildIndex].priority == heap[rightChildIndex].priority && heap[leftChildIndex].sequence < heap[rightChildIndex].sequence)) {
            candidateIndex = leftChildIndex;
         } else {
            candidateIndex = rightChildIndex;
         }
         if (heap[currIndex].priority > heap[candidateIndex].priority || (heap[currIndex].priority == heap[candidateIndex].priority && heap[currIndex].sequence > heap[candidateIndex].sequence)) {
            swap(heap[currIndex], heap[candidateIndex]);
            currIndex = candidateIndex;
         } else {
            break;
         }
      } else if (leftChildIndex < heap.size() && rightChildIndex > heap.size() - 1) {
         candidateIndex = leftChildIndex;
         if (heap[currIndex].priority > heap[candidateIndex].priority || (heap[currIndex].priority == heap[candidateIndex].priority && heap[currIndex].sequence > heap[candidateIndex].sequence)) {
            swap(heap[currIndex], heap[candidateIndex]);
            currIndex = candidateIndex;
         } else {
            break;
         }
      } else {
         break;
      }

   }

   // Step 4: Update the count
   count = count - 1;   

   // Step 5: Return the value of the dequeued entry
   return result;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
   if (count == 0) error("peek: Attempting to peek at an empty queue");
   return heap[0].value;
}

template <typename ValueType>
double PriorityQueue<ValueType>::peekPriority() const {
   if (count == 0) error("peekPriority: Attempting to peek at an empty queue");
   return heap[0].priority;
}

template <typename ValueType>
void enqueueHeap(ValueType & value, double priority) {
   //TODO
}

template <typename ValueType>
ValueType dequeueHeap(){
   //TODO
}

template <typename ValueType>
bool PriorityQueue<ValueType>::takesPriority(int i1, int i2) {
   /* Return true if i1 takes the priority */

   //TODO
}

template <typename ValueType>
void PriorityQueue<ValueType>::swapHeapEntries(int i1, int i2) {
   /* Swap elements in the two positions */

   //TODO
}

template <typename ValueType>
std::string PriorityQueue<ValueType>::toString() {
   /* convert the PriorityQueue into a printable String */
   stringstream stream;
   string result;
   result = result + '{';
   PriorityQueue<string> temp;

   while (heap.size() > 0) {
      // Priority
      double pri = heap[0].priority;
      stream << pri;
      string priString = stream.str(); 
      stream.str(""); 
      
      // Value
         // Temp_Heap
      ValueType val_peek = heap[0].value;
      temp.enqueue(val_peek, pri);
      
         // Original_Heap
      ValueType val = dequeue();
      result = result + priString + ':' + '"' + val + '"';
      if (heap.size() != 0) {
         result = result + ',' + ' ';
      }
   }

   result = result + '}';

   // Recover
   while (temp.size() > 0) {
      double pri = temp.peekPriority();
      ValueType val = temp.peek();
      enqueue(val, pri);
      temp.dequeue();
   }

   return result;
}

template <typename ValueType>
std::ostream & operator<<(std::ostream & os,
                          const PriorityQueue<ValueType> & pq) {
   /* give the output of all the elements in queue(not dequeue)
      i.e.: cout << pq gives the output of all the content in current queue without change pq */

   //TODO
}

int main() {
   PriorityQueue<string> pq;
   string value;
   double priority;

   string in_pair;
   while(getline(cin,in_pair)){
      int sp = in_pair.find(' ');
      value = in_pair.substr(0, sp);
      priority = stod(in_pair.substr(sp+1, in_pair.size()));
      pq.enqueue(value, priority);
   }
   cout<<"pq.size() = "<<pq.size()<<endl;
   cout<<"pq.toString() : "<<pq.toString()<<endl;
   int init_len = pq.size();
   for (int i = 0; i<init_len; i++) {
      cout<<"i="<<i<<": pq.peek() = "<<pq.peek()<<endl;
      cout<<"i="<<i<<": pq.dequeue() = "<<pq.dequeue()<<endl;
   }
   cout<<"pq.isEmpty(): "<<boolalpha<<pq.isEmpty()<<endl;
   return 0;
}
