/*
 * PROGRAM: PIN-based Door Lock System
 * PSEUDOCODE:
 *
 * FUNCTION clear_buffer():
 *     Discard characters from input buffer until newline or EOF
 * END FUNCTION
 *
 * MAIN:
 *     Set correct_pin = 9999, count = 3
 *     WHILE count is between 1 and 3:
 *         Prompt user for PIN
 *         IF input is non-numeric:
 *             Display error, clear buffer, decrement count
 *         ELSE IF PIN is 0:
 *             Exit program
 *         ELSE IF PIN length is invalid (<1000 or >9999):
 *             Display length error, clear buffer, decrement count
 *
 *         IF PIN equals correct_pin:
 *             Display Menu (1: Open Door, 2: Change User, 3: Change PIN, 4: Exit)
 *             WHILE running is true:
 *                 Read user choice
 *                 Process choice with SWITCH statement
 *             Exit main loop
 *         ELSE IF PIN is 4 digits but wrong:
 *             Display wrong PIN message, decrement count
 *
 *         IF count >= 1:
 *             Display remaining attempts
 *         ELSE:
 *             Display lockout message
 *             Run 5-second animated sleep timer
 *             Reset count to 3
 *     END WHILE
 */

#include <stdio.h>
#include <stdbool.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(sec) Sleep((sec) * 1000)
#else
    #include <unistd.h>
    #define SLEEP(sec) sleep(sec)
#endif // _WIN32

void clear_buffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    long int correct_pin = 4747;
    long int user_pin;
    int count = 3;


    while (count <= 3 && count >= 1){
        printf("Enter PIN ( or 0 to exit): ");
        if(scanf("%ld", &user_pin) != 1){
            printf("Invalid PIN. Must contain numerical digits (0-9)\n");
            clear_buffer();
            count--;
        } else if (user_pin < 1000) {
            if (user_pin == 0){
                printf("Exiting System...\n");
                return 0;
            }
            printf("PIN is too short (must be 4 digits)\n");
            clear_buffer();
            count--;
        }  else if(user_pin > 9999){
            printf("PIN is too long (must be 4 digits)\n");
            clear_buffer();
            count--;
        }

        if (user_pin == correct_pin) {
            printf("\n=== Device Menu ===\n");
            printf("1. Open Door\n");
            printf("2. Change Username\n");
            printf("3. Change Pin\n");
            printf("4. Exit\n");

            bool running = true;
            while (running){
                printf("\nChoose an option above: \n");

                int choice;
                if(scanf("%d", &choice) != 1){
                    printf("That option contain letters or symbols. Try again.\n");
                    clear_buffer();
                    continue;
                }
                switch(choice){
                    case 1:
                        printf("\nAccess granted. Door unlocked.\n");
                        running = false;
                        break;
                    case 2:
                        printf("\nChange username feature coming soon.\n");
                        running = false;
                        break;
                    case 3:
                        printf("\nChange PIN feature coming soon.\n");
                        running = false;
                        break;
                    case 4:
                        printf("\nExiting System...\n");
                        running = false;
                        break;
                    default:
                        printf("\nInvalid option. Please try again.\n");
                        break;

                }
            }
            break;
        } else if (user_pin >= 1000 && user_pin <= 9999){
            printf("Wrong PIN. Access denied.\n");
            count--;
        }
        if (count >= 1) {
            printf("Attempts remaining %d\n", count);
       } else {
            printf("No attempts remaining.\n\tSystem locked. Wait for 5 seconds and try again.\n\t\t");
            for(int secs = 5; secs > 0; secs--) {
                printf("%d", secs);
                for(int i = 0; i < 3; i++) {
                    printf(".");
                    SLEEP(0.33);
                }
            }
            printf("\n\tYou can try again now or enter 0 to exit.\n");
            count = 3;
       }
    }

    return 0;
}
