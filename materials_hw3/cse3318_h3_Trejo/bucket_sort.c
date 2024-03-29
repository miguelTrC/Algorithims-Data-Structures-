/* 
 * Updated 2/23/2023 - Alexandra Stefan
 */

/* 
compile with -g to collect debugging info needed for Valgrind ( -lm links the math library): 
gcc -g bucket_sort.c list.c -lm

run with Valgrind:
valgrind --leak-check=full ./a.out

On some systems, but not all, you can also use the --show-leak-kinds=all flag:
valgrind --leak-check=full --show-leak-kinds=all ./a.out

run without Valgrind:
./a.out
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"   // useful if you want to use functions from list.c

void print_array(int arr[], int N);
void run1();

// my functions 
/* Notes: seg fault caused during returnFloor, for files that have a repeating 
		value, unable to finish fixing error before due date
		 i did however code functions that would create the nodes
		and insert into a link list, along with insertion sort 
		of link list as nodes where inserted
*/
int returnFloor(int arrIdx, int min, int max, int N){

	int floor; 
		
	floor = (arrIdx - min) * N; 
	floor = floor / (1 + max - min); 
	
	return floor; 
}


nodePT insert_sorted(nodePT L, int elem){
	
	nodePT new = new_node(elem); 
	nodePT current = L; 
	nodePT prev = NULL; 

	if(L == NULL || L->data > elem){
		new->next = L;
		L = new;
	}	
	else{
		while(current != NULL && current->data < elem){
			prev = current; 
			current = current->next; 
		}
		new->next = current; 
		prev->next = new;
	}
	
	return L;
}

// 
void bucket_sort(int *arr, int N){
// Try N+1? 

	nodePT B[N]; 
	for(int x=0; x<N; x++){
		B[x] = NULL;
	} 
	
	int min = arr[0];
	int max = arr[0];
	
	//Finding the min and max
	for(int x=0; x<N; x++){
		if(min > arr[x]){
			min = arr[x];
		}
		if(max < arr[x]){
			max = arr[x];
		}
	}
	printf("\n Min:%d  Max:%d \n\n", min, max);
	
	//testing N
	printf("\n\n\n\n N = %d \n\n\n\n", N);
	
	int floor;
	for(int x=0; x<N; x++){
		
		floor = returnFloor(arr[x], min, max, N);
		B[floor] = insert_sorted(B[floor], arr[x]);
		printf("\n %d has a floor of %d \n", arr[x], floor);
	}
	
	int count = 0; 
	for(int x=0; x<N; x++){
		nodePT current = B[x];

		while(current != NULL){
			arr[count] = current->data;
			count++;
			current = current->next;
		}
	
	destroy_list(B[x]);
	}
	

	
	
	
}


/* 
// function to insert a new node in a sorted list. E.g.: 
nodePT insert_sorted(nodePT L, nodePT newP);
//or
nodePT insert_sorted(nodePT L, int elem);
//  function to sort an array using bucket sort. E.g.:
void bucket_sort(int * arr, int N);
*/


void print_array(int arr[], int N){
	int j;
	printf("\n array: ");
	for(j= 0; j<N; j++){
		printf("%5d,", arr[j]);
	}
	printf("\n");
}

//-------------------------------------------------------------

void run1(){
	// Fill in your code here. You should not write everything in this function.  
	// Write some helper functions to separate the work.	
	
	
	// Getting Filename from user and opening the file
	printf("\n\n Enter a filename: "); 
	char fileName[100]; 
	scanf("%s", fileName); 
	
	FILE *fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("\n Unable to open file \n");
		return; 
	}
	
	// making a array to hold the scanned value, then copying over to N
	int arrayN[1]; 
	fscanf(fp,"%d", &arrayN[0]);
	
	int N = arrayN[0]; 
	
	
	// create a 1d array of size N
	int *pArr = malloc(N * sizeof(int));
	
	// Inserting ints from file to pArr and printing
	for(int x=0; x<N; x++){
		fscanf(fp,"%d", &pArr[x]);
	}
	
	printf("\n\n Before Bucket \n\n");
	print_array(pArr, N);
	bucket_sort(pArr, N);
	printf("\n\n After Bucket \n\n");
	print_array(pArr, N);
	

	
	// call bucket_sort
		//This in itself will have other steps and function calls
	// print array again (should be sorted now)

	fclose(fp);
	free(pArr);
}

int main()
{
	printf("This program will read a file name, load data for an array from there and print the sorted array.\n");
	printf("The array is sorted using bucket sort.\n");
	printf("This will be repeated as long as the user wants.\n");
	int option;
	do {
		run1();
		printf("\nDo you want to repeat? Enter 1 to repeat, or 0 to stop) ");
		char ch;
		scanf("%d%c",&option, &ch);  // ch is used to remove the Enter from the input buffer
 	} while (option == 1);

   return 0;
}
