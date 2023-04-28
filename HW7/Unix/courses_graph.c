// COME BACK TO eiteher keep file name or rename to courses_graph_easy.c 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// removes '\n'
void removeN (char *string){
	string[strcspn(string, "\n")] = 0;
}

// Will return the indx of the location of pre-req
int search(char **courseList, char *string){
	//strcmp returns =0, if equal
	int index = 0; 
	while ( strcmp(courseList[index], string) != 0 ){
		index++;
	}
	return index; 
}

int main(){
	
	int maxStr = 30;
	int maxLine = 1000;
	char filename[maxStr]; 
	char fileLine[maxLine];
	
	//char course[maxStr];  // even needed? 
	
	char *token;
	
	// token? 
	
	printf("\n Enter file name:\n"); 
	fgets(filename, maxStr, stdin);
	
	removeN(filename);
	
	FILE *fp = fopen(filename, "r"); 
	
	if(fp == NULL){
		printf("\n Unable to open file\n"); 
		return EXIT_FAILURE;
	}
	
	
	
	/*	File is opening and repeating last value
	*/
	
	//I mean not what i expected but it works for the first 
	//parameters
	int x = 0;
	// can repeat loop to find out # of lines == size of array
	// gets size of file for array 
	while ( fgets(fileLine, maxLine, fp) != NULL ){
		
		 // put into a loop?
		token = strtok(fileLine, " ");
		//strcpy(courses[x], token);
		//printf("\n courses[%d]: %s ",x, courses[x]);
		printf("\n %d string: %s \n ",x, token); 
		x++;
		//store token into array
		
	}
	// Dynamically allocate it later? can do lenght too [x][x]
	char *courses[x];
	int table[x][x]; //
	//resetting file pointer 
	fseek(fp, 0, SEEK_SET);
	x = 0;
	//stores values into string array 
	while ( fgets(fileLine, maxLine, fp) != NULL ){
		
		 // put into a loop?
		token = strtok(fileLine, " ");
		strcpy(courses[x], token);
		printf("\n courses[%d]: %s ",x, courses[x]);
		printf("\n %d string: %s \n ",x, token); 
		x++;
		
	}
	
	
	/*
		restart fp 
		
		need to learn how to get a line (fgets), tokenize it
		and be able to use all values in that table, 
		[token1, 2, 3]
		{
		token1==y will be colum arr[][y]
		insert token1 into search() to get y 
		
		after the first token, insert into a loop, until '\n'
			inside this loop token2, ... into search()
			this int return will be our x, arr[x][y] = 1 
		
		
		
		
		
			
	
	*/
	
	
	/*
		Using enum? 
	*/
	
	
	
	
	
	return EXIT_SUCCESS; 
}
