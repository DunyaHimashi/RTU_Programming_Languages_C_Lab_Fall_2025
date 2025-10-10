/*
 * week4_3_struct_database.c
 * Author: Dunya Himashi Thilakarathne
 * Student ID: 241ADB035
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d (name id grade): ", i + 1);
        if (scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            printf("Invalid input.\n");
            free(students); 
        }
    }

    printf("\n%-6s %-15s %-6s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-15s %-6.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("\nAverage grade: %.2f\n", total / n);

    free(students);

    return 0;
}