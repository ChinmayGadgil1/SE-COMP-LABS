//23B-CO-015
#include <stdio.h>
#include <string.h>

int PR_NUM=202311095;
char ROLL_NUM[]="23B-CO-015";
void footer(){
    printf("\n================================\n");
    printf("PR NUMBER: %d\n", PR_NUM);
    printf("ROLL NUMBER: %s ",ROLL_NUM);
    printf("\n================================\n");

}


struct PersonalName {
    char givenName[20];
    char middleInitial[20];
    char surname[20];
};

struct Course {
    char code[10];
    int score;
    char letterGrade[2];
    int creditHours;
};

struct Term {
    int termNumber;
    struct Course courses[4];
    float termGPA;
};

struct Pupil {
    int id;
    struct PersonalName completeName;
    struct Term terms[2];
    float cumulativeGPA;
};

char assignGrade(int score) {
    if (score >= 85) {
        return 'O';
    } else if (score >= 75) {
        return 'A';
    } else if (score >= 65) {
        return 'B';
    } else if (score >= 55) {
        return 'C';
    } else if (score >= 45) {
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

float computeGPA(struct Term *term) {
    int totalCreditHours = 0;
    int totalGradePoints = 0;
    for (int i = 0; i < 4; i++) {
        int gradePoints = gradeToPoints(term->courses[i].letterGrade[0]);
        totalGradePoints += gradePoints * term->courses[i].creditHours;
        totalCreditHours += term->courses[i].creditHours;
    }
    return (float) totalGradePoints / totalCreditHours;
}

float computeCumulativeGPA(struct Pupil *pupil) {
    float totalGPA = 0;
    for (int i = 0; i < 2; i++) {
        totalGPA += pupil->terms[i].termGPA;
    }
    return totalGPA / 2.0;
}

void getInput(struct Pupil *pupil) {
    printf("Enter student's first name: ");
    scanf("%19s", pupil->completeName.givenName);
    printf("Enter student's middle name: ");
    scanf("%19s", pupil->completeName.middleInitial);
    printf("Enter student's last name: ");
    scanf("%19s", pupil->completeName.surname);

    printf("Enter student's roll number: ");
    scanf("%d", &pupil->id);

    for (int term = 0; term < 2; term++) {
        printf("Enter courses and marks for term %d\n", term + 1);
        for (int i = 0; i < 4; i++) {
            printf("Enter course %d code: ", i + 1);
            scanf("%9s", pupil->terms[term].courses[i].code);
            printf("Enter course %d marks: ", i + 1);
            scanf("%d", &pupil->terms[term].courses[i].score);
            printf("Enter course %d credit hours: ", i + 1);
            scanf("%d", &pupil->terms[term].courses[i].creditHours);
            pupil->terms[term].courses[i].letterGrade[0] = assignGrade(pupil->terms[term].courses[i].score);
            pupil->terms[term].courses[i].letterGrade[1] = '\0';
        }
        pupil->terms[term].termGPA = computeGPA(&pupil->terms[term]);
    }

    pupil->cumulativeGPA = computeCumulativeGPA(pupil);
}

void displayInfo(struct Pupil pupil) {
    printf("\nStudent Information:\n");
    printf("Name: %s %s %s\n", pupil.completeName.givenName, pupil.completeName.middleInitial, pupil.completeName.surname);
    printf("Roll No: %d\n", pupil.id);

    for (int term = 0; term < 2; term++) {
        printf("\nTerm %d:\n", term + 1);
        printf("%-15s%-10s%-10s%-10s\n", "Course Code", "Marks", "Grade", "Credits");
        printf("-----------------------------------------\n");
        for (int i = 0; i < 4; i++) {
            printf("%-15s%-10d%-10s%-10d\n", pupil.terms[term].courses[i].code, pupil.terms[term].courses[i].score, pupil.terms[term].courses[i].letterGrade, pupil.terms[term].courses[i].creditHours);
        }
        printf("SGPA: %.2f\n", pupil.terms[term].termGPA);
    }

    printf("\nCGPA: %.2f\n", pupil.cumulativeGPA);
}

int main() {
    struct Pupil pupil;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add student data\n");
        printf("2. Display data\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getInput(&pupil);
                break;
            case 2:
                displayInfo(pupil);
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
