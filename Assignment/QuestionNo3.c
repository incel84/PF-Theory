#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DESIGNATION_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char designation[DESIGNATION_LENGTH];
    double salary;
} Employee;

// Input employee records
int inputEmployees(Employee employees[], int n) {
    char buffer[100];
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &employees[i].id);
        getchar(); // consume newline left by scanf

        printf("Name: ");
        fgets(employees[i].name, NAME_LENGTH, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0; // remove newline

        printf("Designation: ");
        fgets(employees[i].designation, DESIGNATION_LENGTH, stdin);
        employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
        getchar(); // consume newline

        printf("\n");
    }
    return 1; // success
}

// Display all employee records
int displayEmployees(Employee employees[], int n) {
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-20s %-10.2lf\n", employees[i].id, employees[i].name,
               employees[i].designation, employees[i].salary);
    }
    return 1;
}

// Find employee with highest salary
int findHighestSalary(Employee employees[], int n) {
    if (n == 0) return 0;

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (employees[i].salary > employees[maxIndex].salary) {
            maxIndex = i;
        }
    }

    printf("\nEmployee with Highest Salary:\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------------\n");
    printf("%-10d %-20s %-20s %-10.2lf\n", employees[maxIndex].id, employees[maxIndex].name,
           employees[maxIndex].designation, employees[maxIndex].salary);
    return 1;
}

// Search employee by ID or Name
int searchEmployee(Employee employees[], int n) {
    int choice;
    printf("\nSearch by:\n1. ID\n2. Name\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    if (choice == 1) {
        int searchID;
        printf("Enter ID to search: ");
        scanf("%d", &searchID);
        getchar(); // consume newline

        for (int i = 0; i < n; i++) {
            if (employees[i].id == searchID) {
                printf("Employee Found:\n");
                printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
                printf("---------------------------------------------------------------\n");
                printf("%-10d %-20s %-20s %-10.2lf\n", employees[i].id, employees[i].name,
                       employees[i].designation, employees[i].salary);
                return 1;
            }
        }
        printf("Employee with ID %d not found.\n", searchID);
        return 0;

    } else if (choice == 2) {
        char searchName[NAME_LENGTH];
        printf("Enter Name to search (case-sensitive): ");
        fgets(searchName, NAME_LENGTH, stdin);
        searchName[strcspn(searchName, "\n")] = 0; // remove newline

        for (int i = 0; i < n; i++) {
            if (strcmp(employees[i].name, searchName) == 0) {
                printf("Employee Found:\n");
                printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
                printf("---------------------------------------------------------------\n");
                printf("%-10d %-20s %-20s %-10.2lf\n", employees[i].id, employees[i].name,
                       employees[i].designation, employees[i].salary);
                return 1;
            }
        }
        printf("Employee with Name '%s' not found.\n", searchName);
        return 0;

    } else {
        printf("Invalid choice.\n");
        return 0;
    }
}

// Apply bonus to employees with salary below threshold
int applyBonus(Employee employees[], int n, double threshold, double bonusPercent) {
    for (int i = 0; i < n; i++) {
        if (employees[i].salary < threshold) {
            employees[i].salary += employees[i].salary * bonusPercent / 100.0;
        }
    }
    return 1;
}

// Main function
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); // consume newline

    Employee employees[MAX_EMPLOYEES];

    inputEmployees(employees, n);
    displayEmployees(employees, n);
    findHighestSalary(employees, n);
    searchEmployee(employees, n);

    // Apply 10% bonus for employees earning < 50000
    applyBonus(employees, n, 50000, 10);
    printf("\nAfter applying 10%% bonus to salaries below 50000:\n");
    displayEmployees(employees, n);

    return 0;
}
