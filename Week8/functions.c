#include <stdio.h>

// Function Prototypes
void displayWelcome(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float Revenue, float Expenses);
void displayMenu(void);
int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice;
    
    //Task 1: Call displayWelcome() from main()
    displayWelcome();

    do
    {
        //Task 5 & 7: Display the reusable menu[cite: 37, 38, 39]
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input please enter a number between 1 and 5.\n");
           
           while(getchar() !='\n');

            continue;
        }

        switch(choice)
        {
            case 1: {
                //Task 2: calculateVAT()
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                float vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;
            }
            case 2: {
                //Task 3: calculateSalary()
                float basic, housing, transport;
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                float gross = calculateSalary(basic, housing, transport);
                printf("Gross salary: %.2f\n", gross);
                break;
            }
            case 3: {
                //Task 4: calculateBudget()
                float Revenue, Expenses;
                printf("Enter revenue: ");
                scanf("%f", &Revenue);
                printf("Enter expenses: ");
                scanf("%f", &Expenses);
                float Balance = calculateBudget(Revenue, Expenses);
                
                if (Balance > 0) {
                    printf("SURPLUS (Balance: %.2f)\n", Balance);
                } else if (Balance < 0) {
                    printf("DEFICIT (Balance: %.2f)\n", Balance);
                } else {
                    printf("BALANCED (Balance: %.2f)\n", Balance);
                }
                break;
            }
            case 4: {
                //Task 6: searchEmployee()
                int employeeIDs[] = {101, 102, 103, 104, 105};
                int size = 5;
                int searchID;
                
                printf("Enter employee ID: ");
                scanf("%d", &searchID);
                
                int position = searchEmployee(searchID, employeeIDs, size);
                if (position != -1) {
                    printf("Employee found at position %d.\n", position);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            }
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}

//Task 1 Implementation ---
void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

//Task 2 Implementation ---
float calculateVAT(float amount)
{
    return amount * 0.15;
}

// Task 3 Implementation ---
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

// --- Lab Task 4 Implementation ---
float calculateBudget(float Revenue, float Expenses)
{
    return Revenue - Expenses;
}

//Task 5 Implementation ---
void displayMenu(void)
{
    printf("\n=========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("=========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

//Task 6 Implementation ---
int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}