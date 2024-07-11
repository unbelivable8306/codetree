#include <iostream>
using namespace std;
void print_star(int n) {
    if (n == 0) return;
    print_star(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << "\n";
}

int main() {
    int N;
    cin >> N;
    print_star(N);
    return 0;
}