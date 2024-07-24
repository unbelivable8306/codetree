#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

class student {
public:
    string name;
    int korean;
    int math;
    int english;
    student(string a="a", int b=0, int c=0, int d=0) {
        this->name = a;
        this->korean = b;
        this->math = c;
        this->english = d;
    }
};

student STU[10];

bool compare(student a, student b) {
    return a.korean + a.math + a.english < b.korean + b.math + b.english;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        int b, c, d;
        cin >> a >> b >> c >> d;
        STU[i]=student(a, b, c, d);
    }
    sort(STU, STU + n, compare);
    for (int i = 0; i < n; i++) {
        cout << STU[i].name << " " << STU[i].korean << " " << STU[i].math << " " << STU[i].english << endl;
    }
    return 0;
}