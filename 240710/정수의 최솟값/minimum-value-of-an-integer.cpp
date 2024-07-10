#include <iostream>
using namespace std;
int min(int a, int b, int c){
    int min;
    if (a >= b) {
        if (b >= c) min = c;
        else min = b;
    }
    else {
        if (a >= c) min = c;
        else min = a;
    }
    return min;
}

int main() {
    int a,b,c,ans;
    cin >> a >> b >> c;
    ans = min(a,b,c);
    cout << ans;
    return 0;
}