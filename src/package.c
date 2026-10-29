#include <stdio.h>
#include <string.h>

void package_info(const char *name)
{
    if (name == NULL || strlen(name) == 0) {
        printf("Invalid package name.\n");
        return;
    }

    printf("Package: %s\n", name);
    printf("Status: Not installed\n");
    printf("Version: Unknown\n");
    printf("Description: No metadata available.\n");
}

void package_list(void)
{
    FILE *file = fopen("packages.db", "r");
    char line[256];

    if (file == NULL) {
        printf("No package database found.\n");
        return;
    }

    printf("Installed packages:\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
