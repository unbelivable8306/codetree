#include <iostream>
using namespace std;
int main() {
    int n;
    int a;
    int sum = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        if(a%2 == 1 && a%3 == 0) sum += a;
    }
    cout << sum;
    return 0;
}