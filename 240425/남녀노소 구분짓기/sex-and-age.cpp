#include <iostream>
using namespace std;
int main() {
    int s,o;
    cin >> s;
    cin >> o;
    if(s == 0)
        if(o >= 19) cout << "MAN";
        else cout << "BOY";
    if(s == 1)
        if(o >= 19) cout << "WOMAN";
        else cout << "GIRL";
    return 0;
}