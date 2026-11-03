# MFMS – Week 10 Practical

## Project Description

This project is a Municipal Financial Management System (MFMS) developed in C. It demonstrates modular programming, the use of separate source and header files, and file handling.

The system manages employees, budgets, suppliers and assets.

## Modules

- **main.c:** Contains the main menu and controls the program.
- **employees.c / employees.h:** Handles employee management.
- **budget.c / budget.h:** Handles budget management.
- **utilities.c / utilities.h:** Contains reusable input and helper functions.
- **reports.c / reports.h:** Generates system reports.
- **suppliers.c / suppliers.h:** Handles supplier management.
- **assets.c / assets.h:** Handles asset management.

## File Handling

The system supports saving and loading records using text files:

- `data/employees.txt`
- `data/budgets.txt`
- `data/suppliers.txt`
- `data/assets.txt`

The system also includes binary file handling for asset records using:

- `data/assets.bin`

The main menu provides options to save all data and load all data.

## Compilation

Compile the project using GCC:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utilities.c -o mfms.exe
```

Run on Windows:

```powershell
.\mfms.exe
```

## Data Storage

The `data` folder stores the system's saved records. Text files can be opened and viewed using a text editor, while binary files store asset records in binary format.

## Testing

The project has been compiled successfully using GCC with the C99 standard and compiler warnings enabled.

Runtime testing of the latest binary and central save/load features is still pending due to a Windows application-control restriction.
