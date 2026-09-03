#include <stdio.h>
int main(){
    //Decalaring variables
    double salary=0.00;
    double housingAllowance=0.00;
    double transportAllowance=0.00;
    double tax=0.00;
    double grossSalary=0.00;
    double netWage=0.00;
    
    //1.Ask user for basic salary
    printf("Enter salary:");
    scanf("%lf", &salary);

    //2.Ask user for housing allowance
    printf("Enter Housing allowance:");
    scanf("%lf", &housingAllowance);

    //3.Ask user for transport allowance
    printf("Enter Transport allowance:");
    scanf("%lf", &transportAllowance);

    //4.Ask user for tax
    printf("Enter tax:");
    scanf("%lf", &tax);

    //5.Calculate and output gross salary
    grossSalary=salary+housingAllowance+transportAllowance;
    printf("Gross Salary: %.2f", grossSalary);

    //6.Calculate and output net salary 
    netWage=grossSalary-tax;
    printf("Net Salary: %.2f", netWage);

return 0;
}