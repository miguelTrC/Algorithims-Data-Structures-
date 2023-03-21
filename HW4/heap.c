#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0



// uncomment and write your code
struct heap_struct make_heap_empty(int cap){
	
	struct heap_struct heapS;
	heapS.items = malloc(N * sizeof(int)); 
	//n-1?
	heapS.N = 0; // bc starting at indx[0]?
	heapS.capacity = cap;
	reuturn heapS;
}

struct heap_struct make_heap(int N, int * arr){

	struct heap_struct heapS;
	heapS.items = arr; // or &arr?
	heapS.N = N; 
	heapS.capacity = N;
	
	// struct heap_struct NAME = malloc()   // name it heaps
	// items = &arr;  malloc
	// N = N;  / or N = N-1? 
	// ^ same thing for capacity 

	
	// organize array before heap 
	
	
	// Adjust AS NEEDED 
	if (DEBUG){
		printf("In fucntion make_heap, in DEBUG MODE, printing array BEFORE it 					gets turned into heap: \n");
		print_heap(heapS);
	}
	
	for(int x= (N/2) - 1; x>=0; x--){
		//sink_down(i, N, arr);
		if(DEBUG){
			printf("In fucntion make_heap, in DEBUG MODE, printing array AFTER 						sink_down at index %d \n", x);
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
	// p == parent? 
	int imv = p; 
	if( (left <= N) && (A[left] > A[imv]) ){
		imv = left; 
	} // look at signs
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
	
	printf("Heap array: %1d, Capacity: %1d\n", heapS.N, heapS.capacity);
	printf("indexes:    ");
	for(int x=0; i<heapS.N; x++){
		printf("%d ", x);
	}
	printf("\n"); 
	
	printf("values:       ");
	for(int x=0; x<heapS.N; x++){
		printf("%7d,", heapS.items[x]);
	}
	printf("\n\n");
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
	
	int imv = idxOfMaxValue(arr, i, left, right, N);
	while(imv!=p){
		swap(A[imv], A[p]]); // maybe pass the mem &A 
		p = imv; 
		left = (i * 2) + 1;
		right = (i * 2) + 2;
		imv = idxOfMaxValue(arr, i, left, right, N);
		
	}
}

void add(struct heap_struct * heapP, int new_item){
	if(heapP->N == heapP->capacity){ // if heap full / resize
		int new_capacity = (heapP->capacity * 2);
		int *new_items = realloc(heapP->items, new_capacity * sizeof(int));
		if(new_items == NULL){
			printf("Error: could not resize heap. \n"); 
			exit(1); // return; 
		} 
	}
	
	// add new item to the end of the heap
	heapP->items = new_items; 
	heapP->N++; 
	
	swim_up(heapP->N - 1, heapP->items);
	
	
	// inserts new items to heap, if heap is full, resize to 2x its current size
	
}

// Returns (but does not remove) element with largest key 
	// Returns value of last leaf? 
int peek(struct heap_struct heapS){
	printf("\npeek placeholder, returns -1\n");
	
	if( (heapS.N == 0) || (heapP->items == NULL) ){
		printf(" Empty heap \n");
		return -1; // think of replacement; 
	}
	else{
		return heapS.items[0];
	}
	
}

// removes the max item in heap, by max == indx[0] or largest value? 
int poll(struct heap_struct * heapP){
	printf("\npoll placeholder, returns -1\n");
	
	if( (heapP->N == 0) || (heapP->items == NULL) ){
		printf(" Empty heap \n"); 
		return -1; // find alternative 	
	}
	else{
		int max_val = heapP->items[0];
		heapP->N--;  //CHECK 
		heapP->items[0] = heapP->items[heapP->N]; 
		sink_down(0, heapP->N, heapP->items);
		if(heapP->N < heapP->capacity/2){ //CHECK
			int new_capacity = heapP->capacity/2
			int *new_items = realloc(heapP->items, new_capacity * sizeof(int));
			if(new_items == NULL){
				printf("Error: could not rezie heap\n"); //CHECK
				exit(1); //CHEKC
			}
			heapP->capacity = new_capacity; 
			heapP->items = new_items;
		}
		return max_val; 
	}
	
	
	return -1;
}

// key == value 
// N is size and indx of last item in slides (1 to N on slides) (0 to N-1 for HW)

