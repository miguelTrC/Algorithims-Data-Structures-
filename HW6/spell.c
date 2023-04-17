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
    	fillTable(table, first_string, second_string, strOne, strTwo);
    	int editDistance = table[strOne-1][strTwo-1];
    	// removing -1 will get seg fault at return
    	
    	
    	
    if(print_table == 1){
    	printTable(table, first_string, second_string, strOne-1, strTwo-1);
    }
    else{
    	//don't print table
    } 
    
    freeTable(table, strOne);
    return editDistance;  // edit distance // return last indx
}

/*
Parameters:
  - testname - string containing the name of the file with the paragraph to spell check, includes file extenssion e.g. "text1.txt" 
  - dictname - name of file with dictionary words. Includes file extenssion, e.g. "dsmall.txt"
Behavior: If any of the files cannot be open displays a message and returns. (Does not exit the program.)
*/
void spell_check(char * testname, char * dictname){
    
    FILE *fp = fopen(testname, "r");
    if(fp == NULL){
    	printf("\nCould not open dictionary\n");
    	return; 
    }
    	/* Store the first word into a string, and cast into int
    		use that int in a for loop,
    			inside this loop we will: 
    			
    			store the next word into the string, 
    			we will use that string1 
    				inside another loop:
    					we will read (until EOF of dictionary)
    					read the word on dictionary file and store 
    					into string2, 
    					
    					find the edit distance between String1 and String2
    					// int min to keep track of lowest edit distance
    					if (edit distance ^ < min)
    						min = edit distance 
    			
    			once done with going thru dictionary, 
    			do it again, except this time, print/keep track 
    			of the words that had the min edit distance
    			and give user option between choosing one of these
    			words
    			
    			exit this loop, (onto the outest loop)
    			and store the next word from testname onto string1		
    					
    					 
    					
    		
    	*/
    
    /* EACH (testname) FILE HAS AMOUNT OF WORDS AS FIRST line
    
    	dictname == dictionary file
    	testname == has list of words we will find the least edit distance, 
    				(its gonna be multiple words)
    
    	what if i just store the edit distance to a int array, 
    	corresponding to the index of the dictionary. once at end, //
    	print the indx's that have lowest edit distance, use those indx's
    	to file[x] words? 
    	
    	// int[x] = 3 
    	//lowest = 3
    	//for()
    		if(int[x] < lowest)
    			lowest = int[x]
    			
    	print" the lowest edit distance is %d", lowest
    	RUN THRU FILE AGAIN, if "stringHolder edit distance == lowest"
    	print" here are the word(s) with the edit distance"
    	
    	Will give user options if they want to correct the word from 
    	test name (don't have to do anything besides printf("og word, new"))
    	==1
    	if they choose a different number, keep original word
    	
    	from the list of words with lowest edit distance, we will have to set up
    	print statements and give the user option to choose between the words
    	
    	
    	
    	
    */
    
    
    free(fp);
    // Write your code here
    /* 1st file is dictionary 
    	2nd is the word(s) looking for
    	find the what is most similiar to the word(s) 
    	//least amount of edit distance
    */
    
    /*
    	Open the file (testname), 
    	//might be messy but can malloc for each word in 
    	// in file, keeping 'dictname' the same 
    	read in the word onto a 'string2'
    	calculate edit distance // 2d char array (strings?)
    	
    	keep that edit distance as lowest, until a lower edit distance
    	comes along, 
    	if multiple words of edit distance, keep thos, 
    	if a new low comes after multiple strings stored, erase all previous 
    	
    	when all words from 'testname', computed, print the string array
    

    
    */
}

