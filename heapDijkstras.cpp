#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "Graph.h"
#include "MinHeap.h"

using namespace std;

int * Dijkstras(Graph *G, int src){
	int V = G->numVertices();
	int * dist = new int[V];

	MinHeap minHeap(V);

	dist[src] = 0;

	for(int i = 0; i < V; i++){
		if(i != 0) dist[i] = INT_MAX;
		minHeap.insert(i, dist[i]);
	}
	while(!minHeap.isEmpty()){
		int u = minHeap.extractMin();
		struct Edge * edgeCrawl = G->getVertex(u).head;
		while(edgeCrawl != NULL){
			int v = edgeCrawl->dest;
			if(minHeap.isInMinHeap(v) && edgeCrawl->weight + dist[u] < dist[v]){
				dist[v] = edgeCrawl->weight + dist[u];
				minHeap.decreaseKey(v, dist[v]);
			}
			edgeCrawl = edgeCrawl->next;
		}
	}
	return dist;
}

int main(int argc, char* argv[]){
	Graph *G;

	string in = argv[1];
	ifstream infile(in);
	
	bool first = true;
	string line;
	int src, dest, weight, V;
	while(getline(infile, line)){
		stringstream s(line);
		if(first){
			s >> V;
			G = new Graph(V);
			first = !first;
			continue;
		}
		s >> src >> dest >> weight;
		G->addEdge(src, dest, weight);	
	}
	auto start = chrono::high_resolution_clock::now();
	int * dist = Dijkstras(G, 0);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << V << "," << duration.count();
	/*for(int i = 0; i < V; i++){
		cout << dist[i] << endl;
	}
	*/
	delete G;
	delete[] dist;
}
