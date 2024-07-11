#include <iostream>
using namespace std;
void print_rt(int n) {
    if (n == 0) return;  // 종료조건
    for (int i = 0; i < n; i++) {
        cout << "*" << " ";
    }
    cout << "\n";
    print_rt(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "*" << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    print_rt(N);
    return 0;
}