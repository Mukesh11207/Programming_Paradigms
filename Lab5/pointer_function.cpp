#include <iostream>
using namespace std;

int add(int a,int b){
    return a + b;
}

int subtract(int a,int b){
    return a - b;
}

int multiply(int a,int b){
    return a * b;
}

int apply(int (*op)(int,int),int a,int b){
    return op(a,b);
}

int main(){
    cout << "Addition: " << apply(add, 10, 5) << endl;
    cout << "Subtraction: " << apply(subtract, 10, 5) << endl;
    cout << "Multiplication: " << apply(multiply, 10, 5) << endl;

    return 0;
}