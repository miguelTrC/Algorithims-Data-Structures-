
I added the following lines after the while loop that reads from the file:
(AFTER fclose())
```c
printf("\nCourses from file and its pre-reqs:\n");
printf("Vertex\tCourse\n");
for(int x = 0; x < courseCount; x++){
    printf("%d\t%s: ", x, courses[x].name);
    for(int y = 0; y < courses[x].prereqCount; y++){
        printf("%s", courses[x].prerequisites[y].name);
        if(y < courses[x].prereqCount-1){
            printf(", ");
        }
    }
    printf("\n");
}
