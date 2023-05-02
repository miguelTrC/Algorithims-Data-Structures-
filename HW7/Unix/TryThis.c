#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 100

typedef struct Course Course;
struct Course {
    char name[10];
    int num_prereqs;
    Course *prereqs[MAX_COURSES];
    char color[6];
};

void DFS_visit(Course *G[], int u, char *color[], Course *pred[], Course *black[], int *num_black) {
    color[u] = "gray";
    for (int i = 0; i < G[u]->num_prereqs; i++) {
        Course *v = G[u]->prereqs[i];
        if (strcmp(color[v->name], "white") == 0) {
            pred[v->name] = G[u];
            DFS_visit(G, v->name, color, pred, black, num_black);
        } else if (strcmp(color[v->name], "gray") == 0) {
            printf("Cycle detected between courses %s and %s\n", G[u]->name, v->name);
        }
    }
    color[u] = "black";
    black[*num_black] = G[u];
    (*num_black)++;
}

void DFS(Course *G[], int n, char *color[], Course *pred[], Course *black[], int *num_black) {
    for (int i = 0; i < n; i++) {
        color[G[i]->name] = "white";
        pred[G[i]->name] = NULL;
    }
    for (int i = 0; i < n; i++) {
        if (strcmp(color[G[i]->name], "white") == 0) {
            DFS_visit(G, G[i]->name, color, pred, black, num_black);
        }
    }
}

int main() {
    char buffer[256];
    Course *courses[MAX_COURSES];
    char *color[MAX_COURSES];
    Course *pred[MAX_COURSES];
    Course *black[MAX_COURSES];
    int num_black = 0;
    int num_courses = 0;

    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        char *token = strtok(buffer, " ");
        Course *course = malloc(sizeof(Course));
        strcpy(course->name, token);
        course->num_prereqs = 0;
        course->color[0] = '\0';

        while ((token = strtok(NULL, " "))) {
            Course *prereq = malloc(sizeof(Course));
            strcpy(prereq->name, token);
            prereq->num_prereqs = 0;
            prereq->color[0] = '\0';
            course->prereqs[course->num_prereqs++] = prereq;
        }

        courses[num_courses++] = course;
    }

        fclose(fp);

    for (int i = 0; i < num_courses; i++) {
        Course *course = courses[i];
        for (int j = 0; j < course->num_prereqs; j++) {
            char *name = course->prereqs[j]->name;
            for (int k = 0; k < num_courses; k++) {
                if (strcmp(courses[k]->name, name) == 0) {
                    courses[k]->prereqs[courses[k]->num_prereqs++] = course;
                    break;
                }
            }
        }
    }

    DFS(courses, num_courses, color, pred, black, &num_black);

    printf("Topological order:\n");
    for (int i = num_black - 1; i >= 0; i--) {
        printf("%s\n", black[i]->name);
    }

    for (int i = 0; i < num_courses; i++) {
        free(courses[i]);
    }

    return EXIT_SUCCESS;
}
