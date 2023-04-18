#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_JOBNAME_LEN 25


// Structure to store employee data
typedef struct
{
    char surname[MAX_NAME_LEN + 1];
    char job[MAX_JOBNAME_LEN + 1];
    int salary;
    int personnel_number;
} Employee;

// Function prototypes
void print_menu();
void print_employees(Employee **employees, int num_employees);
void add_employee(Employee **employees, int *num_employees);
void delete_employee(Employee **employees, int *num_employees);
void save_employees(Employee *employees, int num_employees);
void load_employees(Employee **employees, int *num_employees);

int main()
{
    // Initialize employee data field
    Employee *employees = 0;
    int num_employees = 0;

    // Load employee data from file
    load_employees(&employees, &num_employees);

    // Main loop
    int choice;
    do
    {
        print_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Print employee data
            print_employees(&employees, num_employees);
            break;
        case 2:
            // Add new employee
            add_employee(&employees, &num_employees);
            save_employees(employees, num_employees);
            break;
        case 3:
            // Delete employee
            delete_employee(&employees, &num_employees);
            save_employees(employees, num_employees);
            break;
        case 4:
            // Quit program
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    // Save employee data to file

    // Free memory
    free(employees);

    return 0;
}

// Print menu
void print_menu()
{
    printf("\nMenu:\n");
    printf("1. Print employee data\n");
    printf("2. Add new employee\n");
    printf("3. Delete employee\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

// Print employee data
void print_employees(Employee **employees, int num_employees)
{
    if (num_employees == 0)
    {
        printf("No data available\n");
    }
    else
    {
        for (int i = 0; i < num_employees; i++)
        {
            printf("Employee %d:\n", i + 1);
            printf("Surname: %s\n", (*employees)[i].surname);
            printf("Job: %s\n", (*employees)[i].job);
            printf("Salary: %d\n", (*employees)[i].salary);
            printf("Personnel number: %d\n", (*employees)[i].personnel_number);
        }
    }
}

// Add new employee
void add_employee(Employee **employees, int *num_employees)
{
    // Increase size of employee data field by 1
    *employees = realloc(*employees, (*num_employees + 1) * sizeof(Employee));
    if (*employees == 0)
    {
        printf("Error allocating memory\n");
        return;
    }

    // Get employee data from user
    printf("Enter surname: ");
    scanf("%s", (*employees)[*num_employees].surname);
    printf("Enter Job: ");
    scanf("%s", (*employees)[*num_employees].job);
    printf("Enter salary: ");
    scanf("%d", &(*employees)[*num_employees].salary);
    printf("Enter personnel number: ");
    scanf("%d", &(*employees)[*num_employees].personnel_number);

    // Increment number of employees
    (*num_employees)++;
}

// Delete employee
void delete_employee(Employee **employees, int *num_employees)
{
    if (*num_employees == 0)
    {
        printf("No data available\n");
        return;
    }

    int personnel_number;
    printf("Enter personnel number of employee to delete: ");
    scanf("%d", &personnel_number);

    // Find index of employee to delete
    int index = -1;
    for (int i = 0; i < *num_employees; i++)
    {
        if ((*employees)[i].personnel_number == personnel_number)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Employee with personnel number %d not found\n", personnel_number);
        return;
    }

    // Shift remaining employees down one position
    for (int i = index; i < *num_employees - 1; i++)
    {
        (*employees)[i] = (*employees)[i + 1];
    }

    // Decrease size of employee data field by 1
    *employees = realloc(*employees, (*num_employees - 1) * sizeof(Employee));
    if (*employees == 0)
    {
        printf("Error allocating memory\n");
        return;
    }

    // Decrement number of employees
    (*num_employees)--;
}

// Save employee data to file
void save_employees(Employee *employees, int num_employees)
{
    FILE *fp = fopen("employees.dat", "wb");
    if (fp == 0)
    {
        printf("Error opening file\n");
        return;
    }

    // Write number of employees to file
    fwrite(&num_employees, sizeof(int), 1, fp);

    // Write employee data to file
    fwrite(employees, sizeof(Employee), num_employees, fp);

    fclose(fp);
}

// Load employee data from file
void load_employees(Employee **employees, int *num_employees)
{
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == 0)
    {
        printf("Error opening file\n");
        return;
    }

    // Read number of employees from file
    fread(num_employees, sizeof(int), 1, fp);

    // Allocate memory for employee data
    *employees = malloc(*num_employees * sizeof(Employee));
    if (*employees == 0)
    {
        printf("Error allocating memory\n");
        return;
    }

    // Read employee data from file
    fread(*employees, sizeof(Employee), *num_employees, fp);

    fclose(fp);
}

// This program defines a structure `Employee` to store the data for each employee, and a field of pointers to `Employee` structures to store the data for multiple employees. The program includes a main loop that presents a menu to the user and allows them to choose between printing all employee data, adding a new employee, or quitting the program.

// The program includes the following functions:

// - `print_menu()`: Prints the menu to the user
// - `print_employees(Employee** employees, int num_employees)`: Prints the data for all employees in the employee data field. If there are no employees, it prints a message indicating that there is no data available.
// - `add_employee(Employee** employees, int* num_employees)`: Prompts the user to input the data for a new employee, allocates memory for the new employee using `malloc()`, fills in the fields of the new employee structure using the user input, and appends the new employee to the employee data field using `realloc()`.

// I hope this helps! Let me know if you have any questions or if you need further assistance.
