#include <stdio.h>

// Constants
#define SUBJECTS 5

// Structure for storing name
struct Name {
    char first[50];
    char middle[50];
    char last[50];
};

// Structure for storing marks
struct Marks {
    float subjects[SUBJECTS];
};

// Structure for storing student information
struct Student {
    struct Name name;
    int rollNumber;
    struct Marks semester1;
    struct Marks semester2;
};

void displayMarksheet(struct Student student);

int main() {
    struct Student student;

    // Input student details
    printf("Enter the first name of the student: ");
    scanf("%s", student.name.first);
    printf("Enter the middle name of the student: ");
    scanf("%s", student.name.middle);
    printf("Enter the last name of the student: ");
    scanf("%s", student.name.last);

    printf("Enter the roll number of the student: ");
    scanf("%d", &student.rollNumber);

    // Input marks for semester 1
    printf("Enter the marks of the student in semester 1:\n");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.semester1.subjects[i]);
    }

    // Input marks for semester 2
    printf("Enter the marks of the student in semester 2:\n");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.semester2.subjects[i]);
    }

    // Display the marksheet
    displayMarksheet(student);

    return 0;
}

void displayMarksheet(struct Student student) {
    printf("\n------------- Marksheet -------------\n");
    printf("Name: %s %s %s\n", student.name.first, student.name.middle, student.name.last);
    printf("Roll Number: %d\n", student.rollNumber);
    
    printf("Semester 1 Marks:\n");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: %.2f\n", i + 1, student.semester1.subjects[i]);
    }
    
    printf("Semester 2 Marks:\n");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: %.2f\n", i + 1, student.semester2.subjects[i]);
    }
    printf("-------------------------------------\n");
}
