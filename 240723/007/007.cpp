#include<iostream>
#include<string>
#include<tuple>
using namespace std;

tuple<string, char, int> t;

int main() {
    string a;
    char b;
    int c;
    cin >> a >> b >> c;
    t = make_tuple(a, b, c);
    cout << "secret code : " << get<0>(t) << endl;
    cout << "meeting point : " << get<1>(t) << endl;
    cout << "time : " << get<2>(t) << endl;
}