#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure definition to store student data
struct Student {
    int studentID;
    char name[100];
    char course[50];
};

// Function to generate a random Student ID between 100000 and 999999
int generateStudentID() {
    return rand() % 900000 + 100000;
}

int main() {
    struct Student student;

    // Initialize the seed for random number generation
    srand(time(NULL));
    student.studentID = generateStudentID();

    // Register student's name
    printf("Enter student name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Removes the trailing newline

    // Register student's course/major
    printf("Enter student course: ");
    fgets(student.course, sizeof(student.course), stdin);
    student.course[strcspn(student.course, "\n")] = '\0'; // Removes the trailing newline

    // Display registered data
    printf("\n=== Student Successfully Registered ===\n");
    printf("Student ID: %d\n", student.studentID);
    printf("Name:       %s\n", student.name);
    printf("Course:     %s\n", student.course);

    return 0;
}
