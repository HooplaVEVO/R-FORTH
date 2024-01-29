#include <stdio.h>

int main() {
    char* filename = "example.txt";

    FILE* fw = fopen(filename, "w");
    fprintf(fw, "Hello, World!");
    fclose(fw);

    FILE* fr = fopen(filename, "r");
    char line[1024];
    while (fgets(line, sizeof(line), fr) != NULL) {
        printf("%s", line);
    }

    return 0;
}