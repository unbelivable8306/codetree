#include <iostream>
using namespace std;

int sum = 0;

void print_sum(int n) {
    if (n == 0) return;
    print_sum(n - 1);
    sum += n;
}

int main() {
    int N;
    cin >> N;
    print_sum(N);
    cout << sum;
    return 0;
}