#include <stdio.h>

void callByValue(int x) {//call by value
    x = 100;
    printf("Inside Call by Value: %d\n", x);
}

void callByAddress(int *x) {//call by address
    *x = 200;
}

/*Call by Reference
C does not support true call by reference.
We use a pointer to achieve reference-like behavior.*/
void callByReference(int *x) {
    *x = 300;
}

/*Default Parameter
C does not support default parameters.
We simulate it by using a wrapper function.*/
void displayDefault(int x) {
    printf("Default Parameter Value: %d\n", x);
}

void display() {
    displayDefault(10);     // Default value
}

/*C does not support keyword parameters.
We simulate them by explicitly passing values.*/
void keywordParameter(int age, int marks) {
    printf("Age: %d\n", age);
    printf("Marks: %d\n", marks);
}
int main() {
    int a = 10;

    printf("Call by Value :- \n");
    printf("Before: %d\n", a);
    callByValue(a);
    printf("After: %d\n\n", a);

    printf("Call by Address :- \n");
    printf("Before: %d\n", a);
    callByAddress(&a);
    printf("After: %d\n\n", a);

    printf("Call by Reference :- \n");
    printf("Before: %d\n", a);
    callByReference(&a);
    printf("After: %d\n\n", a);

    printf("Default Parameter :- \n");
    display();

    printf("\nKeyword Parameter :- \n");
    keywordParameter(20, 95);
    return 0;
}