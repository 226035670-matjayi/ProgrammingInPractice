#include <stdio.h>
int main(){
    //Declare variables
    float salary;
    float total;
    float highest;
    float lowest;
    float average;
    for(int i=1; i<=50; i++){

    
    //1. Capture the salary of each employee
    printf("Enter employee salary %d: ", i);
    scanf("%f", &salary);

     //2. Calculate the total salary
    total=total+salary;
//4. Determine the highest salary 
    if(i==1){
        highest=salary;
        lowest=salary;
    }
    // 5.Determine the lowest salary 
    if(salary>highest){
        highest=salary;
    }
    if(salary<highest){
        lowest=salary;
    }
}
//3. Calculate the average salary
   average=total/50;
    // 6. Display the results
printf("\n--- Municipal Employee Salary Report ---\n");
printf("Total Salary Expenditure: $%.2f\n", total);
printf("Average Salary:           $%,2f\n", average);
printf("Highest Salary:            $%.2f\n", highest);
printf("Lowest Salary:            $%.2f\n", lowest);

return 0;

}