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

/* 
// function to insert a new node in a sorted list. E.g.: 
nodePT insert_sorted(nodePT L, nodePT newP);
//or
nodePT insert_sorted(nodePT L, int elem);
//  function to sort an array sing bucket sort. E.g.:
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
	
	//Steps from OneNote
	// Read a file from the User
	// open the file 
	// read the file to get N (size of array)
	
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
	
	for(int x=0; x<N; x++){
		fscanf(fp,"%d", &pArr[x]);
	}
	
	int min = pArr[0];
	int max = pArr[0];
	
	//Finding the min and max
	for(int x=0; x<N; x++){
		if(min > pArr[x]){
			min = pArr[x];
		}
		if(max < pArr[x]){
			max = pArr[x];
		}
	}
	
	// put the elements from file into the array 
	// print the array 
	
	// call bucket_sort
		//This in itself will have other steps and function calls
	// print array again (should be sorted now)
	printf("\n-------run1 - this is a place holder. You need to edit this function.------ \n");
	
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
