#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;

vector<int> s;

int main() {
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        s.push_back(m);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    sort(s.begin(), s.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    return 0;
}