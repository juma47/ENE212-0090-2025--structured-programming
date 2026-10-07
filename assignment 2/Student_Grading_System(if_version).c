/*
 * PSEUDOCODE:
 *
 * MAIN:
 *   Prompt and read student_count. Exit if invalid.
 *
 *   FOR count = student_count TO count 0:
 *     Prompt and read name, reg_no, marks.
 *     IF any read fails: print error message, EXIT with error.
 *
 *     // Determine Grade
 *     IF marks >= 70 THEN grade = 'A'
 *     ELSE IF marks >= 60 THEN grade = 'B'
 *     ELSE IF marks >= 50 THEN grade = 'C'
 *     ELSE IF marks >= 40 THEN grade = 'D'
 *     ELSE grade = 'F'
 *
 *     // Determine Pass/Fail Status
 *     pass_fail = (marks >= 40) ? "PASS" : "FAIL"
 *
 *     // Display Details
 *     PRINT reg_no, name, grade, marks and pass_fail status.
 *   END FOR
 *
 *   END PROGRAM
 */

#include <stdio.h>

int main(void)
{
    char *name;
    char reg_no[20];
    double marks;
    char grade;
    const char *pass_fail;

    int student_count;

    printf("Enter number of students: ");
    if(scanf("%d", &student_count) != 1){
        printf("Invalid count!\n");
        return 1;
    }
    for(int count = student_count; count > 0; count--){
        printf("Enter student's name: ");
        if(scanf(" %s", name) != 1) {
           printf("Invalid name!\n");
           return 1;
        }
        printf("Enter student's registration number: ");
        if(scanf(" %s", reg_no) != 1) {
            printf("Invalid reg no.\n");
            return 1;
        }
        printf("Enter student's marks: ");
        if(scanf("%lf", &marks) != 1){
            printf("Invalid marks!\n");
            return 1;
        }
        if(marks >= 70 && marks <= 100){
            grade = 'A';
        }
        else if(marks >= 60 && marks <= 69) {
            grade = 'B';
        }
        else if(marks >= 50 && marks <= 59) {
            grade = 'C';
        }
        else if(marks >= 40 && marks <= 49) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
        if (marks >= 40){
            pass_fail = "PASS";
        } else {
            pass_fail = "FAIL";
        }
        printf("\n-----------------------------------------\n");
        printf("\n\t Student Information \t\n");
        printf("\n-----------------------------------------\n");
        printf("\nRegistration number: \t%s\n", reg_no);
        printf("\nName: \t%s\n", name);
        printf("\nGrade: \t%c\n", grade);
        printf("\nMarks: \t%.2f\n", marks);
        printf("\n %s\n", pass_fail);
        printf("\n-----------------------------------------\n");
    }

    return 0;
}
