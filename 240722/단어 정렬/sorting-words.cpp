#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;
vector<string> s;
int main() {
    int n;
    string m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        s.push_back(m);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}