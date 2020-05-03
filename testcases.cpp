#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <limits.h>
 
using namespace std;
 
// A function to generate random graph.
void GenerateRandGraphs(int NOE, int NOV) {
	int j, count;
	int ** edge = new int*[NOE];
	for(int e = 0; e < NOE; e++){
		edge[e] = new int[2];
	}
	int i = 0;
	// Build a connection between two random vertex.
	while (i < NOE) {
		cout << i << endl;
		edge[i][0] = rand() % NOV + 1;
		edge[i][1] = rand() % NOV + 1;
 
		if(edge[i][0] == edge[i][1])
			continue;
		else {
			for(j = 0; j < i; j++) {
				if((edge[i][0] == edge[j][0] && edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] && edge[i][1] == edge[j][0])){
					i--;
					break;
				}
			}
		}
		i++;
	}
 
    ofstream outFile("testinput.txt");

    i = 0;
    while (i < NOE) {
    	    cout << i << endl;
            outFile << edge[i][0] - 1 << " " << edge[i][1] - 1 << " " << 1 + rand() % 20 << endl;
        i++;
    }

    outFile.close();
    for(int e = 0; e < NOE; e++){
	delete[] edge[e];
    }
    delete[] edge;

    /*
	// Print the random graph.
	cout << "\nThe generated random random graph is: ";
	for(i = 0; i < NOV; i++) {
		count = 0;
		cout << "\n\t" << i + 1 << "-> { ";
		for(j = 0; j < NOE; j++) {
			if (edge[j][0] == i + 1) {
				cout << edge[j][1] << "   ";
				count++;
			} else if (edge[j][1] == i + 1) {
				cout << edge[j][0] << "   ";
				count++;
			} else if (j == NOE - 1 && count == 0)
				cout << "Isolated Vertex!";
		    }
		    cout << " }";
	}	
    */
}
 
int main()
{
	int n, i, e, v, max;
 
	cout<<"Random graph generation: ";
 
	// Randomly assign vertex and edges of the graph.
	v = 1 + rand() % 99999;
	cout << "\nThe graph has " << v << " vertexes.";

    max = (((v * (v-1)) / 2) - 1);
    if (max >= INT_MAX) max = INT_MAX - 1;
	e = 1 + rand() % max;
	cout << "\nThe graph has " << e << " edges.\n";
 
	// A function to generate a random undirected graph with e edges and v vertexes.
	GenerateRandGraphs(e, v);
}
