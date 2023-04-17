#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// COMPUTE TC USING VARIABLE FROM HW6 PAGE
#include "spell.h"

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta(............)


Worst case to do an unsuccessful binary search in a dictionary with D words, when 
all dictionary words and the searched word have length MAX_LEN 
Student answer:  Theta(............)
*/


/* Write helper functions here */
int **createTable(int rows, int colums){
	int **array = NULL; 
							// allocating sizeof int or int*?
	array = (int**) malloc(rows*(sizeof(int*)));
	for(int x = 0; x < rows; x++){
		array[x] = (int*) malloc(colums*(sizeof(int)));
	}
	
	return (array);
}

void freeTable(int **table, int rows){
	for(int x = 0; x < rows; x++){
		free(table[x]);
	}
	free(table); 
}

//printTable? YES

//if y=0, left + current (inside the algorithim for computing)
	// diagonal == array[y-1][x-1], top == arr[y-1][x], left == arr[y][x-1]
int min(int diagonal, int top, int left){
	int min = top; 
	if(diagonal < min){
		min = diagonal;
	}
	if(left < min){
		min = left;
	}
	
	return min; 
}



// CHANGE TO int()? to return the last value?
void fillTable (int **table, char *stringOne, char *stringTwo, int lenOne, int lenTwo){
	//stringOne == rows(y),  stringTwo == colums(x) 
	// NEED TO ADD THE '/0', WIll be during printTable
	int x; 
	int y;
	int current;
	int minVal;  
	for(y = 0; y < lenOne; y++){
		for(x = 0; x < lenTwo; x++){
			
			if(stringOne[x] != stringTwo[x]){ // ASCII comparison 
						current = 1; 
					}
					else{
						current = 0; 
					} 
			
			if(y == 0){ //  Diagonal and Top unavailable
				if(x == 0){ // Left unavailable //Only current
					table[y][x] = current; 
				}
					table[y][x] = (table[y][x-1] + current); //Left + Current
			}		
			else if(x == 0){ // if y!=0 but x=0, Left & Diagonal not available 
				//Using top, for all min() parameters
				minVal = min(table[y-1][x], table[y-1][x], table[y-1][x]);
				table[y][x] = (minVal + current);
			}
			else{ // all values available
				minVal = min(table[y-1][x-1], table[y-1][x], table[y][x-1]); 
				table[y][x] = (minVal + current);
				
			}
			
				
		}
	}
	
	
}

void printTable(int **table, char *stringOne, char *stringTwo, int lenOne, int lenTwo){
	printf("\n\n PRINT TABLE \n\n");
	
	printf(" |  | ");
	
	for(int x = 0; x < lenTwo; x++){
		printf("%c| ", stringTwo[x]); 
	}
	printf("\n");
	printf("-----");
			for(int temp = 0; temp < lenTwo; temp++){
				printf("---");
			}
	printf("\n | 0| ");
	
	for(int x = 0; x < lenTwo; x++){
		printf("%d| ", x+1); 
	}
	printf("\n");
	printf("-----");
			for(int temp = 0; temp < lenTwo; temp++){
				printf("---");
			}
	
	for(int y = 0; y < lenOne; y++){
		printf("\n%c| %d|", stringOne[y], y+1);
		
		for(int x = 0; x< lenTwo; x++)
			printf(" %d|", table[y][x]);
			printf("\n");
			printf("-----");
			for(int temp = 0; temp < lenTwo; temp++){
				printf("---");
			}
	}
	printf("\n\n");
	//printf the lenght of str2
}




/*
Parameters:
  - first_string - pointer to the first string (displayed vertical in the table)
  - second_string - pointer to the second string (displayed horizontal in the table)
  - print_table - If 1, the table with the calculations for the edit distance will be printed.
                  If 0 (or any value other than 1)it will not print the table
Return:  the value of the edit distance
*/
int edit_distance(char * first_string, char * second_string, int print_table){
    	
    	int strOne = strlen(first_string)+1;   //strOne == rows
    	int strTwo = strlen(second_string)+1;  // strTwo == colums
    	
    	int **table = createTable(strOne, strTwo); 
    	// make a function to fill table? call it in both if/else
    	fillTable(table, first_string, second_string, strOne, strTwo);
    	int editDistance = table[strOne-1][strTwo-1];
    	printTable(table, first_string, second_string, strOne-1, strTwo-1);
    	
    	freeTable(table, strOne);
    	
    if(print_table == 1){
    	//(print filled table of calculations) //+1 for the '/0'
    	// make a function to fill table? call it in both if/else
    	
    }
    else{
    	//don't print table
    } //try +1?
    // getting seg fault at return (UNLESS i do -1)
    return editDistance;  // edit distance // return last indx
}

/*
Parameters:
  - testname - string containing the name of the file with the paragraph to spell check, includes file extenssion e.g. "text1.txt" 
  - dictname - name of file with dictionary words. Includes file extenssion, e.g. "dsmall.txt"
Behavior: If any of the files cannot be open displays a message and returns. (Does not exit the program.)
*/
void spell_check(char * testname, char * dictname){
    // Write your code here
    /* 1st file is dictionary 
    	2nd is the word(s) looking for
    	find the what is most similiar to the word(s) 
    	//least amount of edit distance
    */
}

