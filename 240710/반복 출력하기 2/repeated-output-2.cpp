#include <iostream>
using namespace std;
void print_HW(int n) {
    if (n == 0) return;
    print_HW(n - 1);
    cout << "HelloWorld" << endl;
}

int main() {
    int N;
    cin >> N;
    print_HW(N);
    return 0;
}