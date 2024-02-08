#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // If statement
    if (a < b) {
        // This block executes if the condition (a < b) is true
        printf("a is less than b.\n");
    }

    // If-else statement
    if (a == b) {
        // This block executes if a is equal to b
        printf("a is equal to b.\n");
    } else {
        // This block executes if a is not equal to b
        printf("a is not equal to b.\n");
    }

    // For loop
    printf("For loop from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        // This block executes repeatedly, incrementing i from 1 to 5
        printf("%d ", i);
    }
    printf("\n");

    // While loop
    int count = 5;
    printf("While loop counting down from 5:\n");
    while (count > 0) {
        // This block executes as long as count is greater than 0
        printf("%d ", count);
        count--; // Decrement count
    }
    printf("\n");

    // Switch statement
    int day = 3; // Let's say 3 represents Wednesday
    printf("Switch case for days of the week (3 = Wednesday):\n");
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        default:
            printf("Weekend\n");
            break; // Break is not necessary here but good practice to include
    }

    // Nested loops and use of continue
    printf("Nested loops with continue (only odd numbers from 1 to 5):\n");
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) { // If i is even
            continue; // Skip the rest of the loop and continue with the next iteration
        }
        // This line only executes for odd values of i
        printf("%d ", i);
    }
    printf("\n");

    // Use of break in a while loop
    printf("While loop with break (stops at 3):\n");
    count = 1;
    while (count <= 5) {
        if (count == 4) {
            break; // Exits the loop if count equals 4
        }
        printf("%d ", count);
        count++;
    }
    printf("\n");

    return 0;
}


// ### Expressions:
// - **Definition**: An expression in C is a combination of one or more operands, operators, and function calls that the compiler can evaluate to produce another value. Every expression resolves to a value, which can be a number, a string, or any data type.
// - **Characteristics**:
//   - **Evaluative Nature**: Expressions are evaluated to produce a single value. For example, `5 + 3`, `a * b`, and `functionCall()` are all expressions that yield a result when evaluated.
//   - **Composability**: Expressions can be simple, consisting of just a single operand (e.g., `a`), or complex, combining multiple operators and operands (e.g., `a + b * c`).
//   - **Contextual Use**: Expressions are often used as part of statements, in function arguments, and in conditional tests (e.g., in an `if` statement's condition).

// ###  Statements:
// - **Definition**: A statement in C is an instruction that the C program executes. It can be a simple command like assigning a value to a variable, or a control structure like an `if` statement, `for` loop, or a function call.
// - **Characteristics**:
//   - **Executable Nature**: Statements perform actions and do not necessarily produce a value. They are the building blocks that define the program's behavior.
//   - **Structural Role**: Statements form the body of functions, loops, and conditional blocks, dictating the flow of execution within a program.
//   - **Variety**: There are several types of statements, including expression statements (an expression followed by a semicolon), control flow statements (`if`, `else`, `for`, `while`, `switch`), and compound statements (a block of statements enclosed in braces `{}`).

// ### Key Differences:
// - **Value vs. Action**: The key difference lies in their outcomes; expressions evaluate to a value, whereas statements perform an action or a series of actions.
// - **Role in Syntax**: Expressions are often part of statements, serving as the building blocks within them. For example, the right-hand side of an assignment statement is an expression, and the condition in an `if` statement is also an expression.
// - **Completeness**: A statement is complete in itself and can exist independently, forming a complete instruction to the program. An expression, by itself, usually does not constitute a complete instruction until it is used within a statement.

// Understanding the distinction between expressions and statements is crucial for grasping how C programs are constructed and how they execute, influencing everything from simple calculations to complex logic and control flow within a program.
