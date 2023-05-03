
I added the following lines after the while loop that reads from the file:

```c
// Printing vertex and course mapping
printf("\nVertex\tCourse\n");
for(int x = 0; x < courseCount; x++){
    printf("%d\t%s\n", x, courses[x].name);
} // after pre-req(if any)

// Printing adjacency matrix
printf("\nEdge Information as Adjacency Matrix:\n");
printf("   ");
for(int x = 0; x < courseCount; x++){
    printf("%s ", courses[x].name);
}
printf("\n");
for(int x = 0; x < courseCount; x++){
    printf("%s ", courses[x].name);
    for(int y = 0; y < courseCount; y++){
        int found = 0;
        for(int z = 0; z < courses[y].prereqCount; z++){
            if(strcmp(courses[x].name, courses[y].prerequisites[z].name) == 0){
                printf("1 ");
                found = 1;
                break;
            }
        }
        if(found == 0){
            printf("0 ");
        }
    }
    printf("\n");
}
``
