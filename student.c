#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

// Function to add student
void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct Student s;

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);  // safe input

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
