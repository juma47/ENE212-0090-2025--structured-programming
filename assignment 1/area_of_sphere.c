#include <stdio.h>

int main(void) {
    //Variable declaration
    double radius;
    double pi = 3.142;
    double area;

    //Capture input from user
    printf("What is the radius of the sphere: ");
    if(scanf("%lf", &radius) != 1) {
        printf("Invalid number!\n");
        return 1;
    }
    area = 4 * pi * radius * radius;
    printf("Area : %.2f", area);

    return 0;
}
