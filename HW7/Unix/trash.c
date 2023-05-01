// was not getting segFaults but wasnt reading all values nor 
// was it reading anything but the first course of each line


int x =0;
	// comment out for loop?
	//for(int x = 0; x < lines; x++){
	//add a if statement if its not != Null, to continue too.
	
	
	//|| fgets(fileLine, maxLine, fp) != "\n" 
	// works for a single for loop
		while( fgets(fileLine, maxLine, fp) != NULL ){// well it returns a 1 or 0.
		//fgets(fileLine, maxLine, fp); 
		
		token = strtok(fileLine, " "); 
		printf("\n Entered if token == %s \n", token);
		while( (token = strtok(NULL, " ")) != NULL ){
			/* this will get the 2nd course in the line
				x = indx of the row we are in 
				meaning that 
				the 2nd course is a pre-req to x 
				we will have the pre-req as token 
				
				x = colum 
				search (pre-req) = row 
				int[row][colum] = 1 
			//*/
			colum = x; 
			printf("\n inside %d ",x);/*
			row = search(courses, token);
			table[row][colum] = 1; 
			printf(" array[%d][%d]: %d \n", row, colum, table[row][colum]);
			printf(" %s ----> %s \n", courses[row], courses[colum]); */
			}
			x++;
		}
	//}

