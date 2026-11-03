#include <stdio.h>
#include "utilities.h"

int readInt(const char message[])
{
    int number;
    int result;
    int ch;

    do
    {

    printf("%s", message);

        result = scanf("%d", &number);

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            /* Clear extra input */
        }

        if (result != 1)
        {
            printf("Invalid input. Please enter a number.\n");
        }

    } while (result != 1);

    return number;
}


/* Read a decimal number from the user */
double readDouble(const char message[])
{
    double number;
    int result;
    int ch;

    do
    {
        printf("%s", message);

        result = scanf("%lf", &number);

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            /* Clear extra input */
        }

        if (result != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
        }

    } while (result != 1);

    return number;
}


/* Pause the screen */
void pauseScreen(void)
{
    char input[10];

    printf("\nPress Enter to continue...");
    fgets(input, sizeof(input), stdin);
}