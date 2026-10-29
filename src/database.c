#include <stdio.h>
#include <string.h>

int database_add(const char *name, const char *version)
{
    FILE *file;

    if (name == NULL || version == NULL ||
        strlen(name) == 0 || strlen(version) == 0 ||
        strchr(name, '|') != NULL ||
        strchr(name, '\n') != NULL ||
        strchr(version, '|') != NULL ||
        strchr(version, '\n') != NULL) {
        fprintf(stderr, "Invalid package metadata.\n");
        return 1;
    }

    file = fopen("packages.db", "a");

    if (file == NULL) {
        perror("Could not open package database");
        return 1;
    }

    if (fprintf(file, "%s|%s\n", name, version) < 0) {
        perror("Could not write package database");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close package database");
        return 1;
    }

    printf("Added package: %s %s\n", name, version);
    return 0;
}
