#include <stdio.h>
#include <string.h>

typedef struct ActivationRecord {
    char name[20];
    struct ActivationRecord *dynamic_link;
    struct ActivationRecord *static_link;
} ActivationRecord;

ActivationRecord stack[20];
int top = -1;

void push(char name[],
          ActivationRecord *dynamic_link,
          ActivationRecord *static_link,
          void *function_address) {
    top++;
    strcpy(stack[top].name, name);
    stack[top].dynamic_link = dynamic_link;
    stack[top].static_link  = static_link;

    printf("\nFunction: %s\n", name);
    printf("Function Address: %p\n", function_address);
    printf("Activation Record Address: %p\n", (void *)&stack[top]);
}

void display() {
    int i;
    printf("\n\nActivation Record Stack:\n\n");
    printf("Level\tProcedure\tAR Address\t\tDynamic Link\t\tStatic Link\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = top; i >= 0; i--) {
        printf("%d\t%s\t\t%p\t\t%p\t\t%p\n",
               i,
               stack[i].name,
               (void *)&stack[i],
               (void *)stack[i].dynamic_link,
               (void *)stack[i].static_link);
    }
}

void D() {
    push("D",
         &stack[4],   // dynamic: C called D
         &stack[2],   // static:  D defined inside B
         (void *)D);
    display();
}

void C() {
    push("C",
         &stack[3],   // dynamic: A_false called C
         &stack[0],   // static:  C defined inside Bigsub
         (void *)C);
    D();
}

void A_false() {
    push("A(false)",
         &stack[2],   // dynamic: B called A_false
         &stack[0],   // static:  A defined inside Bigsub
         (void *)A_false);
    C();
}

void B() {
    push("B",
         &stack[1],   // dynamic: A_true called B
         &stack[1],   // static:  B defined at A_true level
         (void *)B);
    A_false();
}

void A_true() {
    push("A(true)",
         &stack[0],   // dynamic: Bigsub called A_true
         &stack[0],   // static:  A defined inside Bigsub
         (void *)A_true);
    B();
}

void Bigsub() {
    push("Bigsub",
         NULL,        // no caller above Bigsub
         NULL,        // no enclosing scope
         (void *)Bigsub);
    A_true();
}

int main() {
    Bigsub();
    return 0;
}