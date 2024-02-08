#include <stdio.h>

int main() {
    // Integer data type
    int integerVar = 10;
    printf("Integer variable: %d\n", integerVar);

    // Floating point data type
    float floatVar = 3.14;
    printf("Float variable: %.2f\n", floatVar);

    // Character data type
    char charVar = 'A';
    printf("Character variable: %c\n", charVar);

    // Array of integers
    int intArray[5] = {1, 2, 3, 4, 5};
    printf("Integer array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // String (array of characters)
    char str[6] = "Hello"; // Strings in C are null-terminated
    printf("String variable: %s\n", str);

    // Structure (struct) - a complex data type that groups variables of different types
    struct {
        int id;
        char name[50];
        float salary;
    } employee;

    // Initializing structure members
    employee.id = 1;
    employee.salary = 50000.50;
    snprintf(employee.name, sizeof(employee.name), "%s", "John Doe");

    printf("Employee ID: %d\n", employee.id);
    printf("Employee Name: %s\n", employee.name);
    printf("Employee Salary: %.2f\n", employee.salary);

    return 0;
}
