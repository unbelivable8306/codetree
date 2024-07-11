#include <iostream>
#include <math.h>
using namespace std;

int sum = 0;

int print_pow(int n) {
    if (n < 10) return pow(n,2);
    return print_pow(n/10) + pow((n%10),2);
}

int main() {
    int N;
    cin >> N;
    cout << print_pow(N);
    return 0;
}