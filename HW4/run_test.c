
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	//can delete printf
	printf("\nN = %d\n", N);
	
	// Setting array equal to line 2 of file 
	for(int x = 0; x<N; x++){
		fscanf(fp, "%d", &arr[x]);
		// delete printf, using to make sure its working 
			printf("\n\n array %d = %d", x, arr[x]);
	}
	
	// will hold the value that will be push/pop line 3 & 4
	int p;
	char op[10]; 
	int castInt;
	
	fscanf(fp, "%d", &tempN[0]); 
	p = tempN[0]; 
	
	
	for(int x = 0; x<p; x++){
		fscanf(fp, "%s", op);
		// how to tell if its a int or a p, P, *? 
			// Use AISC? 
		
		if( (strcmp("P", op) == 0) || (strcmp("p", op) == 0) ){
			printf("\n Indx:%d peek %s \n", x, op);
		}
		if( (strcmp("*", op) == 0) ){
			// pop 
			printf("\n Indx:%d pop %s \n", x,op);
			
		}
		else{
			castInt = atoi(op); 
			printf("\n Indx:%d int %d \n", x, castInt);
		}
	}
	
		
		
	//free() will be used in one of the functions from heap
	
	return EXIT_SUCCESS;
}
