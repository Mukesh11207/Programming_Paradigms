#include <iostream>
#include <vector>
using namespace std;

vector<int> rm_duplicates(vector<int>& a,int n){
    bool og[n] = {false};
    vector<int> c;
    for(int i = 0;i < n - 1;i++){
        if(!og[i]){
            c.push_back(a[i]);
            og[i] = true;
        }
        for(int j = i + 1;j < n;j++){
            if(a[j] == a[i]){
                og[j] = true;
            }
        }
    }
    return c;
}
void display(vector<int> a){
    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    vector<int> a = {1,1,2,3,2,5,4};
    vector<int> c;
    c = rm_duplicates(a,a.size());
    display(c);
    return 0;
}