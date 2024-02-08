#include <stdio.h>

int main() {
    int a = 5, b = 2;

    // Arithmetic expression
    int result = a + b; // Adds a and b
    printf("The result of a + b is: %d\n", result);

    // More complex arithmetic expression
    result = (a + b) * (a - b); // First adds a and b, then subtracts b from a, and finally multiplies the two results
    printf("The result of (a + b) * (a - b) is: %d\n", result);

    // Logical expression combined with arithmetic
    int isGreater = (a - b) > 0; // Subtracts b from a and checks if the result is greater than 0
    printf("(a - b) > 0 evaluates to: %d\n", isGreater); // In C, 1 represents true, and 0 represents false

    // Using expressions in control structures
    if (a % b == 1) { // Checks if the remainder of a divided by b is equal to 1
        printf("The remainder of a divided by b is 1.\n");
    } else {
        printf("The remainder of a divided by b is not 1.\n");
    }

    // Complex expression using different operators
    result = a + b * 3 - 4 / 2 + (a % b); // Demonstrates the use of multiple operators in a single expression
    printf("The result of a + b * 3 - 4 / 2 + (a %% b) is: %d\n", result);

    // Expression using logical AND and OR
    int logicResult = (a > b) && ((a - b) < a) || (b < a); // Combines relational and logical operators
    printf("The logical expression (a > b) && ((a - b) < a) || (b < a) evaluates to: %d\n", logicResult);

    // Expression with conditional operator (ternary)
    int min = (a < b) ? a : b; // Evaluates to a if a < b, otherwise to b
    printf("The minimum of a and b using ternary operator is: %d\n", min);

    return 0;
}
