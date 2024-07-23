#include<iostream>
#include<string>
#include<tuple>
using namespace std;

class f {
public:
    string id;
    int level;
    f(string a = "codetree", int lv = 10) {
        this->id = a;
        this->level = lv;
    }
};

int main() {
    string a;
    int b;
    cin >> a >> b;
    f f1 = f();
    cout << "user" << " " << f1.id << " " << "lv" << " " << f1.level << endl;
    f1.id = a;
    f1.level = b;
    cout << "user" << " " << f1.id << " " << "lv" << " " << f1.level << endl;
}