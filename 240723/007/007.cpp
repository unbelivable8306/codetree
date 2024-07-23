#include<iostream>
#include<string>
using namespace std;

class m {
public:
    string secret_code;
    char meeting_point;
    int time;

    m(string sc, char mp, int t) {
        this->secret_code = sc;
        this->meeting_point = mp;
        this->time = t;
    }
};

int main() {
    string s;
    char c;
    int t;
    cin >> s >> c >> t;
    m m1 = m(s, c, t);
    cout << "secret code : " << m1.secret_code << endl;
    cout << "meeting point : " << m1.meeting_point << endl;
    cout << "time : " << m1.time << endl;
}