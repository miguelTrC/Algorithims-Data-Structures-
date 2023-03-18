
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char filename[50]; 
	printf("\nEnter file name \n"); 
	scanf("%s", filename); 
	
	FILE * fp = fopen(filename, "r"); 
	if (fp == NULL){
		printf("Unable to open file \n");
		//return; 
		} 
	
	// array that's only purpose is to hold N value, till transferred to int N;
	int tempN[0]; 
	fscanf(fp, "%d", &tempN[0]); 
	int N = tempN[0];
	int *arr = malloc(N * sizeof(int));
	
	for(int x = 0; x<N; x++){
		fscanf(fp, "%d", &arr[x]);
		// delete printf, using to make sure its working 
			printf("\n\n array %d = %d", x, arr[x]);
	}
	
	
		
		
	//free() will be used in one of the functions from heap
	
	return EXIT_SUCCESS;
}
