#include <iostream>
#include <math.h>
using namespace std;

int sum = 0;

int f(int n) {
    if (n == 1) return 1;
    return f(n - 1)*n;
}

int main() {
    int N;
    cin >> N;
    cout << f(N);
    return 0;
}