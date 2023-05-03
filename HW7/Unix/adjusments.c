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

        // ADDED: Print prerequisite
        if (y != -1) {
            printf("\nCourse: %s, Prerequisite: %s", courses[u].name, courses[y].name);
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

...

    printf("\nCourses from file and its pre-reqs:\n");
    for (int x = 0; x < courseCount; x++) {
        printf("%d %s: ", x, courses[x].name);
        for (int y = 0; y < courses[x].prereqCount; y++) {
            // ADDED: Fixed prerequisite print statement
            printf("%s", courses[x].prerequisites[y].name);
            if (y < courses[x].prereqCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

...
