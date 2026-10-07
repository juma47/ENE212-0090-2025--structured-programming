#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    printf("Enter your name: ");
    if(scanf("%s", &name) != 1) {
        return 1;
    }
    printf("Hello %s\n", name);
    printf("Your name has %zu letters\n", strlen(name));
    return 0;
}
