#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char* token;
    char* rest = strdup(input);  // Create a copy of the input string
    
    // Parse the string and initialize the array of structures
    for (int i = 0; i < size; i++) {
        // Extract rollno
        token = strtok_r(rest, " ", &rest);
        students[i].rollno = atoi(token);
        
        // Extract name
        token = strtok_r(rest, " ", &rest);
        strcpy(students[i].name, token);
        
        // Extract marks
        token = strtok_r(rest, " ", &rest);
        students[i].marks = atof(token);
    }
    
    // Free the allocated memory
    free(rest);
}

int main() {
    int size;
    char input[100];
    
    printf("Enter the number of students: ");
    scanf("%d", &size);
    
    // Consume the newline character left by scanf
    getchar();
    
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the trailing newline character from fgets
    input[strcspn(input, "\n")] = '\0';
    
    parseString(input, students, size);
    
    printf("\nInitialized array of structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    
    free(students);
    
    return 0;
}
