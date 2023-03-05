#include <stdio.h>
#include <stdlib.h>


struct node *info(int val){
	int data = val;
	struct info *Next; // why does removing 'node' make it not compile?
};

int main(int argc, char *argv[]){

	
	
	
//Steps from OneNote // will have the file be argv[1] 
	// Read a file from the User
	// open the file 
	// read the file to get N (size of array)
		/*
		First line in file will be N (the size of the array)
		Second line will be the values of the Array (store them)
		
		*/
	FILE *fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("file didn't open "); 
		// return EXIT_SUCCESS;
	}
	//N needs to be a array to store a SINGLE VALUE, if not it causes an error
	int N[1]; //creating it temp to use
	// retrieves N from file
	

	fscanf(fp,"%d", &N[0]);
	printf("N is %d \n", N[0]);
	
	int temp = N[0];
	printf("temp %d \n", temp);
	
	/*
		Kept recieving errors when storing N onto a non-array index
		so i made another variable to hold same value on a 
		non-array (regular int)
	
	*/
	
	
	
// Will probably need to copy the N[0] onto another variable? 
// 


	// my array of pointers
	int *pArr = malloc(temp * sizeof(int));
	printf("%p \n", pArr);
	

	// do i need to remove [x] and just do pArr++?
	for(int x = 0; x<temp; x++){
		pArr[x] = 1;
		printf("index:%d addy:%p value:%d \n", x, &pArr[x], pArr[x]);
		
	}

	printf("\n Placing file into array \n");
	// places values from file into array
	for(int x = 0; x<temp; x++){
		//dont need to & to place value, since its already giving us the addy
		fscanf(fp, "%d", &pArr[x]); 
		printf("index:%d value:%d \n", x, pArr[x]);
		}
	
	//find min and max 
	int min = pArr[0];
	int max = pArr[0];
	
	printf("\n\n Finding the min and max \n");
	for(int x=0; x<temp; x++){
		if(min > pArr[x]){
			min = pArr[x];
		}
		if(max < pArr[x]){
			max = pArr[x];
		}
		printf("min:%d  max:%d \n", min, max);
	}
	
	

	fclose(fp);
	free(pArr);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

return EXIT_SUCCESS;

}



	
	
	
	
/*
int *pArr[10];
	for(int x = 0; x<=10; x++){
		pArr[x] = NULL;
		printf("%d %p \n", x, &pArr[x]);
	}
	for(int x = 0; x<=10; x++){
		int pArr[x] = //how to declare struct?
		//do i declare struct?
		// do this after sorted array? 
			// or sort array while its in array? 

*/



	// create a 1d array of size N
	/*int *pArr[N]; 
	for(int x=0; x<=N; x++){
		pArr[x] = NULL; 
	} */
	// put the elements from file into the array 
	// print the array 
