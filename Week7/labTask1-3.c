#include <stdio.h>
#include <string.h>

int main(){

 //Declaring variables
    char supplierName[100];
    char supplierEmail[50];
    char phone[50];
    char town[50];
    char userInput[100];

    // Task3 predefined suppliers
    char suplier1[] = "ABC Office Supplies";
    char suplier2[]= "Namibia Stationery";

//1.ask the user to enter supplier name
    printf("Enter supplier name: \n");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")]= '\0';
    

//2, ask user to enter the supplier email
     printf("Enter the supplier email: \n");
    fgets(supplierEmail, sizeof(supplierEmail), stdin);
    supplierEmail[strcspn(supplierEmail, "\n")]= '\0';


//3.ask user to enter supplier phone number
    printf("Enter the supplier's phone number:\n");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")]= '\0';
    
 //4. Enter the place where the supplier recides
    printf("Enter the town name: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")]= '\0';

 //5.Dislpay all supplier information
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name: %s \n", supplierName);
    printf("Email: %s \n", supplierEmail);
    printf("Phone: %s \n", phone);
    printf("Town: %s", town);

    //Task2 Display Length of supplier name, email and town name
    printf("\n --- STRING LENGTHS ---\n");
    printf("Supplier name legth:  %zu\n", strlen(supplierName));
    printf("email length:         %zu\n", strlen(supplierEmail));
    printf("Town length:          %zu\n", strlen(town));

printf("Enter a supplier name: \n");
fgets(userInput, sizeof(userInput), stdin);
userInput[strcspn(userInput, "\n")]='\0';


userInput[strcspn(userInput, "\n")] ='\0';

//11. Determine whether the supplier exists
if(strcmp(userInput, suplier1)== 0 || strcmp(userInput, suplier2) == 0){
    printf("Suplier found: \n");
} else {
    (printf("supplier not found: \n"));
    }

    return 0;

}