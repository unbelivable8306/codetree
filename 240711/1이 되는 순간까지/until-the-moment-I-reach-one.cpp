#include <iostream>
#include <math.h>
using namespace std;

int sum = 0;

int print_num(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) {
        return print_num(n / 2) + 1;
    }
    else return print_num(n / 3) + 1;
}

int main() {
    int N;
    cin >> N;
    cout << print_num(N);
    return 0;
}