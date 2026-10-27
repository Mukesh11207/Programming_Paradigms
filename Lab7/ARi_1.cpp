#include <stdio.h>
#include <string.h>

typedef struct ARI{
    char name[20];
    struct ARI *dynamic_link;
    struct ARI *static_link;
}ari;

ari stack[20];
int top = -1;

void push(const char name[],ari *dynamic_link,ari* static_link,void *function_address){
    top++;
    strcpy(stack[top].name,name);
    stack[top].dynamic_link = dynamic_link;
    stack[top].static_link = static_link;

    printf("\nFunction name : %s\n",name);
    printf("Function address :- %p\n",function_address);
    printf("Activation record instance address :- %p\n",(void *)&stack[top]);
}

void display(){
    int i;
    printf("\n\nActivation record stack : \n\n");
    printf("Procedure\tAR Address\t\tDynamic Link\t\tStatic Link\n");
    printf("---------------------------------------------------------------");

    for(i = top;i >= 0;i--){
        printf("\n%s\t%p\t%p\t%p\n",stack[i].name,
        (void *)&stack[i],
        (void *)stack[i].dynamic_link,
        (void *)stack[i].static_link);
    }
}

void D(){
    push("D",&stack[4],&stack[2],(void *)D);
    display();
}

void C() {
    push("C",
         &stack[3],   // dynamic: A_false called C  → stack[3]=A_false
         &stack[0],   // static:  C defined in Bigsub → stack[0]=Bigsub
         (void *)C);
    D();
}

void A_false() {
    push("A(false)",
         &stack[2],   // dynamic: B called A_false  → stack[2]=B
         &stack[0],   // static:  A defined in Bigsub → stack[0]=Bigsub
         (void *)A_false);
    C();
}

void B() {
    push("B",
         &stack[1],   // dynamic: A_true called B   → stack[1]=A_true
         &stack[1],   // static:  B defined in A_true → stack[1]=A_true
         (void *)B);
    A_false();
}

void A_true() {
    push("A(true)",
         &stack[0],   // dynamic: Bigsub called A_true → stack[0]=Bigsub
         &stack[0],   // static:  A defined in Bigsub  → stack[0]=Bigsub
         (void *)A_true);
    B();
}

void Bigsub() {
    push("Bigsub",
         NULL,        // no caller
         NULL,        // no enclosing scope
         (void *)Bigsub);
    A_true();
}

int main(){
    Bigsub();
    return 0;
}