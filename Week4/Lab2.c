#include <stdio.h>
int main(){

    //Decalaration of variables
    float budget=0.00;
    char suppliername[50];
    float supplierprice=0.00;
    int registered;
    int documentsComplete;

    //1. Prompt Supplier for Registration status
    printf("Is supplier registered? (1=yes, 0=no):");
    scanf("%d", &registered);

    //2. Prompt Suppliers for name 
    printf("Enter supplier name:");
    scanf("%49s", suppliername);

    //3. Prompt Supplier for price
    printf("Enter tender price:");
    scanf("%f", &supplierprice);

    //4. Prompt Suppliers for documents 
    printf("Are all documents complete? (1=yes, 0=no):");
    scanf("%d", &documentsComplete);

    //5. Prompt Supplier for budget
    printf("Enter current budget:");
    scanf("%f", &budget);
    // Supplier qualification conditions
    if(registered==1 && documentsComplete==1 && supplierprice<=budget)
    { if(supplierprice<budget){
        printf("Preferred Supplier");
    }
        printf("supplier is qualified\n");
        printf("\%s\n", suppliername);
    }
    else{
        printf("\%s\n", suppliername);
        printf("supplier is disqualified\n");
    }



    return 0;

}