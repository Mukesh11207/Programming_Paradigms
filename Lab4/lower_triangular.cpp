#include <iostream>
#include <vector>
using namespace std;

void lower_triangle(vector<vector<int>> a){
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[i].size();j++){
            if(i > j){
                cout << a[i][j] << " ";
            }
            else{
                cout << "- ";
            }
        }
        cout << endl;
    }
}
int main(){
    vector<vector<int>> matrix(3,vector<int>(3));
    matrix = {{1,2,3},
              {4,5,6},
              {7,8,9}};
    lower_triangle(matrix);
    return 0;
}