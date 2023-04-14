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
int **createTable(int rows, int colums){ //int **createTable? 
	//allocate for int double pointe
	int **array = NULL; 
	
	array = (int**) malloc(rows*(sizeof(int)));
	for(int x=0; x<rows; x++){
		array[x] = (int*) malloc(colums*(sizeof(int)));
	}
	
	return (array);
}

void freeTable(int **table, int rows){
	for(int x=0; x<rows; x++){
		free(table[x]);
	}
	free(table); 
}

//printTable? YES


/*
Parameters:
  - first_string - pointer to the first string (displayed vertical in the table)
  - second_string - pointer to the second string (displayed horizontal in the table)
  - print_table - If 1, the table with the calculations for the edit distance will be printed.
                  If 0 (or any value other than 1)it will not print the table
Return:  the value of the edit distance
*/
int edit_distance(char * first_string, char * second_string, int print_table){
    if(print_table == 1){
    	//(print filled table of calculations) //+1 for the '/0'
    	int strOne = strlen(first_string)+1;   //strOne == rows
    	int strTwo = strlen(second_string)+1;  // strTwo == colums
    	
    	int **table = createTable(strOne, strTwo); 
    	
    	
    }
    else{
    	//don't print table
    }
    return -1;  // edit distance
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

