#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_COURSE_LENGTH 30
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_COURSES 100

struct Vertex {
    char name[MAX_COURSE_LENGTH];
    int inDegree;
    int startTime;
    int finishTime;
    struct Vertex* adjList[MAX_NUM_COURSES];
};

int time = 0;

// Perform depth-first search to compute start and finish times
void DFS_visit(struct Vertex* vertex) {
    time++;
    vertex->startTime = time;
    for (int i = 0; i < MAX_NUM_COURSES && vertex->adjList[i] != NULL; i++) {
        if (vertex->adjList[i]->startTime == 0) {
            DFS_visit(vertex->adjList[i]);
        }
    }
    time++;
    vertex->finishTime = time;
}

// Perform topological sorting and print order of courses to be taken
void topologicalSort(struct Vertex** graph, int numVertices, char** sortedCourses) {
    // Initialize a queue and an array to store the sorted order of courses
    struct Vertex** queue = malloc(numVertices * sizeof(struct Vertex*));
    int queueFront = 0, queueRear = 0;
    int sortedIndex = 0;

    // Compute the in-degree of each vertex
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; graph[i]->adjList[j] != NULL; j++) {
            graph[i]->adjList[j]->inDegree++;
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < numVertices; i++) {
        if (graph[i]->inDegree == 0) {
            queue[queueRear++] = graph[i];
        }
    }

    // Perform topological sort
    while (queueFront != queueRear) {
        struct Vertex* current = queue[queueFront++];
        sortedCourses[sortedIndex++] = malloc(strlen(current->name) + 1);
		strcpy(sortedCourses[sortedIndex], current->name);
        sortedIndex++;

        // Decrement the in-degree of all vertices adjacent to current
        for (int i = 0; i < MAX_NUM_COURSES && current->adjList[i] != NULL; i++) {
            current->adjList[i]->inDegree--;

            // Enqueue any vertices with in-degree 0
            if (current->adjList[i]->inDegree == 0) {
                queue[queueRear++] = current->adjList[i];
            }
        }
    }

    // Compute start and finish times for each vertex
    for (int i = 0; i < numVertices; i++) {
        if (graph[i]->startTime == 0) {
            DFS_visit(graph[i]);
        }
    }

    // Print out start and finish times for each vertex
    printf("Vertex\tStart Time\tFinish Time\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%s\t%d\t\t%d\n", graph[i]->name, graph[i]->startTime, graph[i]->finishTime);
    }

    // Print out order in which courses should be taken
    printf("Courses to be taken:\n");
// Print out the sorted order of courses
for (int i = 0; i < numVertices; i++) {
printf("%s\n", sortedCourses[i]);
}
// Free memory allocated for queue and sortedCourses
free(queue);
for (int i = 0; i < numVertices; i++) {
    free(sortedCourses[i]);
}
}

int main() {
// Prompt user to enter input file name
char filename[MAX_FILENAME_LENGTH];
printf("Enter name of input file: ");
scanf("%s", filename);
// Open input file
FILE* inputFile = fopen(filename, "r");
if (inputFile == NULL) {
    printf("Could not open file.\n");
    return 1;
}

// Read in course information from input file
int numVertices = 0;
struct Vertex* graph[MAX_NUM_COURSES];
char* courseNames[MAX_NUM_COURSES];
char line[MAX_LINE_LENGTH];
while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
    char* token = strtok(line, ",");
    struct Vertex* vertex = malloc(sizeof(struct Vertex));
    strcpy(vertex->name, token);
    vertex->inDegree = 0;
    vertex->startTime = 0;
    vertex->finishTime = 0;
    int numAdj = 0;
    while ((token = strtok(NULL, ",")) != NULL) {
        vertex->adjList[numAdj++] = malloc(sizeof(struct Vertex));
        strcpy(vertex->adjList[numAdj - 1]->name, token);
        vertex->adjList[numAdj - 1]->inDegree = 0;
        vertex->adjList[numAdj - 1]->startTime = 0;
        vertex->adjList[numAdj - 1]->finishTime = 0;
    }
    graph[numVertices++] = vertex;
    courseNames[numVertices - 1] = vertex->name;
}
fclose(inputFile);

// Link vertices in graph using adjacency lists
for (int i = 0; i < numVertices; i++) {
    for (int j = 0; graph[i]->adjList[j] != NULL; j++) {
        for (int k = 0; k < numVertices; k++) {
            if (strcmp(graph[k]->name, graph[i]->adjList[j]->name) == 0) {
                graph[i]->adjList[j] = graph[k];
                break;
            }
        }
    }
}

// Perform topological sort and print order of courses to be taken
char* sortedCourses[MAX_NUM_COURSES];
topologicalSort(graph, numVertices, sortedCourses);

// Free memory allocated for graph and courseNames
for (int i = 0; i < numVertices; i++) {
    free(graph[i]);
    free(courseNames[i]);
}

return 0;
}




