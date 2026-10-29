#include <stdio.h>
#include <string.h>

void package_list(void);
void package_info(const char *name);
void dependency_check(const char *name);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("ForgePM - Simple Package Manager\n");
        printf("Usage:\n");
        printf("  forgepm list\n");
        printf("  forgepm info NAME\n");
        printf("  forgepm deps NAME\n");
        printf("  forgepm version\n");
        return 0;
    }

    if (strcmp(argv[1], "list") == 0) {
        package_list();
    } else if (strcmp(argv[1], "info") == 0 && argc >= 3) {
        package_info(argv[2]);
    } else if (strcmp(argv[1], "deps") == 0 && argc >= 3) {
        dependency_check(argv[2]);
    } else if (strcmp(argv[1], "version") == 0) {
        printf("ForgePM version 0.1.0\n");
    } else {
        printf("Unknown command. Run 'forgepm' for help.\n");
        return 1;
    }

    return 0;
}
