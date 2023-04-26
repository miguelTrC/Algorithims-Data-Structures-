// COME BACK TO eiteher keep file name or rename to courses_graph_easy.c 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(){
	
	int maxStr = 30;
	int maxLine = 1000;
	char filename[maxStr]; 
	char fileLine[maxLine];
	char course[maxStr];  // even needed? 
	
	// token? 
	
	printf("\n Enter file name:\n"); 
	fgets(filename, maxStr, stdin);
	
	FILE *fp = fopen(filename, "r"); 
	
	if (fp == NULL){
		printf("\n Unable to open file\n"); 
		return EXIT_FAILURE;
	}
	
	char *token;
	
	
	while (fp != NULL){
		fgets(fileLine, maxLine, fp); // put into a loop?
		token = strtok(fileLine, " ");
		
	}
	

	
	/*
		read file from user 
			maxLen of filename = 30 
			maxLen of course = 30 
			maxLenght of each line will be 1,000
			
			
		will use fgets 
		
	*/
	
	
	return EXIT_SUCCESS; 
}
