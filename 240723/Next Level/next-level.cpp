#include<iostream>
#include<string>
#include<tuple>
using namespace std;

tuple<string, int> t;

int main() {
    string a;
    int b;
    cin >> a >> b;
    t = make_tuple("codetree", 10);
    cout << "user" << " " << get<0>(t) << " " << "lv" << " " << get<1>(t) << endl;
    t = make_tuple(a, b);
    cout << "user" << " " << get<0>(t) << " " << "lv" << " " << get<1>(t) << endl;
}