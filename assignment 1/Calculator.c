#include <stdio.h>
#include <stdbool.h>

void print_menu(void){
    printf("Choose an operation\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("%%: Modulus\n");
    printf("q : Quit\n");
}

double add(double a, double b){
    return a + b;
}
double subtract(double a, double b){
    return a - b;
}
double multiply(double a, double b){
    return a * b;
}
double divide(double a, double b){
    return a / b;
}
int main (void){
    printf("---Simple Calculator---\n");
    print_menu();
    bool running = true;
    while(running){
        double a, b, result;
        char op;
        printf("Enter op(+, -, *, /, %%) or q to quit: ");
        if(scanf(" %c", &op) != 1) {
            printf("Invalid Operator!\n");
            return 1;
        }
        if (op == 'q' || op == 'Q') {
            running = false;
            printf("Goodbye!");
            break;
        }

        printf("Enter first number: ");
        if(scanf("%lf", &a) != 1) {
            printf("Invalid number!\n");
            return 1;
        }

        printf("Enter second number: ");
        if(scanf("%lf", &b) != 1) {
            printf("Invalid number!\n");
            return 1;
        }

        switch (op){
            case '+':
                 result = add(a, b);
                 break;
            case '-':
                 result = subtract(a, b);
                 break;
            case '*':
                 result = multiply(a, b);
                 break;
            case '/':
                 if(b == 0){
                     printf("Division by 0!");
                     return 1;
                 }
                 result = divide(a, b);
                 break;
            case '%':
                 if((int)b == 0){
                     printf("Modulo by 0!\n");
                     return 1;
                 }
                 result = (int)a % (int)b;
                 break;

            default :
                 printf("Invalid operator %c!\n", op);
                 return 1;
        }
        printf("Result : %.2f\n", result);
    }
    printf("\n");

    return 0;
}
