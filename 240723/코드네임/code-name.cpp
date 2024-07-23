#include<iostream>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;

tuple<char, int> t[5];

bool compare(tuple<char,int> a, tuple<char,int> b) {
    return get<1>(a) < get<1>(b);
}

int main() {
    for (int i = 0; i < 5; i++) {
        char a;
        int b;
        cin >> a >> b;
        t[i] = make_tuple(a, b);
    }
    sort(t, t + 5, compare);
    cout << get<0>(t[0]) << " " << get<1>(t[0]);
}