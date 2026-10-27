#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a = {1,5,4,6,2};
    int n = a.size();
    for(int i = 0;i < n;i++){
        bool visited[n] = {false};
        if(visited[i]){
            continue;
        }
        int count = 1;

        for(int j = i + 1;j < n;j++){
            if(a[i] == a[j]){
                count++;
                visited[j] = true;
            }
        }
        cout << a[i] << " occurs " << count << " times\n";
    }
    return 0;
}