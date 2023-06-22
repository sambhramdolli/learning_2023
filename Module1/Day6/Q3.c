#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void displayMembers(const struct Person* members, int size) {
    for (int i = 0; i < size; i++) {
        printf("Member %d:\n", i + 1);
        printf("Name: %s\n", members[i].name);
        printf("Age: %d\n", members[i].age);
        printf("\n");
    }
}

int main() {
    // Example usage
    struct Person members[] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };
    
    int size = sizeof(members) / sizeof(members[0]);
    displayMembers(members, size);
    
    return 0;
}
