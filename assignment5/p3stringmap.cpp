/* Q34
 * File: stringmap.cpp
 * ----------------------
 * Implementation for the stringmap class.
 * 
 * @version 2014/10/08
 * - removed 'using namespace' statement
 */


#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <iostream>
#include <string>
#include "CSC3002OJActive/assignment5/tokenscanner.h"
#include "CSC3002OJActive/assignment5/p3stringmap.h"
using namespace std;

/*
 * Implementation notes: HashMap constructor and destructor
 * --------------------------------------------------------
 * The constructor allocates the array of buckets and initializes each
 * bucket to the empty list.  The destructor frees the allocated cells.
 */

StringMap::StringMap() {
   nBuckets = INITIAL_BUCKET_COUNT;
   buckets = new KeyValuePair[nBuckets];
   clear();
}

StringMap::~StringMap() {
   delete[] buckets;
}

/*
 * Implementation notes: get
 * -------------------------
 * The get method calls findKeyValuePair to search the linked list for the
 * matching key.  If no key is found, get returns the empty string.
 */

string StringMap::get(const string & key) const {
   int index = findKey(key);
   return (index == -1) ? "" : buckets[index].value;
}

/*
 * Implementation notes: put
 * -------------------------
 * The put method calls insertKey to search the bucket array for a matching
 * key.  If a key already exists, put simply resets the value field.  If no
 * matching key is found, put adds a new entry in the first free slot.
 */

void StringMap::put(const string & key, const string & value) {
   if ((double) count / nBuckets > REHASH_THRESHOLD) {
      rehash(2 * nBuckets + 1);
   }
   int index = insertKey(key);
   buckets[index].value = value;
}

int StringMap::size() const {
   return count;
}

bool StringMap::isEmpty() const {
   return count == 0;
}

bool StringMap::containsKey(const string & key) const {
   return findKey(key) != -1;
}

/*
 * Implementation notes: remove
 * ----------------------------
 * This implementation is tricky because removing one key can make later
 * keys inaccessible.  This implementation finds the first key that could
 * have gone in this position (if any) and moves it to this space, repeating
 * that process until an empty entry is found.  A much simpler but less
 * efficient strategy is to rehash after every deletion.
 */

void StringMap::remove(const string & key) {
   int index = findKey(key);
   if (index != -1) {
      buckets[index].occupied = false;
      count--;
      int toFill = index;
      while (true) {
         index = (index + 1) % nBuckets;
         if (!buckets[index].occupied) return;
         if (insertKey(buckets[index].key) == toFill) {
            buckets[toFill].value = buckets[index].value;
            buckets[index].occupied = false;
            toFill = index;
         }
      }
   }
}

void StringMap::clear() {
   for (int i = 0; i < nBuckets; i++) {
      buckets[i].occupied = false;
   }
   count = 0;
}

int StringMap::getNBuckets() {
   return nBuckets;
}

/* TODO PART:
 * Implementation notes: rehash
 * ----------------------------
 * The rehash method iterates over the existing key-value pairs, entering
 * them into a new table.
 */

void StringMap::rehash(int newBuckets) {
   KeyValuePair * newBucket = new KeyValuePair[newBuckets];
   KeyValuePair * oldBucket = buckets;
   int oldNBuckets = nBuckets;
   buckets = newBucket;
   for (int i = 0; i < oldNBuckets; i++) {
      if (oldBucket[i].occupied) {
         int index = insertKey(oldBucket[i].key);
         buckets[index].value = oldBucket[i].value;
      }
   }
   delete[] oldBucket;
   nBuckets = newBuckets;
}

/*
 * Private method: findKey
 * Usage: int index = findKey(key);
 * --------------------------------
 * This private method looks for a key in the buckets array.  If the
 * key is found, findKey returns its index.  If no match is found, the
 * findKey returns -1.
 */

int StringMap::findKey(const string & k) const {
   for (int i = 0; i < nBuckets; i++) {
      if (buckets[i].key == k) {
         return i;
      }
   }
   return -1;
}

