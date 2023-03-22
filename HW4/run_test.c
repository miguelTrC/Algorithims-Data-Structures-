// Miguel Trejo 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main(){
	
	char filename[50]; 
	printf("\nEnter file name \n"); 
	scanf("%s", filename); 
	
	FILE * fp = fopen(filename, "r"); 
	if (fp == NULL){
		printf("Unable to open file \n");
		return EXIT_FAILURE; 
		} 
	
	// array that's only purpose is to hold N value, till transferred to int N;
	int tempN[0]; 
	fscanf(fp, "%d", &tempN[0]); 
	int N = tempN[0];
	int *arr = malloc(N * sizeof(int));
	
	// Setting array equal to line 2 of file 
	for(int x = 0; x<N; x++){
		fscanf(fp, "%d", &arr[x]);
	}
	
	//making heap
	struct heap_struct myHeap = make_heap(N, arr);
	
	
	
	
	// will hold the value that will be push/pop line 3 & 4
	int p;
	char op[10]; 
	int castInt;
	
	fscanf(fp, "%d", &tempN[0]); 
	p = tempN[0]; 
	
	for(int x = 0; x<p; x++){
		fscanf(fp, "%s", op);
		
		if( (strcmp("P", op) == 0) || (strcmp("p", op) == 0) ){
			peek(myHeap);
		}
		if( (strcmp("*", op) == 0) ){
			poll(&myHeap);
		}
		else{
			castInt = atoi(op); 
			add(&myHeap, castInt);
		}
	}
	
	free(fp);
	free(arr);
	destroy(&myHeap);
	
	return EXIT_SUCCESS;
}
