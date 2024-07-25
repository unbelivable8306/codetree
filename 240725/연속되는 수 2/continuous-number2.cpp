#include <iostream>
using namespace std;

int a[1000];
int Max = -100;
int cnt = 1;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        if (a[i + 1] == a[i]) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        if (cnt > Max) {
            Max = cnt;
        }
    }
    cout << Max;
    return 0;
}