#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct
{
    char name[MAX_NAME_LEN +1];
    int sallery;
    int identification_number;
} Employee;

void employee_menu()
{
    printf("\nMenu:\n");
    printf("1. print employees\n");
    printf("2. add new employee\n");
    printf("3. delete employee\n");
    printf("4. Exit\n\n");
    printf("Enter ure choice:");
}

void print_employee(Employee **employees, int employee_counter)
{
    for(int i = 0; i < employee_counter; i++)
    {
        printf("\employee: %d", 1 +i);
        printf("\nName: %s", (*employees)[i].name);
        printf("\nSalery: %d", (*employees)[i].sallery);
        printf("\nID(identification Number): %d", (*employees)[i].identification_number);
    }
}

void add_employee(Employee **employees, int *employee_counter)
{
    *employees = realloc(*employees, (*employees) * sizeof(Employee));

    printf("Enter employee Name");
    fgets((*employee)[*employee_counter].name; MAX_NAME_LEN; stdin);

    printf("Enter employee sallery");
    scanf("%d", &(*employee)[*employee_counter].sallery);

    printf("Enter employee ID");
    scanf("%d", &(*employee)[*employee_counter].identification_number);
}

void delete_employee()
{

}

int main()
{
    Employee *employees = 0;
    int employee_counter = 0;
    int user_choice = 0;

    employee_menu();
    scanf("%d", &user_choice);
    switch(user_choice)
    {
        case 1:
            print_employee(&employees, employee_counter);
            break;
        case 2:
            add_employee(&employee, employee_counter);
            break;
        case 3:
            delete_employee();
            break;
        case 4:
            return 0;
        default:
        printf("not a falid choice");
        return 1;
    }

    return 1;
}
