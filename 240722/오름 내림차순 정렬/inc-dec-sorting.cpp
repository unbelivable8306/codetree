#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;
int a[100];

int main() {
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a,a+n, greater<int>());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}