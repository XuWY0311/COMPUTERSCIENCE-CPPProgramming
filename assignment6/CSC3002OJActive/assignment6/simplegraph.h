/*
 * File: simplegraph.h
 * -------------------
 * This file defines a low-level, structure-based representation for
 * graphs along with basic functions for reading and writing graphs.
 */

#ifndef _simplegraph_h
#define _simplegraph_h

#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include "lib.h"

using namespace std;

struct Node;     /* Forward references to these two types so  */
struct Arc;      /* that the C++ compiler can recognize them. */

/*
 * Type: SimpleGraph
 * -----------------
 * This type represents a graph and consists of a set of nodes, a set of
 * arcs, and a map that creates an association between names and nodes.
 */

struct SimpleGraph {
   set<Node *> nodes;
   set<Arc *> arcs;
   map<std::string,Node *> nodeMap;
};

/*
 * Type: Node
 * ----------
 * This type represents an individual node and consists of the
 * name of the node and the set of arcs from this node.
 */

struct Node {
   std::string name;
   set<Arc *> arcs;
};

/*
 * Type: Arc
 * ---------
 * This type represents an individual arc and consists of pointers
 * to the endpoints, along with the cost of traversing the arc.
 */

struct Arc {
   Node *start;
   Node *finish;
   double cost;
};


/*
 * Function: readGraph
 * Usage: readGraph(g, infile);
 * ----------------------------
 * Reads in a simple description of a graph from the input stream.
 */

void readGraph(SimpleGraph & g, std::istream & infile);

/*
 * Function: writeGraph
 * Usage: writeGraph(g, outfile);
 * ------------------------------
 * Writes out a simple description of the graph g to the output stream.
 */

void writeGraph(const SimpleGraph & g, std::ostream & outfile);

#endif
