#include <iostream>
using namespace std;
void print_sq(int n, int m) {
    int max = 1;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && m % i == 0) {
            max = i;
        }
    }
    cout << max;
}
int main() {
    int n,m;
    cin >> n >> m ;
    print_sq(n,m);
    return 0;
}