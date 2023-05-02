#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    char *name;
    struct Course **prerequisites;
    int prereq_count;
} Course;

enum Color { WHITE, GRAY, BLACK };

void DFS(Course *courses, int course_count);
void DFS_visit(Course *courses, int course_count, int u, enum Color *color, int *pred, int *finish, int *time);

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    Course *courses = NULL;
    int course_count = 0;
    char line[1000];

    while (fgets(line, sizeof(line), file)) {
        char *course_name = strtok(line, " \n");
        Course *course = malloc(sizeof(Course));
        course->name = strdup(course_name);
        course->prerequisites = NULL;
        course->prereq_count = 0;

        course_count++;
        courses = realloc(courses, course_count * sizeof(Course));
        courses[course_count - 1] = *course;

        char *prereq_name;
        while ((prereq_name = strtok(NULL, " \n")) != NULL) {
            course->prereq_count++;
            course->prerequisites = realloc(course->prerequisites, course->prereq_count * sizeof(Course *));
            course->prerequisites[course->prereq_count - 1] = malloc(sizeof(Course));
            course->prerequisites[course->prereq_count - 1]->name = strdup(prereq_name);
        }
    }

    fclose(file);

    DFS(courses, course_count);

    for (int i = 0; i < course_count; i++) {
        free(courses[i].name);
        for (int j = 0; j < courses[i].prereq_count; j++) {
            free(courses[i].prerequisites[j]);
        }
        free(courses[i].prerequisites);
    }
    free(courses);

    return 0;
}

void DFS(Course *courses, int course_count) {
    enum Color *color = malloc(course_count * sizeof(enum Color));
    int *pred = malloc(course_count * sizeof(int));
    int *finish = malloc(course_count * sizeof(int));
    int time = 0;

    for (int u = 0; u < course_count; u++) {
        color[u] = WHITE;
        pred[u] = -1;
    }

    for (int u = 0; u < course_count; u++) {
        if (color[u] == WHITE) {
            DFS_visit(courses, course_count, u, color, pred, finish, &time);
        }
    }

    printf("Topological Sort:\n");
    for (int i = course_count - 1; i >= 0; i--) {
        int index = -1;
        int max_finish = -1;

        for (int j = 0; j < course_count; j++) {
            if (finish[j] > max_finish) {
                max_finish = finish[j];
                index = j;
            }
        }

        if (index != -1) {
            printf("%s\n", courses[index].name);
            finish[index] = -1;
       
        }
    }

    free(color);
    free(pred);
    free(finish);
}

void DFS_visit(Course *courses, int course_count, int u, enum Color *color, int *pred, int *finish, int *time) {
    color[u] = GRAY;
    (*time)++;
    
    for (int i = 0; i < courses[u].prereq_count; i++) {
        int y = -1;
        
        for (int j = 0; j < course_count; j++) {
            if (strcmp(courses[u].prerequisites[i]->name, courses[j].name) == 0) {
                y = j;
                break;
            }
        }

        if (y != -1 && color[y] == WHITE) {
            pred[y] = u;
            DFS_visit(courses, course_count, y, color, pred, finish, time);
        }
    }
    
    color[u] = BLACK;
    finish[u] = ++(*time);
}
