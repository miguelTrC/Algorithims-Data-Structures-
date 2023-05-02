//Miguel Trejo 1001685532
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


//Has the string array of first course
// Vertices is the table showing the vertices 
//   lines is the size of the arrays (# of lines in file)
int *DFS_visit(char **courses, int** vertices, int lines){
	int visited = 0; //0 = white, 1 = grey, 2 = black
	int *stack; 
	for (int x = 0; x < lines; x++){
		printf("\n Looking at %s ",courses[x]); 
		printf(" \n this course is a Pre-req to: ");
		for (int y = 0; y < lines; y++){
			if(vertices[x][y] == 1){
				printf(" %s ", courses[y]);
				visited++; 
				if(visited == 2){
					stack[x] = vertices[x][y]; 
				}
			}
		}
		//DFS_visit()
		if(visited == 1){
		printf("\n Cycle found");
		}
	}
	return (stack); 
}

int *tropological(int *stack, int lines){
	//reversing DFS 
	int *values; 
	int temp;
	for(int x = 0; x < lines; x++){
		temp = stack[lines - x]; 
		values[x] = temp; 
	}
	return (values); 
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
		printf(" Line:%d course: %s \n ",lines, token); 
		lines++;
	}
	
	//Dynamically allocate int and string
	int **table = createTable(lines, lines); 
	char **courses = createString(lines, maxStr);
	
	fseek(fp, 0, SEEK_SET); //Resets file pointer
	
	// this copies the first course in each line onto courses
	for(int x = 0; x < lines; x++){
		fgets(fileLine, maxLine, fp); 
		token = strtok(fileLine, " "); 
		strcpy(courses[x], token); 
		printf(" %d : %s \n", x, courses[x]);
	}
	
	
	//filling int array

	int colum; 
	int row; 
	int current = 0;
	int temp = 0;
	char holder[maxStr];
	fseek(fp, 0, SEEK_SET);
	
		
	for(int x = 0; x < lines; x++){
		fgets(fileLine, maxLine, fp); 
		token = strtok(fileLine, " "); 
		while( (token = strtok(NULL, " ")) != NULL ){
			/* this will get the 2nd course in the line
				x = indx of the row we are in 
				meaning that 
				the 2nd course is a pre-req to x 
				we will have the pre-req as token 
				
				x = colum 
				search (pre-req) = row 
				int[row][colum] = 1 
			// */
			colum = x; 
			row = search(courses, token);
			table[row][colum] = 1; 
			printf(" array[%d][%d]: %d \n", row, colum, table[row][colum]);
			printf(" %s ----> %s \n", courses[row], courses[colum]);
			}
	} 
	
	
	
	
		/*
	// Retrieves each individual course (had to read each character due to strtok errors)
	while (fgets(fileLine, maxLine, fp)) {
        if (fileLine[0] == '\n'){
        	return EXIT_FAILURE;
        }
        int idx = 0;
        int x = 0;
        while (fileLine[idx]) {
            if ( (fileLine[idx] != ' ') && (fileLine[idx] != '\n') ){
                holder[x++] = fileLine[idx++];
            } 
            else{
                holder[x] = '\0';
                x = 0;
                idx++;
            }
            //printf(" \n Final result %s ",holder);
        }
        printf(" \n Final result %s  %d",holder,current);
        temp = search(courses, holder); 
        
        
        current++;
    }
	*/

	
	
	fclose(fp); 
	freeTable(table, lines);
	freeString(courses, lines);
	
	return EXIT_SUCCESS; 
}
