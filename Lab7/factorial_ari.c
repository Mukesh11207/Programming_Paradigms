#include <stdio.h>
#include <string.h>

typedef struct ActivationRecord{
    char name[20];
    int n;
    int result;
    struct ActivationRecord *dynamic_link;
    struct ActivationRecord *static_link;
}Ari;

Ari stack[20];
int top = -1;

void push(char name[],int n,Ari *dynamic_link,Ari *static_link){
    top++;

    strcpy(stack[top].name,name);
    stack[top].n = n;
    stack[top].result = 0;

    stack[top].dynamic_link = dynamic_link;
    stack[top].static_link = static_link;

    printf("\nActivation Record Created");
    printf("\nFunction: %s",name);
    printf("\nn = %d", n);
    printf("\nAR Address : %p",(void*)&stack[top]);
    printf("\nDynamic Link : %p",(void *)dynamic_link);
    printf("\nStatic Link : %p\n",(void *)static_link);
}

void display(){
    printf("\n\nActivation Record Stack :- ");
    printf("Function\t n\t AR Address\t\t Dynamic Link\t\t Static Link\n");
    printf("--------------------------------------------------------------------------\n");

    for(int i = top; i >= 0; i--) {

    printf("%s\t\t%d\t%p\t%p\t%p\n",
        stack[i].name,
        stack[i].n,
        (void *)&stack[i],
        (void *)stack[i].dynamic_link,
        (void *)stack[i].static_link);
    }
}
int factorial(int n){
    Ari *caller = (top == -1) ? NULL : &stack[top];
    push("factorial",n,caller,NULL);
    display();

    if(n == 0 || n == 1){
        stack[top].result = 1;
        top--;
        return 1;
    }

    int result = n * factorial(n  -1);
    stack[top].result = result;

    top--;

    return result;
}
int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int ans = factorial(n);

    printf("\nFinal Factorial = %d\n", ans);

    return 0;
}