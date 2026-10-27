#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& a){
    for(int i = 0;i < a.size()/2;i++){
        int temp = a[i];
        a[i] = a[a.size() - i -1];
        a[a.size() - i - 1] = temp;
    }
}

int main(){
    vector<int> a = {1,2,3,4,5};
    reverse(a);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}