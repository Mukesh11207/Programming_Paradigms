#include <stdio.h>
#include <string.h>

struct Record{
    char label[20];
    char procedure[20];
    struct Record *dynamic_link;
    struct Record *static_link;
};

struct Record records[10];
struct Record *stack[10];
int top = -1;total = 0;

struct Record *enter(char label[],char proc[],char parent[]){
    struct Record *r = &records[total++];

    strcpy(r -> label,label);
    strcpy(r -> procedure,proc);

    r -> dynamic_link = (top == -1) ? NULL : stack[top];
    r -> static_link = NULL;

    for(int i = top;i >= 0;i--){
        if(strcmp(stack[i]->procedure,parent) == 0){
            r -> static_link = stack[i];
            break;
        }
    }

    stack[++top] = r;
    return r;
}

int main() {
    enter("Bigsub", "Bigsub", "");

    enter("A(true)", "A", "Bigsub");
    enter("B", "B", "A");
    enter("A(false)", "A", "Bigsub");
    enter("C", "C", "Bigsub");
    enter("D", "D", "C");

    printf("%-15s %-15s %-15s\n",
           "Record", "Dynamic Link", "Static Link");

    for (int i = top; i >= 0; i--) {
        struct Record *r = stack[i];

        printf("%-15s %-15s %-15s\n",
               r->label,
               r->dynamic_link ? r->dynamic_link->label : "-",
               r->static_link ? r->static_link->label : "-");
    }

    return 0;
}