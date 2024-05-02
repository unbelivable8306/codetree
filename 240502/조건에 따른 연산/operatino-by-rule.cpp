#include <iostream>
using namespace std;
int main() {
    int N;
    int cnt = 0;
    cin >> N;
    while (N <1000) {
        if (N % 2 == 0) N = N * 3 + 1;
        else if (N % 2 == 1) N = N * 2 + 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}