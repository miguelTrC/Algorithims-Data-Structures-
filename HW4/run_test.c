// this will have main()
// ask user for a file[50]

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char filename[50]; 
	printf("\nEnter file name \n"); 
	scanf("%s", filename); 
	
	FILE * fp = fopen(filename, "r"); 
	if (fp == NULL){
		printf("Unable to open file \n");
		return; 
		} 
	
	// array that's only purpose it to hold N value, till transferred to int N;
	int tempN[0]; 
	fscanf("%d", &tempN[0]); 
	int N = tempN[0];
	// int *arr = malloc(N * sizeof(int));
	
	
	// dynamically allocate array using the values from file
	/* line by line values
		N           == amount of vales 
		Values themselves 
		? amout of values that will be push/pop ? 
		the values that are pushed or pop  // 13, push/ *, pop / 
		
		
		? is that a string? place in loop until it recieves that amount?
	
	
		malloc array size of N, allocate each value 
		from (0 to N index). 
		
	*/
	
}
