/*
 * File: simplegraph.cpp
 * ---------------------
 * This file implements the I/O methods for the simplegraph.h interface.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "CSC3002OJActive/assignment6/simplegraph.h"
using namespace std;

/* Function prototypes */

//extern void error(string msg);
Node *addNode(SimpleGraph & g, string name);
Arc *addArc(SimpleGraph & g, Node *n1, Node *n2, double cost);

/*
 * Function: readGraph
 * Usage: readGraph(g, infile);
 * ----------------------------
 * Reads in a simple description of a graph from the input stream.
 */

void readGraph(SimpleGraph & g, istream & infile) {
   string line;
   while (getline(infile, line) && line.length() > 0) {
      //cout << line << endl;
      int arrow = line.find("-");
      //cout << line << " " << arrow << " " << string::npos << endl;
      if (arrow == string::npos) {
         addNode(g, trim(line));
      } else {
         int start = arrow + 1;
         int finish = arrow - 1;
         bool bidirectional = true;
         if (start < line.length() && line[start] == '>') {
            start++;
            if (finish >= 0 && line[finish] == '<') {
               finish--;
            } else {
               bidirectional = false;
            }
         }
         string s1 = trim(line.substr(0, finish + 1));
         string s2;
         double cost = 0;
         int lp = line.find("(", start);
         if (lp == string::npos) {
            s2 = trim(line.substr(start));
         } else {
            s2 = trim(line.substr(start, lp - start));
            int rp = line.find(")", lp);
            if (rp == string::npos) error("Mismatched parentheses");
            cost = stringToReal(trim(line.substr(lp + 1, rp - lp - 1)));
         }
         // cout << "addArc s1 " << s1 << " s2 " << s2 << endl;
         Node *n1 = addNode(g, s1);
         Node *n2 = addNode(g, s2);
         addArc(g, n1, n2, cost);
         if (bidirectional) addArc(g, n2, n1, cost);
      }
   }
}

/*
 * Function: writeGraph
 * Usage: writeGraph(g, outfile);
 * ------------------------------
 * Writes out a simple description of the graph g to the output stream.
 */

void writeGraph(const SimpleGraph & g, ostream & outfile) {
   set<string> connectedNodes;
   for (Arc *arc : g.arcs) {
      // cout << "writeGraph " << arc->start->name << " " << arc->finish->name << endl;
      connectedNodes.insert(arc->start->name);
      connectedNodes.insert(arc->finish->name);
      outfile << arc->start->name << " -> " << arc->finish->name;
      if (arc->cost != 0) outfile << " (" << arc->cost << ")";
      outfile << endl;
   }
   for (Node *node : g.nodes) {
      if (connectedNodes.find(node->name) == connectedNodes.end()) {
         outfile << node->name << endl;
      }
   }
}

/* Helper functions */

Node *addNode(SimpleGraph & g, string name) {
   // cout << "calling addNode " << name << endl;
   auto missing = g.nodeMap.find(name) == g.nodeMap.cend();
   if (missing) {
      // cout << "adding new Node " << name << endl;
      Node *node = new Node;
      node->name = name;
      g.nodes.insert(node);
      g.nodeMap.insert_or_assign(name, node);
      return node;
   } else {
      return g.nodeMap.at(name);;
   }
}

Arc *addArc(SimpleGraph & g, Node *n1, Node *n2, double cost) {
   //cout << "addArc, start " << n1->name << " finish " << n2->name << " cost " << cost << endl;

   Arc *arc = new Arc;
   arc->start = n1;
   arc->finish = n2;
   arc->cost = cost;
   g.arcs.insert(arc);
   n1->arcs.insert(arc);
   return arc;
}
