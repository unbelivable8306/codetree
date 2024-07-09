#include <iostream>
using namespace std;
void print_sq(int N) {
    int init = 0;
    int a[9] = { 1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[init % 9] << " ";
            init++;
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n ;
    print_sq(n);
    return 0;
}