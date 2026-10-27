#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> a,vector<int> b){
    vector<int> c;
    int i,j;
    i = j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()){
        c.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        c.push_back(b[j]);
        j++;
    }
    return c;
}
void display(vector<int> c){
    for(int x : c){
        cout << x << " ";
    }cout << endl;
}
int main(){
    vector<int> a = {1,2,5,34};
    vector<int> b = {4,5,67,81};
    cout << "Sorted array :- \n";
    display(merge_sort(a,b));
    return 0;
}