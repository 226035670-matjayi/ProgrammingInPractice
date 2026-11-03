#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "reports.h"
#include "utilities.h"

#define MAX_BUDGETS 10


/* Employee Menu */
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n==============================\n");
        printf("       EMPLOYEE MANAGEMENT\n");
        printf("==============================\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Back to main menu\n");

        choice = readInt("Enter choice: ");

        if (choice == 1)
        {
            addEmployee();
        }
        else if (choice == 2)
        {
            displayEmployees();
        }
        else if (choice == 3)
        {
            searchEmployee();
        }
        else if (choice == 4)
        {
            printf("Going back to main menu...\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


/* Budget Menu */
void budgetMenu(Budget budgets[], int *budgetCount)
{
    int choice;

    do
    {
        printf("\n==============================\n");
        printf("        BUDGET MANAGEMENT\n");
        printf("==============================\n");
        printf("1. Add budget\n");
        printf("2. Display budgets\n");
        printf("3. Update spending\n");
        printf("4. Back to main menu\n");

        choice = readInt("Enter choice: ");

        if (choice == 1)
        {
            if (*budgetCount < MAX_BUDGETS)
            {
                if (addBudget(budgets, *budgetCount))
                {
                    *budgetCount = *budgetCount + 1;
                }
            }
            else
            {
                printf("Budget storage is full.\n");
            }
        }
        else if (choice == 2)
        {
            displayBudgets(budgets, *budgetCount);
        }
        else if (choice == 3)
        {
            updateSpending(budgets, *budgetCount);
        }
        else if (choice == 4)
        {
            printf("Going back to main menu...\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


/* Supplier Menu */
void supplierMenu(int supplierIDs[],
                  char supplierNames[][STR_LEN],
                  char supplierEmails[][STR_LEN],
                  char supplierTelephones[][STR_LEN],
                  char supplierTowns[][STR_LEN],
                  int *supplierCount)
{
    int choice;
    char searchName[STR_LEN];
    int result;

    do
    {
        printf("\n=============================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("==============================\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier by name\n");
        printf("4. Compare/search supplier information\n");
        printf("5. Back to main menu\n");

        choice = readInt("Enter choice: ");

        if (choice == 1)
        {
            *supplierCount = addSupplier(
                supplierIDs,
                supplierNames,
                supplierEmails,
                supplierTelephones,
                supplierTowns,
                *supplierCount
            );
        }
        else if (choice == 2)
        {
            displaySuppliers(
                supplierIDs,
                (const char (*)[STR_LEN]) supplierNames,
                (const char (*)[STR_LEN]) supplierEmails,
                (const char (*)[STR_LEN]) supplierTelephones,
                (const char (*)[STR_LEN]) supplierTowns,
                *supplierCount
            );
        }
        else if (choice == 3)
        {
            if (*supplierCount == 0)
            {
                printf("There are no suppliers to search.\n");
            }
            else
            {
                printf("Enter supplier name: ");
                fgets(searchName, STR_LEN, stdin);
                removeNewline(searchName);

                result = searchSupplierByName(
                    (const char (*)[STR_LEN]) supplierNames,
                    *supplierCount,
                    searchName
                );

                if (result == -1)
                {
                    printf("Supplier was not found.\n");
                }
                else
                {
                    printf("\nSupplier found.\n");
                    printf("Supplier ID: %d\n", supplierIDs[result]);
                    printf("Name: %s\n", supplierNames[result]);
                    printf("Email: %s\n", supplierEmails[result]);
                    printf("Telephone: %s\n", supplierTelephones[result]);
                    printf("Town: %s\n", supplierTowns[result]);
                }
            }
        }
        else if (choice == 4)
        {
            compareAndSearchSupplier(
                supplierIDs,
                (const char (*)[STR_LEN]) supplierNames,
               (const char (*)[STR_LEN]) supplierEmails,
                (const char (*)[STR_LEN]) supplierTelephones,
               (const char (*)[STR_LEN]) supplierTowns,
                *supplierCount
            );
        }
        else if (choice == 5)
        {
            printf("Going back to main menu...\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);
}


/* Reports Menu */
void reportsMenu(Budget budgets[],
                 int budgetCount,
                 int supplierIDs[],
                 char supplierNames[][STR_LEN],
                 char supplierEmails[][STR_LEN],
                 char supplierTelephones[][STR_LEN],
                 char supplierTowns[][STR_LEN],
                 int supplierCount)
{
    int choice;

    do
    {
        printf("\n==============================\n");
        printf("             REPORTS\n");
        printf("==============================\n");
        printf("1. Employee report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Back to main menu\n");

        choice = readInt("Enter choice: ");

        if (choice == 1)
        {
            employeeReport();
            pauseScreen();
        }
        else if (choice == 2)
        {
            budgetReport(budgets, budgetCount);
            pauseScreen();
        }
        else if (choice == 3)
        {
            supplierReport(
                supplierIDs,
                supplierNames,
                supplierEmails,
                supplierTelephones,
                supplierTowns,
                supplierCount
            );

            pauseScreen();
        }
        else if (choice == 4)
        {
            printf("Going back to main menu...\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


/* Main Function */
int main(void)
{
    int choice;

    Budget budgets[MAX_BUDGETS];
    int budgetCount = 0;

    int supplierIDs[MAX_SUPPLIERS];
    char supplierNames[MAX_SUPPLIERS][STR_LEN];
    char supplierEmails[MAX_SUPPLIERS][STR_LEN];
    char supplierTelephones[MAX_SUPPLIERS][STR_LEN];
    char supplierTowns[MAX_SUPPLIERS][STR_LEN];
    int supplierCount = 0;

    do
    {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Reports\n");
        printf("5. Exit\n");

        choice = readInt("Enter choice: ");

        if (choice == 1)
        {
            employeeMenu();
        }
        else if (choice == 2)
        {
            budgetMenu(budgets, &budgetCount);
        }
        else if (choice == 3)
        {
            supplierMenu(
                supplierIDs,
                supplierNames,
                supplierEmails,
                supplierTelephones,
                supplierTowns,
                &supplierCount
            );
        }
        else if (choice == 4)
        {
            reportsMenu(
                budgets,
                budgetCount,
                supplierIDs,
                supplierNames,
                supplierEmails,
                supplierTelephones,
                supplierTowns,
                supplierCount
            );
        }
        else if (choice == 5)
        {
            printf("\nThank you for using the system.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}