#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <limits.h>
#include <string>
#include <unordered_map>
 
using namespace std;

enum Type{RANDOM, DENSE, SPARSE};

// A function to generate random graph.
void GenerateRandGraph(int NOE, int NOV, enum Type type) {
	int j, count;
	int ** edge = new int*[NOE];
	for(int e = 0; e < NOE; e++){
		edge[e] = new int[2];
	}

	unordered_map<string, bool> edgeCheck;

	int i = 0;
	// Build a connection between two random vertex.
	if (NOE == (NOV * (NOV-1) / 2) ) {
		int e = 0;
		for (i = 0; i < (NOV + 1); i++) {
			for (j = i + 1; j < NOV; j++) {
				if (i == j) continue;
				edge[e][0] = i + 2;
				edge[e][1] = j + 2;
				e++;
			}
		}
	} else {
		while (i < NOE) {
			edge[i][0] = rand() % NOV + 1;
			edge[i][1] = rand() % NOV + 1;
			string f_edgeStr = to_string(edge[i][0]) + to_string(edge[i][1]);
			string r_edgeStr = to_string(edge[i][1]) + to_string(edge[i][0]);
			cout << f_edgeStr << endl; 
			if(edge[i][0] == edge[i][1]){
				continue;
			} else {
				cout << f_edgeStr << endl;
				try {
					edgeCheck.at(f_edgeStr);
					i--;
				} catch (...) {
					edgeCheck[f_edgeStr] = true;
					edgeCheck[r_edgeStr] = true;
				}
			} /*else {
			    for(j = 0; j < i; j++) {
			    if((edge[i][0] == edge[j][0] && edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] && edge[i][1] == edge[j][0])){
			    i--;
			    break;
			    }
			    }
			    }
			    */
			i++;
		}

	}
	string out;
	switch(type){
		case RANDOM:
			out = "./tests/random/test" + to_string(NOV) + "_" + "random";
			break;
		case DENSE:
			out = "./tests/dense/test" + to_string(NOV) + "_" + "dense";
			break;
		case SPARSE:
			out = "./tests/sparse/test" + to_string(NOV) + "_" + "sparse";
	}
	ofstream outFile(out);

	i = 0;
	outFile << NOV << endl;
	while (i < NOE) {
		outFile << edge[i][0] - 1 << " " << edge[i][1] - 1 << " " << 1 + rand() % 20 << endl;
		i++;
	}

	outFile.close();
	for(int e = 0; e < NOE; e++){
		delete[] edge[e];
	}
	delete[] edge;
}

int main(int argc, char* argv[])
{
	int e, v, max;
	for(int i = 5; i <= 500; i++){
		cout << "===================================\n";
		v = i;
		// Random Graph Generation
		max = ((v * (v-1)) / 2);
		e = v + rand() % (max - 1);
		cout << "Generating Random Graph => " << "V: " << v << "E: " << e << endl;
		GenerateRandGraph(e, v, RANDOM);

		// Dense Graph Generation
		e = max;	
		cout << "Generating Dense Graph => " << "V: " << v << "E: " << e << endl;
		GenerateRandGraph(e, v, DENSE);

		// Sparse Graph Generation
		e = v;
		cout << "Generating Sparse Graph => " << "V: " << v << "E: " << e << endl;
		GenerateRandGraph(e, v, SPARSE);
	}
}
