#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int n){
	num_of_vertices = n;
	Adj = new list<int>[n];
}

void Graph::addEdge(int u, int v){
	Adj[u].push_front(v);
}

void Graph::printAdjacencyList(){
	list<int>::iterator v;
	for(int u = 0; u < num_of_vertices; u++){
		cout << u << ": ";
		for (v = Adj[u].begin(); v != Adj[u].end(); v++){
			cout << *v << " ";
		}
		cout << endl;
	}
}

void Graph::dfs(list<int>* L, int mark[],int v){
  
  if(mark[v] == 2)
    return;
  if(mark[v] == 1){
    // return false
    cout << "Cycle Detected." << endl; 
    cycle = true;
    return;
  }

  mark[v] = 1;
  list<int>::iterator i;
  for(i = Adj[v].begin(); i != Adj[v].end(); i++){
    //if(mark[*i] == 0){
      dfs(L,mark,*i);
      //}
  }
  mark[v] = 2;
  L->push_front(v);
}

void Graph::sort(){
  //This needs to be implemented.
  list<int>*L = new list<int>[num_of_vertices];
  list<int>::iterator v;
  
  int mark[num_of_vertices];

  for(int i = 0; i < num_of_vertices; i++)
    mark[i] = 0;
  for(int i = 0; i < num_of_vertices; i++){
    dfs(L,mark,i);
  }

  if(!cycle){
    cout<<"Topological Sort: ";
    for(v = L->begin(); v != L->end(); v++){
      cout<< *v << " ";
    }
    cout<<endl;
  }
}
