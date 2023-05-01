#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_COURSE_LENGTH 30
#define MAX_LINE_LENGTH 1000

int n; // number of courses
int E[MAX_LINE_LENGTH][MAX_LINE_LENGTH]; // adjacency matrix

void dfs(int u, int *visited, int *stack, int *top) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) 
      {
        if (E[u][v] && !visited[v]) {
            dfs(v, visited, stack, top);
        } else if (E[u][v] && visited[v]) {
            printf("Error: the graph contains a cycle.\n");
            exit(1);
        }
    }
    stack[(*top)++] = u;
}

void topological_sort() {
    int visited[MAX_LINE_LENGTH] = {0};
    int stack[MAX_LINE_LENGTH];
    int top = 0;
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, visited, stack, &top);
        }
    }
    //for (int i = n-1; i >= 0; i--) {
       // printf("%d\n", stack[i]+1);
    //}
}

int main() {
    char filename[MAX_FILENAME_LENGTH+1];
    printf("Please enter the filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH+1];
    char courses[MAX_LINE_LENGTH][MAX_COURSE_LENGTH+1];
    int num_courses[MAX_LINE_LENGTH];
    memset(num_courses, 0, sizeof(num_courses));
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n') break;
        int i = 0, j = 0;
        while (line[i]) {
            if (line[i] != ' ' && line[i] != '\n') {
                courses[n][j++] = line[i++];
                printf("\n %s ",courses[n]);
            } else {
                courses[n][j] = '\0';
                num_courses[n]++;
                j = 0;
                i++;
            }
            printf(" \n Final result %s ",courses[n]);
        }
        n++;
    }
    fclose(fp);
    for (int u = 0; u < n; u++) {
        for (int i = 1; i <= num_courses[u]; i++) {
            for (int v = 0; v < n; v++) {
                if (strcmp(courses[u], courses[v]) == 0) continue;
                for (int j = 1; j <= num_courses[v]; j++) {
                    if (strcmp(courses[u], courses[v+j]) == 0) {
                        E[v][u] = 1;
                        break;
                    }
                }
            }
        }
    }
 printf(" \n Number of vertices in built graph: N = %d\n " , n);
printf(" Vertex -course correspondence\n");
for (int i =0; i<n; i++){
   printf(" %-3d- %s\n", i,courses[i]);
 }
printf(" \n Adjacency matrix:\n");
printf("    |");
for(int i=0; i< n; i++){
 printf("%4d", i);
}

printf("\n------------------");

  
   printf("\n");
for (int i=0; i<n; i++)
{
  printf("%4d|", i);
for(int j=0; j<n; j++) 
{
printf("%4d", E[i][j]);
}
printf("\n");
}

    topological_sort();

    return 0;
}
