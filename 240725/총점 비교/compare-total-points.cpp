#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

tuple<string, int, int, int> student[10];

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
    string name1;
    int kor, math, eng;
    tie(name1, kor, math, eng) = a;
    string name2;
    int kor1, math1, eng1;
    tie(name2, kor1, math1, eng1) = b;
    return kor + math + eng < kor1 + math1 + eng1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        int b, c, d;
        cin >> a >> b >> c >> d;
        student[i] = make_tuple(a,b,c,d);
    }
    sort(student, student + n, compare);
    for (int i = 0; i < n; i++) {
        string a;
        int b, c, d;
        tie(a, b, c, d) = student[i];
        cout << a << " " << b << " " << c << " " << d << endl;
    }
    return 0;
}