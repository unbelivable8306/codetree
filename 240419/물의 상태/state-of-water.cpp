#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if(n>=100) cout << "vapor";
    else if(n>=0) cout << "water";
    else cout << "ice";
    return 0;
}