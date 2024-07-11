#include <iostream>
using namespace std;
void print_one(int n) {
    if (n == 0) return;
    print_one(n - 1);
    cout << n << " ";
}
void print_two(int n) {
    cout << n << " ";
    if (n == 1) return;
    print_two(n - 1);
}

int main() {
    int N;
    cin >> N;
    print_one(N);
    cout << endl;
    print_two(N);
    return 0;
}