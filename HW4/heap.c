#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0


/*
// uncomment and write your code
struct heap_struct make_heap_empty(int cap){
}

struct heap_struct make_heap(int N, int * arr){
}
*/

//my function 
int swap(int *a, int idxOne, int idxTwo){
	int temp = a[idxOne];
	a[idxOne] = a[idxTwo]; 
	a[idxTwo] = temp; 
	
	return *a;
}

void destroy(struct heap_struct * heapP){
	// write your code here
}


void print_heap(struct heap_struct heapS){
	// write your code here
}


void swim_up(int idx, int * arr){
	// given array and indx 
	// (indx - 1 ) / 2, will always give child -> parent
	while( (indx > 0) && (arr[indx] > arr[(indx - 1) / 2]))
		
		//swap arr[indx] and arr[(indx - 1) / 2] 
		swap(arr, idx, (idx - 1) / 2);
		indx = indx / 2; 
}


void sink_down(int i, int N, int * arr){
	// i = parent 
	int left = (i * 2) + 1; 
	int right = (i * 2) + 2;
}

void add(struct heap_struct * heapP, int new_item){
	// write your code here
}

// Returns (but does not remove) element with largest key 
	// Returns value of last leaf? 
int peek(struct heap_struct heapS){
	printf("\npeek placeholder, returns -1\n");
	return -1;
}

// removes the max item in heap, by max == indx[0] or largest value? 
int poll(struct heap_struct * heapP){
	printf("\npoll placeholder, returns -1\n");
	return -1;
}

