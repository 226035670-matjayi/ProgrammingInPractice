#include <stdio.h>
#include <string.h>

int main() {
    // ==========================================
    // PART A: Employee Salaries (50 Employees)
    // ==========================================
    float salaries[5];
    float totalSalary = 0.0;
    float highestSalary, lowestSalary, avgSalary;

    printf("=== EMPLOYEE SALARIES ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        totalSalary += salaries[i];

        // Track highest and lowest dynamically
        if (i == 0) {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        } else {
            if (salaries[i] > highestSalary) {
                highestSalary = salaries[i];
            }
            if (salaries[i] < lowestSalary) {
                lowestSalary = salaries[i];
            }
        }
    }

    avgSalary = totalSalary / 5;
    printf("\n--- Salary Report ---\n");
    printf("Total Salary Expenditure: %.2f\n", totalSalary);
    printf("Average Salary: %.2f\n", avgSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);

    // Search for a particular salary (Linear Search)
    float searchSalary;
    int salaryFound = 0;
    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 5; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f found at position %d.\n", searchSalary, i);
            salaryFound = 1;
            break;
        }
    }
    if (!salaryFound) {
        printf("Salary not found.\n");
    }

    // ==========================================
    // PART B: Department Budgets (10 Departments)
    // ==========================================
    float budgets[5];
    float totalBudget = 0.0;

    printf("\n===  DEPARTMENT BUDGETS ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }

    float avgBudget = totalBudget / 5;
    printf("\nTotal Department Budget: %.2f\n", totalBudget);
    printf("Average Department Budget: %.2f\n", avgBudget);

    // Sort Budgets from Lowest to Highest (Bubble Sort)
    float temp;
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets Sorted (Lowest to Highest):\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f\n", budgets[i]);
    }

    // ==========================================
    // PART C: Vehicle Registration Numbers
    // ==========================================
    char registrations[3][20]; // Storing 3 vehicle plates (scaled from 20)
    
    printf("\n=== VEHICLE REGISTRATIONS ===\n");
    // Clear input buffer before reading strings
    while (getchar() != '\n');

    for (int i = 0; i < 3; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle Registrations List:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", registrations[i]);
    }

    // Search for a particular registration number
    char searchPlate[20];
    int plateFound = 0;
    printf("\nEnter registration number to search: ");
    scanf("%19s", searchPlate);

    for (int i = 0; i < 3; i++) {
        if (strcmp(registrations[i], searchPlate) == 0) {
            printf("Registration '%s' found at index %d.\n", searchPlate, i);
            plateFound = 1;
            break;
        }
    }
    if (!plateFound) {
        printf("Registration number not found.\n");
    }

    return 0;
}