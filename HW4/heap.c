//Miguel Trejo
#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0




struct heap_struct make_heap_empty(int cap){
	
	struct heap_struct heapS;
	heapS.items = malloc(cap * sizeof(int)); 
	//n-1?
	heapS.N = 0;
	heapS.capacity = cap;
	
	return heapS;
}

struct heap_struct make_heap(int N, int * arr){

	struct heap_struct heapS;
	heapS.items = arr;
	heapS.N = N; 
	heapS.capacity = N;
		
	if (DEBUG){
		printf("\nIn fucntion make_heap, in DEBUG MODE, printing array BEFORE it 			        				gets turned into heap: \n");
		print_heap(heapS);
	}
		// (N/2) - 1 
	for(int x= (N-1)/2; x>=0; x--){
		sink_down(x, N, arr);
		
		if(DEBUG){
			printf("\nIn fucntion make_heap, in DEBUG MODE, printing array after 						sink_down at index %d \n", x);
			print_heap(heapS);
		}
	}
		
	return heapS;
}


//my function 
int swap(int *a, int idxOne, int idxTwo){
	
	int temp = a[idxOne];
	a[idxOne] = a[idxTwo]; 
	a[idxTwo] = temp; 
	
	return *a;
}

int indxOfMaxValue(int *A, int p, int left, int right, int N){
	// p == parent
	int imv = p; 
	if( (left <= N) && (A[left] > A[imv]) ){
		imv = left; 
	} 
	if( (right <= N) && (A[right] > A[imv]) ){
		imv = right;
	}
	
	return imv;
}

void destroy(struct heap_struct * heapP){
	
	free(heapP->items);
	heapP->items = NULL; 
	heapP->N = 0; 
	heapP->capacity = 0; 
}



void print_heap(struct heap_struct heapS){
	
	printf("\nHeap array:%3d, Capacity:%3d\n", heapS.N, heapS.capacity);
	printf("index: ");
	for(int x=0; x<heapS.N; x++){
		printf("%5d ", x);
	} 
	
	printf("\nvalue: ");
	for(int x=0; x<heapS.N; x++){
		printf(" %5d,", heapS.items[x]);
	}
	printf("\n");
}


void swim_up(int idx, int * arr){

	while( (idx > 0) && (arr[idx] > arr[(idx - 1) / 2]))
		swap(arr, arr[idx], arr[(idx - 1) / 2]);
		idx = idx / 2; 
}


void sink_down(int i, int N, int * arr){
	// i = parent 
	int left = (i * 2) + 1; 
	int right = (i * 2) + 2;
	
	int imv = indxOfMaxValue(arr, i, left, right, N);
	while(imv!=i){
		swap(arr, arr[imv], arr[i]);
		i = imv; 
		left = (i * 2) + 1;
		right = (i * 2) + 2;
		imv = indxOfMaxValue(arr, i, left, right, N);
		
	}
}

void add(struct heap_struct * heapP, int new_item){
	
	if(heapP->N == heapP->capacity){
		int new_capacity = (heapP->capacity * 2);
		int *new_items = realloc(heapP->items, new_capacity * sizeof(int));
		if(new_items == NULL){
			printf("\n Could not resize the heap \n"); 
			return; // exit fail
		} 
	}
	
	// adding to the end of heap
	heapP->items = &new_item; //added &
	heapP->N++; 
	
	swim_up(heapP->N--, heapP->items);
	
}

// Returns (but does not remove) element with largest key 
int peek(struct heap_struct heapS){
	
	if( (heapS.N == 0) || (heapS.items == NULL) ){ // changed -> to . 
		printf(" Empty heap \n");
		return EXIT_FAILURE; 
	}
	else{
		return heapS.items[0];
	}
	
}

// removes the max item in heap
int poll(struct heap_struct * heapP){
	
	if( (heapP->N == 0) || (heapP->items == NULL) ){
		printf(" Empty heap \n"); 
		return EXIT_FAILURE; 	
	}
	else{
		int max = heapP->items[0];
		heapP->N--;  
		heapP->items[0] = heapP->items[heapP->N]; 
		sink_down(0, heapP->N, heapP->items);
		
		if( (heapP->N) < (heapP->capacity/2) ){ 
			int new_capacity = heapP->capacity/2;
			int *new_items = realloc(heapP->items, new_capacity * sizeof(int));
			
			if(new_items == NULL){
				printf("\n Could not resize the heap \n");
				return EXIT_FAILURE;
			}
			
			heapP->capacity = new_capacity; 
			heapP->items = new_items;
		}
		return max; 
	}
	
	
	return EXIT_FAILURE;
}

// key == value 
// N is size and indx of last item in slides (1 to N on slides) (0 to N-1 for HW)

