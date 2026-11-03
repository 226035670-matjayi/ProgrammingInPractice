# MFMS – Week 9 Practical

## Project Description
This project is a Multi-Functional Management System (MFMS) developed in C. It demonstrates the use of separate source files, header files and modular programming.

## Modules

- **main.c:** Contains the main menu and controls the program.
- **employees.c / employees.h:** Handles employee management.
- **budget.c / budget.h:** Handles budget management.
- **utilities.c / utilities.h:** Contains reusable input and helper functions.
- **reports.c / reports.h:** Generates employee, budget and supplier reports.
- **suppliers.c / suppliers.h:** Handles supplier management.

## Compilation

Compile the project using:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c utilities.c reports.c suppliers.c -o mfms
```

Run on Windows:

```powershell
.\mfms.exe
```

## Testing
The program was tested using three test runs covering employee management, budget management, supplier management, reports and menu navigation.

Screenshots of the test runs are included in the screenshots folder.