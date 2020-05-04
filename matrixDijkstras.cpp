#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <limits.h>

using namespace std;

struct Graph {
	int V;
	int ** edges;
};

struct Graph * createGraph(int V){
	Graph * G = new Graph;
	G->V = V;
	G->edges = new int*[V];
	for(int i = 0; i < V; i++){
		G->edges[i] = new int[V];
		for(int j = 0; j < V; j++){
			G->edges[i][j] = -1;
		}
	}
	return G;
}

void deleteGraph(Graph * G){
	for(int i = 0; i < G->V; i++){
		delete[] G->edges[i];
	}
	delete[] G->edges;
	delete G;
}

void addEdge(Graph * G, int src, int dest, int weight){
	G->edges[src][dest] = weight;
	G->edges[dest][src] = weight;
}

int minDistV(Graph * G, int * dist, bool * vSet){
	int min = INT_MAX, minIndex;
	for(int v = 0; v < G->V; v++){
		if(vSet[v] == false && dist[v] <= min){
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

int * Dijkstras(Graph * G, int src) {
	int * dist = new int[G->V];
	
	bool vSet[G->V];

	for(int i = 0; i < G->V; i++){
		dist[i] = INT_MAX;
		vSet[i] = false;
	}

	dist[src] = 0;
	
	for(int count = 0; count < G->V - 1; count++){
		int u = minDistV(G, dist, vSet);
		vSet[u] = true;
		for(int v = 0; v < G->V; v++){
			int weight = G->edges[u][v];
			if(weight == -1){
				continue;
			}
			if(!vSet[v] && weight + dist[u] < dist[v]){
				dist[v] = weight + dist[u];
			}
		}
	}
	return dist;
}


int main(int argc, char *argv[]) {
	Graph * G;
	
	string in = argv[1];
	ifstream infile(in);

	bool first = true;
	string line;
	int src, dest, weight, V;
	while(getline(infile, line)){		
		stringstream s(line);
		if(first){
			s >> V;
			G = createGraph(V);
			first = !first;
			continue;
		}
		s >> src >> dest >> weight;
		addEdge(G, src, dest, weight);
	}
	
	auto start = chrono::high_resolution_clock::now();
	int * dist = Dijkstras(G, 0);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << V << "," << duration.count() << endl;
	
	/*
	int * dist = Dijkstras(G, 0);
	for(int i = 0; i < V; i++){
		cout << dist[i] << endl;
	}
	*/
	deleteGraph(G);
	delete[] dist;
}
