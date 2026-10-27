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
          void *functionAddress) {
    top++;
    strcpy(stack[top].name, name);
    stack[top].dynamic_link = dynamic_link;
    stack[top].static_link  = static_link;

    printf("\nFunction Name: %s\n", name);
    printf("Function Address: %p\n", functionAddress);
    printf("Activation Record Address: %p\n", (void *)&stack[top]);
}

void display() {
    int i;
    printf("\n\nActivation Record Stack:\n\n");
    printf("Procedure\tAR Address\t\tDynamic Link\t\tStatic Link\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = top; i >= 0; i--) {
        printf("%s\t\t%p\t\t%p\t\t%p\n",
               stack[i].name,
               (void *)&stack[i],
               (void *)stack[i].dynamic_link,
               (void *)stack[i].static_link);
    }
}

void C(float Plums) {
    push("C",
         &stack[2],   // dynamic: B called C
         &stack[0],   // static:  C defined inside Bigsub
         (void *)C);
    display();
}

void B(float sum) {
    float y, z;
    push("B",
         &stack[1],   // dynamic: A called B
         &stack[1],   // static:  B defined at A's level
         (void *)B);
    C(z);
}

void A() {
    float sum;
    push("A",
         &stack[0],   // dynamic: Bigsub called A
         &stack[0],   // static:  A defined inside Bigsub
         (void *)A);
    B(sum);
}

void Bigsub() {
    float MySum;
    push("Bigsub",
         NULL,        // no caller above Bigsub
         NULL,        // no enclosing scope
         (void *)Bigsub);
    A();
}

int main() {
    Bigsub();
    return 0;
}