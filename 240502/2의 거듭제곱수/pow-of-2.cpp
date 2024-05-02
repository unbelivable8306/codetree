#include <iostream>
using namespace std;
int main() {
    int N;
    int cnt = 0;
    cin >> N;
    while (N != 1) {
        N /= 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}