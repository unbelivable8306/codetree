#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    bool satisfied = true;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++) {
        if (i%c == 0) satisfied = false;
    }
    if (satisfied == true) cout << "YES";
    else cout << "NO";
    return 0;
}