#include <stdlib.h>

// ----- Adjacency List Implmentation -----
struct Edge {
	int dest;
	int weight;
	struct Edge * next;
};

struct Edge * newEdge(int dest, int weight){
	struct Edge * n = new Edge;
	n->dest = dest;
	n->weight = weight;
	n->next = NULL;
	return n;
}

struct AdjList {
	struct Edge * head;
};

// ----- Graph Implementation -----
class Graph {
	private:
		int V;
		struct AdjList * vertices;
	public:
		Graph(int);
		~Graph();
		void addEdge(int, int, int);
		int numVertices(){return V;};
		AdjList getVertex(int i){return vertices[i];};
};

Graph::Graph(int numV){
	V = numV;
	vertices = new AdjList[numV];
}

Graph::~Graph(){
	for(int i = 0; i < V; i++){
		Edge * curr = vertices[i].head;
		Edge * prev;
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}
	delete[] vertices;
}

void Graph::addEdge(int src, int dest, int weight){
	struct Edge * n = newEdge(dest, weight);
	n->next = vertices[src].head;
	vertices[src].head = n;

	n = newEdge(src, weight);
	n->next = vertices[dest].head;
	vertices[dest].head = n;
}	
