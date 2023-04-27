// COME BACK TO eiteher keep file name or rename to courses_graph_easy.c 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// removes '\n'
void removeN (char *string){
	string[strcspn(string, "\n")] = 0;
}

int main(){
	
	int maxStr = 30;
	int maxLine = 1000;
	char filename[maxStr]; 
	char fileLine[maxLine];
	
	char course[maxStr];  // even needed? 
	
	
	// token? 
	
	printf("\n Enter file name:\n"); 
	fgets(filename, maxStr, stdin);
	
	removeN(filename);
	
	
	printf("\n String recieved: (%s)", filename); 
	
	FILE *fp = fopen(filename, "r"); 
	
	
	
	if(fp == NULL){
		printf("\n Unable to open file\n"); 
		return EXIT_FAILURE;
	}
	
	char *token;
	
	/*	File is opening and repeating last value
	*/
	
	//I mean not what i expected but it works for the first 
	//parameters
	while ( fgets(fileLine, maxLine, fp) != NULL ){
		
		 // put into a loop?
		token = strtok(fileLine, " ");
		
		printf("string: %s \n ", token); 
		
	}
	
	
	
	/*
		read file from user 
			maxLen of filename = 30 
			maxLen of course = 30 
			maxLenght of each line will be 1,000
			
			
		will use fgets 
		
		IF I WANT TO GET RID OF \n in line;
		strName[strcspn(strName, "\n")] = 0 
									^ second string using compared
		
		// cspn returns the indx of the two strings compared, 
		but im using it to replaced said index
	*/
	
	
	return EXIT_SUCCESS; 
}
