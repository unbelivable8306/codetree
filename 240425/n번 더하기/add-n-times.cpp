#include <iostream>
using namespace std;
int main() {
    int a,n,sum;
    cin >> a >> n;
    for(int i=1;i<=n;i++){
        sum = a+n*i;
        cout << sum << endl;
    }
    return 0;
}