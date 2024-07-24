#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

tuple<string, int, int> student[10];

bool compare(tuple<string, int, int> a, tuple<string, int, int> b) {
    return get<1>(a) < get<1>(b);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        student[i] = make_tuple(a, b, c);
    }
    sort(student, student + n, compare);
    for (int i = 0; i < n; i++) {
        string a;
        int b, c;
        tie(a, b, c) = student[i];
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}