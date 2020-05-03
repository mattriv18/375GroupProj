#include <stdlib.h>
#include <iostream>

// ----- Nodes of MinHeap implementation -----
struct Node {
	int v;
	int dist;
};

// ----- Min Heap Implemenation -----
class MinHeap {
	private:
		int size;
		int capacity;
		int * pos;
		struct Node ** array;

		void swap(struct Node **, struct Node **);
		void minHeapify(int idx);
	public:
		MinHeap(int);
		~MinHeap();
		void insert(int, int);
		int isEmpty(){return size == 0;};
		int extractMin();
		void decreaseKey(int, int);
		int isInMinHeap(int);
};

void MinHeap::insert(int v, int dist){
	struct Node * n = new Node;
	n->v = v;
	n->dist = dist;
	array[v] = n;
	pos[v] = v;
	size++;
	decreaseKey(v, dist);
}

MinHeap::MinHeap(int capacity){
	this->pos = new int[capacity];
	this->size = 0;
	this->capacity = capacity;
	this->array = new Node*[capacity];
}

MinHeap::~MinHeap(){
	delete[] array;
	delete[] pos;
}

void MinHeap::swap(struct Node ** a, struct Node ** b){
	struct Node * t = *a;
	*a = *b;
	*b = t;
}

void MinHeap::minHeapify(int idx){
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2* idx + 2;

	if(left < size && array[left]->dist < array[smallest]->dist){
		smallest = left;
	}
	if(right < size && array[right]->dist < array[smallest]->dist){
		smallest = right;
	}

	if(smallest != idx){
		Node * smallestNode = array[smallest];
		Node * idxNode = array[idx];

		pos[smallestNode->v] = idx;
		pos[idxNode->v] = smallest;

		swap(&array[smallest], &array[idx]);

		minHeapify(smallest);
	}
}

int MinHeap::extractMin(){
	if(isEmpty()){
		return -1;
	}
	struct Node * root = array[0];

	struct Node * lastNode = array[size - 1];
	array[0] = lastNode;
	pos[root->v] = size-1;
	pos[lastNode->v] = 0;

	size--;
	minHeapify(0);
	int v = root->v;
	delete root;
	return v;
}

void MinHeap::decreaseKey(int v, int dist){
	int i = pos[v];
	
	array[i]->dist = dist;

	while(i && array[i]->dist < array[(i-1) / 2]->dist){
		pos[array[i]->v] = (i-1) / 2;
		pos[array[(i-1)/2]->v] = i;
		swap(&array[i], &array[(i-1)/2]);
		i = (i-1)/2;
	}
}

int MinHeap::isInMinHeap(int v){
	if(pos[v] < size){
		return 1;
	}
	return 0;
}
