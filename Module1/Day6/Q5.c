#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int searchStudentByName(const struct Student* students, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; // Return the index if found
        }
    }
    
    return -1; // Return -1 if not found
}

void displayStudent(const struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Marks: %d\n", student->marks);
}

int main() {
    // Example usage
    struct Student students[] = {
        {"Alice", 85},
        {"Bob", 90},
        {"Charlie", 80}
    };
    
    int size = sizeof(students) / sizeof(students[0]);
    
    const char* searchName = "Bob";
    int index = searchStudentByName(students, size, searchName);
    
    if (index != -1) {
        printf("Student found:\n");
        displayStudent(&students[index]);
    } else {
        printf("Student not found.\n");
    }
    
    return 0;
}
