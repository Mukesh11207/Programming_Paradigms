#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int arr[] = {10, 5, 10, 8, 3};
    int n = 5;

    vector<int> v(arr, arr + n);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (v.size() < 2) {
        cout << "Second largest does not exist";
    } else {
        cout << "Second largest: " << v[v.size() - 2];
    }

    return 0;
}