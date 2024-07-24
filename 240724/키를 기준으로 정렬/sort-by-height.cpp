#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class student {
public:
    string name;
    int tall;
    int weight;
    student(string a="a", int b=0, int c=0) {
        this->name = a;
        this->tall = b;
        this->weight = c;
    }
};


bool compare(student a, student b) {
    return a.tall < b.tall;
}
int main() {
    student STU[10];
    int n;
    string a;
    int b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        STU[i] = student(a, b, c);
    }
    sort(STU, STU + n, compare);
    for (int i = 0; i < n; i++) {
        cout << STU[i].name << " " << STU[i].tall << " " << STU[i].weight << endl;
    }
    return 0;
}