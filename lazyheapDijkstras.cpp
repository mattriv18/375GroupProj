#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

typedef pair<int, int> iPair; // used to store (path vertex, distance) and (destination vertex, weight)

class Graph {
	private:
		int V;
		vector<iPair> * vertices;
	public:
		Graph(int);
		~Graph();
		void addEdge(int, int, int);
		int * Dijkstras(int);
};

Graph::Graph(int V){
	this->V = V;
	vertices = new vector<iPair>[V];
}

Graph::~Graph(){
	delete[] vertices;
}

void Graph::addEdge(int src, int dest, int weight){
	vertices[src].push_back(make_pair(dest, weight));
	vertices[dest].push_back(make_pair(src, weight));
}

int * Graph::Dijkstras(int src){
	int * dist = new int[V];

	priority_queue< iPair, vector<iPair>, greater<iPair> > pq;

	pq.push(make_pair(0, src));
	dist[src] = 0;

	for(int i = 1; i < V; i++){
		dist[i] = INT_MAX;
	}

	int visited[V] = {0};
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		if(visited[u] == 1){
			continue;
		}
		visited[u] = 1;
		vector<iPair>::iterator it;
		for(it = vertices[u].begin(); it != vertices[u].end(); it++){
			int v = (*it).first;
			int weight = (*it).second;

			if(weight + dist[u] < dist[v]){
				dist[v] = weight + dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(int argc, char* argv[]){
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
			G = new Graph(V);
			first = !first;
			continue;
		}
		s >> src >> dest >> weight;
		G->addEdge(src, dest, weight);
	
	}
	
	auto start = chrono::high_resolution_clock::now();
	int * dist = G->Dijkstras(0);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << V << "," << duration.count();

	/*int * dist = G.Dijkstras(0);
	for(int i = 0; i < V; i++){
		cout << dist[i] << endl;
	}*/
	delete dist;
}