/*
 * Private method: insertKey
 * Usage: int index = insertKey(key);
 * ----------------------------------
 * This private method is identical to findKey except that it inserts the
 * key in the correct place if it is not already in the table.
 */

int StringMap::insertKey(const string & key) {
   if (findKey(key) != -1) {
      buckets[findKey(key)].key = key;
      return findKey(key);
   } else {
      for (int i = hashCode(key) % nBuckets; i < nBuckets; i++) {
         if (buckets[i].key.empty()) {
            buckets[i].key = key;
            count = count + 1;
            return i;
         }
      }
      for (int i = 0; i < hashCode(key) % nBuckets; i++) {
         if (buckets[i].key.empty()) {
            buckets[i].key = key;
            count = count + 1;
            return i;
         }
      }
      error("Insufficient space in hash table");
   }
}

/*
 * Implementation notes: hashCode
 * ------------------------------
 * This function takes a string key and uses it to derive a hash code,
 * which is nonnegative integer related to the key by a deterministic
 * function that distributes keys well across the space of integers.
 * The specific algorithm used here is called djb2 after the initials
 * of its inventor, Daniel J. Bernstein, Professor of Mathematics at
 * the University of Illinois at Chicago.
 */

const int HASH_SEED = 5381;               /* Starting point for first cycle */
const int HASH_MULTIPLIER = 33;           /* Multiplier for each cycle      */
const int HASH_MASK = unsigned(-1) >> 1;  /* The largest positive integer   */

int hashCode(const string & str) {
   unsigned hash = HASH_SEED;
   int n = str.length();
   for (int i = 0; i < n; i++) {
      hash = HASH_MULTIPLIER * hash + str[i];
   }
   return int(hash & HASH_MASK);
}

void helpCommand() {
   cout << "Available commands:" << endl;
   cout << "  size         -- Prints the size of the map" << endl;
   cout << "  isEmpty      -- Prints whether the map is empty" << endl;
   cout << "  get key      -- Returns the value associated with key" << endl;
   cout << "  set key str  -- Sets the entry for key to str" << endl;
   cout << "  contains key -- Indicates whether the map contains key" << endl;
   cout << "  remove key   -- Removes the key from the table" << endl;
   cout << "  clear        -- Clears the map" << endl;
   cout << "  buckets      -- Prints the number of buckets" << endl;
   cout << "  rehash       -- Rehashes the map to have n buckets" << endl;
   cout << "  help         -- List these commands" << endl;
   cout << "  quit         -- Quits the program" << endl;
}


void executeCommand(TokenScanner & scanner, StringMap & map) {
   string cmd = scanner.nextToken();
   if (cmd == "size") {
      cout << map.size() << endl;
   } else if (cmd == "isEmpty") {
      cout << ((map.isEmpty()) ? "true" : "false") << endl;
   } else if (cmd == "clear") {
      map.clear();
   } else if (cmd == "get") {
      string key = scanner.getStringValue(scanner.nextToken());
      cout << map.get(key) << endl;
   } else if (cmd == "set") {
      string key = scanner.getStringValue(scanner.nextToken());
      map.put(key, scanner.getStringValue(scanner.nextToken()));
   } else if (cmd == "contains") {
      string key = scanner.getStringValue(scanner.nextToken());
      cout << ((map.containsKey(key)) ? "true" : "false") << endl;
   } else if (cmd == "remove") {
      string key = scanner.getStringValue(scanner.nextToken());
      map.remove(key);
   } else if (cmd == "buckets") {
      cout << map.getNBuckets() << endl;
   } else if (cmd == "rehash") {
      int n = stringToInteger(scanner.nextToken());
      map.rehash(n);
   } else if (cmd == "help") {
      helpCommand();
   } else if (cmd == "quit") {
      exit(0);
   } else if (cmd != "") {
      cout << "Unrecognized command: " << cmd << endl;
   }
}

int main() {
   StringMap map;
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   scanner.scanStrings();
   string str;
   while (true) {
      getline(cin,str);
      scanner.setInput(str);
      executeCommand(scanner, map);
   }
   return 0;
}
