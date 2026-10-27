#include <stdio.h>

void callbyValue(int x){
    x = 100;
    printf("Inside callbyvalue function :- ",x);
}

void callbyAddress(int *x){
    *x = 20;
}

void callbyreference(int *x){
    *x = 30;
}

void displayDefault(int x){
    printf("Default parameter value : %d\n",x);
}
void display(){
    displayDefault(10);
}
void keywordParameter(int age, int marks){
printf("Age: %d\n", age);
printf("Marks: %d\n", marks);
}
int main(){
int a = 10;
printf("Call by Value :- \n");
printf("Before: %d\n", a);
callbyValue(a);
printf("After: %d\n\n", a);
printf("Call by Address :- \n");
printf("Before: %d\n", a);
callbyAddress(&a);
printf("After: %d\n\n", a);
printf("Call by Reference :- \n");
printf("Before: %d\n", a);
callbyreference (&a);
printf("After: %d\n\n", a);
printf("Default Parameter :- \n");
display();
printf("\nKeyword Parameter :- \n");
keywordParameter(20, 95);
return 0;
}