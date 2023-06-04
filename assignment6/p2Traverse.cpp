/*
 * File: Traverse.cpp
 * ------------------
 * This program reimplements the breadth-first search using an
 * explicit queue, and depth-first search algorithm using an explicit stack
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include "CSC3002OJActive/assignment6/simplegraph.h"
using namespace std;

void bfs(Node *start) {
   queue<Node *> queue;
   set<Node *> visited;

   queue.push(start);
   
   while (!queue.empty()) {
      Node * node = queue.front();
      queue.pop();

      auto it = visited.find(node);
      if (it == visited.end()) {
         cout << (node -> name) << endl;
         visited.insert(node);
         for (Arc *arc : node -> arcs) {
            queue.push(arc -> finish);
         }
      }
   }
}

void dfs(Node *start) {
   stack<Node *> stack;
   set<Node *> visited;

   stack.push(start);

   while (!stack.empty()) {
      // Step 1
      Node * node = stack.top();
      stack.pop();

      // Step 2
      auto it = visited.find(node);
      if (it == visited.end()) {
         cout << (node -> name) << endl;
         visited.insert(node);
      }
 
      // Step 3
      for (Arc *arc : node -> arcs) {
         auto it = visited.find(arc -> finish);
         if (it == visited.end()) {
            stack.push(arc -> finish);   
         }
      }
   }
}


int main(){
   SimpleGraph airline;
   readGraph(airline, cin);
   cout << "DFS at Portland ...." << endl;
   dfs(airline.nodeMap.at("Portland"));
   cout << "BFS at Portland ...." << endl;
   bfs(airline.nodeMap.at("Portland"));
   return 0;
}
