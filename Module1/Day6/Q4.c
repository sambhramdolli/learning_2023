#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int compareByMarks(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    
    // Sort in descending order
    if (studentA->marks > studentB->marks) {
        return -1;
    } else if (studentA->marks < studentB->marks) {
        return 1;
    }
    
    return 0;
}

void sortStudentsByMarks(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compareByMarks);
}

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    // Example usage
    struct Student students[] = {
        {"Alice", 85},
        {"Bob", 90},
        {"Charlie", 80}
    };
    
    int size = sizeof(students) / sizeof(students[0]);
    sortStudentsByMarks(students, size);
    displayStudents(students, size);
    
    return 0;
}
