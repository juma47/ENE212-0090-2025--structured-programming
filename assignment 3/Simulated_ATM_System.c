#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
START

1. Display "Welcome to ATM"

2. Set balance = 10000

3. Ask user to enter PIN

4. IF PIN is correct THEN

      Display ATM Menu:
      1. Check Balance
      2. Withdraw Money
      3. Deposit Money
      4. Exit

5. Ask user to select an option

6. IF option = 1 THEN
      Display account balance

   ELSE IF option = 2 THEN
      Ask user to enter withdrawal amount
      IF amount <= balance THEN
          Subtract amount from balance
          Display "Withdrawal successful"
      ELSE
          Display "Insufficient funds"
      END IF

   ELSE IF option = 3 THEN
      Ask user to enter deposit amount
      Add amount to balance
      Display "Deposit successful"

   ELSE IF option = 4 THEN
      Display "Thank you for using our ATM"

   ELSE
      Display "Invalid option"

7. Repeat menu until user selects Exit

ELSE
      Display "Incorrect PIN"

END IF

STOP
*/
int balance = 3200;

const char correct_pin[5] = "4747";

void clear_buffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool login() {
    char pin[50];
    int count = 2;
    while (count <= 2 && count >= 0) {
        printf("Enter PIN: ");
        if(scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            printf("Correct PIN.\n");
            printf("Successful login.\n");
            return true;
        } else {
            printf("Wrong PIN.\n");
            if (count >= 1) {
                printf("Try again. Attempts remaining %d\n", count--);

                    continue;
            } else {
                printf("No attempts remaining.\n\tExiting System.\n");
                    return false;
            }
        }
    }
    }

void checkBalance() {
    char pin[50];
    printf("Enter PIN: \n");

    if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
        printf("Dear customer, your account balance is %d.\n", balance);
    } else {
        printf("You have entered the wrong PIN.\n");
    }
}



void display_menu(void) {
    printf("\n1. Balance Inquiry.\n");
    printf("2. Withdraw.\n");
    printf("3. Deposit.\n");
    printf("4. Exit.\n");

    printf("Choose an option above.\n");
}

bool deposit(int amount) {
    char pin[50];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        printf("\nEnter PIN to confirm deposit of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance += amount;
            printf("You have successfully deposited %d in your account.\n", amount);
            return true;
        } else {
            printf("You have entered the wrong PIN.\n");
            return false;
        }
    }
}

bool withdraw(int amount) {
    char pin[50];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        if (amount > balance) {
            printf("You have insufficient funds.\n");
            return false;
        }
        printf("\nEnter PIN to confirm withdrawal of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance -= amount;
            printf("You have successfully withdrawn %d in your account.\n", amount);
            return true;
        } else {
            printf("You have entered the wrong PIN.\n");
            return false;
        }
    }
}

int main()
{
    if (login() == true) {
        bool running = true;
        int amount;
        while (running) {
            int choice;
            display_menu();
            if (scanf("%d", &choice) != 1) {
                printf("That option contain letters or symbols. Try again.\n");
                clear_buffer();
                continue;
            }

            switch (choice) {
                case 1 : checkBalance();
                         break;
                case 2 : printf("Enter amount you would like to withdraw: ");
                         if (scanf("%d", &amount) == 1) {
                            withdraw(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 3 : printf("Enter amount you would like to deposit: ");
                         if (scanf("%d", &amount) == 1) {
                            deposit(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 4 : printf("Exiting system.\n");
                         running = false;
                         return 0;
                default : printf("\nInvalid option. Please try again.\n");
                          break;
            }

        }
    }
    return 0;

}
