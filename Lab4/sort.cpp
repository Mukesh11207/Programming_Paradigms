#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &a,int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void display(vector<int> a){
    for(int x : a){
        cout << x << " ";
    }cout << endl;
}
int main(){
    vector<int> a = {1,443,23,89,67,0};
    sort(a,a.size());
    cout << "Sorted array :- \n";
    display(a);
    return 0;
}