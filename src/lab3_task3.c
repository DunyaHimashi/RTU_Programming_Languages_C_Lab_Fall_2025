
/*Lab 3, Task 3
 *Dunya Himashi Thilakarathne - 241ADB035
 */

#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
    // TODO: Test your functions here
    char test[] = "Programming in C";
    char copy[100];

    int len = my_strlen(test);
    printf("Length: %d\n", len);

    my_strcpy(copy, test);
    printf("Copy: %s\n", copy);
    
    char empty [] ="";
    printf("Empty length: %d\n", my_strlen(empty));
    my_strcpy(copy, empty);
    printf("Empty copy: %s\n", copy);

    return 0;
}

// Implement functions below
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length; // placeholder
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] = src[i];){
        dest[i] = src[i];
        i++;
    }
    dest[i]= '\0';
}
