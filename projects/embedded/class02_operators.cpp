#include <stdio.h>

int main() {
    int a = 10, b = 4;

    // Arithmetic Operators
    printf("a + b = %d\n", a + b); // Addition
    printf("a - b = %d\n", a - b); // Subtraction
    printf("a * b = %d\n", a * b); // Multiplication
    printf("a / b = %d\n", a / b); // Division
    printf("a %% b = %d\n", a % b); // Modulus (remainder)

    // Relational Operators
    printf("a == b is %d\n", a == b); // Equal to
    printf("a != b is %d\n", a != b); // Not equal to
    printf("a > b is %d\n", a > b);  // Greater than
    printf("a < b is %d\n", a < b);  // Less than
    printf("a >= b is %d\n", a >= b); // Greater than or equal to
    printf("a <= b is %d\n", a <= b); // Less than or equal to

    // Logical Operators
    printf("(a > b) && (a != 0) is %d\n", (a > b) && (a != 0)); // Logical AND
    printf("(a < b) || (a != 0) is %d\n", (a < b) || (a != 0)); // Logical OR
    printf("!(a == b) is %d\n", !(a == b)); // Logical NOT

    // Bitwise Operators
    printf("a & b = %d\n", a & b); // Bitwise AND
    printf("a | b = %d\n", a | b); // Bitwise OR
    printf("a ^ b = %d\n", a ^ b); // Bitwise XOR
    printf("~a = %d\n", ~a);       // Bitwise NOT
    printf("a << 1 = %d\n", a << 1); // Left shift
    printf("a >> 1 = %d\n", a >> 1); // Right shift

    // Assignment Operators
    a += b; // a = a + b
    printf("After a += b, a = %d\n", a);
    a -= b; // a = a - b
    printf("After a -= b, a = %d\n", a);
    a *= b; // a = a * b
    printf("After a *= b, a = %d\n", a);
    a /= b; // a = a / b
    printf("After a /= b, a = %d\n", a);
    a %= b; // a = a % b
    printf("After a %%= b, a = %d\n", a);

    // Conditional (Ternary) Operator
    int max = (a > b) ? a : b; // if a > b then max = a else max = b
    printf("Max of a and b is %d\n", max);

    return 0;
}
