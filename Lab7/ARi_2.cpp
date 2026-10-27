#include <stdio.h>
#include <string.h>

typedef struct ActivationRecord{
    char name[20];
    struct ActivationRecord *dynamic_link;
    struct ActivationRecord *static_link;
}ari;

ari stack[20];
int top = -1;

void push(const char name[],ActivationRecord *dynamic_link,ActivationRecord *static_link,
    void *functionAddress){
        top++;
        strcpy(stack[top].name,name);
        stack[top].dynamic_link = dynamic_link;
        stack[top].static_link = static_link;

        printf("\nFunction name : %s\n",name);
        printf("Function address :- %p\n",functionAddress);
        printf("Activation record instance address :- %p\n",(void *)&stack[top]);
    }
    void display(){
        int i;
        printf("\n\nActivation record stack : \n\n");
        printf("Procedure\tAR Address\t\tDynamic Link\t\tStatic Link\n");
        printf("---------------------------------------------------------------");
        for(i = top;i >= 0;i--){
            printf("%s\t\t%p\t%p\t%p\n",
            stack[i].name,
            (void *)&stack[i],
            (void*)stack[i].dynamic_link,
            (void *)stack[i].static_link);
        }
    }
    void C(float Plums){
        push("C",&stack[2],&stack[0],(void *)C);
        display();
    }
    void B(float sum){
        float y,z;
        push("B",&stack[1],&stack[1],(void *)B);
        C(z);
    }
    void A(){
        float sum;
        push("A",&stack[0],&stack[0],(void *)A);
        B(sum);
    }
    void Bigsub(){
        float MySum;
        push("Bigsub",NULL,NULL,(void *)Bigsub);
        A();
    }

int main(){
    Bigsub();
    return 0;
}