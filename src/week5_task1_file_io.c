// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];
    int linecount = 0;

    printf("Enter filename (or press Enter to use default 'data.txt'): ");
    fgets(filename, sizeof(filename), stdin);

    if (filename[0] != '\n') {
        size_t len = 0;
        while (filename[len] != '\0') {
            if (filename[len] == '\n') {
                filename[len] = '\0';
                break;
            }
            len++;
        }
    } else {
        snprintf(filename, sizeof(filename), "data.txt");
    }

    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    printf("\nWriting to file '%s'...\n", filename);

    fprintf(fp, "Hello, this is line 1.\n");
    fprintf(fp, "This is line 2.\n");
    fprintf(fp, "File I/O in C is fun!\n");

    fclose(fp);
    printf("Finished writing.\n");

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("\nReading from file '%s':\n", filename);

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        lineCount++;
    }

    fclose(fp);

    printf("\n\nTotal lines read: %d\n", lineCount);

    return 0;
}