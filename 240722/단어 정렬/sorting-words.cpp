#include <iostream>
#include <algorithm>
using namespace std;
string s[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}