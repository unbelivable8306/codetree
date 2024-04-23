#include <iostream>

using namespace std;

int main() {
    // 변수 선언 및 입력
    int a, b, c;
    cin >> a >> b >> c;
    
    // a가 가장 작은 경우
    if(a <= b && a <= c) {
        cout << a;
    }
    // b가 가장 작은 경우
    else if(b <= a && b <= c) {
        cout << b;
    }
    // c가 가장 작은 경우
    else {
        cout << c;
    }
    return 0;
}