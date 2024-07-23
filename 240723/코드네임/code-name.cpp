#include<iostream>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;

class student {
public:
    char name;
    int score;

    student(char n='a', int s=0) {
        this->name = n;
        this->score = s;
    }
};

bool compare(student a, student b) {
    return a.score < b.score;
}

int main() {
    student stu[5];
    for (int i = 0; i < 5; i++) {
        char a;
        int b;
        cin >> a >> b;
        stu[i] = student(a, b);
    }
    sort(stu, stu + 5, compare);
    cout << stu[0].name << " " << stu[0].score;
}