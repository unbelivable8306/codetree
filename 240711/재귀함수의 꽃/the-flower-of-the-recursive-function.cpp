#include <iostream>
using namespace std;
void print_rt(int n) {
    if (n == 0) return;
    cout << n << " ";
    print_rt(n - 1);
    cout << n << " ";
}

int main() {
    int N;
    cin >> N;
    print_rt(N);
    return 0;
}