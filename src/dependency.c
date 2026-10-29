#include <stdio.h>
#include <string.h>

void dependency_check(const char *name)
{
    FILE *file;
    char line[256];
    int found = 0;

    if (name == NULL || strlen(name) == 0) {
        printf("Invalid package name.\n");
        return;
    }

    file = fopen("packages.db", "r");

    if (file == NULL) {
        printf("No package database found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *separator = strchr(line, '|');

        if (separator != NULL) {
            *separator = '\0';

            if (strcmp(line, name) == 0) {
                found = 1;
                break;
            }
        }
    }

    fclose(file);

    if (found) {
        printf("Package '%s' is recorded in the database.\n", name);
        printf("Dependency resolution is not implemented yet.\n");
    } else {
        printf("Package '%s' is not recorded in the database.\n", name);
    }
}
