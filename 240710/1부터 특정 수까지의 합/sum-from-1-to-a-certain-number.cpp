#include <iostream>
using namespace std;
int total_num(int num){
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    return sum / 10;
}

int main() {
    int n, total;
    cin >> n;
    total = total_num(n);
    cout << total;
    return 0;
}