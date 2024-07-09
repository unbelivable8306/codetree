#include <iostream>
using namespace std;
void print_row(int n) {
    for (int i = 0; i < n; i++) {
        cout << "12345^&*()_";
        cout << endl;
    }
}
int main() {
    int row_num;
    cin >> row_num;
    print_row(row_num);
    return 0;
}