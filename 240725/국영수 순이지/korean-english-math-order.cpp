#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

tuple<int, int, int, string> student[10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        student[i] = make_tuple(-a, -b, -c,s);
    }
    sort(student, student + n);
    for (int i = 0; i < n; i++) {
        string s;
        int a, b, c;
        tie(a, b, c,s) = student[i];
        cout << s << " " << -a << " " << -b << " " << -c << endl;
    }
    return 0;
}