#include <iostream>
#include <math.h>
using namespace std;

int sum = 0;

int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 0) {
        return n + f(n - 2);
    }
    else  return n + f(n - 2);
}

int main() {
    int N;
    cin >> N;
    cout << f(N);
    return 0;
}