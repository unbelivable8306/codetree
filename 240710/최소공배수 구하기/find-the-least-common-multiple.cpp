#include <iostream>
using namespace std;
void print_sq(int n, int m) {
    int min = 1;
    while (1) {
        if (min / n >= 1 && min / m >= 1 && min % n == 0 && min % m == 0) {
            break;
        }
        min++;
    }
    cout << min;
}
int main() {
    int n,m;
    cin >> n >> m ;
    print_sq(n,m);
    return 0;
}