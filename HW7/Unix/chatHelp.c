#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    FILE *file;
    char filename[MAX_LENGTH];
    char **courses;
    int **prerequisites;
    int num_courses = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read file to count number of courses
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file)) {
        num_courses++;
    }

    // Reset file pointer to beginning of file
    fseek(file, 0, SEEK_SET);

    // Allocate memory for courses and prerequisites
    courses = (char **)malloc(num_courses * sizeof(char *));
    prerequisites = (int **)malloc(num_courses * sizeof(int *));
    for (int i = 0; i < num_courses; i++) {
        courses[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        prerequisites[i] = (int *)calloc(num_courses, sizeof(int));
    }

    // Read file to populate courses and prerequisites arrays
    int course_idx = 0;
    while (fgets(line, MAX_LENGTH, file)) {
        // Remove trailing newline character from line
        line[strcspn(line, "\n")] = '\0';

        // Extract course name from line
        char *course = strtok(line, " ");
        strcpy(courses[course_idx], course);

        // Extract prerequisites from line and update prerequisites array
        while ((course = strtok(NULL, " "))) {
            for (int i = 0; i < num_courses; i++) {
                if (strcmp(courses[i], course) == 0) {
                    prerequisites[course_idx][i] = 1;
                    break;
                }
            }
        }

        course_idx++;
    }

    // Print courses and prerequisites arrays
    printf("Courses:\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s\n", courses[i]);
    }

    printf("Prerequisites:\n");
    for (int i = 0; i < num_courses; i++) {
        for (int j = 0; j < num_courses; j++) {
            printf("%d ", prerequisites[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_courses; i++) {
        free(courses[i]);
        free(prerequisites[i]);
    }
    free(courses);
    free(prerequisites);

    // Close file
    fclose(file);

    return 0;
}
