# Graph-Topological-Ordering

## Description
C++ algorithm to output a topological order of a graph if it exists.
Includes Make file, header file, and a main file implementation with two graph examples (the first works while the second cannot be ordered).
---

## Graph Functions 
* Graph(int n) initializes a directed graph with n vertices
* void addEdge(int u, int v) will add a node to the graph with value u directed to the node with value v
* void printAdjacencyList() prints the adjacenecy list of all vertices in the graph
* void dfs(list<int>* L,int mark[], int v) does a depth first search within the graph with adjacency list pointer L, tracking node array mark[], and integer with number of vertices v
* void sort() will topologically sort the graph if posible and output the result
