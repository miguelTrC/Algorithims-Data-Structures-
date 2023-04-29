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


int **createTable(int rows, int colums){
	
	int **array = NULL; 

	array = (int**) malloc(rows*(sizeof(int*)));
	for(int x = 0; x < rows; x++){
		array[x] = (int*) malloc(colums*(sizeof(int)));
		
		for(int j = 0; j < colums; j++){
		array[x][j] = 0; 
		}
	}
	
	return (array);
}

void freeTable(int **table, int rows){
	for(int x = 0; x < rows; x++){
		free(table[x]);
	}
	free(table); 
}

char **createString(int amount, int len){ 
//amount = amount of strings, len = lenght of each string
	char **array = (char **) malloc(amount * sizeof(char *));
	
	for(int x = 0; x < amount; x++){
		array[x] = (char *) malloc(len * sizeof(char));
		array[x][0] = '\0';
	} 
	return (array);
}

void freeString(char **array, int amount){
	for(int x = 0; x < amount; x++){
		free(array[x]);
	}
	free(array);
}


// restarting due to segmentation faults
int main(){
	
	int maxStr = 30;
	int maxLine = 1000;
	int lines = 0; 
	
	char filename[maxStr]; 
	char fileLine[maxLine];
	
	//char course[maxStr];  // even needed? 
	
	char *token;
	
	//Recieving fileName
	printf("\n Enter file name:\n"); 
	fgets(filename, maxStr, stdin);
	removeN(filename);
	//Opening File
	FILE *fp = fopen(filename, "r"); 
	
	if(fp == NULL){
		printf("\n Unable to open file\n"); 
		return EXIT_FAILURE;
	}
	
	// Gets lenght for table
	while ( fgets(fileLine, maxLine, fp) != NULL ){
		token = strtok(fileLine, " ");
		printf("\n %d string: %s \n ",lines, token); 
		lines++;
	}
	
	//Dynamically allocate int and string
	int **table = createTable(lines, lines); 
	char **courses = createString(lines, maxStr);
	
	
	
	
	
	free(fp); 
	freeTable(table, lines);
	freeString(courses, lines);
	
	
	return EXIT_SUCCESS; 
}
