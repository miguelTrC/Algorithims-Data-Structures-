#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// removes '\n'
void removeN(char *string) {
    string[strcspn(string, "\n")] = 0;
}

// Struct that will hold beginning course and its pre-requisites
typedef struct Course {
    char name[30];
    struct Course *prerequisites;
    int prereqCount;
} Course;

// Will be used in DFS
enum Color { WHITE, GRAY, BLACK };

void DFS(Course *courses, int courseCount) {
    enum Color *color = malloc(courseCount * sizeof(enum Color));
    int *pred = malloc(courseCount * sizeof(int));
    int *finish = malloc(courseCount * sizeof(int));
    int visited = 0; // 0=White, 1=Grey, 2=black

    // unvisited vertices
    for (int u = 0; u < courseCount; u++) {
        color[u] = WHITE;
        pred[u] = -1;
    }

    // visiting vertices
    for (int u = 0; u < courseCount; u++) {
        if (color[u] == WHITE) {
            DFS_visit(courses, courseCount, u, color, pred, finish, &visited);
        }
    }

    printf("\nTopological Sort:\n");
    for (int i = courseCount - 1; i >= 0; i--) {
        int idx = -1;
        int maxFinish = -1;

        for (int j = 0; j < courseCount; j++) {
            if (finish[j] > maxFinish) {
                maxFinish = finish[j];
                idx = j;
            }
        }

        if (idx != -1) {
            printf("%s\n", courses[idx].name);
            finish[idx] = -1;
        }
    }

    free(color);
    free(pred);
    free(finish);
}

void DFS_visit(Course *courses, int courseCount, int u, enum Color *color, int *pred, int *finish, int *visited) {
    // Vertix is visited
    color[u] = GRAY;
    (*visited)++;

    // going thru the pre-req courses
    for (int i = 0; i < courses[u].prereqCount; i++) {
        int y = -1;

        // Finding vertices of that lead to current
        for (int j = 0; j < courseCount; j++) {
            if (strcmp(courses[u].prerequisites[i].name, courses[j].name) == 0) {
                y = j;
                break;
            }
        }

        // Performing DFS on the pre-req
        if (y != -1 && color[y] == WHITE) {
            pred[y] = u;
            DFS_visit(courses, courseCount, y, color, pred, finish, visited);
        }
    }

    color[u] = BLACK;
    finish[u] = ++(*visited);
}

int main() {
    int maxStr = 30;
    int maxLine = 1000;

    char filename[maxStr];
    char fileLine[maxLine];

    // Receiving fileName
    printf("\nEnter file name:\n");
    fgets(filename, maxStr, stdin);
    removeN(filename);

    // Opening File
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("\nUnable to open file\n");
        return EXIT_FAILURE;
    }

    Course *courses = NULL;
   
    int courseCount = 0;

    // File reading
    while (fgets(fileLine, maxLine, fp)) {
        char *courseName = strtok(fileLine, " \n");
        Course *course = malloc(sizeof(Course));

        // first token storing
        printf("\nCourse: %s ", courseName);
        strcpy(course->name, courseName);
        course->prerequisites = NULL;
        course->prereqCount = 0;

        // Tracking the amount of vertices
        courseCount++;
        courses = realloc(courses, courseCount * sizeof(Course));
        courses[courseCount - 1] = *course;

        // Assigning pre-reqs(if any)
        char *prereqName;
        while ((prereqName = strtok(NULL, " \n")) != NULL) {
            course->prereqCount++;
            course->prerequisites = realloc(course->prerequisites, course->prereqCount * sizeof(Course));
            strcpy(course->prerequisites[course->prereqCount - 1].name, prereqName);
        }
    }

    fclose(fp);

    printf("\nCourses from file and its pre-reqs:\n");
    for (int x = 0; x < courseCount; x++) {
        printf("%d %s: ", x, courses[x].name);
        for (int y = 0; y < courses[x].prereqCount; y++) {
            printf("%s", courses[x].prerequisites[y].name);
            if (y < courses[x].prereqCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    DFS(courses, courseCount);

    for (int x = 0; x < courseCount; x++) {
        for (int z = 0; z < courses[x].prereqCount; z++) {
            free(courses[x].prerequisites);
        }
    }
    free(courses);

    return EXIT_SUCCESS;
}
