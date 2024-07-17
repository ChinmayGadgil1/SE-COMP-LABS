#include <stdio.h>
#include <string.h>

struct Name {
    char firstName[20];
    char middleName[20];
    char lastName[20];
};

struct Subject {
    char subjectCode[10];
    int marks;
    char grade[2];
    int credits;
};

struct Semester {
    int semesterNumber;
    struct Subject subjects[4];
    float SGPA;
};

struct Student {
    int rollNumber;
    struct Name fullName;
    struct Semester semesters[2];
    float CGPA;
};

char calculateGrade(int marks) {
    if (marks >= 85) {
        return 'O';
    } else if (marks >= 75) {
        return 'A';
    } else if (marks >= 65) {
        return 'B';
    } else if (marks >= 55) {
        return 'C';
    } else if (marks >= 45) {
        return 'D';
    } else {
        return 'F';
    }
}

int gradeToPoints(char grade) {
    switch (grade) {
        case 'O': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'F': return 0;
        default: return 0;
    }
}

float calculateSGPA(struct Semester *semester) {
    int totalCredits = 0;
    int totalPoints = 0;
    for (int i = 0; i < 4; i++) {
        int gradePoints = gradeToPoints(semester->subjects[i].grade[0]);
        totalPoints += gradePoints * semester->subjects[i].credits;
        totalCredits += semester->subjects[i].credits;
    }
    return (float) totalPoints / totalCredits;
}

float calculateCGPA(struct Student *student) {
    float totalSGPA = 0;
    for (int i = 0; i < 2; i++) {
        totalSGPA += student->semesters[i].SGPA;
    }
    return totalSGPA / 2.0;
}

void inputStudentData(struct Student *student) {
    printf("Enter student's full name: ");
    scanf("%19s%19s%19s", student->fullName.firstName,student->fullName.middleName,student->fullName.lastName);
    printf("Enter student's roll number: ");
    scanf("%d", &student->rollNumber);

    for (int sem = 0; sem < 2; sem++) {
        printf("Enter subjects and marks for semester %d\n", sem + 1);
        for (int i = 0; i < 4; i++) {
            printf("Enter subject %d code: ", i + 1);
            scanf("%9s", student->semesters[sem].subjects[i].subjectCode);
            printf("Enter subject %d marks: ", i + 1);
            scanf("%d", &student->semesters[sem].subjects[i].marks);
            printf("Enter subject %d credits: ", i + 1);
            scanf("%d", &student->semesters[sem].subjects[i].credits);
            student->semesters[sem].subjects[i].grade[0] = calculateGrade(student->semesters[sem].subjects[i].marks);
            student->semesters[sem].subjects[i].grade[1] = '\0';
        }
        student->semesters[sem].SGPA = calculateSGPA(&student->semesters[sem]);
    }

    student->CGPA = calculateCGPA(student);
}

void displayStudentData(struct Student student) {
    printf("\nStudent Information:\n");
    printf("Name: %s %s %s\n", student.fullName.firstName, student.fullName.middleName, student.fullName.lastName);
    printf("Roll No: %d\n", student.rollNumber);

    for (int sem = 0; sem < 2; sem++) {
        printf("\nSemester %d:\n", sem + 1);
        printf("%-15s%-10s%-10s%-10s\n", "Subject Code", "Marks", "Grade", "Credits");
        printf("-----------------------------------------\n");
        for (int i = 0; i < 4; i++) {
            printf("%-15s%-10d%-10s%-10d\n", student.semesters[sem].subjects[i].subjectCode, student.semesters[sem].subjects[i].marks, student.semesters[sem].subjects[i].grade, student.semesters[sem].subjects[i].credits);
        }
        printf("SGPA: %.2f\n", student.semesters[sem].SGPA);
    }

    printf("\nCGPA: %.2f\n", student.CGPA);
}

void displayMenu() {
    
}

int main() {
    
    struct Student student;
    int numStudents = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add student data\n");
        printf("2. Display Data\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                    inputStudentData(&student);
                break;
            case 2:
                    displayStudentData(student);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
