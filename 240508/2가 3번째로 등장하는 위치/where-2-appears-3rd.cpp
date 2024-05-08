#include <iostream>
using namespace std;
int n,chpoint;
int cnt = 0;
int a[100];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 2) cnt++;
        if (cnt == 3) {
            chpoint = i + 1;
            cnt = -100;
        }
    }
    cout << chpoint;
    return 0;
}